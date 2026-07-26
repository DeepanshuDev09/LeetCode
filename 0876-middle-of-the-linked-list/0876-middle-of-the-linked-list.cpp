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
    ListNode* middleNode(ListNode* head) {
        ListNode* temp = head;
        int count = 0;

        while (temp){
            count++;
            temp = temp->next;
        }

        int cut = count/2;
        count = 0;
        temp = head;

        while (temp){
            if (count == cut) return temp;
            count++;
            temp = temp->next;
        }

        return nullptr;
    }
};