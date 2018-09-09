#include <iostream>

using namespace std;

/* Definition for singly-linked list.*/
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode *p1=l1,*p2=l2;
        ListNode *head = new ListNode(0);
        ListNode *cur = head;
        int remain=0,flag=0;

        cout<<"List : ";
        while(p1!=NULL||p2!=NULL){
            if(p1!=NULL&&p2!=NULL){
                remain = p1->val+p2->val+flag;
                p1=p1->next;
                p2=p2->next;
            }else if(p1!=NULL){
                remain = p1->val + flag;
                p1=p1->next;
            }else{
                remain = p2->val + flag;
                p2=p2->next;
            }
            flag = int(remain/10);
            cur->next = new ListNode(remain%10);
            
            cur = cur->next;
            cout<<cur->val<<" ";
        }
        if(flag){
            cur->next = new ListNode(flag);
        }
        return head->next;
    }
};


int main(){
    ListNode num1(2),num2(4),num3(5);
    ListNode num4(5),num5(6),num6(4);
    num1.next = &num2;
    num2.next = &num3;
    num4.next = &num5;
    num5.next = &num6;
    Solution solu;

    ListNode* result = solu.addTwoNumbers(&num1,&num4);
    
    int num = 0;
    int pow10 = 1;
    ListNode* p = result;

    cout<<"List sum: ";
    while(p){
        cout<<p->val<<" ";
        num = num + p->val*pow10;
        p = p->next;
        pow10 *= 10;
    }

    cout<<endl<<"result sum: "<<num<<endl;

}