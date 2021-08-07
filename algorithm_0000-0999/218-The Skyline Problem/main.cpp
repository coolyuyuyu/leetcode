class Solution {
public:
    class Corner {
    public:
        enum class Type {kLft, kRht};

        Corner(int x_, int y_, Type type_)
            : x(x_)
            , y(y_)
            , type(type_) {
        }

        bool operator<(const Corner& rhs) {
            if (x == rhs.x) {
                if (type == Type::kLft && rhs.type == Type::kLft) {
                    return !(y < rhs.y);
                }
                else if (type == Type::kRht && rhs.type == Type::kRht) {
                    return (y < rhs.y);
                }
                else {
                    return (type == Type::kLft);
                }
            }
            else {
                return (x < rhs.x);
            }
        }

        int x;
        int y;
        Type type;
    };

    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<Corner> corners;
        for (const auto& building : buildings) {
            assert(building[0] < building[1]);
            assert(0 < building[2]);

            corners.emplace_back(building[0], building[2], Corner::Type::kLft);
            corners.emplace_back(building[1], building[2], Corner::Type::kRht);
        }
        sort(corners.begin(), corners.end());

        map<int, int> hCnts;
        vector<vector<int>> points;
        for (const Corner& corner : corners) {
            switch (corner.type) {
                case Corner::Type::kLft:
                    ++hCnts[corner.y];
                    break;
                case Corner::Type::kRht:
                    --hCnts[corner.y];
                    if (hCnts[corner.y] == 0) {
                        hCnts.erase(corner.y);
                    }
                    break;
            }

            if (points.empty()) {
                assert(corner.type == Corner::Type::kLft);
                points.push_back({corner.x, corner.y});
            }
            else if (hCnts.empty()) {
                points.push_back({corner.x, 0});
            }
            else if (hCnts.rbegin()->first != points.back()[1]) {
                points.push_back({corner.x, hCnts.rbegin()->first});
            }
        }

        return points;
    }
};
