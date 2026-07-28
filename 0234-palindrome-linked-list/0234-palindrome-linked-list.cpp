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
    ListNode* reverseLL (ListNode* head, ListNode* slow){
        ListNode* curr = head;
        ListNode* temp = nullptr;

        while (curr){
            if (curr == slow) break;
            head = curr;
            ListNode* currTemp = curr;
            curr = curr->next;
            currTemp->next = temp;
            temp = currTemp;
        }

        return head;
    }
public:
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* revHead = reverseLL(head, slow);

        if (fast != nullptr) slow = slow->next;

        while (slow){
            if (slow->val != revHead->val) return false;
            slow = slow->next;
            revHead = revHead->next;
        }

        return true;
    }
};