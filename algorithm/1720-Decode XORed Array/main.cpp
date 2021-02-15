class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int> arr(encoded.size() + 1);
        arr[0] = first;
        for (size_t i = 0; i < encoded.size(); ++i) {
            arr[i + 1] = arr[i] ^ encoded[i];
        }

        return arr;
    }
};