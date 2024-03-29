template<typename T>
class MaxSegmentTree {
public:
    typedef typename std::vector<T>::size_type size_type;

    explicit MaxSegmentTree(size_type n, const T& val = T()) {
        build(n, val);
    }

    void add(size_type lo, size_type hi, const T& val) {
        add(0, size() - 1, 0, lo, hi, val);
    }

    const T& get(size_type idx) const {
        assert(idx < size());

        size_type l = 0, h = size() - 1, i = 0;
        while (l < h) {
            pushDown(l, h, i);
            size_type m = l + (h - l) / 2;
            if (idx <= m) {
                h = m;
                i = lft(i);
            }
            else {
                l = m + 1;
                i = rht(i);
            }
        }

        return m_vals[i];
    }

    template <class OutputIterator>
    OutputIterator output(OutputIterator itr) {
        output(0, size() - 1, 0, itr);
        return itr;
    }

    size_type size() const { return m_size; }
    bool empty() const { return m_size == 0; }

private:
    inline size_type lft(size_type i) const { return i * 2 + 1; }
    inline size_type rht(size_type i) const { return i * 2 + 2; }

    void build(size_type n, const T& val) {
        m_size = n;
        if (m_size) {
            build(0, m_size - 1, 0, val);
        }
    }

    void build(size_type l, size_type h, size_type i, const T& val) {
        assert(l <= h);

        if (l == h) {
            if (m_vals.size() <= i) {
                m_vals.resize(i + 1);
                m_tags.resize(i + 1);
            }
            m_vals[i] = val;
            m_tags[i] = false;
        }
        else {
            size_type m = l + (h - l) / 2;
            build(l, m, lft(i), val);
            build(m + 1, h, rht(i), val);
        }
    }

    void pushDown(size_type l, size_type h, size_type i) const {
        if (l == h) {
            return;
        }
        if (m_tags[i] == false) {
            return;
        }

        m_vals[lft(i)] = m_vals[i];
        m_tags[lft(i)] = true;
        m_vals[rht(i)] = m_vals[i];
        m_tags[rht(i)] = true;
        m_tags[i] = false;
    }

    void add(size_type l, size_type h, size_type i, size_type lo, size_type hi, const T& val) {
        if (hi < l || h < lo) {
            return;
        }

        if (l == h) {
            m_vals[i] = std::max(m_vals[i], val);;
            return;
        }

        if (lo <= l && h <= hi && val >= m_vals[i]) {
            m_vals[i] = val;
            m_tags[i] = true;
            return;
        }

        pushDown(l, h, i);
        size_type m = l + (h - l) / 2;
        add(l, m, lft(i), lo, hi, val);
        add(m + 1, h, rht(i), lo, hi, val);
        m_vals[i] = std::max(m_vals[lft(i)], m_vals[rht(i)]);
    }

    template <class OutputIterator>
    void output(size_type l, size_type h, size_type i, OutputIterator& itr) {
        if (l == h || m_tags[i]) {
            *itr++ = {l, m_vals[i]};
            return;
        }

        size_type m = l + (h - l) / 2;
        output(l, m, lft(i), itr);
        output(m + 1, h, rht(i), itr);
    }

private:
    mutable std::vector<T> m_vals;
    mutable std::vector<bool> m_tags;
    size_type m_size;
};

class Solution {
public:
    vector<vector<int>> bySegmentTree(vector<vector<int>>& buildings) {
        unordered_map<int, int> pos2idx; vector<int> idx2pos; {
            set<int> s;
            for (const auto& building : buildings) {
                int lft = building[0], rht = building[1];
                s.insert(lft);
                s.insert(rht);
            }
            idx2pos.resize(s.size());

            int i = 0;
            for (auto pos : s) {
                pos2idx[pos] = i;
                idx2pos[i] = pos;
                ++i;
            }
        }
        int n = pos2idx.size();

        MaxSegmentTree<int> st(n, 0);

        // optimization. avoid possible lazy-propogate
        sort(buildings.begin(), buildings.end(), [](vector<int>&a, vector<int>&b){return a[2]<b[2];});
        for (const auto& building : buildings) {
            int lft = building[0], rht = building[1], h = building[2];
            st.add(pos2idx[lft], pos2idx[rht] - 1, h);
        }

        vector<pair<MaxSegmentTree<int>::size_type, int>> all;
        st.output(std::insert_iterator(all, all.begin()));

        vector<vector<int>> ret;
        ret.push_back({idx2pos[all[0].first], all[0].second});

        for (int i = 1; i < all.size(); ++i) {
            if (all[i].second == ret.back()[1]) {
                continue;
            }
            ret.push_back({ idx2pos[all[i].first], all[i].second});
        }

        return ret;
    }

    vector<vector<int>> byDiffArray(vector<vector<int>>& buildings) {
        map<int, vector<int>> x2heights;
        for (const auto& building : buildings) {
            int lft = building[0], rht = building[1], h = building[2];
            x2heights[lft].push_back(h);
            x2heights[rht].push_back(-h);
        }

        vector<vector<int>> ret;

        multiset<int> ms;
        for (const auto& [x, heights] : x2heights) {
            for (int h : heights) {
                if (h > 0) {
                    ms.emplace(h);
                }
                else {
                    ms.erase(ms.find(-h));
                }
            }

            int maxH = ms.empty() ? 0 : *(ms.rbegin());
            if (ret.empty() || maxH != ret.back()[1]) {
                ret.push_back({x, maxH});
            }
        }

        return ret;
    }

    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        //return bySegmentTree(buildings);
        return byDiffArray(buildings);
    }
};
