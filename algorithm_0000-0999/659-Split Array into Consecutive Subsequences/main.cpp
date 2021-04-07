class Solution {
public:
    bool isPossible_Heap(vector<int>& nums) {
        class Interval {
        public:
            Interval(int start_, int len_)
                : start(start_)
                , len(len_) {
            }

            int end() const {
                return (start + len - 1);
            }

            int start;
            int len;
        };
        auto comp = [](const Interval& i1, const Interval& i2) {
            if (i1.end() == i2.end()) {
                return i1.len > i2.len;
            }
            else {
                return i1.end() > i2.end();
            }
        };
        priority_queue<Interval, vector<Interval>, decltype(comp)> pq(comp);

        for (int num : nums) {
            while (!pq.empty() && (pq.top().end() + 1 < num)) {
                if (pq.top().len < 3) {
                    return false;
                }
                pq.pop();
            }

            if (pq.empty() || pq.top().end() == num) {
                pq.emplace(num, 1);
            }
            else {
                assert((pq.top().end() + 1) == num);
                Interval i = pq.top();
                pq.pop();

                pq.emplace(i.start, i.len + 1);
            }
        }

        for (; !pq.empty(); pq.pop()) {
            if (pq.top().len < 3) {
                return false;
            }
        }

        return true;
    }

    bool isPossible(vector<int>& nums) {
        return isPossible_Heap(nums);
    }
};