#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int i=0,num=0;
        ListNode *p = head;
        while(p){
            num++;
            p = p->next;
        }
        if(num==1)return NULL;
        if(num==n)return head->next;
        int idx = num-n;
        cout<<"num: "<<num<<endl;
        cout<<"idx: "<<idx<<endl;
        p = head;
        while(p){
            i++;
            if(i>=idx){
                break;
            }
            p = p->next;
        }
        p->next = p->next->next;
        return head;
    }
};