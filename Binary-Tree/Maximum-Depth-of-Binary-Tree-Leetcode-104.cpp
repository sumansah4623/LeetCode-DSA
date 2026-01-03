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

// //Approach : using Level order traversal
// //time complexity : O(n)
// //space complexity : O(n) 
class Solution 
{
public:
    int maxDepth(TreeNode* root) 
    {
        //Edge Case
        if(root == NULL)
           return 0;

        //Take a queue for Processing
        queue<TreeNode*> q;
        q.push(root);

        //variable for counting level
        int maxDepth = 0;

        //Loop untill queue is empty
        while(!q.empty())
        {
            int levelSize = q.size();                        //calculate size of curr level
            maxDepth++;                                      //increment level

            //loop for each level
            for(int i = 0; i<levelSize; i++)
            {
                TreeNode* node = q.front();                  //fetch front node of queue
                q.pop();                                     //and then remove

                if(node->left != NULL)                       //if node have left
                {
                    q.push(node->left);
                }
                if(node->right != NULL)                       //if node have right
                {
                    q.push(node->right);
                }
            }
        } 

        return maxDepth;  
        
    }
};





//Approach : Recursive 
//time complexity : O(n)
//space complexity : O(n) recursion stack in worst case (skewed tree)
class Solution 
{
public:
    int maxDepth(TreeNode* root) 
    {
        
        if(root == NULL)                                     //Base case: if tree is empty, depth is 0
           return 0;

        int leftHeight = maxDepth(root->left);                //Recursively find depth of left subtree
        int rightHeight = maxDepth(root->right);              //Recursively find depth of right subtree


        return 1 + max(leftHeight, rightHeight);              //Current Node depth = 1(current node)+ max of left/right subtree
    }
};