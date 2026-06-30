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
        q.push({root,0});
        long long ans = 0;
        while(!q.empty()){
            int len = q.size();
            int cnt = 0;
            long long start = -1,end = 0,base = 0;
            while(cnt<len){
                TreeNode* node = q.front().first;
                long long i = q.front().second;
                if(start==-1){
                    start = i;
                    base = 2LL*i+1;
                }
                end = i;
                q.pop();
                if(node->left) q.push({node->left,2LL*i+1-base});
                if(node->right) q.push({node->right,2LL*i+2-base});
                cnt++;
            }
            ans = max(ans,(end-start+1));
        }
        return (int)ans;
    }
};