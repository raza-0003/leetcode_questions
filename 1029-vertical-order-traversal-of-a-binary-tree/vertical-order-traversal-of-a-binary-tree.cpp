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
    void dfs(TreeNode* root,int row,int col,map<int,map<int,multiset<int>>>&mpp){
        if(root == nullptr){
            return;
        }
        mpp[col][row].insert(root->val);
        dfs(root->left,row+1,col-1,mpp);
        dfs(root->right,row+1,col+1,mpp);

    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>ans;
        map<int,map<int,multiset<int>>>mpp;
        dfs(root,0,0,mpp);
        for(auto &colPair:mpp){
            vector<int> coloumn;
            for(auto &rowPair:colPair.second){
                for(auto &value:rowPair.second){
                    coloumn.push_back(value);
                }

            }
            ans.push_back(coloumn);
        }
        return ans;
    }
};