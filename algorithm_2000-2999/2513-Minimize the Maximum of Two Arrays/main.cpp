class Solution {
public:
    int binary_search(int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2) {
        auto isOk = [&divisor1, &divisor2, &uniqueCnt1, &uniqueCnt2](int n) {
            long a = n - n / divisor1;
            if (a < uniqueCnt1) {
                return false;
            }
            long b = n - n / divisor2;
            if (b < uniqueCnt2) {
                return false;
            }

            long  c = n - (n / divisor1 + n / divisor2 - n / std::lcm<long>(divisor1, divisor2));
            if ((a + b - c) < (uniqueCnt1 + uniqueCnt2)) {
                return false;
            }

            return true;
        };
        
        int lft = 1, rht = INT_MAX;
        while (lft < rht) {
            int mid = lft + (rht - lft) / 2;
            if (isOk(mid)) {
                rht = mid;
            }
            else {
                lft = mid + 1;
            }
        }

        return lft;
    }

    int minimizeSet(int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2) {
        return binary_search(divisor1, divisor2, uniqueCnt1, uniqueCnt2);
    }
};

// a: number of numbers which is NOT divisible by divisor1
//     => n - n / divisor1
// b: number of numbers which is NOT divisible by divisor2
//     => n - n / divisor2
// c: number of numbers which is (NOT divisible by divisor1 && Not divisible by divisor2) 
