class Solution {
public:
    int secondsBetweenTimes(string startTime, string endTime) {
        std::function<int(const string&)> toSecs = [](const string& t){
            int h = (t[0] - '0') * 10 + t[1] - '0';
            int m = (t[3] - '0') * 10 + t[4] - '0';
            int s = (t[6] - '0') * 10 + t[7] - '0';
            return h * 3600 + m * 60 + s;
        };

        return toSecs(endTime) - toSecs(startTime);
    }
};
