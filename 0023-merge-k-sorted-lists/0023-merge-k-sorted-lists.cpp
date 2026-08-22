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

        ListNode dummy;
        ListNode* node = &dummy;

        while (head1 && head2) {
            if (head1->val > head2->val) {
                node->next = head2;
                head2 = head2->next;
            } else {
                node->next = head1;
                head1 = head1->next;
            }
            node = node->next;
        }

        node->next = head1 ? head1 : head2;

        return dummy.next;
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