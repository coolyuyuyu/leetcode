class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<int> quantities = {1, 2, 4 , 8, 16 ,32, 60, 120, 240, 480};

        struct Node {
            Node(int s, int c, int i)
                : sum(s)
                , count(c)
                , index(i)
            {}
            int sum;
            int count;
            int index;
        };

        unordered_set<int> results;
        stack<Node> stk;
        stk.push(Node(0, 0, 0));
        while (!stk.empty()) {
            Node node = stk.top();
            stk.pop();
            
            if (node.index == 6 && 60 <= node.sum) {
                continue;
            }

            if (node.count == num) {
                results.insert(node.sum);
            }
            else {
                if (num <= (quantities.size() - node.index + node.count)) {
                    stk.push(Node(node.sum + quantities[node.index], node.count + 1, node.index + 1));
                    stk.push(Node(node.sum, node.count, node.index + 1));
                }
            }
        }

        vector<string> times;
        times.reserve(results.size());
        for (unordered_set<int>::const_iterator iter = results.begin(); iter != results.end(); ++iter) {
            if (*iter < 720) {
                ostringstream oss;
                oss << (*iter / 60) << ":" << setfill('0') << setw(2) << (*iter % 60);
                times.push_back(oss.str());
            }
        }

        return times;
    }
};