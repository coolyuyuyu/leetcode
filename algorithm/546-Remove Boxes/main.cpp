class Solution {
public:
    struct Box {
        Box(int num_, int count_)
            : num(num_)
            , count(count_){

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
                scoreLwr = scoreUpr;
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

    // Pruned and Search, TLE
    int removeBoxesRecv(const vector<Box>& boxes) {
        auto comp = [](const State& a, const State& b) {
            if (a.scoreLwr != b.scoreLwr) {
                return b.scoreLwr < a.scoreLwr;
            }
            else {
                return b.scoreUpr < a.scoreUpr;
            }
        };
        priority_queue<State, vector<State>, decltype(comp)> pq(comp);
        pq.emplace(0, boxes);

        int totalStateCount = 0;
        int prunedStateCount = 0;

        int scoreUprLowest = 0;
        while (!pq.empty()) {
            State s = pq.top();
            pq.pop();

            if (scoreUprLowest <= s.scoreLwr) {
                continue;
            }

            if (s.scoreUpr < scoreUprLowest) {
                scoreUprLowest = s.scoreUpr;
            }
            if (s.scoreLwr == s.scoreUpr) {
                continue;
            }

            const vector<Box>& boxes = s.boxes;
            for (size_t i = 0; i < boxes.size(); ++i) {
                vector<Box> boxesTmp(boxes);
                if (0 < i && i + 1 < boxesTmp.size() && boxesTmp[i - 1].num == boxesTmp[i + 1].num) {
                    boxesTmp[i - 1].count += boxesTmp[i + 1].count;
                    boxesTmp.erase(boxesTmp.begin() + i, boxesTmp.begin() + i + 2);
                }
                else {
                    boxesTmp.erase(boxesTmp.begin() + i);
                }

                pq.emplace(s.score - boxes[i].count * boxes[i].count, boxesTmp);
            }
        }

        return -scoreUprLowest;
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