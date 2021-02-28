class Solution {
public:

    static bool compLog(const string& log1, const string& log2) {

        size_t index1 = log1.find(' ');
        size_t index2 = log2.find(' ');

        string id1 = log1.substr(index1);
        string id2 = log2.substr(index2);

        string left1 = log1.substr(index1 + 1);
        string left2 = log2.substr(index2 + 1);
        if (left1 != left2) {
            return left1 < left2;
        }
        else {
            return id1 < id2;
        }
    }

    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> digitLogs, letterLogs;
        for (const string& log : logs) {
            if (log[log.find(' ') + 1] < 'a') {
                digitLogs.push_back(log);
            }
            else {
                letterLogs.push_back(log);
            }
        }

        sort(letterLogs.begin(), letterLogs.end(), compLog);

        vector<string> ans;
        ans.reserve(logs.size());
        for (const string& log : letterLogs) {
            ans.push_back(log);
        }
        for (const string& log : digitLogs) {
            ans.push_back(log);
        }

        return ans;
    }
};