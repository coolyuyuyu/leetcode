class Solution {
public:
    vector<string> constructNeighbors(const string& word, const string& target) {
        vector<string> neighbors;

        size_t i = 0;
        for (; i < word.size(); ++i) {
            if (word[i] != target[i]) {
                break;
            }
        }

        for (size_t j = i + 1; j < word.size(); ++j) {
            if (word[i] == word[j]) {
                continue;
            }

            if (word[i] == target[j]) {
                neighbors.emplace_back(word);
                swap(neighbors.back()[i], neighbors.back()[j]);
            }
        }

        return neighbors;
    }

    size_t kSimilarity(const string& A, const string& B) {
        unordered_map<string, int> similiarities = {{A, 0}};
        queue<string> q;
        q.emplace(A);
        while (!q.empty()) {
            string word = q.front();
            q.pop();

            if (word == B) {
                return similiarities[word];
            }

            int k = similiarities[word];
            for (const string& neighbor : constructNeighbors(word, B)) {
                if (similiarities.find(neighbor) == similiarities.end()) {
                    similiarities[neighbor] = k + 1;
                    q.emplace(neighbor);
                }
            }
        }

        return numeric_limits<size_t>::max();
    }
};