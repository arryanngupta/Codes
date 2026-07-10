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

    map<pair<TreeNode*,int>,int> mpp;

    int recFind(TreeNode* node,int flag){
        if(!node) return 0;
        if(mpp.find({node,flag})!=mpp.end()) return mpp[{node,flag}];
        int take = 0,notTake=0;
        if(flag==0){
            take = node->val+recFind(node->left,1)+recFind(node->right,1);
        }
        notTake = recFind(node->left,0)+recFind(node->right,0);
        return  mpp[{node,flag}]=max(take,notTake);
    }

    int rob(TreeNode* root) {
        return recFind(root,0);
    }
};