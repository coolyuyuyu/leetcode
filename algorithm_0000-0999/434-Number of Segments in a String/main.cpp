class Solution {
public:
    int countSegments(string s) {
        int count = 0;
        size_t pos = 0;
        while (pos != string::npos) {
            pos = s.find_first_not_of(" ", pos);
            if (pos != string::npos) {
                ++count;
                pos = s.find_first_of(" ", pos + 1);
            }
        
        }

        return count;
    }
};