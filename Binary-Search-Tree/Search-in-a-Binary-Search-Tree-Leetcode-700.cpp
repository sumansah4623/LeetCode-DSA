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




//Approach : Recursive DFS on BST
//Time Complexity : O(H)  → H = height of BST
//Space Complexity : O(H) → recursion stack
class Solution 
{
public:
    TreeNode* searchBST(TreeNode* root, int val) 
    {

        if(root == NULL)                                  //Base Case : tree is empty
          return NULL;      

        if(root->val == val)                              //if target found
        {
            return root;
        } 
        else if(root->val > val)             //if target is smaller, search left subtree
        {
            return searchBST(root->left, val);            
        }
        else                                 //if target is larger, search right subtree
        {
            return searchBST(root->right, val);           
        }  

    }
};