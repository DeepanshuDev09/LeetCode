/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = 0;
        int lenB = 0;
        ListNode* tempA = headA;
        ListNode* tempB = headB;

        while (tempA){
            lenA++;
            tempA = tempA->next;
        }

        while (tempB){
            lenB++;
            tempB = tempB->next;
        }

        tempA = headA;
        tempB = headB;

        if (lenA > lenB){
            int diff = lenA - lenB;
            while (diff != 0){
                tempA = tempA->next;
                diff--; 
            }
        }
        else {
            int diff = lenB - lenA;
            while (diff != 0){
                tempB = tempB->next;
                diff--; 
            }
        }

        while (tempA && tempB){
            if (tempA == tempB) return tempA;
            tempA = tempA->next;
            tempB = tempB->next;
        }

        return nullptr; 
    }
};