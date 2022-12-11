class Allocator {
public:
    Allocator(int n)
        : m_avail({{0,n}})
        , m_alloc(1001) {
    }

    int allocate(int size, int mID) {
        auto itrAvail = std::find_if(m_avail.begin(), m_avail.end(), [&size](const pair<int, int>&block) { return size <= block.second; });
        if (itrAvail == m_avail.end()) {
            return -1;
        }

        int index = itrAvail->first;
        itrAvail->first += size;
        itrAvail->second -= size;
        if (itrAvail->second == 0) {
            m_avail.erase(itrAvail);
        }

        list<pair<int, int>>& alloc = m_alloc[mID];
        auto itrAlloc = std::find_if(alloc.begin(), alloc.end(), [&index](const pair<int, int>&block) { return index <= block.first; });
        itrAlloc = alloc.emplace(itrAlloc, index, size);

        auto itrNxt = std::next(itrAlloc);
        if (itrNxt != alloc.end() && (itrAlloc->first + itrAlloc->second) == itrNxt->first) {
            itrNxt->first = itrAlloc->first;
            itrNxt->second += itrAlloc->second;
            itrAlloc = alloc.erase(itrAlloc);
        }

        if (itrAlloc != alloc.begin())  {
            auto itrPrev = std::prev(itrAlloc);
            if ((itrPrev->first + itrPrev->second) == itrAlloc->first) {
                itrAlloc->first = itrPrev->first;
                itrAlloc->second += itrPrev->second;
                itrAlloc = alloc.erase(itrPrev);
            }
        }

        return index;
    }

    int free(int mID) {
        int amount = 0;
        for (auto itrAvail = m_avail.begin(), itrAlloc = m_alloc[mID].begin(); itrAlloc != m_alloc[mID].end(); ++itrAlloc) {
            amount += itrAlloc->second;

            itrAvail = std::find_if(itrAvail, m_avail.end(), [&itrAlloc](const pair<int, int>&block) { return itrAlloc->first <= block.first; });
            itrAvail = m_avail.insert(itrAvail, *itrAlloc);

            auto itrNxt = std::next(itrAvail);
            if (itrNxt != m_avail.end() && (itrAvail->first + itrAvail->second) == itrNxt->first) {
                itrNxt->first = itrAvail->first;
                itrNxt->second += itrAvail->second;
                itrAvail = m_avail.erase(itrAvail);
            }

            if (itrAvail != m_avail.begin())  {
                auto itrPrev = std::prev(itrAvail);
                if ((itrPrev->first + itrPrev->second) == itrAvail->first) {
                    itrAvail->first = itrPrev->first;
                    itrAvail->second += itrPrev->second;
                    itrAvail = m_avail.erase(itrPrev);
                }
            }
        }
        m_alloc[mID].clear();

        return amount;
    }

private:
    list<pair<int, int>> m_avail; // <index, size>
    vector<list<pair<int, int>>> m_alloc;
};

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->free(mID);
 */
