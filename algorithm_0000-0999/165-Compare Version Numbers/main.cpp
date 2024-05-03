class Solution {
public:
    int compareVersion(string version1, string version2) {
        size_t start1 = 0;
        size_t start2 = 0;
        size_t found1 = string::npos;
        size_t found2 = string::npos;
        do {
            found1 = version1.find_first_of(".", start1);
            int v1 = stoi(version1.substr(start1, found1 - start1));

            found2 = version2.find_first_of(".", start2);
            int v2 = stoi(version2.substr(start2, found2 - start2));

            if (v1 > v2) {
                return 1;
            }
            else if (v1 < v2){
                return -1;
            }

            start1 = found1 + 1;
            start2 = found2 + 1;
        } while (found1 != string::npos && found2 != string::npos);

        if (found1 == string::npos && found2 == string::npos) {
            return 0;
        }
        else if (found1 != string::npos) {
            return (version1.find_first_not_of("0.", start1) == string::npos) ? 0 : 1;
        }
        else {
            assert(found2 != string::npos);
            return (version2.find_first_not_of("0.", start2) == string::npos) ? 0 : -1;
        }
    }
};
