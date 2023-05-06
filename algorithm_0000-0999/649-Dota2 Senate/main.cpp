class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> q1, q2;
        for (int i = 0; i < senate.size(); ++i) {
            if (senate[i] == 'R') {
                q1.push(i);
            }
            else {
                q2.push(i);
            }
        }

        for (int n = senate.size(); !q1.empty() && !q2.empty(); ++n) {
            int i1 = q1.front(); q1.pop();
            int i2 = q2.front(); q2.pop();
            if (i1 < i2) {
                q1.push(n);
            }
            else {
                q2.push(n);
            }
        }

        return q2.empty() ? "Radiant" : "Dire";
    }
};
