class Solution {
public:
    // Time: O(N), Space: O(N)
    string linearAssign(string& s, vector<int>& indices) {
        string ret(s.size(), ' ');
        for (size_t i = 0; i < indices.size(); ++i) {
            ret[indices[i]] = s[i];
        }

        return ret;
    }

    // Time: O(N), Space: O(1)
    string linearSwap(string& s, vector<int>& indices) {
        for (size_t i = 0; i < indices.size(); ++i) {
            while (indices[i] != i) {
                std::swap(s[i], s[indices[i]]);
                std::swap(indices[i], indices[indices[i]]);
            }
        }

        return s;
    }

    string restoreString(string s, vector<int>& indices) {
        //return linearAssign(s, indices);
        return linearSwap(s, indices);
    }
};
