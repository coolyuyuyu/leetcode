/**
 * // This is the HtmlParser's API interface.
 * // You should not implement it, or speculate about its implementation
 * class HtmlParser {
 *   public:
 *     vector<string> getUrls(string url);
 * };
 */

class Solution {
public:
    vector<string> crawl(string startUrl, HtmlParser htmlParser) {
        string host = getHost(startUrl);
        unordered_set<string> urls;
        crawl(host, startUrl, htmlParser, urls);

        return vector<string>(urls.begin(), urls.end());
    }

private:
    void crawl(const string& host, const string& startUrl, HtmlParser& htmlParser, unordered_set<string>& urls) {
        if (checkBelonging(startUrl, host) && urls.insert(startUrl).second) {
            for (const string& url : htmlParser.getUrls(startUrl)) {
                crawl(host, url, htmlParser, urls);
            }
        }
    }

    string getHost(const string& url) {
        size_t end = url.find("/", 7);
        return url.substr(0, end);
    }

    bool checkBelonging(const string& url, const string& host) {
        return
            url.compare(0, host.size(), host) == 0 &&
            (host.size() == url.size() || url[host.size()] == '/');
    }
};
