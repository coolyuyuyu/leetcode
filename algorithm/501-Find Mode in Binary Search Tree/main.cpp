/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    // iterative, required addition space for traveral store the visited elements
    vector<int> findMode(TreeNode* root) {
        if (!root) {
            return {};
        }

        unordered_map<int, int> counts;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* pNode = q.front();
            q.pop();

            pair<unordered_map<int, int>::iterator, bool> p = counts.emplace(pNode->val, 1);
            if (!p.second) {
                ++p.first->second;
            }

            if (pNode->left) {
                q.push(pNode->left);
            }
            if (pNode->right) {
                q.push(pNode->right);
            }
        }

        int maxCount = 0;
        for (auto kv: counts) {
            maxCount = max(maxCount, kv.second);
        }

        vector<int> modes;
        for (auto kv : counts) {
            if (kv.second == maxCount) {
                modes.push_back(kv.first);
            }
        }

        return modes;
    }

    // purely iterative, no stack, non-recursion, space-efficient
    vector<int> findMode(TreeNode* root) {
        vector<int> modes;

        int count = 0;
        int countMax = 0;
        bool hasVisited = false;
        int preVal;

        TreeNode* cur = root;
        TreeNode* pre = NULL;
        while (cur) {
            if (cur->left) {
                pre = cur->left;
                while (pre->right && pre->right != cur) {
                    pre = pre->right;
                }

                if (pre->right) {
                    pre->right = NULL;

                    if (hasVisited) {
                        if (preVal == cur->val) {
                            ++count;
                        }
                        else {
                            preVal = cur->val;
                            count = 1;
                        }

                        if (countMax < count) {
                            countMax = count;
                            modes.clear();
                            modes.push_back(cur->val);
                        }
                        else if (countMax == count) {
                            modes.push_back(cur->val);
                        }
                    }
                    else {
                        count = countMax = 1;
                        preVal = cur->val;
                        modes.push_back(cur->val);
                        hasVisited = true;
                    }

                    cur = cur->right;
                }
                else {
                    pre->right = cur;
                    cur = cur->left;
                }
            }
            else {
                if (hasVisited) {
                    if (preVal == cur->val) {
                        ++count;
                    }
                    else {
                        preVal = cur->val;
                        count = 1;
                    }

                    if (countMax < count) {
                        countMax = count;
                        modes.clear();
                        modes.push_back(cur->val);
                    }
                    else if (countMax == count) {
                        modes.push_back(cur->val);
                    }
                }
                else {
                    count = countMax = 1;
                    preVal = cur->val;
                    modes.push_back(cur->val);
                    hasVisited = true;
                }

                cur = cur->right;
            }
        
        }

        return modes;
    }
};