class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        vector<int> cnts(2, 0);
        for (int student : students) {
            ++cnts[student];
        }

        int ret = students.size();
        for (int sandwich : sandwiches) {
            if (cnts[sandwich] > 0) {
                --cnts[sandwich];
                --ret;
            }
            else {
                break;
            }
        }

        return ret;
    }
};
