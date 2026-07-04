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

class NodeDetails{
public:
    int mini,maxi,sum;
    NodeDetails(int mini,int maxi,int sum){
        this->mini = mini;
        this->maxi = maxi;
        this->sum = sum;
    }
};

class Solution {
public:

    int ans = 0;

    NodeDetails recFind(TreeNode* node){
        if(!node) return NodeDetails(INT_MAX,INT_MIN,0);
        auto l = recFind(node->left);
        auto r = recFind(node->right);
        if(node->val>l.maxi && node->val<r.mini){
            ans = max(ans,node->val+l.sum+r.sum);
            return NodeDetails(min(l.mini,node->val),max(r.maxi,node->val),node->val+l.sum+r.sum);
        }
        else return NodeDetails(INT_MIN,INT_MAX,max(l.sum,r.sum));
    }

    int maxSumBST(TreeNode* root) {
        recFind(root);
        return max(0,ans);
    }
};