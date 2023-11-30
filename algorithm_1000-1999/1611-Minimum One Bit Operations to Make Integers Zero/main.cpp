class Solution {
public:
    int minimumOneBitOperations(int n) {
        // int f1(int n): minimum number of operations to transform n to 0
        // assume n = 1[xxxx]
        // => 1[xxxx]           => 1[1000] => 0[1000] => 0[0000]
        // => f1(1[xxxx]) = +f2(xxxx)      +1      +f1(1000)

        // int f2(int src, int dst): minimum number of operations to transform src to dst, where there is exactly 1 bit of 1 in src.
        // assume src = x[yyy], dst = 1000
        // if x == 1:
        //     => 1[yyy]           => 1000
        //     => f2(1[yyy]) =  +f1(yyy)
        // if x == 0:
        //     => 0[yyy]          => 0[100] => 1[100] => 1000
        //     => f2(0[yyy]) = +f2(yyy)     +1      +f1(100)
        // }

        std::function<int(int)> f1;
        std::function<int(int, int)> f2;

        unordered_map<int, int> cache1;
        f1 = [&](int n) {
            if (n == 0) { return 0; }
            if (n == 1) { return 1; }

            if (cache1.find(n) != cache1.end()) {
                return cache1[n];
            }

            // index of most significant bit of 1
            int ms1 = 31 - __builtin_clz(n);

            int& ret = cache1[n];
            ret = 0;
            ret += f2(n & ~(1 << ms1), 1 << (ms1 - 1));
            ret += 1;
            ret += f1(1 << (ms1 - 1));

            return ret;
        };

        map<pair<int, int>, int> cache2;
        f2 = [&](int src, int dst) {
            assert(__builtin_popcount(dst) == 1);

            if (dst == 1) {
                if (src == 0) { return 1; }
                if (src == 1) { return 0; }
            }

            if (cache2.find({src, dst}) != cache2.end()) {
                return cache2[{src, dst}];
            }

            int& ret = cache2[{src, dst}];
            ret = 0;
            if (src & dst) {
                ret += f1(src & ~dst);
            }
            else {
                ret += f2(src, dst >> 1);
                ret += 1;
                ret += f1(dst >> 1);
            }

            return ret;
        };

        return f1(n);
    }
};
