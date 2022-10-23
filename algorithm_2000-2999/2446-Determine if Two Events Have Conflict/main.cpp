class Solution {
public:
    int computeMins(const string& s) {
        return (s[0] - '0') * 600 + (s[1] - '0') * 60 + (s[3] - '0') * 10 + (s[4] - '0');
    }

    bool haveConflict(vector<string>& event1, vector<string>& event2) {
        int bgn1 = computeMins(event1[0]), end1 = computeMins(event1[1]);
        int bgn2 = computeMins(event2[0]), end2 = computeMins(event2[1]);
        return bgn1 <= end2 && bgn2 <= end1;
    }
};
