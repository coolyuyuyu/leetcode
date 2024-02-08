class Solution {
public:
    string stdsort(string& s) {
        int cnts[128];
        std::fill(cnts, cnts + 128, 0);
        for (char c : s) {
            ++cnts[c];
        }

        auto comp = [&](char c1, char c2) {
            return (cnts[c1] > cnts[c2]) || (cnts[c1] == cnts[c2] && c1 < c2);
        };
        std::sort(s.begin(), s.end(), comp);

        return s;
    }

    string bucketsort(string& s) {
        vector<int> cnts(128, 0);
        for (char c : s) {
            ++cnts[c];
        }

        vector<string> buckets;
        for (char c = 0; c < cnts.size(); ++c) {
            if (buckets.size() <= cnts[c]) {
                buckets.resize(cnts[c] + 1);
            }
            buckets[cnts[c]].push_back(c);
        }

        s.clear();
        for (size_t cnt = buckets.size(); 0 < cnt--;) {
            for (char c : buckets[cnt]) {
                s.append(cnt, c);
            }
        }

        return s;
    }

    string stdheap(string& s) {
        vector<int> cnts(128, 0);
        for (char c : s) {
            ++cnts[c];
        }

        auto comp = [&cnts](char c1, char c2) {
            return (cnts[c1] < cnts[c2]) || (cnts[c1] == cnts[c2] && c1 < c2) ;
        };
        priority_queue<char, vector<char>, decltype(comp)> pq(comp);
        for (char c = 0; c < cnts.size(); ++c) {
            if (cnts[c] == 0) {
                continue;
            }
            pq.push(c);
        }

        for (auto itr = s.begin(); !pq.empty(); pq.pop()) {
            char c = pq.top();
            itr = std::fill_n(itr, cnts[c], c);
        }

        return s;
    }

    string frequencySort(string s) {
        return stdsort(s);
        //return bucketsort(s);
        //return stdheap(s);
    }
};
