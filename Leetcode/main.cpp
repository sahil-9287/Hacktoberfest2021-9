class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        int x_depth = -1, y_depth = -1;
        
        TreeNode* x_parent = getDepth(root, x, 0, x_depth);
        TreeNode* y_parent = getDepth(root, y, 0, y_depth);
        
        if (x_depth == y_depth && x_parent != y_parent)
            return true;
        
        return false;
    }
    
    TreeNode* getDepth(TreeNode* root, int val, int depth, int& level) {
        if(!root)
            return nullptr;
        
        if ((root->left && root->left->val == val) || (root->right && root->right->val == val)) {
            level = depth;
            return root;
        }

        TreeNode* left = getDepth(root->left, val, depth + 1, level);
        if (left) 
            return left;

        TreeNode* right = getDepth(root->right, val, depth + 1, level);
        if (right) 
            return right;

        return nullptr;
    }
};