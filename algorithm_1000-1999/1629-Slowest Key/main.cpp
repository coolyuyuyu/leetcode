class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        char key = keysPressed.front();
        int time = releaseTimes.front();
        for (size_t i = 1; i < releaseTimes.size(); ++i) {
            int t = releaseTimes[i] - releaseTimes[i - 1];
            if (time < t) {
                key = keysPressed[i];
                time = t;
            }
            else if (time == t) {
                key = max(key, keysPressed[i]);
            }
        }

        return key;
     }
};
