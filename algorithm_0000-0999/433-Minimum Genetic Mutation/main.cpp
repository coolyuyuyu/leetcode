class Solution {
public:
    vector<char> choices = {'A', 'C', 'G', 'T'};
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> candidates;
        for (const string& gene : bank) {
            candidates.insert(gene);
        }

        queue<string> q({startGene});
        for (int depth = 1; !q.empty(); ++depth) {
            for (int n = q.size(); 0 < n--;) {
                string gene = q.front();
                q.pop();
                for (int i = 0; i < 8; ++i) {
                    for (char c : choices) {
                        if (c == gene[i]) { continue; }

                        string mutated = gene;
                        mutated[i] = c;
                        if (candidates.find(mutated) == candidates.end()) { continue; }

                        if (mutated == endGene) {
                            return depth;
                        }

                        candidates.erase(mutated);
                        q.push(mutated);
                    }
                }
            }
        }

        return -1;
    }
};
