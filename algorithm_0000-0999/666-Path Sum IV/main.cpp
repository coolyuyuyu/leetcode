class Solution {
public:
    int pathSum(vector<int>& nums) {
        int arr[5][8];
        std::memset(arr, 0, sizeof(arr));

        for (int num : nums) {
            int depth = num / 100;
            int index = (num / 10) % 10 - 1;
            int value = num % 10;
            arr[depth][index] = value + arr[depth - 1][index / 2];
        }

        int ret = 0;
        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < 8; ++j) {
                if (i == 4 || (arr[i][j] != 0 && arr[i + 1][j * 2] == 0 && arr[i + 1][j * 2 + 1] == 0)) {
                    ret += arr[i][j];
                }
            }
        }

        return ret;
    }
};
