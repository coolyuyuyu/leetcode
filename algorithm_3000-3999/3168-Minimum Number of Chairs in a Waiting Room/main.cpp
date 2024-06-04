class Solution {
public:
    int minimumChairs(string s) {
        int ret = 0;
        int cnt = 0;
        for (char c : s) {
            switch (c) {
            case 'E':
                ret = std::max(ret, ++cnt);
                break;
            case 'L':
                --cnt;
                break;
            }
        }

        return ret;
    }
};
