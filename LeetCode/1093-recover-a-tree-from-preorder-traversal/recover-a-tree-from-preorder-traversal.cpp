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
    TreeNode* recoverFromPreorder(string traversal) {
        vector<TreeNode*> latestNodes(1000, nullptr);  
        TreeNode* root = nullptr;
        
        for (int i = 0; i < traversal.size(); i++) {
            int dashCnt = 0;
            while (traversal[i] == '-') {
                dashCnt++;
                i++;
            }
            
            int val = 0;
            while (i < traversal.size() && isdigit(traversal[i])) {
                val = val * 10 + (traversal[i] - '0');
                i++;
            }
            i--; // Adjust
            
            TreeNode* node = new TreeNode(val);
            latestNodes[dashCnt] = node;
            
            if (dashCnt == 0) {
                root = node;
            } else {
                TreeNode* parent = latestNodes[dashCnt - 1];
                if (!parent->left) {
                    parent->left = node;
                } else {
                    parent->right = node;
                }
            }
        }
        return root;
    }
};