class FileSystem {
private:
    struct TrieNode {
        unordered_map<string, TrieNode*> childs;
        int val;

        TrieNode(int v = 0) {
            val = v;
        }
    };
    TrieNode* m_root;

public:
    FileSystem() {
        m_root = new TrieNode();
    }

    bool createPath(string path, int value) {
        vector<string> names = split(path);

        TrieNode* node = m_root;
        for (int i = 0; i + 1 < names.size(); ++i) {
            if (node->childs.find(names[i]) == node->childs.end()) {
                return false;
            }
            node = node->childs[names[i]];
        }

        if (node->childs.find(names.back()) != node->childs.end()) {
            return false;
        }

        node->childs[names.back()] = new TrieNode(value);
        return true;
    }

    int get(string path) {
        vector<string> names = split(path);

        TrieNode* node = m_root;
        for (const string& name : names) {
            if (node->childs.find(name) == node->childs.end()) {
                return -1;
            }
            node = node->childs[name];
        }

        return node->val;
    }

private:
    vector<string> split(const string& path) {
        vector<string> ret;
        for (int i = 0, n = path.size(); i < n;) {
            assert(path[i] == '/');
            ++i;
            string name;
            for (; i < n && path[i] != '/'; ++i) {
                name += path[i];
            }
            ret.push_back(name);
        }

        return ret;
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * bool param_1 = obj->createPath(path,value);
 * int param_2 = obj->get(path);
 */
