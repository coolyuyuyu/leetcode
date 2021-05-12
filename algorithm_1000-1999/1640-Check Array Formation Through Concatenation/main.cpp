class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        map<int, size_t> indexes;
        for (size_t i = 0; i < pieces.size(); ++i) {
            indexes[pieces[i].front()] = i;
        }

        size_t index = 0;
        while (index < arr.size()) {
            auto itr = indexes.find(arr[index]);
            if (itr == indexes.end()) {
                break;
            }

            const auto& piece = pieces[itr->second];
            for (int num : piece) {
                if (arr[index] != num) {
                    break;
                }
                ++index;
            }
        }

        return (arr.size() <= index);
    }
};
