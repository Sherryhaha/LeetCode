//
// Created by sunguoyan on 2017/4/28.
//

#include "LeetCode.h"

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};


//将以head为链表头的长为k的链表段进行reverse
ListNode *reverseList(ListNode *head, int k) {
    ListNode *p = head;
    ListNode *q = p->next;
    p->next = NULL;
    ListNode *temp;
    while (k - 1) {
        temp = q->next;
        q->next = p;
        p = q;
        q = temp;
        k--;
    }
    return p;
}

ListNode *reverseKGroup(ListNode *head, int k) {
    ListNode *temp = head;
    int len = 0;
    while (temp) {
        len++;
        temp = temp->next;
    }    //求取链表的长度
    if(k>len){
        return head;
    }

    ListNode *p = head;    //用来存储每次reverse的头节点
    ListNode *q = NULL;    //用来存储每次reverse后的头节点
    ListNode *preEnd = NULL;  //用来存储每次reverse后小段链表的尾节点
    ListNode *result = NULL;  //存放最终结果的头节点，也就是第一次反转后的尾节点
    for (int i = 0; i < len;) {
        if (i + k < len + 1) {
            ListNode *temp = p;
            int k1 = k;
            while (k1) {
                temp = temp->next;
                k1--;
            }      //求取下一次开始反转的头节点
            q = reverseList(p, k);
            if (i == 0) {
                result = q;
            }
            if (i != 0) {
                preEnd->next = q;
            }
            ListNode *tmp2 = q;
            int k3 = k;
            while (k3 - 1) {
                tmp2 = tmp2->next;
                k3--;
            }
            preEnd = tmp2;

            p = temp;
            i = i + k;
        } else {
            preEnd->next = p;
            return result;
        }
    }
    return result;
}


int main() {
    ListNode *head;
    head = (ListNode *) malloc(sizeof(ListNode));//为头节点分配内存空间
    head->next = NULL;
    ListNode *h = head;
    ListNode *p;
    for (int i = 1; i < 2; i++) {
        p = (ListNode *) malloc(sizeof(ListNode));
        p->val = i;
        h->next = p;
        h = p;
    }
    h->next = NULL;    //这一句很重要，创建链表的时候不要忘记了最后一个节点next的指向
//    ListNode*result = swapPairs(head);
//    ListNode *result = reverseList(head, 3);
    ListNode*result = reverseKGroup(head->next,2);

    while (result != NULL) {
        cout << result->val << " ";
        result = result->next;
    }
    return 0;
}