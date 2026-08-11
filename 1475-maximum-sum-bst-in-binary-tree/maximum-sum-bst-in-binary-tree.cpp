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

    struct Info {
        bool isBST;
        int minVal;
        int maxVal;
        int sum;
    };

    int ans = 0;

    Info solve(TreeNode* root) {

        // Empty tree
        if (root == nullptr) {
            return {
                true,
                INT_MAX,
                INT_MIN,
                0
            };
        }

        // Get information from left and right
        Info left = solve(root->left);
        Info right = solve(root->right);

        // Check whether current subtree is BST
        if (left.isBST &&
            right.isBST &&
            left.maxVal < root->val &&
            root->val < right.minVal) {

            int currSum =
                left.sum + root->val + right.sum;

            ans = max(ans, currSum);

            return {
                true,
                min(left.minVal, root->val),
                max(right.maxVal, root->val),
                currSum
            };
        }

        // Current subtree is not a BST
        return {
            false,
            0,
            0,
            0
        };
    }

    int maxSumBST(TreeNode* root) {

        solve(root);

        return ans;
    }
};