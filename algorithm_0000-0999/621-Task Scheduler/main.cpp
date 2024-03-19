class Solution {
public:
    int byPQ(vector<char>& tasks, int n) {
        ++n;

        unordered_map<char, int> freqs;
        for (char task : tasks) {
            ++freqs[task];
        }

        priority_queue<int> pq;
        for (const auto& [_, freq] : freqs) {
            pq.push(freq);
        }

        int ret = 0;
        while (!pq.empty()) {
            int k = std::min<int>(n, pq.size());
            vector<int> tmp;
            for (int i = 0; i < k; ++i) {
                int freq = pq.top();
                pq.pop();

                if (freq - 1 > 0) {
                    tmp.push_back(freq - 1);
                }
            }
            for (int freq : tmp) {
                pq.push(freq);
            }

            ret += tmp.empty() ? k : n;
        }

        return ret;
    }

    int byGreedy(vector<char>& tasks, int n) {
        ++n;

        unordered_map<char, int> freqs;
        for (char task : tasks) {
            ++freqs[task];
        }

        int maxFreq = 0, numMaxFreq;
        for (const auto& [_, freq] : freqs) {
            if (freq > maxFreq) {
                maxFreq = freq;
                numMaxFreq = 1;
            }
            else if (freq == maxFreq) {
                ++numMaxFreq;
            }
        }

        return std::max<int>((maxFreq - 1) * n + numMaxFreq, tasks.size());
    }

    int leastInterval(vector<char>& tasks, int n) {
        //return byPQ(tasks, n);
        return byGreedy(tasks, n);
    }
};
