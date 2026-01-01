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

//Approach : Using two pass iteration of LL
//time complexity : O(2n)
//space complexity : O(n), extra space is use here
class Solution 
{
public:
    ListNode* oddEvenList(ListNode* head) 
    {
        //Edge case
        if(head == NULL || head->next == NULL)
        {
            return head;
        }

        //take a array
        vector<int> arr;

        //pointer to pointing to head
        ListNode* temp = head;

        //iterating Loop
        while(temp != NULL && temp->next != NULL)
        {
            arr.push_back(temp->val);
            temp = temp->next->next;
        }
        //if any odd node left at last
        if(temp != NULL)
        {
            arr.push_back(temp->val);
        }

        //again pointing to head of LL
        temp = head->next;

        while(temp != NULL && temp->next != NULL)
        {
            arr.push_back(temp->val);
            temp = temp->next->next;
        }
        if(temp != NULL)
        {
            arr.push_back(temp->val);
        }


        //assign back to LL
        temp = head;
        int i = 0;
        while(temp != NULL)
        {
            temp->val = arr[i];
            i++;
            temp = temp->next;
        }

        return head;
    }
};




//Approach : Changing Links of nodes
//time complexity : O(n)
//space complexity : O(1)
class Solution 
{
public:
    ListNode* oddEvenList(ListNode* head) 
    {
        //Edge Case 
        if(head == NULL || head->next == NULL)       //if no node or one node 
        {
            return head;
        }

        
        ListNode* odd = head;                      //Pointer to track odd-positioned nodes
        ListNode* even = head->next;               //Pointer to track even-positioned nodes
        ListNode* evenHead = head->next;           //Store head of even list to attach at end later


        //Traverse while there are even and next-even nodes available
        while(even != NULL && even->next != NULL)        
        {
            
            odd->next = odd->next->next;          //Link current odd node to next odd node
            even->next = even->next->next;        //Link current even node to next even node

            
            odd = odd->next;                     //move odd pointers forward
            even = even->next;                   //Move even pointer forward
        }

        odd->next = evenHead;                    //Attach even list after the last odd node
        return head;                             //return modified LL
            
    }
};