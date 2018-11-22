class TwoSum {
public:
    /** Initialize your data structure here. */
    TwoSum() {        
    }
    
    /** Add the number to an internal data structure.. */
    void add(int number) {
        auto p = m_duplicates.emplace(number, false);
        if (p.second == false) {
            p.first->second = true;
        }
    }
    
    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value) {
        for (const pair<int, bool>& p : m_duplicates) {
            int x = p.first;
            int y = value - x;
            if (x == y) {
                if (p.second) {
                    return true;
                }
            }
            else {
                if (m_duplicates.find(y) != m_duplicates.end()) {
                    return true;
                }
            }
            
        }
        
        return false;
    }
    
private:
    unordered_map<int, bool> m_duplicates;
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum obj = new TwoSum();
 * obj.add(number);
 * bool param_2 = obj.find(value);
 */
