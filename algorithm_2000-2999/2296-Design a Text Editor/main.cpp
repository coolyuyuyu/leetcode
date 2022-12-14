class TextEditor {
public:
    TextEditor() {
    }

    void addText(string text) {
        for (char c : text) {
            m_lftStk.push_back(c);
        }
    }

    int deleteText(int k) {
        int ret = std::min(k, (int)m_lftStk.size());
        while (!m_lftStk.empty() && 0 < k--) {
            m_lftStk.pop_back();
        }

        return ret;
    }

    string cursorLeft(int k) {
        while (!m_lftStk.empty() && 0 < k--) {
            m_rhtStk.push_back(m_lftStk.back());
            m_lftStk.pop_back();
        }

        return string(m_lftStk.end() - std::min((size_t)10, m_lftStk.size()), m_lftStk.end());
    }

    string cursorRight(int k) {
        while (!m_rhtStk.empty() && 0 < k--) {
            m_lftStk.push_back(m_rhtStk.back());
            m_rhtStk.pop_back();
        }

        return string(m_lftStk.end() - std::min((size_t)10, m_lftStk.size()), m_lftStk.end());
    }

private:
    vector<char> m_lftStk;
    vector<char> m_rhtStk;
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */
