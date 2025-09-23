class MovieRentingSystem {
public:
    MovieRentingSystem(int n, vector<vector<int>>& entries)
        : m_prices(n) {
        for (const auto& entry : entries) {
            int shop = entry[0], movie = entry[1], price = entry[2];
            m_prices[shop].emplace(movie, price);
            m_unrented[movie].emplace(price, shop);
        }
    }

    vector<int> search(int movie) {
        vector<int> ret;
        for (const auto& [_, shop]: m_unrented[movie]) {
            ret.push_back(shop);
            if (ret.size() >= 5) {
                break;
            }
        }

        return ret;
    }

    void rent(int shop, int movie) {
        int price = m_prices[shop][movie];
        m_unrented[movie].erase({price, shop});
        m_rented.emplace(price, shop, movie);
    }

    void drop(int shop, int movie) {
        int price = m_prices[shop][movie];
        m_rented.erase({price, shop, movie});
        m_unrented[movie].emplace(price, shop);
    }

    vector<vector<int>> report() {
        vector<vector<int>> ret;
        for (const auto& [price, shop, movie]: m_rented) {
            //ret.emplace_back(shop, movie);
            ret.push_back({shop, movie});
            if (ret.size() >= 5) {
                break;
            }
        }

        return ret;
    }

private:
    vector<unordered_map<int, int>> m_prices; // shop -> (movie -> price)
    unordered_map<int, set<pair<int, int>>> m_unrented;// movice -> <price, shop>
    set<tuple<int, int, int>> m_rented; // <price, shop, movie>
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */
