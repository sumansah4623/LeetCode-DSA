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


//Approach : Using Level Order Traversal(BFS)
//time complexity : O(n)
//space complexity : O(n), queue
class Solution 
{
public:
    int maxLevelSum(TreeNode* root) 
    {
        int maxSum = INT_MIN;                             //store maximum level sum
        int maxLevel = 1;                                 //level having maximum sum
        int levelCount = 1;                               //current level number


        queue<TreeNode*> q;                               //queue for BFS
        q.push(root);                                     //push root node


        while(!q.empty())                                 //process tree level by level
        {
            int size = q.size();                          //current level size
            int currSum = 0;                              //sum of current level

            for(int i = 0; i<size; i++)                   //traverse current level
            {
                TreeNode* node = q.front();
                q.pop();

                currSum = currSum + node->val;            //add node value to sum
 
                if(node->left != NULL)                    //check left ,right subtree node
                  q.push(node->left);
                if(node->right != NULL)
                  q.push(node->right);  
            }


            if(currSum > maxSum)                          //update maxSum and level
            {
                maxSum = currSum;
                maxLevel = levelCount;
            }

            levelCount++;                                      //move to next level
        }
        
        return maxLevel;
    }
};