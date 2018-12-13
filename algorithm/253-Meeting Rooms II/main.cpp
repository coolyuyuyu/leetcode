/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<State> states;
        for (const Interval& interval : intervals) {
            states.emplace_back(interval.start, true);
            states.emplace_back(interval.end, false);
        }

        auto comp = [](const State& lft, const State& rht) {
            if (lft.time == rht.time) {
                return lft.flag < rht.flag;
            }
            else {
                return lft.time < rht.time;
            }
        };
        sort(states.begin(), states.end(), comp);

        int height = 0, maxHeight = 0;
        for (const State& state : states) {
            if (state.flag) {
                ++height;
                maxHeight = max(maxHeight, height);
            }
            else {
                --height;
            }
        }

        return maxHeight;
    }

private:
    class State{
    public:
        State(int t, bool f)
            : time(t)
            , flag(f) {
        }

        int time;
        bool flag;
    };
};