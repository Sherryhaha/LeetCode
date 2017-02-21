//
// Created by sunguoyan on 2017/2/21.
//

#include "LeetCode.h"


//******************************************
// ????????????????????????????????????
//******************************************

struct ListNode {
         int val;
         ListNode *next;
         ListNode(int x) : val(x), next(NULL) {}
     };


ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    while(l1==NULL && l2==NULL){
        return NULL;
    }
    int sum = 0;
    ListNode*root=NULL,*tail=NULL;

    while(l1!=NULL | l2!=NULL){
        if(l1!=NULL){
            sum += l1->val;
            l1 = l1->next;
        }
        if(l2!=NULL){
            sum += l2->val;
            l2 = l2->next;
        }
        ListNode*p = new ListNode(sum%10);
        if(root==NULL){
            root = p;
            tail = p;
        } else{
            tail->next = p;
            tail = p;
        }
        sum = sum/10;
    }
    if(sum!=0){
        ListNode*p = new ListNode(sum%10);
        if(root==NULL){
            root = p;
            tail = p;
        } else{
            tail->next = p;
            tail = p;
        }
    }
    return root;
}

int main(){
    int data1[10] = {1,2,3,4,5,6,7,8,9,2};
    int data2[10] = {2,3,4,5,6,7,8,9,0,1};

    ListNode*l1 = NULL,*l2 = NULL;
    ListNode*s1 = new ListNode(data1[0]);
    ListNode*s2 = new ListNode(data2[0]);
//    ListNode*s1 = NULL;
//    ListNode*s2 = NULL;
    l1 = s1;
    l2 = s2;

    //?????????
    for(int i = 1;i< 10;i++){
        ListNode*t1 = new ListNode(data1[i]);
        ListNode*t2 = new ListNode(data2[i]);
        s1->next = t1;
        s2->next = t2;
        s1 = s1->next;
        s2 = s2->next;
    }

//    for(int i = 0;i<10;i++){
//        cout<<l1->val<<" ";
//        l1 = l1->next;
//    }
//    cout<<endl;
//    for(int i = 0;i<10;i++){
//        cout<<l2->val<<" ";
//        l2 = l2->next;
//    }
    ListNode*result = NULL;
    result = addTwoNumbers(l1,l2);
    for(int i = 0;result!=NULL;i++){
        cout<<result->val<<" ";
        result = result->next;
    }
    return 0;
}

