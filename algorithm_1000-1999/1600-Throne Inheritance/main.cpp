class ThroneInheritance {
private:
    class Node {
    public:
        Node(const string& name_)
            : name(name_)
            , death(false) {
        }

        string name;
        vector<Node*> children;
        bool death;
    };

public:
    ThroneInheritance(string kingName)
        : m_root(nullptr) {
        m_root = new Node(kingName);
        m_map[kingName] = m_root;
    }

    void birth(string parentName, string childName) {
        Node* node = new Node(childName);
        m_map[childName] = node;
        m_map[parentName]->children.push_back(node);
    }

    void death(string name) {
        m_map[name]->death = true;
    }

    vector<string> getInheritanceOrder() {
        vector<string> names;
        preorder(m_root, names);
        return names;
    }

private:
    void preorder(Node* root, vector<string>& names) {
        if (!root) {
            return;
        }

        if (!root->death) {
            names.push_back(root->name);
        }

        for (Node* child : root->children) {
            preorder(child, names);
        }
    }

    Node* m_root;
    unordered_map<string, Node*> m_map;
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */