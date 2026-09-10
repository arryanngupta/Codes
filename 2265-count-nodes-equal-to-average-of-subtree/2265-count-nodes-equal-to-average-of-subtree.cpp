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

    int ans = 0;

    int find(TreeNode* node){
        if(!node) return 0;
        int lh = find(node->left);
        int rh = find(node->right);
        return lh+rh+1;
    }

    int recFind(TreeNode* node){
        if(!node) return 0;
        int lh = find(node->left);
        int rh = find(node->right);
        int total = lh+rh+1;
        int l = recFind(node->left);
        int r = recFind(node->right);
        int sum = l+r+node->val;
        if(sum/total==node->val) ans++;
        return sum;
    }

    int averageOfSubtree(TreeNode* root) {
        recFind(root);
        return ans;
    }
};