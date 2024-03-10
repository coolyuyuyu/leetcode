class Solution {
public:
    vector<string> byBruteForce(vector<string>& arr) {
        int n = arr.size();

        vector<string> ret(n);
        for (int i = 0; i < n; ++i) {
            const string& str = arr[i];
            int len = str.size();
            for (int j = 0; j < len; ++j) {
                string substr;
                for (int k = j; k < len; ++k) {
                    substr += str[k];

                    bool found = false;
                    for (int x = 0; x < n; ++x) {
                        if (x == i) { continue; }
                        if (arr[x].find(substr) != string::npos) {
                            found = true;
                            break;
                        }
                    }
                    if (found) { continue; }
                    if ((ret[i].empty() ||
                        substr.size() < ret[i].size() ||
                        (substr.size() == ret[i].size() && substr < ret[i]))) {
                        ret[i] = substr;
                    }
                }
            }
        }

        return ret;
    }

    vector<string> byTrie(vector<string>& arr) {
        int n = arr.size();

        class TrieNode {
        public:
            array<TrieNode*, 26> childs;
            int cnt;
            TrieNode() {
                childs.fill(nullptr);
                cnt = 0;
            }
        };
        TrieNode* root = new TrieNode();

        std::function<void(const string&, int)> add = [&](const string& str, int i) {
            TrieNode* node = root;
            for (; i < str.size(); ++i) {
                if (node->childs[str[i] - 'a'] == nullptr) {
                    node->childs[str[i] - 'a'] = new TrieNode();
                }
                node = node->childs[str[i] - 'a'];
                node->cnt += 1;
            }
        };
        for (int i = 0; i < n; ++i) {
            const string& str = arr[i];
            for (int j = 0; j < str.size(); ++j) {
                add(str, j);
            }
        }

        std::function<void(const string&, int)> remove = [&](const string& str, int i) {
            TrieNode* node = root;
            for (; i < str.size(); ++i) {
                node = node->childs[str[i] - 'a'];
                node->cnt -= 1;
            }
        };
        std::function<string(const string&, int)> find = [&](const string& str, int i) {
            TrieNode* node = root;
            string ret;
            for (; i < str.size(); ++i) {
                node = node->childs[str[i] - 'a'];
                ret += str[i];
                if (node->cnt == 0) {
                    return ret;
                }
            }

            return string();
        };
        vector<string> ret(n);
        for (int i = 0; i < n; ++i) {
            const string& str = arr[i];
            for (int j = 0; j < str.size(); ++j) {
                remove(str, j);
            }

            for (int j = 0; j < str.size(); ++j) {
                string substr = find(str, j);
                if (substr.empty()) { continue; }
                if ((ret[i].empty() ||
                    substr.size() < ret[i].size() ||
                    (substr.size() == ret[i].size() && substr < ret[i]))) {
                    ret[i] = substr;
                }
            }

            for (int j = 0; j < str.size(); ++j) {
                add(str, j);
            }
        }

        return ret;
    }

    vector<string> byHash(vector<string>& arr) {
        using ULL = unsigned long long;

        int n = arr.size();

        vector<ULL> hashs[n][21];
        for (int i = 0; i < n; ++i) {
            const string& str = arr[i];
            ULL power = 26;
            for (int len = 1; len <= str.size(); ++len, power *= 26) {
                ULL hash = 0;
                for (int j = 0; j < str.size(); ++j) {
                    hash = 26 * hash + str[j] - 'a';
                    if (j >= len) {
                        hash -= power * (str[j - len] - 'a');
                    }
                    if (j + 1 >= len) {
                        hashs[i][len].push_back(hash);
                    }
                }
            }
        }

        vector<string> ret(n);
        for (int len = 1; len <= 20; ++len) {
            unordered_map<ULL, int> hash2cnt;
            for (int i = 0; i < n; ++i) {
                for (ULL hash : hashs[i][len]) {
                    hash2cnt[hash] += 1;
                }
            }

            for (int i = 0; i < n; ++i) {
                if (!ret[i].empty()) { continue; }

                for (int j = 0; j < hashs[i][len].size(); ++j) {
                    hash2cnt[hashs[i][len][j]] -= 1;
                }

                vector<string> substrs;
                for (int j = 0; j < hashs[i][len].size(); ++j) {
                    if (hash2cnt[hashs[i][len][j]] == 0) {
                        substrs.push_back(arr[i].substr(j, len));
                    }
                }
                if (!substrs.empty()) {
                    ret[i] = *std::min_element(substrs.begin(), substrs.end());
                }

                for (int j = 0; j < hashs[i][len].size(); ++j) {
                    hash2cnt[hashs[i][len][j]] += 1;
                }
            }
        }

        return ret;
    }

    vector<string> shortestSubstrings(vector<string>& arr) {
        //return byBruteForce(arr);
        //return byTrie(arr);
        return byHash(arr);
    }
};
