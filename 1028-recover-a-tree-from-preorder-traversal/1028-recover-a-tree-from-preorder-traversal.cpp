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

    vector<pair<int,int>> a;
    vector<int> b;
    int len,idx;

    TreeNode* recFind(int cnt){
        if(idx>=a.size() || a[idx].second!=cnt) return NULL;
        TreeNode* root = new TreeNode(a[idx].first);
        idx++;
        root->left = recFind(cnt+1);
        root->right = recFind(cnt+1);
        return root;
    }

    TreeNode* recoverFromPreorder(string traversal) {
        int n = traversal.size(),i=0,cnt = 0;
        while(i<n){
            int cnt = 0;
            while(traversal[i]=='-'){
                cnt++;
                i++;
            }
            string s = "";
            while(i<n && traversal[i]!='-'){
                s += traversal[i];
                i++;
            }
            a.push_back({stoi(s),cnt});
        }
        idx = 0;
        return recFind(0);
    }
};