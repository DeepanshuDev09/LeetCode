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
    ListNode* solve(ListNode* head1, ListNode* head2){
        if (head1 == nullptr && head2 == nullptr) return nullptr;
        if (head1 == nullptr) return head2;
        if (head2 == nullptr) return head1;

        ListNode* newHead = nullptr;
        ListNode* temp = nullptr;

        if (head1->val < head2->val){
            newHead = head1;
            temp = head1;
            head1 = head1->next;
        }
        else {
            newHead = head2;
            temp = head2;
            head2 = head2->next;
        }

        while (head1 && head2){
            if (head1->val < head2->val){
                temp->next = head1;
                head1 = head1->next;
            }
            else {
                temp->next = head2;
                head2 = head2->next;
            }
            temp = temp->next;
        }

        while (head1) {
            temp->next = head1;
            head1 = head1->next;
            temp = temp->next;
        }

        while (head2) {
            temp->next = head2;
            head2 = head2->next;
            temp = temp->next;
        }

        return newHead;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* sortedHead = nullptr;
        int i = 0;

        for (int i = 0; i < lists.size(); i++) {
            sortedHead = solve(sortedHead, lists[i]);
        }

        return sortedHead;
    }
};