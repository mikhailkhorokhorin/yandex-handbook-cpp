bool Tree::Has(const std::vector<std::string>& path) const {
    const Node* node = &root;

    for (const auto& key : path) {
        auto iter = node->children.find(key);

        if (iter == node->children.end())
            return false;

        node = &iter->second;
    }
    return true;
}

void Tree::Insert(const std::vector<std::string>& path) {
    Node* node = &root;

    for (const auto& key : path) 
        node = &node->children[key];
    
}

void Tree::Delete(const std::vector<std::string>& path) {
    Node* node = &root;
    std::vector<Node*> nodes;
    std::vector<std::string> keys;

    nodes.push_back(node);
    for (const auto& key : path) {
        auto iter = node->children.find(key);

        if (iter == node->children.end())
            return;
        node = &iter->second;
        
        nodes.push_back(node);
        keys.push_back(key);
    }

    Node* parent = nodes[nodes.size() - 2];
    parent->children.erase(keys.back());
}
