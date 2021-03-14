class Solution {
public:
    int maximumScore_Heap(int a, int b, int c) {
        int score = 0;

        priority_queue<int> pq; // max_heap
        pq.push(a);
        pq.push(b);
        pq.push(c);
        while (1 < pq.size()) {
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();

            if (1 < x) {
                pq.push(x - 1);
            }
            if (1 < y) {
                pq.push(y - 1);
            }

            ++score;
        }

        return score;
    }

    int maximumScore_Math(int a, int b, int c) {
        vector<int> v{a, b, c};
        sort(v.begin(), v.end());
        a = v[0];
        b = v[1];
        c = v[2];

        if ((a + b) <= c) {
            return (a + b);
        }
        else {
            return ((a + b + c) / 2);
        }
    }

    int maximumScore(int a, int b, int c) {
        //return maximumScore_Heap(a, b, c);
        return maximumScore_Math(a, b, c);
    }
};
