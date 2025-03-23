class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string, vector<string>> graph;
        unordered_map<string, int> degrees;
        for (int i = 0; i < recipes.size(); ++i) {
            for (int j = 0; j < ingredients[i].size(); ++j) {
                graph[ingredients[i][j]].push_back(recipes[i]);
                ++degrees[recipes[i]];
            }
        }
        unordered_set<string> targets(recipes.begin(), recipes.end());

        vector<string> ret;
        for (queue<string> q(supplies.begin(), supplies.end()); !q.empty();) {
            string cur = q.front();
            q.pop();

            if (targets.find(cur) != targets.end()) {
                ret.push_back(cur);
            }
            for (const string& nxt : graph[cur]) {
                if (--degrees[nxt] == 0) {
                    q.push(nxt);
                }
            }
        }

        return ret;
    }
};
