class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> operations;

        int i = 1;
        for (int t : target) {
            for (; i < t; ++i) {
                operations.push_back("Push");
                operations.push_back("Pop");
            }
            operations.push_back("Push");
            ++i;
        }

        return operations;
    }
};