class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        // d[0] = o[0] ^ o[1]          => o[0] ^ d[0] = o[1]
        // d[1] = o[1] ^ o[2]          => o[1] ^ d[1] = o[2]
        // ...
        // d[n-2] = o[n-2] ^ o[n-1]    => o[n-2] ^ d[n-2] = o[n-1]
        // d[n-1] = o[n-1] ^ o[0]      => o[n-1] ^ d[n-1] = o[0]

        // cumulative xor left == cumulative xor right
        // => d[0] ^ d[1] ^ ... ^ d[n-1] = 0

        return std::accumulate(derived.begin(), derived.end(), 0, std::bit_xor<int>()) == 0;
    }
};
