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
    ListNode *detectCycle(ListNode *head) {
        vector<ListNode*> visted;
        ListNode* temp = head;

        while (temp){
            auto it = find(visted.begin(), visted.end(), temp);
            if (it != visted.end()) return temp;

            visted.push_back(temp);
            temp = temp->next;
        }

        return nullptr;
    }
};