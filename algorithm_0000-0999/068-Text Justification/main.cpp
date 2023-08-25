class Solution {
public:
    string justify(vector<string>& words, int bgn, int end, int maxWidth) {
        int len = 0;
        for (int i = bgn; i < end; ++i) {
            len += words[i].size();
        }

        int n = (end - bgn);
        int spaces = n == 1 ? 0 : (maxWidth - len) / (n - 1);
        int rem = n == 1 ? 0 : (maxWidth - len)  % (n - 1);

        string line;
        for (int i = bgn; i < end; ++i) {
            line += words[i];
            if ((i + 1) < end) {
                for (int j = 0; j < spaces; ++j) {
                    line += " ";
                }
                if ((i - bgn) < rem) {
                    line += " ";
                }
            }
        }
        while (line.size() < maxWidth) {
            line += " ";
        }

        return line;
    }

    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int n = words.size();

        vector<string> lines;
        for (int bgn = 0; bgn < n;) {
            int end = bgn, len = 0;
            for (; end < n && (len + words[end].size()) <= maxWidth; ++end) {
                len += (words[end].size() + 1);
            }

            if (end == n) {
                string line;
                for (int i = bgn; i < end; ++i) {
                    line += words[i];
                    line += " ";
                }
                line.pop_back();
                while (line.size() < maxWidth) {
                    line += " ";
                }

                lines.push_back(line);
            }
            else {
                lines.push_back(justify(words, bgn, end, maxWidth));
            }

            bgn = end;
        }

        return lines;
    }
};
