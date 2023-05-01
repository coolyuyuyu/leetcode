class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        std::sort(
            courses.begin(), courses.end(),
            [](const auto& course1, const auto& course2) {
                return course1[1] < course2[1];
            });

        int days = 0;
        priority_queue<int> pq;
        for (const auto& course : courses) {
            days += course[0];
            pq.push(course[0]);
            if (course[1] < days) {
                days -= pq.top();
                pq.pop();
            }
        }

        return pq.size();
    }
};
