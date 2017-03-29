class Solution {
public:
    int climbStairs(int n) {
        vector<int> steps;
        steps.reserve(n + 1);
        steps.push_back(1);
        steps.push_back(1);
        while (steps.size() <= n) {
            steps.push_back(steps[steps.size() - 1] + steps[steps.size() - 2]);
        }
        return steps.back();
    }
};