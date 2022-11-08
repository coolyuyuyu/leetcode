class Solution {
public:
    vector<vector<int>> recursive1(const vector<int>& candidates, size_t index, int target) {
        assert(0 < target);

        vector<vector<int>> combs;
        for (size_t i = index; i < candidates.size() ; ++i) {
            if (candidates[i] == target) {
                combs.push_back({candidates[i]});
            }
            else if (candidates[i] < target) {
                vector<vector<int>> subCombs = recursive1(candidates, i, target - candidates[i]);
                for (auto itr = combs.insert(combs.end(), subCombs.begin(), subCombs.end()); itr != combs.end(); ++itr) {
                    itr->push_back(candidates[i]);
                }
            }
        }

        return combs;
    }

    void recursive2(const vector<int>& candidates, size_t index, int target, vector<int>& comb, vector<vector<int>>& combs) {
        assert(0 < target);

        for (size_t i = index; i < candidates.size() ; ++i) {
            if (candidates[i] == target) {
                combs.push_back(comb);
                combs.back().push_back(candidates[i]);
            }
            else if (candidates[i] < target) {
                comb.push_back(candidates[i]);
                recursive2(candidates, i, target - candidates[i], comb, combs);
                comb.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        //return recursive1(candidates, 0, target);

        vector<int> comb;
        vector<vector<int>> combs;
        recursive2(candidates, 0, target, comb, combs);
        return combs;
    }
};
