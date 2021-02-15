class Solution {
public:
    bool checkRec(vector<int>& rec) {
        return rec[0] != rec[2] && rec[1] != rec[3];
    }

    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        if (!(checkRec(rec1) && checkRec(rec2))) {
            return false;
        }

        bool hOverlap = rec2[0] < rec1[2] && rec1[0] < rec2[2];
        bool vOverlap = rec2[1] < rec1[3] && rec1[1] < rec2[3];
        return hOverlap && vOverlap;
    }
};
