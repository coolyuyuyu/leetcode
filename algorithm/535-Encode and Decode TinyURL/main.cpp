class Solution {
public:
    Solution()
        : m_chars(s_Chars){
        srand(time(nullptr));
        random_shuffle(m_chars.begin(), m_chars.end());
    }

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        auto itr = m_urlToKey.find(longUrl);
        if (itr != m_urlToKey.end()) {
            return s_BaseUrl + itr->second;
        }

        string key;
        do {
            key.clear();
            for (size_t i = 0; i < s_KeyLen; ++i) {
                key.push_back(m_chars[rand() % m_chars.size()]);
            }
        } while (m_keyToUrl.find(key) != m_keyToUrl.end());

        m_urlToKey[longUrl] = key;
        m_keyToUrl[key] = longUrl;;

        return s_BaseUrl + key;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        string key = shortUrl.substr(s_BaseUrl.size());
        auto itr = m_keyToUrl.find(key);
        if (itr == m_keyToUrl.end()) {
            return "";
        }

        return itr->second;
    }

private:
    string m_chars;
    unordered_map<string, string> m_urlToKey;
    unordered_map<string, string> m_keyToUrl;

    static const size_t s_KeyLen;
    static const string s_Chars;
    static const string s_BaseUrl;
};

const size_t Solution::s_KeyLen = 6;
const string Solution::s_Chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
const string Solution::s_BaseUrl = "http://tinyurl.com/";

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));