class Solution {
public:
    // stable sort
    vector<string> reorderLogFiles_StableSort(vector<string>& logs) {
        auto comp = [](const string& str1, const string& str2) {
            size_t index1 = str1.find(' ');
            if (isalpha(str1[index1 + 1])) {
                size_t index2 = str2.find(' ');
                if (isalpha(str2[index2 + 1])) {
                    int v = str1.compare(index1 + 1, string::npos, str2, index2 + 1, string::npos);
                    if (v == 0) {
                        return str1.compare(0, index1, str2, 0, index2) < 0;
                    }
                    else {
                        return v < 0;
                    }
                }
                else {
                    return true;
                }
            }
            else {
                return false;
            }
        };
        std::stable_sort(logs.begin(), logs.end(), comp);

        return logs;
    }

    // move all digit to right half, unstable sort the left half
    vector<string> reorderLogFiles_MoveAndSort(vector<string>& logs) {
        size_t boundary = logs.size();
        for (size_t i = logs.size(); 0 < i--;) {
            if (isdigit(logs[i][logs[i].find(' ') + 1])) {
                std::swap(logs[i], logs[--boundary]);
            }
        }

        auto comp = [](const string& str1, const string& str2) {
            size_t index1 = str1.find(' ');
            size_t index2 = str2.find(' ');
            int v = str1.compare(index1 + 1, string::npos, str2, index2 + 1, string::npos);
            if (v == 0) {
                return str1.compare(0, index1, str2, 0, index2) < 0;
            }
            else {
                return v < 0;
            }
        };
        std::sort(logs.begin(), logs.begin() + boundary, comp);

        return logs;
    }

    vector<string> reorderLogFiles(vector<string>& logs) {
        //return reorderLogFiles_StableSort(logs);
        return reorderLogFiles_MoveAndSort(logs);
    }
};
