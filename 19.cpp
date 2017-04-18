//
// Created by sunguoyan on 2017/4/18.
//

#include "LeetCode.h"

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };



ListNode* removeNthFromEnd(ListNode* head, int n) {
    int len = 0;
    ListNode*h1 = head;
    while(h1!=NULL){
        len++;
        h1 = h1->next;
    }
    ListNode*p = head;
    ListNode*p1 = p;
    int index = len - n;
    if(index == 0){
        return head->next;
    }
    for(int i = 0;i<index-1;i++){
        p1 = p1->next;
    }
    ListNode*p2 = p1->next;
    p2 = p2->next;
    p1->next = p2;
    return p;
}

int main(){
    ListNode*head;
    head=(ListNode *)malloc(sizeof(ListNode));//为头节点分配内存空间
    head->next=NULL;
    ListNode*h = head;
    ListNode*p;
    for(int i = 1;i<6;i++){
        p=(ListNode *)malloc(sizeof(ListNode));
        p->val = i;
        h->next = p;
        h = p;
    }
    h->next = NULL;
//    while(head){
//        cout<<head->val<<" ";
//        head = head->next;
//    }
    ListNode*result = removeNthFromEnd(head->next,5);
    while(result){
        cout<<result->val<<endl;
        result = result->next;
    }
    return 0;
}