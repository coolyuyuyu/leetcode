class Solution {
public:
    void traverse(int depth, int position, const map<pair<int, int>, int>& nodes, int pathSum, int& totalPathSum) {
        auto itr = nodes.find({depth, position}) ;
        if (itr == nodes.end()) {
            return;
        }
        pathSum += itr->second;

        int depthChild = depth + 1;
        int positionLft = (position - 1) * 2 + 1, positionRht = (position - 1) * 2 + 2;
        traverse(depthChild, positionLft, nodes, pathSum, totalPathSum);
        traverse(depthChild, positionRht, nodes, pathSum, totalPathSum);

        if ((nodes.find({depthChild, positionLft}) == nodes.end()) &&
            (nodes.find({depthChild, positionRht}) == nodes.end())) {
            totalPathSum += pathSum;
        }
    }

    int pathSum(vector<int>& nums) {
        map<pair<int, int>, int> nodes; // pair{depth, position} : value
        for (int num : nums) {
            int depth = num / 100;
            int position = num % 100 / 10;
            int val = num % 10;
            nodes.emplace(pair<size_t, size_t>{depth, position}, val);
        }

        int totalPathSum = 0;
        if (!nums.empty()) {
            traverse(nums.front() / 100, nums.front() % 100 / 10, nodes, 0, totalPathSum);
        }
        return totalPathSum;
    }
};