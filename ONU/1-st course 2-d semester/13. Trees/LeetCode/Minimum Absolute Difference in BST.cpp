/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int min_diff = INT_MAX;
    TreeNode* prev = nullptr;

    void InOrder(TreeNode* node) {
        if (node == nullptr) return;

        InOrder(node->left); // 1. Левое поддерево

        // 2. Обработка текущего узла
        if (prev) {
            min_diff = min(min_diff, abs(node->val - prev->val));
        }
        prev = node;

        InOrder(node->right); // 3. Правое поддерево
    }

    int getMinimumDifference(TreeNode* root) {
        InOrder(root);
        return min_diff;
    }
};