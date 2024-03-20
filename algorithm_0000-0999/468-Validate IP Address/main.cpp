class Solution {
public:
    string validIPAddress(string queryIP) {
        std::function<bool(const string&)> checkIPv4 = [](const string& ip) {
            if (ip.empty() || ip.back() == '.') {
                return false;
            }

            vector<string> strs;
            for (int i = 0; i < ip.size();) {
                string str;
                int j = i;
                for (; j < ip.size() && ip[j] != '.' ; ++j) {
                    str += ip[j];
                }

                strs.push_back(str);

                i = j + 1;
            }
            if (strs.size() != 4) {
                return false;
            }

            for (const string& str : strs) {
                if (str.size() == 0 || str.size() > 3) {
                    return false;
                }
                if (std::find_if(str.begin(), str.end(), [](char c){ return isdigit(c) == 0; }) != str.end()) {
                    return false;
                }
                if (str.size() >= 2 && str[0] == '0') {
                    return false;
                }
                if (std::stoi(str) > 255) {
                    return false;
                }
            }

            return true;
        };

        std::function<bool(const string&)> checkIPv6 = [](const string& ip) {
            if (ip.empty() || ip.back() == ':') {
                return false;
            }

            vector<string> strs;
            for (int i = 0; i < ip.size();) {
                string str;
                int j = i;
                for (; j < ip.size() && ip[j] != ':' ; ++j) {
                    str += ip[j];
                }

                strs.push_back(str);

                i = j + 1;
            }
            
            if (strs.size() != 8) {
                return false;
            }

            for (const string& str : strs) {
                if (str.size() == 0 || str.size() > 4) {
                    return false;
                }
                if (std::find_if(str.begin(), str.end(), [](char c){
                    return 
                !(
                    (isdigit(c) != 0) ||
                    (isalpha(c) != 0 && toupper(c) <= 'F')
                ); }) != str.end()) {
                    return false;
                }
            }

            return true;
        };

        if (checkIPv4(queryIP)) {
            return "IPv4";
        }
        else if (checkIPv6(queryIP)) {
            return "IPv6";
        }
        else {
            return "Neither";
        }
    }
};
