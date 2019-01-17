/*
// Definition for a Node.
class Node {
public:
    int val = NULL;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(Node* root) {
        if (!root) {
            return "";
        }

        ostringstream oss;
        if (root->children.empty()) {
            oss << root->val;
        }
        else {
            oss << "[" << root->val;
            for (Node* child : root->children) {
                oss << " " << serialize(child);
            }
            oss << "]";
        }

        return oss.str();
    }

    // Decodes your encoded data to tree.
    Node* deserialize(string data) {
        if (data.empty()) {
            return nullptr;
        }
        else if (data.front() != '[') {
            Node* root = new Node(atoi(data.c_str()));
            return root;
        }

        size_t index = data.find(' ', 1);
        Node* root = new Node(atoi(data.substr(1, index - 1).c_str()));
        ++index;

        while (index < data.size()) {
            size_t bgn = index;
            if (data[index] == '[') {
                size_t openCount = 0;
                do {
                    switch (data[index++]) {
                        case '[':
                            ++openCount;
                            break;
                        case ']':
                            --openCount;
                            break;
                        default:
                            break;
                    }
                } while (0 < openCount);
            }
            else {
                index = data.find_first_of(" ]", bgn);
            }

            root->children.emplace_back(deserialize(data.substr(bgn, index - bgn)));

            if (index != string::npos) {
                index = index + 1;
            }
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));