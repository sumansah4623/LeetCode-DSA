/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */


//Approach : Recursive DFS(in-order traversal)
//time complexity : O(n)
//space complexity : O(n), Recursive stack 
class Solution 
{
public:
    void inorder(TreeNode* root, vector<int> &ans)
    {
        //Base Case
        if(root == NULL)
           return;

        inorder(root->left, ans);                     //go left 
        ans.push_back(root->val);                     //then node
        inorder(root->right, ans);                    //go right

    }
    vector<int> inorderTraversal(TreeNode* root) 
    {
        vector<int> ans;
        inorder(root, ans);
        return ans;
    }
};




//Approach : Iterative using Stack(DFS)
//time complexity : O(n)
//space complexity : O(n), stack 
class Solution 
{
public:
    vector<int> inorderTraversal(TreeNode* root) 
    {
        vector<int> ans;                                 //store inorder result
        stack<TreeNode*> st;                             //stack to simulate recursion
        TreeNode* curr = root;                           //start from root

        while(curr != NULL || !st.empty())
        {
            //go to leftmost node
            while(curr != NULL)
            {
                st.push(curr);
                curr = curr->left;
            }

            //process node
            curr = st.top();
            st.pop();
            ans.push_back(curr->val);


            //move to right substree
            curr = curr->right;
        }

        return ans;
    }
};