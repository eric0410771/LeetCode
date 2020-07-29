/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    struct ListNode* head;
    struct ListNode* current;

        
    head = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next = NULL;
    
    
    if(l1 != NULL && l2 != NULL){  
        if(l1->val > l2 ->val){
            head->val = l2->val;
            l2 = l2->next;
            
        }else{
            head->val = l1->val;
            l1 = l1->next;
        }
        current = head;
        
        while(l1 != NULL && l2 != NULL){
            current->next = (struct ListNode*)malloc(sizeof(struct ListNode));
            current = current->next;
            if(l1->val > l2->val){
                
                current->val = l2->val;
                l2 = l2->next;
            }else{
                
                current->val = l1->val;
                l1 = l1->next;
            }
            
        }
        if(l1 != NULL){
            current->next = l1;
        }else{
            current->next = l2;
        }
        return head;
    }else if(l1 != NULL){
        return l1;
    }else if(l2 != NULL){
        return l2;
    }else{
        return NULL;
    }
}
