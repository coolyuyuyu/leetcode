class Solution {
public:
    Solution() {
        for (int n = 1; 0 <= n; n <<= 1) {
            m_results.insert(count(n));
        }
    }

    bool reorderedPowerOf2(int N) {
        return m_results.find(count(N)) != m_results.end();
    };

private:
    array<int, 10> count(int n) {
        array<int, 10> result;
        result.fill(0);

        while (n) {
            ++result[n % 10];
            n /= 10;
        }

        return result;
    }

    set<array<int, 10>> m_results;
};