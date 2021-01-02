#include<stdio.h>
#include<stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *result = malloc(sizeof(struct ListNode));
    result->val=0;
    result->next=NULL;
    struct ListNode *Origin = result;
    while(l1!=NULL&&l2!=NULL){
        result->val = (l1->val+l2->val);
        result->next = malloc(sizeof(struct ListNode));
        result = result->next;
        l1 = l1->next;
        l2= l2->next;
    }
    while(l1!=NULL){
        result->val = l1->val;
        l1 = l1->next;
        result->next = malloc(sizeof(struct ListNode));
        result = result->next;
    }
    while(l2!=NULL){
        result->val = l2->val;
        l2 = l2->next;
        result->next = malloc(sizeof(struct ListNode));
        result = result->next;
    }
    result->val=0;
    result->next=NULL;
    int carry=0;
    result=Origin;
    while(result!=NULL){
        result->val+=carry;
        carry=0;
        if(result->val>=10){
            carry=1;
            result->val-=10;
        }
        result = result->next;
    }
    result=Origin;
    while(result!=NULL){
        if(result->next!=NULL){
            if(result->next->next==NULL&&result->next->val==0){
                free(result->next);
                result->next=NULL;
                break;
            }
        }
        result = result->next;
    }
    return Origin;
}
int main(){
    return 0;
}