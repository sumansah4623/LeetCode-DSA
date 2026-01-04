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



//Approach : iterative BFS and queue data structure for processing
//time complexity : O(n)  visit each node once
//space complexity : O(n), queue stores nodes of a level
class Solution 
{
public:
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        vector<vector<int>> ans;                             //store final level order result
        queue<TreeNode*> q;                                  //queue for BFS traversal
        q.push(root);

        if(root == NULL)                                     //edge case: empty tree
           return ans; 

        while(!q.empty())                                    //process nodes level by level
        {
            int size = q.size();                             //number of nodes at current level
            vector<int> level;                               //store current level values

            for(int i = 0; i<size; i++)                      //traverse all nodes of current level
            {
                TreeNode* node = q.front();
                q.pop();

                level.push_back(node->val);                  //store node value

                if(node->left != NULL)                       //push left and right child if exist
                   q.push(node->left);
                if(node->right != NULL)
                   q.push(node->right);
   
            }

            ans.push_back(level);                            //add current level to answer
        }  

        return ans;  
    }
};