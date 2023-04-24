class Solution {
public:
    int sumOfMultiples(int n) {
        std::function<int(int)> f = [n](int k) {
            int cnt = n / k + 1;
            return k * (cnt - 1) * cnt / 2;
        };

        return f(3) + f(5) + f(7) - f(15) - f(35) - f(21) + f(105);
    }
};
