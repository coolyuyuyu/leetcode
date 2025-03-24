class Solution {
public:
    struct Node {
        array<Node*, 10> nexts;
        int cnt;
        Node() {
            nexts.fill(nullptr);
            cnt = 0;
        }
    };

    bool phonePrefix(vector<string>& numbers) {
        std::sort(numbers.rbegin(), numbers.rend(), [](const string& s1, const string& s2){ return s1.size() < s2.size(); });

        Node* root = new Node();
        for (const string& number : numbers) {
            Node* node = root;
            for (char c : number) {
                if (node->nexts[c - '0'] == nullptr) {
                    node->nexts[c - '0'] = new Node();
                }
                node = node->nexts[c - '0'];
                node->cnt += 1;
            }

            if (node->cnt > 1) {
                return false;
            }
        }

        return true;
    }
};
