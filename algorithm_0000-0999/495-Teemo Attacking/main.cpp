class Solution {
public:
    // Time: O(N), Jump 1 by 1
    int findPoisonedDuration_JumpOne(vector<int>& timeSeries, int duration) {
        int totalDuration = 0;
        for (size_t i = 0; i < timeSeries.size(); ++i) {
            int diff = (i == 0 ? duration : (timeSeries[i] - timeSeries[i - 1]));
            totalDuration += std::min(diff, duration);
        }
        
        return totalDuration;
    }
    
    // Jump across distance as duration
    int findPoisonedDuration_JumpDuration(vector<int>& timeSeries, int duration) {
        int totalDuration = 0;
        for (size_t i = 0; i < timeSeries.size();) {
            totalDuration += duration;
            
            size_t j = std::lower_bound(timeSeries.begin() + i + 1, timeSeries.end(), timeSeries[i] + duration) - timeSeries.begin();            
            if (i + 1 == j) {
                i = j;
            }
            else {
                totalDuration -= (timeSeries[i] + duration - timeSeries[j - 1]);
                i = j - 1;
            }            
        }
        
        return totalDuration;
    }
    
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        //return findPoisonedDuration_JumpOne(timeSeries, duration);
        return findPoisonedDuration_JumpDuration(timeSeries, duration);
    }
};
