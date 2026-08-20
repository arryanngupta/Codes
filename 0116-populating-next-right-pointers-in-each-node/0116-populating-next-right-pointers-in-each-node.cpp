/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:

    

    Node* connect(Node* root) {
        if(!root) return root;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int len = q.size(),cnt = 0;
            while(cnt<len){
                cnt++;
                Node* node1 = q.front();
                q.pop();
                if(cnt!=len){
                    Node* node2 = q.front();
                    node1->next = node2;
                }
                else node1->next = NULL;
                if(node1->left) q.push(node1->left);
                if(node1->right) q.push(node1->right);
            }
        }
        return root;
    }
};