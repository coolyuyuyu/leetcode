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
        return deserialize(data, 0, data.size());
    }

private:
    Node* deserialize(const string& data, size_t bgn, size_t end) {
        if (end <= bgn) {
            return nullptr;
        }

        if (data[bgn] == '[') {
            ++bgn;
            --end;
        }

        int num = 0;
        while (bgn < end && data[bgn] != ' ') {
            num *= 10;
            num += data[bgn++] - '0';
        }
        Node* root = new Node(num);

        size_t index = ++bgn;
        size_t openCount = 0;
        while (bgn < end) {
            switch (data[bgn]) {
                case '[':
                    ++openCount;
                    if (openCount == 1) {
                        index = bgn;
                    }
                    break;
                case ']':
                    --openCount;
                    break;
                case ' ':
                    if (openCount == 0) {
                        root->children.emplace_back(deserialize(data, index, bgn));
                        index = bgn + 1;
                    }
                    break;
                default:
                    break;
            }
            ++bgn;
        }
        if (index < end) {
            root->children.emplace_back(deserialize(data, index, end));
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));