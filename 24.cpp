//
// Created by sunguoyan on 2017/4/27.
//


#include "LeetCode.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


ListNode* swapPairs(ListNode* head) {
    ListNode**cur = &head;
    ListNode*p,*q;

    while((p=*cur)&&(q=p->next)){
        p->next = q->next;
        q->next = p;
        *cur = q;
        cur = &(p->next);
    }
    return head;
}
//用递归的方法来做
ListNode*swapPairs_recursive(ListNode*head){
    if(head==NULL) return NULL;
    if(head->next == NULL) return head;
    ListNode*h = head;
    ListNode* temp = h->next;

    h->next = swapPairs_recursive(temp->next);
    temp->next = h;

    return temp;
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
    h->next = NULL;    //这一句很重要，创建链表的时候不要忘记了最后一个节点next的指向
//    ListNode*result = swapPairs(head);
    ListNode* result = swapPairs_recursive(head);

    while(result->next!=NULL){
        cout<<result->val<<" ";
        result = result->next;
    }
//    while(head){
//        cout<<head->val<<" ";
//        head = head->next;
//    }

    return 0;
}

