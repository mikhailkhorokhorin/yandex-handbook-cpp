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
