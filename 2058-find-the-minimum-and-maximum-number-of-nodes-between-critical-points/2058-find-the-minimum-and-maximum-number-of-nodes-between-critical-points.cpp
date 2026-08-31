/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* node = head;
        int cnt = 0,mini = -1,maxi = -1,p = -1,c = -1,val = 1e9;
        vector<int> ans(2);
        while(node){
            cnt++;
            int next = node->next?node->next->val:-1;
            if(!prev || next==-1){
                prev = node;
                node = node->next;
                continue;
            }
            int pr = prev->val;
            if((node->val > pr && node->val > next)||(node->val < pr && node->val < next)){
                if(mini==-1) mini = cnt;
                maxi = cnt;
                if(p == -1) p = cnt;
                else if(c == -1){
                    c = cnt;
                    val = min(val,c-p);
                    p = c;
                    c = -1;
                }
            }
            prev = node;
            node = node->next;
        }
        if(mini == maxi) return {-1,-1};
        ans[1] = maxi-mini;
        ans[0] = val;
        return ans;
    }
};