class NumberContainers {
public:
    NumberContainers() {
    }

    void change(int index, int number) {
        if (m_index2num.find(index) != m_index2num.end()) {
            m_num2indexes[m_index2num[index]].erase(index);
            if (m_num2indexes[m_index2num[index]].empty()) {
                m_num2indexes.erase(m_index2num[index]);
            }
        }

        m_index2num[index] = number;
        m_num2indexes[number].insert(index);
    }

    int find(int number) {
        if (m_num2indexes.find(number) == m_num2indexes.end()) { return -1; }
        const auto& indexes = m_num2indexes[number];
        return *(indexes.begin());
    }

private:
    unordered_map<int, int> m_index2num;
    unordered_map<int, set<int>> m_num2indexes;
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */
