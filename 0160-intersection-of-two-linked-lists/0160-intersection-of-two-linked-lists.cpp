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
        vector<ListNode*> list1;
        ListNode* temp = headA;

        while (temp){
            list1.push_back(temp);
            temp = temp->next;
        }

        temp = headB;

        while (temp){
            
            auto it = find(list1.begin(), list1.end(), temp);
            if (it != list1.end()) return temp;

            temp = temp->next;
        }

        return nullptr;
    }
};