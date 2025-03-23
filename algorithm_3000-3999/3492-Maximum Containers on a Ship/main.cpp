class Solution {
public:
    int maxContainers(int n, int w, int maxWeight) {
        return std::min(maxWeight / w, n * n);
    }
};
