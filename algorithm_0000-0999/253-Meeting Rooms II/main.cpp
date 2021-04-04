class Solution {
public:
    size_t minMeetingRooms_Sort(vector<vector<int>>& intervals) {
        vector<pair<bool, int>> states; // <bool: open/close, int: time>
        for (const vector<int>& interval : intervals) {
            states.emplace_back(true, interval[0]);
            states.emplace_back(false, interval[1]);
        }

        auto comp = [](const pair<bool, int>& state1, const pair<bool, int>& state2) {
            if (state1.second == state2.second) {
                return (state1.first == false);
            }
            else {
                return (state1.second < state2.second);
            }
        };
        sort(states.begin(), states.end(), comp);

        size_t numRooms = 0, maxNumRooms = 0;
        for (const pair<bool, int>& state : states) {
            if (state.first) {
                ++numRooms;
                maxNumRooms = max(maxNumRooms, numRooms);
            }
            else {
                --numRooms;
            }
        }

        return maxNumRooms;
    }

    size_t minMeetingRooms_Heap(vector<vector<int>>& intervals) {
        auto comp = [](const vector<int>& interval1, const vector<int>& interval2) {
            return (interval1[0] < interval2[0]);
        };
        sort (intervals.begin(), intervals.end(), comp);

        size_t maxNumRooms = 0;
        priority_queue<int, vector<int>, greater<int>> pq; // min_heap
        for (const vector<int>& interval : intervals) {
            while (!pq.empty() && pq.top() <= interval[0]) {
                pq.pop();
            }
            pq.push(interval[1]);
            maxNumRooms = max(maxNumRooms, pq.size());
        }

        return maxNumRooms;
    }

    size_t minMeetingRooms(vector<vector<int>>& intervals) {
        return minMeetingRooms_Sort(intervals);
        //return minMeetingRooms_Heap(intervals);
    }
};