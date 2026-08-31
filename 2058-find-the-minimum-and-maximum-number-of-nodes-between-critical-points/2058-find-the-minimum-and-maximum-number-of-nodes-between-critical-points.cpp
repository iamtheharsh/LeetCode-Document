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
        int first = -1, last = -1;
        int mnd = INT_MAX;

        ListNode* prev = head;
        ListNode* curr = head->next;
        int i = 1;

        while(curr->next != nullptr){
            if((curr->val > prev->val && curr->val > curr->next->val) ||
            (curr->val < prev->val && curr->val < curr->next->val)){
                
                if(first == -1){
                    first = i;
                }
                else{
                    mnd = min(mnd, i-last);
                }

                last = i;
            }

            prev = curr;
            curr = curr->next;
            i++;
        }

        if(first == -1 || first == last) return {-1,-1};

        return {mnd, last-first};
    }
};
