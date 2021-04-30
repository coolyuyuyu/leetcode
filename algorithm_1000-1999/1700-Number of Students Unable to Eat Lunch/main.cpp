class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        vector<int> counts(2, 0);
        for (auto student : students) {
            ++counts[student];
        }

        int remaining = sandwiches.size();
        for (auto sandwich : sandwiches) {
            if (0 < counts[sandwich]) {
                --counts[sandwich];
                --remaining;
            }
            else {
                break;
            }
        }

        return remaining;
    }
};
