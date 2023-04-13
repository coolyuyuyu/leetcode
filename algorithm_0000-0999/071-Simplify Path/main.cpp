class Solution {
public:
    string simplifyPath(string path) {
        istringstream iss(path);
        vector<string> tokens;
        for (string token; std::getline(iss, token, '/');) {
            if (token == "") {
            }
            else if (token == ".") {
            }
            else if (token == "..") {
                if (!tokens.empty()) {
                    tokens.pop_back();
                }
            }
            else {
                tokens.push_back(token);
            }
        }

        ostringstream oss;
        if (tokens.empty()) {
            oss << '/';
        }
        else {
            for (const string& token : tokens) {
                oss << '/' << token;
            }
        }

        return oss.str();
    }
};
