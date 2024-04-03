class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        std::sort(courses.begin(), courses.end(), [](const auto& course1, const auto& course2){ return course1[1] < course2[1]; });

        int day = 0;
        priority_queue<int> maxPQ;
        for (const auto& course : courses) {
            int duration = course[0], lastDay = course[1];

            day += duration;
            maxPQ.push(duration);
            if (day > lastDay) {
                day -= maxPQ.top();
                maxPQ.pop();
            }
        }

        return maxPQ.size();
    }
};
