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

    ListNode* tailOdd;
    ListNode* headEven;
    ListNode* tailEven;
    ListNode* nxtNode;
    ListNode* node;
    int flag;

    void handleOdd(int cnt){
        flag = 0;
        int len = 1;
        ListNode* temp = node;
        while(temp->next && len<cnt){
            len++;
            temp = temp->next;
        }
        if(cnt!=len && len%2==0){
            flag = 1;
            handleEven(cnt);
            return ;
        }
        tailOdd = temp;
        node = temp;
        node = node->next;
    }

    void handleEven(int cnt){
        int len = 1;
        int cnt1 = 1;
        ListNode* temp = node;
        while(cnt1<cnt && temp->next){
            cnt1++;
            temp = temp->next;
        }
        if(cnt1!=cnt && cnt1%2!=0){
            handleOdd(cnt);
            return ;
        }
        temp = node;
        ListNode* prev = NULL;
        while(len<=cnt && temp){
            len++;
            if(len==2 && !flag) headEven = temp;
            nxtNode = temp->next;
            temp->next = prev;
            prev = temp;
            temp = nxtNode;
        }
        tailEven = prev;
        node = nxtNode;
        if(cnt==3) cout << tailOdd->val;
        if(flag==0){
            tailOdd->next = tailEven;
            headEven->next = nxtNode;
        }
        else{
            headEven->next = tailEven;
        }
    }

    ListNode* reverseEvenLengthGroups(ListNode* head) {
        node = head;
        tailOdd = NULL,headEven = NULL,tailEven = NULL;
        int cnt = 1;
        while(node){
            if(cnt%2!=0){
                handleOdd(cnt);
            }
            else{
                handleEven(cnt);
            }
            cnt++;
        }
        return head;
    }
};