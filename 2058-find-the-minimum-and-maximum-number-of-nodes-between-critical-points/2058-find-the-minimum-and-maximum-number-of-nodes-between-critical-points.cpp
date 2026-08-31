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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int firstCriticalPoint = -1;
        int recentCriticalPoint = -1;
        int lastNodeVal = head->val;
        int index = 2;
        int minDistance = INT_MAX, maxDistance = -1;
        ListNode* temp = head->next;

        while (temp != nullptr && temp->next != nullptr){
            if (lastNodeVal > temp->val && temp->val < temp->next->val){
                if (firstCriticalPoint != -1) maxDistance = max((index - firstCriticalPoint), maxDistance);
                if (recentCriticalPoint != -1 ) minDistance = min((index - recentCriticalPoint), minDistance);
                if (firstCriticalPoint == -1) firstCriticalPoint = index;
                recentCriticalPoint = index;
            }

            if (lastNodeVal < temp->val && temp->val > temp->next->val){
                if (firstCriticalPoint != -1 ) maxDistance = max((index - firstCriticalPoint), maxDistance);
                if (recentCriticalPoint != -1 ) minDistance = min((index - recentCriticalPoint), minDistance);
                if (firstCriticalPoint == -1) firstCriticalPoint = index;
                recentCriticalPoint = index;
            }

            lastNodeVal = temp->val; temp = temp->next; index++;
        }

        if (minDistance == INT_MAX) return {-1, -1};

        return {minDistance, maxDistance};
    }
};