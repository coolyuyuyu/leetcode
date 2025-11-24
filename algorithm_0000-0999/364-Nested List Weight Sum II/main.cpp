/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        int maxDepth = 0; {
            queue<NestedInteger> q(nestedList.begin(), nestedList.end());
            while (!q.empty()) {
                ++maxDepth;

                for (int n = q.size(); 0 < n--;) {
                    NestedInteger ni = q.front();
                    q.pop();

                    if (!ni.isInteger()) {
                        for (const NestedInteger& child : ni.getList()) {
                            q.push(child);
                        }
                    }
                }
            }
        }

        int ret = 0; {
            queue<NestedInteger> q(nestedList.begin(), nestedList.end());
            for (int depth = 1; !q.empty(); ++depth) {
                for (int n = q.size(); 0 < n--;) {
                    NestedInteger ni = q.front();
                    q.pop();

                    if (ni.isInteger()) {
                        ret += (maxDepth - depth + 1) * ni.getInteger();
                    }
                    else {
                        for (const NestedInteger& child : ni.getList()) {
                            q.push(child);
                        }
                    }
                }
            }
        }

        return ret;
    }
};
