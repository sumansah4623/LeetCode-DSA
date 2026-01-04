/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */



//Approach : Recursive DFS (Post-Order Traversal) (left->right->node)Approach
//time complexity : O(n) -> each node visited onces
//space complexity : O(n) -> recursion stack
class Solution 
{
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {

        if(root == NULL || root == p || root == q)                          //Base case: if tree is empty or root is p or q
        {
            return root;
        }

        TreeNode* leftVal = lowestCommonAncestor(root->left, p , q);         //Search p and q in left subtree
        TreeNode* rightVal = lowestCommonAncestor(root->right, p, q);        //Search p and q in right subtree

        if(leftVal != NULL && rightVal != NULL)                              //If p is in one subtree and q in another, root is LCA
        {
            return root;
        }
        if(leftVal  != NULL)                                                 //If both nodes found in left subtree
        {
            return leftVal;
        }

        return rightVal;                                                    //Otherwise, nodes are in right subtree
    }
};