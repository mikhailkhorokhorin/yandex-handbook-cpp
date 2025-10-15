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
