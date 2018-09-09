#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        int tmp = 0;
        
        ListNode* head = new ListNode(0);
        ListNode* cur = head;
        while(p1!=NULL||p2!=NULL){
            if(p1!=NULL&&p2!=NULL){
                if(p1->val < p2->val){
                    tmp = p1->val;
                    p1 = p1->next;
                }else{
                    tmp = p2->val;
                    p2 = p2->next;
                }
                cur->next = new ListNode(tmp);
            }else if(p1!=NULL&&p2==NULL){
                cur->next = new ListNode(p1->val);
                p1 = p1->next;
            }else if(p1==NULL&&p2!=NULL){
                cur->next = new ListNode(p2->val);
                p2 = p2->next;
            }
            cur = cur->next;
        }
        return head->next;
    }
    void print(ListNode *l){
        while(l!=NULL){
            cout<<l->val<<endl;
            l = l->next;
        }
        cout<<endl;
    }
};

int main()
{
    ListNode node1(1),node2(2),node3(4);
    ListNode node4(1),node5(3),node6(4);
    node1.next=&node2;node2.next=&node3;
    node4.next=&node5;node5.next=&node6;
    ListNode *l1=&node1,*l2=&node4;
    Solution solu;
    ListNode *result = solu.mergeTwoLists(l1,l2);
    solu.print(result);
    solu.print(l1);
    solu.print(l2);

    return 0;
}