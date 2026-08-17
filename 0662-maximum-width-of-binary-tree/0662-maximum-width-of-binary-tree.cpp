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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,long long>> q;
        q.push({root,1});
        long long ans = 0;
        while(!q.empty()){
            int len = q.size(),cnt = 0;
            long long mini = 1e18,maxi = 0;
            while(cnt<len){
                cnt++;
                TreeNode* node = q.front().first;
                long long idx = q.front().second;
                q.pop();
                mini = min(mini,idx);
                maxi = max(maxi,idx);
                if(node->left) q.push({node->left,2LL*idx-mini});
                if(node->right) q.push({node->right,2LL*idx+1-mini});
            }
            ans = max(ans,maxi-mini+1);
        }
        return (int)ans;
    }
};