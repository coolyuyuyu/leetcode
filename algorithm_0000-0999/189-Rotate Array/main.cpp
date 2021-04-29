template<typename ForwardIterator>
void ROTATE(ForwardIterator first, ForwardIterator middle, ForwardIterator last) {
    ForwardIterator next = middle;
    while (first != next) {
        swap(*first++, *next++);
        if (next == last) {
            next = middle;
        }
        else if (first == middle) {
            middle = next;
        }
    }
}

class Solution {
public:
    void rotate_reverse(vector<int>& nums, int k) {
        k %= nums.size();
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }

    void rotate_rotate(vector<int>& nums, int k) {
        k %= nums.size();
        ROTATE(nums.begin(), nums.begin() + (0 < k ? (nums.size() - k) : 0), nums.end());
    }

    void rotate(vector<int>& nums, int k) {
        //rotate_reverse(nums, k);
        rotate_rotate(nums, k);
    }
};
