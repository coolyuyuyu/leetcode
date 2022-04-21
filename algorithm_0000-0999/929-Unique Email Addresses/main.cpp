class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> s;
        for (const string& email : emails) {
            size_t pos = 0;

            string local;
            for (bool end = false; !end;) {
                switch (email[pos]) {
                    case '+':
                        pos = email.find_first_of('@', pos);
                    case '@':
                        end = true;
                        break;
                    case '.':
                        break;
                    default:
                        local.push_back(email[pos]);
                }
                ++pos;

            }
            string domain = email.substr(pos);

            s.insert(local + "@" + domain);
        }

        return s.size();
    }
};
