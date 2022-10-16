class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> s;
        for (const string& email : emails) {
            string local;
            for (size_t pos = 0; pos < email.size(); ++pos) {
                switch(email[pos]) {
                    case '.':
                        break;
                    case '+':
                        pos = email.find('@', pos + 1);
                    case '@':
                        s.emplace(local + "@" + email.substr(pos + 1));
                        pos = email.size();
                        break;
                    default:
                        local += email[pos];
                        break;
                }
            }
        }

        return s.size();
    }
};