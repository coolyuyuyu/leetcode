class Solution {
public:
    struct Box {
        Box(int num_, int count_)
            : num(num_)
            , count(count_) {
        }

        bool operator<(const Box rhs)const {
            if (num == rhs.num) {
                return count < rhs.count;
            }
            else {
                return num < rhs.num;
            }
        }

        int num;
        int count;
    };

    struct State {
        State(int score_, const vector<Box>& boxes_)
            : score(score_)
            , boxes(boxes_)
            , scoreUpr(score_)
            , scoreLwr(score_) {
            unordered_map<int, int> counts;
            for (const Box& box : boxes) {
                scoreUpr -= (box.count * box.count);
                counts[box.num] += box.count;
            }

            if (counts.size() == boxes.size()) {
                boxes.clear();
                score = scoreLwr = scoreUpr;
            }
            else {
                for (const pair<int, int>& p : counts) {
                    scoreLwr -= (p.second * p.second);
                }
            }
        }

        int score;
        vector<Box> boxes;
        int scoreUpr;
        int scoreLwr;
    };

    // A* Branch and Bound + Memorization, TLE
    int removeBoxesRecv(const vector<Box>& boxes) {
        auto comp = [](const State& a, const State& b) {
            if (b.scoreLwr != a.scoreLwr) {
                return b.scoreLwr < a.scoreLwr;
            }
            else {
                return b.scoreUpr < a.scoreUpr;
            }
        };
        priority_queue<State, vector<State>, decltype(comp)> pq(comp);
        pq.emplace(0, boxes);

        int totalStateCount = 0;
        int cacheHitCount = 0;

        int scoreLowest = 0;
        map<vector<Box>, int> cache;
        while (!pq.empty()) {
            State state = pq.top();
            pq.pop();
            ++totalStateCount;

            auto p = cache.emplace(state.boxes, state.score);
            if (!p.second) {
                cacheHitCount++;
                if (p.first->second <= state.score) {
                    continue;
                }
                else {
                    p.first->second = state.score;
                }
            }

            if (state.scoreLwr == state.scoreUpr) {
                scoreLowest = state.score;
                break;
            }

            const vector<Box>& boxes = state.boxes;
            for (size_t i = 0; i + 1 < boxes.size(); ++i) {
                for (size_t j = i + 2; j < boxes.size(); ++j) {
                    if (boxes[i].num == boxes[j].num) {
                        int scoreTmp = state.score;
                        for (size_t k = i + 1; k < j; ++k) {
                            scoreTmp -= boxes[k].count * boxes[k].count;
                        }

                        vector<Box> boxesTmp(boxes.begin(), boxes.begin() + i);
                        boxesTmp.emplace_back(boxes[i].num, boxes[i].count + boxes[j].count);
                        boxesTmp.insert(boxesTmp.end(), boxes.begin() + j + 1, boxes.end());


                        pq.emplace(scoreTmp, boxesTmp);

                        break;
                    }
                }
            }
        }

        cout << "totalStateCount=" << totalStateCount << endl;
        cout << "cacheHitCount=" << cacheHitCount << endl;

        return -scoreLowest;
    }

    int removeBoxes(vector<int>& nums) {
        vector<Box> boxes;
        for (int num : nums) {
            if (boxes.empty() || boxes.back().num != num) {
                boxes.emplace_back(num, 1);
            }
            else {
                ++boxes.back().count;
            }
        }
        return removeBoxesRecv(boxes);
    }
};