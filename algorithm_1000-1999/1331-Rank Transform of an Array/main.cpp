class Solution {
public:
    vector<int> arrayRankTransform_Map(vector<int>& arr) {
        map<int, int> ranks;
        for (int num : arr) {
            ranks.emplace(num, 0);
        }

        int rank = 1;
        for (auto& p : ranks) {
            p.second = rank++;
        }


        for (int& num : arr) {
            num = ranks[num];
        }
        return arr;
    }

    vector<int> arrayRankTransform_Array(vector<int>& arr) {
        size_t len = arr.size();

        vector<pair<int, size_t>> valueIndexes(len);
        for (size_t i = 0; i < len; ++i) {
            valueIndexes[i] = {arr[i], i};
        }

        auto comp = [](const pair<int, size_t>& p1, const pair<int, size_t>& p2) {
            return (p1.first < p2.first);
        };
        sort(valueIndexes.begin(), valueIndexes.end(), comp);

        int rank = 1;
        for (size_t i = 0; i < len; ++i) {
            if (0 < i && valueIndexes[i - 1].first < valueIndexes[i].first) {
                ++rank;
            }
            arr[valueIndexes[i].second] = rank;
        }

        return arr;
    }

    vector<int> arrayRankTransform(vector<int>& arr) {
        //return arrayRankTransform_Map(arr);
        return arrayRankTransform_Array(arr);
    }
};
