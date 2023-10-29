class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int ret = 0;
        while (pow(minutesToTest / minutesToDie + 1, ret) < buckets) {
            ++ret;
        }

        return ret;
    }
};

// 1 pig within 1 round can test upto 1 + 1 buckets
// 1 pig within 2 round can test upto 2 + 1 buckets
// 1 pig within (minutesToTest / minutesToDie) round can test upto (minutesToTest / minutesToDie) + 1 buckets
// n pig within (minutesToTest / minutesToDie) round can test upto ((minutesToTest / minutesToDie) + 1) ^ n buckets
