class Solution {
public:
    string generateTag(string caption) {
        string ret = "#";

        for (int i = 0, n = caption.size(); i < n;) {
            while (i < n && std::isspace(caption[i])) {
                ++i;
            }

            if (i < n) {
                ret += std::toupper(caption[i++]);
            }
            while (i < n && !std::isspace(caption[i])) {
                ret += std::tolower(caption[i++]);
            }
        }

        if (ret.size() >= 2) {
            ret[1] = std::tolower(ret[1]);
        }
        if (ret.size() > 100) {
            ret = ret.substr(0, 100);
        }

        return ret;
    }
};
