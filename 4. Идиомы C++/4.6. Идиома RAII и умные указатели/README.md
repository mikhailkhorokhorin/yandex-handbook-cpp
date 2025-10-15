# 4.6. Идиома RAII и умные указатели

### A. Tree-2

```cpp
#include <iostream>
#include <vector>

class TreeNode {
   private:
    int value;
    TreeNode* root = nullptr;
    std::vector<TreeNode*> children;

   public:
    explicit TreeNode(int val) : value(val) {
    }

    TreeNode(const TreeNode&) = delete;
    TreeNode& operator=(const TreeNode&) = delete;

    ~TreeNode() {
        for (TreeNode* child : children)
            delete child;
    }

    TreeNode* AddChild(int child_value) {
        auto* node = new TreeNode(child_value);
        node->root = this;
        children.push_back(node);
        return node;
    }

    void Print(int depth = 0) const {
        for (int i = 0; i < depth; ++i)
            std::cout << " ";

        std::cout << "- " << value << std::endl;

        for (const auto& child : children)
            child->Print(depth + 1);
    }
};
```

### B. Monitor

```cpp
#include <map>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>

class Monitor {
   private:
    using Ptr = ParticipantResults*;
    using ConstPtr = const ParticipantResults*;

    std::map<std::string, std::unique_ptr<ParticipantResults>> byParticipant_;
    std::map<std::string, std::vector<ConstPtr>> byTeam_;
    std::vector<ConstPtr> allResults_;

   public:
    Monitor() = default;
    Monitor(const Monitor&) = delete;
    Monitor& operator=(const Monitor&) = delete;

    Ptr RegisterParticipant(const std::string& login, const std::string& team) {
        if (byParticipant_.count(login))
            throw std::invalid_argument("Participant is already registered");

        auto participant = std::make_unique<ParticipantResults>(login, team);
        Ptr ptr = participant.get();

        byParticipant_[login] = std::move(participant);

        byTeam_[team].push_back(ptr);
        allResults_.push_back(ptr);

        return ptr;
    }

    Ptr GetParticipantResults(const std::string& login) {
        return byParticipant_.at(login).get();
    }

    ConstPtr GetParticipantResults(const std::string& login) const {
        return byParticipant_.at(login).get();
    }

    std::vector<ConstPtr> GetTeamResults(const std::string& team) const {
        return byTeam_.at(team);
    }

    std::vector<ConstPtr> GetAllResults() const {
        return allResults_;
    }
};
```

### C. Снова жизнь объекта

```cpp
class B : public A {
   private:
    A a_;

   public:
    B() : A(42), a_(17) {
    }
};
```

### D. Зоопарк

```cpp
#include <iostream>
#include <memory>
#include <stdexcept>
#include <vector>

#include "animals.h"

using Zoo = std::vector<std::unique_ptr<Animal>>;

Zoo CreateZoo() {
    Zoo zoo;
    std::string word;

    while (std::cin >> word) {
        if (word == "Tiger")
            zoo.push_back(std::make_unique<Tiger>());
        else if (word == "Wolf")
            zoo.push_back(std::make_unique<Wolf>());
        else if (word == "Fox")
            zoo.push_back(std::make_unique<Fox>());
        else
            throw std::runtime_error("Unknown animal!");
    }

    return zoo;
}

void Process(const Zoo& zoo) {
    for (const auto& animal : zoo)
        std::cout << animal->Voice() << std::endl;
}
```

### E. Выживание

```cpp
#include <memory>
#include <string>

class ConstExpr : public Expression {
    int value_;

   public:
    explicit ConstExpr(int value) : value_(value) {
    }

    int Evaluate() const override {
        return value_;
    }

    std::string ToString() const override {
        return std::to_string(value_);
    }
};

class SumExpr : public Expression {
    ExpressionPtr left_, right_;

   public:
    SumExpr(ExpressionPtr l, ExpressionPtr r) : left_(std::move(l)), right_(std::move(r)) {
    }

    int Evaluate() const override {
        return left_->Evaluate() + right_->Evaluate();
    }

    std::string ToString() const override {
        return left_->ToString() + " + " + right_->ToString();
    }
};

class ProductExpr : public Expression {
    ExpressionPtr left_, right_;

   public:
    ProductExpr(ExpressionPtr l, ExpressionPtr r) : left_(std::move(l)), right_(std::move(r)) {
    }

    int Evaluate() const override {
        return left_->Evaluate() * right_->Evaluate();
    }

    std::string ToString() const override {
        std::string lstr = left_->ToString();
        std::string rstr = right_->ToString();

        if (dynamic_cast<SumExpr*>(left_.get()))
            lstr = "(" + lstr + ")";
        if (dynamic_cast<SumExpr*>(right_.get()))
            rstr = "(" + rstr + ")";

        return lstr + " * " + rstr;
    }
};

inline ExpressionPtr Const(int value) {
    return std::make_shared<ConstExpr>(value);
}

inline ExpressionPtr Sum(ExpressionPtr left, ExpressionPtr right) {
    return std::make_shared<SumExpr>(std::move(left), std::move(right));
}

inline ExpressionPtr Product(ExpressionPtr left, ExpressionPtr right) {
    return std::make_shared<ProductExpr>(std::move(left), std::move(right));
}
```

### F. Документы

```cpp
#include <iostream>
#include <memory>
#include <string>
#include <vector>

class Document {
   protected:
    const std::string Content;

   public:
    Document(const std::string& s) : Content(s) {
    }

    virtual ~Document() = default;

    virtual void Save() const {
        std::cout << Content << std::endl;
    }
};

class PlainTextDocument : public Document {
   public:
    PlainTextDocument(const std::string& s) : Document(s) {
    }

    void Save() const override {
        std::cout << Content << std::endl;
    }
};

class HTMLDocument : public Document {
   public:
    HTMLDocument(const std::string& s) : Document(s) {
    }

    void Save() const override {
        std::cout << "<HTML><BODY>" << Content << "</BODY></HTML>" << std::endl;
    }
};

using DocumentCollection = std::vector<std::shared_ptr<Document>>;

void AddDocument(const std::string& content, const std::string& type,
                 DocumentCollection& collection) {
    if (type == "plain")
        collection.push_back(std::make_shared<PlainTextDocument>(content));
    else if (type == "html")
        collection.push_back(std::make_shared<HTMLDocument>(content));
}

void PrintCollection(const DocumentCollection& collection) {
    for (const auto& doc : collection)
        doc->Save();
}
```

### G. Коварная матрица

```cpp
Matrix(const Matrix& other) : rows(other.rows), columns(other.columns) {
    data = new T*[rows];
    size_t i = 0;
    try {
        for (; i != rows; ++i) {
            data[i] = new T[columns];

            for (size_t j = 0; j != columns; ++j)
                data[i][j] = other.data[i][j];
        }
    } catch (...) {
        for (size_t k = 0; k != i; ++k)
            delete[] data[k];

        delete[] data;
        throw;
    }
}

Matrix& operator=(const Matrix& other) {
    if (this == &other)
        return *this;

    T** new_data = new T*[other.rows];
    size_t i = 0;

    try {
        for (; i != other.rows; ++i) {
            new_data[i] = new T[other.columns];

            for (size_t j = 0; j != other.columns; ++j)
                new_data[i][j] = other.data[i][j];
        }
    } catch (...) {
        for (size_t k = 0; k != i; ++k)
            delete[] new_data[k];

        delete[] new_data;
        throw;
    }

    for (size_t k = 0; k != rows; ++k)
        delete[] data[k];

    delete[] data;

    data = new_data;
    rows = other.rows;
    columns = other.columns;

    return *this;
}

Matrix(Matrix&& other) noexcept : data(other.data), rows(other.rows), columns(other.columns) {
    other.data = nullptr;
    other.rows = 0;
    other.columns = 0;
}

Matrix& operator=(Matrix&& other) noexcept {
    if (this != &other) {
        for (size_t k = 0; k != rows; ++k)
            delete[] data[k];

        delete[] data;

        data = other.data;
        rows = other.rows;
        columns = other.columns;

        other.data = nullptr;
        other.rows = 0;
        other.columns = 0;
    }

    return *this;
}
```
