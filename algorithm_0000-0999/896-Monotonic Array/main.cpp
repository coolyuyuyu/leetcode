class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        enum class Order {
            increasing,
            decreasing,
            none,
        };

        Order order = Order::none;
        for (size_t i = 1; i < nums.size(); ++i) {
            if (nums[i - 1] < nums[i]) {
                switch (order) {
                    case Order::increasing:
                        break;
                    case Order::decreasing:
                        return false;
                    case Order::none:
                        order = Order::increasing;
                        break;
                }
            }
            else if (nums[i] < nums[i - 1]) {
                switch (order) {
                    case Order::increasing:
                        return false;
                    case Order::decreasing:
                        break;
                    case Order::none:
                        order = Order::decreasing;
                        break;
                }
            }
        }

        return true;
    }
};
