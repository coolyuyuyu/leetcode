class Solution {
public:
    int compress(vector<char>& chars) {
        int k = 0;
        for (int i = 0, j = 0; i <= chars.size(); ++i) {
            if (i == chars.size() || chars[i] != chars[j]) {
                chars[k++] = chars[j];

                int count = i - j;
                if (1 < count) {
                    for (char c : std::to_string(count)) {
                        chars[k++] = c;
                    }
                }
                j = i;
            }
        }

        return k;
    }
};
