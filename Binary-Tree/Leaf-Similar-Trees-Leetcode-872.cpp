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



//Approach : Inorder Traversal
//time complexity : O(n)
//space complexity : O(n) , two vector and Recursive calls also use stack space
class Solution 
{
public:
    void inorder(TreeNode* root, vector<int> &tree)
    {

        if(root == NULL)                                          // Base case: empty node
          return;

        if(root->left == NULL && root->right == NULL)            // If current node is a leaf, store its value
        {
            tree.push_back(root->val);                        
            return;
        }  

        inorder(root->left, tree);                               //Recur on left and right subtree
        inorder(root->right, tree);

    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) 
    {
        vector<int> tree1;                          //vector stores leaf of tree1
        vector<int> tree2;                          //vector stores leaf of tree2
 

        inorder(root1, tree1);                       //Collect leaf sequences of both trees
        inorder(root2, tree2);

        if(tree1.size() != tree2.size())              //If number of leaf nodes differ
           return false;
        
        for(int i = 0; i<tree1.size(); i++)           //Compare leaf values one by one
        {
            if(tree1[i] != tree2[i])                   //if not equal
               return false;
        }

        return true;                                   //Leaf sequences are same
    }
};