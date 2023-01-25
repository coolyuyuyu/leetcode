class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        auto comp = [&](const vector<int>& student1, const vector<int>& student2) {
            return student1[k] > student2[k];
        };
        std::sort(score.begin(), score.end(), comp);

        return score;
    }
};
