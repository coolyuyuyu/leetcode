class Solution {
public:
    vector<int> scoreValidator(vector<string>& events) {
        int score = 0, counter = 0;
        for (const string& event : events) {
            if (event.size() == 1) {
                if (std::isdigit(event[0])) {
                    score += (event[0] - '0');
                }
                else {
                    ++counter;
                }
            }
            else {
                ++score;
            }

            if (counter >= 10) {
                break;
            }
        }

        return {score, counter};
    }
};
