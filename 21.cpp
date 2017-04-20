//
// Created by sunguoyan on 2017/4/20.
//


//水题，合并两个链表
#include "LeetCode.h"
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };


ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode result(0);
    ListNode* head = &result;
    ListNode* h1 = l1;
    ListNode* h2 = l2;
    while(h1!=NULL && h2!=NULL){
        if(h1->val < h2->val){
            head->next = h1;
            h1 = h1->next;
        }else{
            head->next = h2;
            h2 = h2->next;
        }
        head = head->next;
    }

//    while(h1){
//            head->next = h1;
//            head = head->next;
//            h1 = h1->next;
//        }
//
//
//        while(h2){
//            head->next = h2;
//            head = head->next;
//            h2 = h2->next;
//        }
    head->next = h1 ? h1:h2;  //这边的处理很巧妙，借鉴的网上的

    return result.next;
}

int main(){
    ListNode*head1;
    head1=(ListNode *)malloc(sizeof(ListNode));//为头节点分配内存空间
    head1->next=NULL;
    ListNode*h1 = head1;

    ListNode*head2;
    head2=(ListNode *)malloc(sizeof(ListNode));//为头节点分配内存空间
    head2->next=NULL;
    ListNode*h2 = head2;

    ListNode*p;
    for(int i = 1;i<6;i++){
        p=(ListNode *)malloc(sizeof(ListNode));
        p->val = i;
        h1->next = p;
        h1 = p;
    }

    ListNode*q;
    for(int i = 1;i<20;){
        q=(ListNode *)malloc(sizeof(ListNode));
        q->val = i;
        h2->next = q;
        h2 = q;
        i =i+2;
    }

    h1->next = NULL;
    h2->next = NULL;
//    while(head1){
//        cout<<head1->val<<" ";
//        head1 = head1->next;
//    }
//    cout<<endl;
//    while(head2){
//        cout<<head2->val<<" ";
//        head2 = head2->next;
//    }
    ListNode*result = mergeTwoLists(head1->next,head2->next);
    while(result){
        cout<<result->val<<endl;
        result = result->next;
    }
    return 0;
}