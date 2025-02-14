class ProductOfNumbers {
public:
    ProductOfNumbers() {
    }

    void add(int num) {
        if (num > 0) {
            m_pres.push_back((m_pres.empty() ? 1 : m_pres.back()) * num);
        }
        else {
            m_pres.clear();
        }
    }

    int getProduct(int k) {
        if (k > m_pres.size()) {
            return 0;
        }
        else if (k == m_pres.size()) {
            return m_pres.back();
        }

        return m_pres.back() / m_pres[m_pres.size() - k - 1];
    }

private:
    vector<int> m_pres;
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
