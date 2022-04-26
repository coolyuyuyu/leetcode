class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        std::sort(seats.begin(), seats.end());
        std::sort(students.begin(), students.end());

        int move = 0;
        for (size_t i = 0; i < seats.size(); ++i) {
            move += abs(seats[i] - students[i]);
        }
        return move;
    }
};
