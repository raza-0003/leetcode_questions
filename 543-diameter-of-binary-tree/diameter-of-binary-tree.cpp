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
    int solve(TreeNode* root,int &res){
        if(root == nullptr){
            return 0;
        }
        int left = solve(root->left,res);
        int right = solve(root->right,res);
        int got = 1 + left + right;
        int d_got = 1 + max(left,right);
        res = max(res,max(got,d_got));
        return d_got;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;
        int ans = solve(root,res);
        return res-1;
    }
};