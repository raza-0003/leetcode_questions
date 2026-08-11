class Solution {
public:
    TreeNode* prev = nullptr;

    void flatten(TreeNode* root) {
        if (root == nullptr)
            return;
        // Reverse preorder: Right -> Left -> Root
        flatten(root->right);
        flatten(root->left);
        root->right = prev;
        root->left = nullptr;
        prev = root;
    }
};