class Solution {
public:
    void pathSum_Recursive(map<pair<int, int>, int>& nodes, int& totalSum, int sum = 0, int depth = 1, int pos = 1) {
        auto itr = nodes.find({depth, pos});
        if (itr == nodes.end()) {
            return;
        }

        sum += itr->second;

        int lftPos = (pos - 1) * 2 + 1;
        int rhtPos = (pos - 1) * 2 + 2;
        if (nodes.find({depth + 1, lftPos}) == nodes.end() &&
            nodes.find({depth + 1, rhtPos}) == nodes.end()) {
            totalSum += sum;
        }
        else {
            pathSum_Recursive(nodes, totalSum, sum, depth + 1, lftPos);
            pathSum_Recursive(nodes, totalSum, sum, depth + 1, rhtPos);
        }
    }

    void pathSum_Iterative(map<pair<int, int>, int>& nodes, int& totalSum) {
        queue<tuple<int, int, int>> q; // <depth, pos, sum>
        if (nodes.find({1, 1}) != nodes.end()) {
            q.emplace(1, 1, 0);
        }
        while (!q.empty()) {
            int depth = get<0>(q.front());
            int pos = get<1>(q.front());
            int sum = get<2>(q.front());
            q.pop();

            sum += nodes[{depth, pos}];

            int lftPos = (pos - 1) * 2 + 1;
            int rhtPos = (pos - 1) * 2 + 2;
            if (nodes.find({depth + 1, lftPos}) == nodes.end() &&
                nodes.find({depth + 1, rhtPos}) == nodes.end()) {
                totalSum += sum;
            }
            else {
                if (nodes.find({depth + 1, lftPos}) != nodes.end()) {
                    q.emplace(depth + 1, lftPos, sum);
                }
                if (nodes.find({depth + 1, rhtPos}) != nodes.end()) {
                    q.emplace(depth + 1, rhtPos, sum);
                }
            }
        }
    }

    int pathSum(vector<int>& nums) {
        map<pair<int, int>, int> nodes; // <<depth, pos>, val>;
        for (int num : nums) {
            int depth = num / 100;
            int pos = (num % 100) / 10;
            int val = num % 10;
            nodes[{depth, pos}] = val;
        }

        int totalSum = 0;

        //pathSum_Recursive(nodes, totalSum);
        pathSum_Iterative(nodes, totalSum);

        return totalSum;
    }
};