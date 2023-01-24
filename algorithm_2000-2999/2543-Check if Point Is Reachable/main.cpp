class Solution {
public:
    bool isReachable(int targetX, int targetY) {
        int x = std::gcd(targetX, targetY);
        while (x % 2 == 0) {
            x /= 2;
        }

        return x == 1;
    }
};

/*
thinking reversly
(x, y) => (1, 1)

1. (a, b) => (a, b-a) = (x, y)
=> (a,b) = (x, x+y)

2. (a, b) => (a-b, b) = (x, y)
=> (a,b) = (x+y, y)

3. (a, b) => (2*a, b) = (x, y)
=> (a,b) = (x/2, y) if x % 2 == 0

4. (a, b) => (a, 2*b) = (x, y)
=> (a,b) = (x, y/2) if y % 2 == 0

Consider 1 and 2
mx + ny = 1 <=> gcd(x, y) = 1

Consider 3 and 4
gcd(x, y) = 2^k, k = 0, 1, ...
*/
