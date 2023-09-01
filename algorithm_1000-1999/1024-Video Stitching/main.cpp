class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        std::sort(clips.begin(), clips.end(), [](const auto& clip1, const auto& clip2) { return clip1[0] < clip2[0]; });

        int n = clips.size();
        int far = 0;
        int ret = 0;
        for (int i = 0; i < n;) {
            int nextFar = far;
            while (i < n && clips[i][0] <= far) {
                nextFar = std::max(nextFar, clips[i][1]);
                ++i;
            }
            if (far == nextFar) {
                return -1;
            }

            ++ret;

            if (time <= nextFar) {
                return ret;
            }

            far = nextFar;
        }

        return -1;
    }
};
