class Solution {
public:
    // Time: O(n!)
    int f1(const string& tiles) {
        unordered_set<string> seqs;

        string seq;
        vector<bool> used(tiles.size(), false);
        std::function<void(int)> dfs = [&](int pos) {
            seqs.insert(seq);
            for (int i = 0; i < tiles.size(); ++i) {
                if (used[i]) { continue; }
                used[i] = true;
                seq.push_back(tiles[i]);
                dfs(pos + 1);
                seq.pop_back();
                used[i] = false;
            }
        };
        dfs(0);

        return seqs.size() - 1;
    }

    // Time: O(2^n)
    int f2(const string& tiles) {
        vector<int> cnts(26, 0);
        for (char c : tiles) {
            ++cnts[c - 'A'];
        }

        std::function<int()> dfs = [&]() {
            int ret = 0;
            for (int i = 0; i < cnts.size(); ++i) {
                if (cnts[i] == 0) { continue; }
                ++ret;
                --cnts[i];
                ret += dfs();
                ++cnts[i];
            }
            return ret;
        };
        dfs();

        return dfs();
    }

    int numTilePossibilities(string tiles) {
        //return f1(tiles);
        return f2(tiles);
    }
};
