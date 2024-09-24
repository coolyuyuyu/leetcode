class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        struct Node {
            std::array<Node*, 10> childs;
            Node() {
                childs.fill(nullptr);
            }
        };

        Node* root = new Node();
        for (const int num : arr1) {
            string str = std::to_string(num);
            Node* node = root;
            for (char c : str) {
                if (node->childs[c - '0'] == nullptr) {
                    node->childs[c - '0'] = new Node();
                }
                node = node->childs[c - '0'];
            }
        }

        int ret = 0;
        for (const int num : arr2) {
            string str = std::to_string(num);
            Node* node = root;
            for (int i = 0; i < str.size(); ++i) {
                char c = str[i];
                if (node->childs[c - '0'] == nullptr) {
                    break;
                }
                node = node->childs[c - '0'];

                ret = std::max(ret, i + 1);
            }
        }

        return ret;
    }
};
