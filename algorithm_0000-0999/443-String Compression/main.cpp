class Solution {
public:
    int compress(vector<char>& chars) {
        size_t index = 0;
        for (size_t prev = 0, i = 0; i < chars.size(); ++i) {
            if (i + 1 == chars.size() || chars[i] != chars[i + 1]) {
                chars[index++] = chars[i];

                int count = i - prev + 1;
                if (1 < count) {
                    for (char c : to_string(count)) {
                        chars[index++] = c;
                    }
                }

                prev = i + 1;
            }
        }

        return index;
    }
};