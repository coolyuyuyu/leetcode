class FoodRatings {
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for (int i = 0, n = foods.size(); i < n; ++i) {
            m_food2cuisine[foods[i]] = cuisines[i];
            m_food2rating[foods[i]] = ratings[i];
            m_cuisine2foods[cuisines[i]].emplace(-ratings[i], foods[i]);
        }
    }

    void changeRating(string food, int newRating) {
        m_cuisine2foods[m_food2cuisine[food]].erase({-m_food2rating[food], food});
        m_food2rating[food] = newRating;
        m_cuisine2foods[m_food2cuisine[food]].emplace(-newRating, food);
    }

    string highestRated(string cuisine) {
        return m_cuisine2foods[cuisine].begin()->second;
    }

private:
    unordered_map<string, string> m_food2cuisine;
    unordered_map<string, int> m_food2rating;
    unordered_map<string, set<pair<int, string>>> m_cuisine2foods;
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */
