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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count = 0;
        ListNode* temp = head;

        while (temp) {
            count++;
            temp = temp->next;
        }

        int cut = count - n;
        count = 0;
        if (cut == 0) return head->next;
        temp = head;

        while (temp){
            count++;
            if (count == cut){
                temp->next = temp->next->next;
            }
            temp = temp->next;
        }

        return head;
    }
};