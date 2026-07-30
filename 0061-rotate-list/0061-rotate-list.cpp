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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr) return head;

        ListNode* temp = head;
        int count = 0;
        ListNode* newHead = nullptr;

        while (temp){
            temp = temp->next;
            count++;
        }

        if (count <= k) k = k % count;
        if (k == 0) return head;
        int cut = count - k;
        count = 0;
        temp = head;

        while (temp){
            count++;
            ListNode* a = temp->next;
            if (count == cut){
                newHead = temp->next;
                temp->next = nullptr;
            }

            if (a == nullptr) temp->next = head;

            temp = a;
        }

        return newHead;
    }
};