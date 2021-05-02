class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        if (destination < start) {
            swap(start, destination);
        }

        int distance1 = accumulate(distance.begin() + start, distance.begin() + destination, 0);
        int distance2 = accumulate(distance.begin(), distance.begin() + start, 0) + accumulate(distance.begin() + destination, distance.end(), 0);
        return min(distance1, distance2);
    }
};
