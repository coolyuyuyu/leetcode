class Bank {
public:
    Bank(vector<long long>& balance)
        : m_balances(balance) {
    }

    bool transfer(int account1, int account2, long long money) {
        if (account1 > m_balances.size()) { return false; }
        if (account2 > m_balances.size()) { return false; }

        if (m_balances[account1 - 1] < money) {
            return false;
        }
        m_balances[account1 - 1] -= money;
        m_balances[account2 - 1] += money;
        return true;
    }

    bool deposit(int account, long long money) {
        if (account > m_balances.size()) { return false; }

        m_balances[account - 1] += money;
        return true;
    }

    bool withdraw(int account, long long money) {
        if (account > m_balances.size()) { return false; }

        if (m_balances[account - 1] < money) {
            return false;
        }
        m_balances[account - 1] -= money;
        return true;
    }

private:
    vector<long long> m_balances;
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */
