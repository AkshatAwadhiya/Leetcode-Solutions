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
    int getDecimalValue(ListNode* head) {
        int result = 0;
        
        while (head != nullptr) {
            result = (result << 1) | head->val;
            head = head->next;
        }
        
        return result;
    }
};

class SolutionAlternative {
public:
    int getDecimalValue(ListNode* head) {
        int result = 0;
        
        while (head != nullptr) {
            result = (result << 1) + head->val;
            head = head->next;
        }
        
        return result;
    }
};

class SolutionTwoPass {
public:
    int getDecimalValue(ListNode* head) {
        int length = 0;
        ListNode* current = head;
        while (current != nullptr) {
            length++;
            current = current->next;
        }
        
        int result = 0;
        current = head;
        int power = length - 1;
        
        while (current != nullptr) {
            if (current->val == 1) {
                result += (1 << power);
            }
            power--;
            current = current->next;
        }
        
        return result;
    }
};