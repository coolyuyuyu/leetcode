class Solution {
public:
    int distMoney(int money, int children) {
        if (money < children) {
            return -1;
        }
        if ((children * 8) < money) {
            return children - 1;
        }

        money -= children;
        int quotient = money / 7;
        int reminder = money % 7;
        if (reminder == 3 && quotient == (children - 1)) {
            return quotient - 1;
        }
        else {
            return quotient;
        }
    }
};
