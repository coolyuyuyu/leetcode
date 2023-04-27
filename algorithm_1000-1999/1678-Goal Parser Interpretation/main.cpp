class Solution {
public:
    string interpret(string command) {
        string ret;
        for (int i = 0; i < command.size(); ++i) {
            if (command[i] == 'G') {
                ret += 'G';
            }
            else {
                assert(command[i] == '(');
                if (command[i + 1] == 'a') {
                    ret += "al";
                    i += 3;
                }
                else {
                    ret += "o";
                    i += 1;
                }
            }
        }

        return ret;
    }
};
