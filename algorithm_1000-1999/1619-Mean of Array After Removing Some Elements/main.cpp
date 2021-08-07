class Solution {
public:
    double trimMean(vector<int>& arr) {
        auto first = arr.begin() + arr.size() / 20, last = arr.end() - arr.size() / 20;
        nth_element(arr.begin(), first, arr.end());
        nth_element(first, last, arr.end());
        return (accumulate(first, last, double(0.0)) / distance(first, last));
    }
};
