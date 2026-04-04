class Solution {
public:
    int uniqueEmailGroups(vector<string>& emails) {
        std::function<pair<string, string>(const string&)> parse = [](const string& email) {
            string local;

            int i = 0;
            for (bool skip = false; i < email.size() && email[i] != '@'; ++i) {
                switch (email[i]) {
                    case '.':
                        break;
                    case '+':
                        skip = true;
                        break;
                    default:
                        if (!skip) {
                            local += std::tolower(email[i]);
                        }
                        break;
                }
            }

            string domain = email.substr(i);
            for (char& c : domain) {
                c = std::tolower(c);
            }
            return std::make_pair(local, domain);
        };

        set<pair<string, string>> s;
        for (const auto& email : emails) {
            s.insert(parse(email));
        }

        return s.size();
    }
};
