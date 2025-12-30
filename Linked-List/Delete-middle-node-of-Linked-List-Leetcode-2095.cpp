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


//Approach : Using two pass of LL(iterative)
//time complexity : O(N)
//space complexity : O(1)
class Solution 
{
public:
    ListNode* deleteMiddle(ListNode* head) 
    {
        //Edge Case
        if(head == NULL || head->next == NULL)
        {
            return NULL;
        }

        //count no of node in LL
        int count = 0;
        ListNode* temp = head;
        while(temp != NULL)
        {
            count++;
            temp = temp->next;
        }

        //now delete middle node of LL
        int target = count/2;
        temp = head;             //again point to head of LL
        while(target > 0)
        {
            target--;
            if(target == 0)
            {
                //reached to Middle , delete it by changing next pointers
                ListNode* middle = temp->next;
                temp->next = temp->next->next;        //changing next pointer
                delete middle;                        //then delete it
            }

            temp = temp->next;   //move every time
        }
        
        return head;
    }
};




//Approach : Using slow, fast pointers algorithm(tortose and hare)
//time complexity : O(N/2)
//space complexity : O(1)
class Solution 
{
public:
    ListNode* deleteMiddle(ListNode* head) 
    {
        //Edge Case
        if(head == NULL || head->next == NULL)
        {
            return NULL;
        }

        //slow fast pointers
        ListNode* slow = head;
        ListNode* fast = head;
        fast = fast->next->next;    //skip one time slow pointer
        while(fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        //middle node is slow->next
        //change link and delete middle node
        ListNode* middleNode = slow->next;
        slow->next = slow->next->next;
        delete middleNode;
        
        return head;
    }
};