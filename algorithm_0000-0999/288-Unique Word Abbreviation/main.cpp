class ValidWordAbbr {
public:
    ValidWordAbbr(vector<string> dictionary) {
        for (const string& word: dictionary) {
            m_groups[getAbbr(word)].emplace(word);
        }
    }

    bool isUnique(string word) {
        auto itr = m_groups.find(getAbbr(word));
        if (itr == m_groups.end()) {
            return true;
        }

        const unordered_set<string>& words = itr->second;
        return words.size() == 1 && words.find(word) != words.end();
    }

private:
    string getAbbr(const string& word) {
        if (word.size() <= 2) {
            return word;
        }

        string abbr;
        abbr.push_back(word.front());
        abbr += word.size();
        abbr.push_back(word.back());
        return abbr;
    }

    unordered_map<string, unordered_set<string>> m_groups;
};

/**
 * Your ValidWordAbbr object will be instantiated and called as such:
 * ValidWordAbbr obj = new ValidWordAbbr(dictionary);
 * bool param_1 = obj.isUnique(word);
 */