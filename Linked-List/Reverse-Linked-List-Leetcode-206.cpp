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
 

//Approach : Iterative linked list reversal
//time complexity : O(n)
//space complexity : O(1)
class Solution 
{
public:
    ListNode* reverseList(ListNode* head) 
    {
        //Pointer to traverse the linked list
        ListNode* temp = head;

        //Pointer to store the previous node (initially NULL)
        ListNode* prev = NULL;

        //Traverse the list until the end
        while(temp != NULL)
        {
            //Store the next node
            ListNode* front = temp->next;

            //Reverse the current node's pointer
            temp->next = prev;

            //Move prev one step forward
            prev = temp;

            //Move temp one step forward
            temp = front;
        }
        
        //prev will be the new head of the reversed list
        return prev;
    }
};
