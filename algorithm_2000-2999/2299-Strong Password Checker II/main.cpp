class Solution {
public:
    bool strongPasswordCheckerII(string password) {
        if (password.size() < 8) {
            return false;
        }
        if (std::find_if(password.begin(), password.end(), [](char c) { return islower(c); }) == password.end()) {
            return false;
        }
        if (std::find_if(password.begin(), password.end(), [](char c) { return isupper(c); }) == password.end()) {
            return false;
        }
        if (std::find_if(password.begin(), password.end(), [](char c) { return isdigit(c); }) == password.end()) {
            return false;
        }
        for (int i = 0; i + 1 < password.size(); ++i) {
            if (password[i] == password[i + 1]) {
                return false;
            }
        }
        if (password.find_first_of("!@#$%^&*()-+") == string::npos) {
            return false;
        }

        return true;
    }
};
