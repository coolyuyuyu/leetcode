class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        set<int> s;
        for (int num : arr) {
            if (num == 0) {
                if (s.find(0) != s.end()) {
                    return true;
                }
            }
            else {
                if (s.find(num * 2) != s.end()) {
                    return true;
                }
                if (num % 2 == 0 && s.find(num / 2) != s.end()) {
                    return true;
                }
            }

            s.insert(num);
        }

        return false;
    }
};
