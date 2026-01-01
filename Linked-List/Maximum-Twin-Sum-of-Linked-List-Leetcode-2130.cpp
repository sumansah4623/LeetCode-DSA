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


//Approach : Using array as extra space
//time complexity : O(n)
//space complexity : O(n)
class Solution 
{
public:
    int pairSum(ListNode* head) 
    {
        vector<int> ans;                          //Store values of linked list

        ListNode* temp = head;                    //Pointer to traverse the linked list
        while(temp != NULL)                       //Traverse the linked list
        {
            ans.push_back(temp->val);             //Save current node value
            temp = temp->next;                    //Move to next node
        }

        int i = 0;                                //Start pointer
        int j = ans.size()-1;                     //End pointer
        int maxi = INT_MIN;                       //Store maximum twin sum
        while(i < j)                              //Check pairs from both ends
        {
            int twinSum = ans[i] + ans[j];        //Calculate twin sum
            maxi = max(maxi, twinSum);            //Update maximum sum
            i++;                                  //Move forward
            j--;                                  //Move Backward
        }

        return maxi;                              //return maximum twin
        
    }
};





//Approach : Using Stack
//time complexity : O(n)
//space complexity : O(n)
class Solution 
{
public:
    int pairSum(ListNode* head) 
    {
        stack<int> st;                          //Store Values of Linked List

        ListNode* temp = head;                  //Pointers to travsal Linked List
        int size = 0;                           //Count Number of Linked List
        while(temp != NULL)                     //traverse Linked List
        {
            st.push(temp->val);                 //Save current node value
            size++;                             //count node
            temp = temp->next;                  //Move to next Node
        }

        int mid = size/2;                       //mid of LL
        temp = head;                            //again point to head
        int maxi = INT_MIN;                     //variable to store maximum
        while(mid > 0)                         //Loop to access top(LL last value)
        {
            int twinSum = temp->val + st.top();         //add last and LL value
            maxi = max(maxi, twinSum);                  //update maxi
            st.pop();                                   //after adding remove top of stack
            mid--;                                      //decrement mid
            temp = temp->next;                          //move to next node
        }

        return maxi;                                     //return maximum twin sum
    }
};



//Approach : Reversing Half LL(Using slow fast pointers)
//time complexity : O(n)
//space complexity : O(1)
class Solution 
{
public:
    int pairSum(ListNode* head) 
    {
        //Step 1 : Find middle
        ListNode* slow = head;                        
        ListNode* fast = head;

        while(fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        
        //Step 2 : Reverse half LL
        ListNode* prev = NULL;
        ListNode* curr = slow;
        while(curr != NULL)
        {
            ListNode* forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }


        //Step 3 : Calculate twin sum
        ListNode* temp1 = head;
        ListNode* temp2 = prev;
        int maxi = INT_MIN;
        while(temp2 != NULL)
        {
            int twinSum = temp1->val + temp2->val;
            maxi = max(maxi, twinSum);
            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        return maxi;
    }
};