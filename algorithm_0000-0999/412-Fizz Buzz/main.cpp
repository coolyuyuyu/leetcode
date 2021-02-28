class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> results;
        results.reserve(n);

        
        for (int i = 1; i <= n; ++i) {
            results.push_back(to_string(i));
        }

        int x = 2;
        while (x < n) {
            results[x] = "Fizz";
            x += 3;
        }

        int y = 4;
        while (y < n) {
            results[y] = "Buzz";
            y += 5;
        }

        int z = 14;
        while (z < n) {
            results[z] = "FizzBuzz";
            z += 15;
        }

        return results;
    }
};