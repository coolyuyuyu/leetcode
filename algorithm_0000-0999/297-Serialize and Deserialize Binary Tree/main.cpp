/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Strategy {
public:
    virtual string serialize(TreeNode* root) = 0;
    virtual TreeNode* deserialize(const string& data) = 0;
};

class LevelOrderStrategy : public Strategy {
public:
    string serialize(TreeNode* root) {
        ostringstream oss;

        queue<TreeNode*> q({root});
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (node) {
                oss << node->val;
                q.push(node->left);
                q.push(node->right);
            }
            else {
                oss << "#";
            }
            oss << ",";

        }

        return oss.str();
    }

    TreeNode* deserialize(const string& data) {
        TreeNode* pRoot = nullptr;
        queue<TreeNode**> q({&pRoot});
        string token;
        for (istringstream iss(data); std::getline(iss, token, ',');) {
            TreeNode** ppNode = q.front();
            q.pop();

            if (token != "#") {
                *ppNode = new TreeNode(std::stoi(token));
                q.push(&((*ppNode)->left));
                q.push(&((*ppNode)->right));
            }
        }

        return pRoot;
    }
};

class PreOrderStrategy : public Strategy {
public:
    string serialize(TreeNode* root) {
        if (!root) {
            return "#";
        }

        return std::to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right);
    }

    TreeNode* deserialize(const string& data) {
        istringstream iss(data);
        return deserialize(iss);
    }

private:
    TreeNode* deserialize(istringstream& iss) {
        string token;
        if (!std::getline(iss, token, ',') || token == "#") {
            return nullptr;
        }

        return new TreeNode(std::stoi(token), deserialize(iss), deserialize(iss));
    }
};

class Codec {
public:
    Codec() {
        //m_pStrategy = new LevelOrderStrategy();
        m_pStrategy = new PreOrderStrategy();
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root)
    {
        return m_pStrategy->serialize(root);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data)
    {
        return m_pStrategy->deserialize(data);
    }

private:
    Strategy* m_pStrategy;
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
