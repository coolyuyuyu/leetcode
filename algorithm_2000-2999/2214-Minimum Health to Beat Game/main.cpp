class Solution {
public:
    long long minimumHealth(vector<int>& damages, int armor) {
       long long health = 1;

       int d = 0;
       for (int damage : damages) {
           health += damage;
           d = std::max(d, std::min(damage, armor));
       }

       return health - d;
    }
};
