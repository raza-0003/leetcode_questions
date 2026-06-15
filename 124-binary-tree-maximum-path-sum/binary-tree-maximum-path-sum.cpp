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
        int got = root->val + left + right;
        int d_got = root->val + max(left,right);
        int ind = root->val;
        d_got = max(d_got,ind);
        res = max(res,max(got,d_got));
        return d_got;
    }
    int maxPathSum(TreeNode* root) {
        int sum = INT_MIN;
        solve(root,sum);
        return sum;
    }
};