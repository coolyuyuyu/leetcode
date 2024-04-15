class FileSystem {
private:
    struct Node {
        std::map<string, Node*> childs;
        string content;
    };

public:
    FileSystem()
        : m_root(new Node) {
    }

    vector<string> ls(string path) {
        Node* node = m_root;
        string token;
        for (int i = 1; i < path.size(); ++i) {
            token.clear();
            while (i < path.size() && path[i] != '/') {
                token += path[i++];
            }

            if (node->childs[token] == nullptr) {
                node->childs[token] = new Node();
            }
            node = node->childs[token];
        }

        if (node->content.empty()) {
            vector<string> ret;
            for (const auto& [file, _] : node->childs) {
                ret.push_back(file);
            }
            return ret;
        }
        else {
            return {token};
        }
    }

    void mkdir(string path) {
        Node* node = m_root;
        for (int i = 1; i < path.size(); ++i) {
            string token;
            while (i < path.size() && path[i] != '/') {
                token += path[i++];
            }

            if (node->childs[token] == nullptr) {
                node->childs[token] = new Node();
            }
            node = node->childs[token];
        }
    }

    void addContentToFile(string filePath, string content) {
        Node* node = m_root;
        for (int i = 1; i < filePath.size(); ++i) {
            string token;
            while (i < filePath.size() && filePath[i] != '/') {
                token += filePath[i++];
            }

            if (node->childs[token] == nullptr) {
                node->childs[token] = new Node();
            }
            node = node->childs[token];
        }

        node->content += content;
    }

    string readContentFromFile(string filePath) {
        Node* node = m_root;
        for (int i = 1; i < filePath.size(); ++i) {
            string token;
            while (i < filePath.size() && filePath[i] != '/') {
                token += filePath[i++];
            }

            if (node->childs[token] == nullptr) {
                node->childs[token] = new Node();
            }
            node = node->childs[token];
        }

        return node->content;
    }

private:
    Node* m_root;
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * vector<string> param_1 = obj->ls(path);
 * obj->mkdir(path);
 * obj->addContentToFile(filePath,content);
 * string param_4 = obj->readContentFromFile(filePath);
 */
