class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        set<string> addresses;
        for (const string& address: emails) {
            size_t atIndex = address.find('@');
            string local = address.substr(0, atIndex);
            string domain = address.substr(atIndex + 1);

            size_t plusIndex = local.find('+');
            if (plusIndex != string::npos) {
                local = local.substr(0, plusIndex);
            }

            size_t pos = 0;
            while (pos < local.size()) {
                pos = local.find('.', pos);
                if (pos != string::npos) {
                    local.erase(pos, 1);
                }
            }

            addresses.emplace(local + "@" + domain);
        }

        return addresses.size();
    }
};