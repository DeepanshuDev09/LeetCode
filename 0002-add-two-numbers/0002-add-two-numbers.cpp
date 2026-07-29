/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* tempL1 = l1;
        ListNode* tempL2 = l2;
        int countL1 = 0, countL2 = 0;

        while (tempL1){
            countL1++;
            tempL1 = tempL1->next;
        }
        while (tempL2){
            countL2++;
            tempL2 = tempL2->next;
        }

        if (countL2 < countL1) return addTwoNumbers(l2, l1);

        tempL1 = l1;
        tempL2 = l2;

        while (tempL1 && tempL2){
            int sum = carry + tempL1->val + tempL2->val;
            tempL2->val = sum % 10;
            carry = sum / 10;

            if (!tempL1->next) break;
            tempL1 = tempL1->next;
            tempL2 = tempL2->next;
        }

        while (tempL2->next){
            int sum = tempL2->next->val + carry;
            tempL2->next->val = sum % 10;
            carry = sum / 10;

            tempL2 = tempL2->next;
        }

        if (carry)
            tempL2->next = new ListNode(carry);

        return l2;
    }
};