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
    ListNode* reverseLL(ListNode* head, int k, ListNode* prev) {
        ListNode* curr = head;
        int count = 0;

        while (curr != nullptr) {
            if (count == k) break;
            ListNode* next = curr->next; // Save next node
            curr->next = prev;           // Reverse the link
            prev = curr;                 // Move prev forward
            curr = next;
            count++;          
        }

        return prev; 
    }

    ListNode* getTail(ListNode* head, int k){
        ListNode* temp = head;
        int count = 1;
        while (temp->next){
            if (count == k) break;
            temp = temp->next;
            count++;
        }
        return temp;
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* prevGroup = nullptr;
        ListNode* temp = head;
        ListNode* groupHead = nullptr;
        ListNode* newGroup = nullptr;
        int count = 1;

        while (temp){
            if (count == 1) groupHead = temp;
            
            temp = temp->next; 

            if (count == k){
                newGroup = reverseLL(groupHead, k, temp);
            
                if (prevGroup != nullptr){
                    ListNode* prevTail = getTail(prevGroup, k);
                    prevTail->next = newGroup;
                }
                else {
                    head = newGroup;
                }
                prevGroup = newGroup;
                count = 1;
            }
            else { count++; }   
        }

        return head;
    }
};