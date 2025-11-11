class Solution {
public:

    int recursion(int n) {
        // int f1(int n): minimum number of operations to transform n to 0
        // assume n = 1[xxxx]
        // => 1[xxxx] (=> ... =>) 1[1000]) => 0[1000] (=> ... =>) 0[0000])
        // =>         (+f2(xxxx,1000))     +1         (+f1(1000))

        // int f2(int src, dst): minimum number of operations to transform src to dst where the bit length of src <= dst and dst has only one set bit
        // assume src = x[yyyy], dst = 10000
        // if x == 1:
        //     => 1[yyyy] (=> ...  =>) 10000
        //     =>         (+f1(yyyy) )
        // if x == 0:
        //     => 0[yyyy] (=> ... =>) 0[1000] => 1[1000] (=> ... =>) 10000
        //     =>         (+f2(yyyy, 1000))   +1         (+f1(1000))
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

            int msb = 31 - __builtin_clz(n);

            int& ret = cache1[n] = 0;
            ret += f2(n & ~(1 << msb), (1 << (msb - 1)));
            ret += 1;
            ret += f1(1 << (msb - 1));

            return ret;
        };

        map<pair<int, int>, int> cache2;
        f2 = [&](int src, int dst) {
            int clzSrc = (src == 0 ? 32 : __builtin_clz(src)), clzDst = (dst == 0 ? 32 : __builtin_clz(dst));
            assert(clzSrc >= clzDst);
            assert(__builtin_popcount(dst) == 1);

            if (dst == 1) {
                if (src == 0) { return 1; }
                if (src == 1) { return 0; }
            }

            if (cache2.find({src, dst}) != cache2.end()) {
                return cache2[{src, dst}];
            }

            int& ret = cache2[{src, dst}] = 0;
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

    int math(int n) {
        if (n == 0) { return 0; }

        // index of most significant bit of 1
        int msb = 31 - __builtin_clz(n);

        // graycode
        // graycode[i]: i ^ (i >> 1)
        // given gray[i] = n, find i

        int ret = 1 << msb;
        for (int i = msb; 0 < i--;) {
            ret |= ((ret >> 1) & (1 << i)) ^ (n & (1 << i));
        }

        return ret;
    }

    int minimumOneBitOperations(int n) {
        return recursion(n);
        //return math(n);
    }
};
