class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long totalChalk = std::accumulate(chalk.begin(), chalk.end(), 0L);
        k -= (k / totalChalk ) * totalChalk;
        
        int ret = 0;
        for (; true; k -= chalk[ret++]) {
            if (k < chalk[ret]) {
                break;
            }
        }

        return ret;
    }
};
