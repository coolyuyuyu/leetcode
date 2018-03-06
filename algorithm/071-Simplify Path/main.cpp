class Solution {
public:
    string simplifyPath(string path) {
        vector<string> names;

        string name;
        for (size_t i = 0; i < path.size(); ++i) {
            char c = path[i];
            switch (c) {
            case '/':
                if (name.empty()) {
                }
                else if (name == ".") {
                }
                else if (name == "..") {
                    if (!names.empty()) {
                        names.pop_back();
                    }
                }
                else {
                    names.push_back(name);
                }
                name.clear();
                break;
            default:
                name.push_back(c);
                break;
            }
        }

        if (name.empty()) {
        }
        else if (name == ".") {
        }
        else if (name == "..") {
            if (!names.empty()) {
                names.pop_back();
            }
        }
        else {
            names.push_back(name);
        }

        ostringstream oss;
        if (names.empty()) {
            oss << "/";
        }
        else {
            for (size_t i = 0; i < names.size(); ++i) {
                oss << "/";
                oss << names[i];
            }
        }

        return oss.str();
    }
};