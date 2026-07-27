class Solution {
public:
    bool hasCycle(ListNode *head) {
        vector<ListNode*> visited;
        ListNode* temp = head;

        while (temp) {
            auto it = find(visited.begin(), visited.end(), temp);
            if (it != visited.end())
                return true;

            visited.push_back(temp);
            temp = temp->next;
        }

        return false;
    }
};