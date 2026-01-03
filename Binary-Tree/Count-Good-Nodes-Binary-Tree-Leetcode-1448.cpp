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


//Approach : Recursive
//time complexity : O(n)
//space complexity : O(n)
class Solution 
{
public:
    int count = 0;                              //stores number of good nodes
    int maxVal = INT_MIN;                       //stores maximum value seen so far in path


    void solve(TreeNode* node)
    {
        if(node == NULL)                         //base case
        {
            return;
        }

        int oldMax = maxVal;                      //store previous max for backtracking
        maxVal = max(maxVal, node->val);          //update max value on current path

        if(node->val == maxVal)                   //if current node is a good node
        {
            count++;
        }

        solve(node->left);                         //traverse left subtree
        solve(node->right);                        //traverse right subtree

        maxVal = oldMax;                           //backtrack maxVal for other paths

    }

    int goodNodes(TreeNode* root) 
    {
        solve(root);                              //start DFS traversal
        return count;                             //return total good nodes
    }
};