class Solution {
public:
    string orderlyQueue(string s, int k) {
        if (k == 1) {
            string ret = s;
            for (int i = 1; i < s.size(); ++i) {
                std::rotate(s.begin(),s.begin()+1,s.end());
                ret = std::min(ret, s);
            }
            return ret;
        }
        else {
            std::sort(s.begin(), s.end());
            return s;
        }
    }
};
