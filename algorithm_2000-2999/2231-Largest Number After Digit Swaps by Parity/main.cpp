class Solution {
public:
    int largestInteger(int num) {
        string str = std::to_string(num);
        vector<char> oChars, eChars;
        for (char c : str) {
            if ((c - '0') & 1) {
                oChars.push_back(c);
            }
            else {
                eChars.push_back(c);
            }
        }

        std::sort(oChars.rbegin(), oChars.rend());
        std::sort(eChars.rbegin(), eChars.rend());
        
        int i = 0, j = 0;
        for (char& c : str) {
            if ((c - '0') & 1) {
                c = oChars[i++];
            }
            else {
                c = eChars[j++];
            }
        }

        return stoi(str);
    }
};
