class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> points;
        for (const string& op : ops) {
            if (op == "D") {
                points.push(points.top() * 2);
            }
            else if (op == "C") {
                points.pop();
            }
            else if (op == "+") {
                int lastPoint = points.top();
                points.pop();

                int latestPoint = points.top() + lastPoint;
                points.push(lastPoint);
                points.push(latestPoint);
            }
            else {
                points.push(stoi(op));
            }
        }

        int sumOfPoints = 0;
        while (!points.empty()) {
            sumOfPoints += points.top();
            points.pop();
        }

        return sumOfPoints;
    }
};