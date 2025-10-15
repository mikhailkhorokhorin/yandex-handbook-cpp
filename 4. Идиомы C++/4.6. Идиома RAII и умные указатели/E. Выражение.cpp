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
