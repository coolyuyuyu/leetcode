class Solution {
public:
    string simplifyPath(string path) {
        vector<string> tokens;
        istringstream iss(path);
        for (string token; getline(iss, token, '/');) {
            if (token == "..") {
                if (!tokens.empty()) {
                    tokens.pop_back();
                }
            }
            else if (token == ".") {
            }
            else if (token == "") {
            }
            else {
                tokens.push_back(token);
            }
        }

        ostringstream oss;
        if (tokens.empty()) {
            oss << "/";
        }
        else {
            for (const string& token : tokens) {
                oss << "/" << token;
            }
        }

        return oss.str();
    }
};