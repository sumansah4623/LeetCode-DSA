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



//Approach : level Order Traversal
//time complexity : O(n)
//space complexity : O(n)
class Solution 
{
public:
    vector<int> rightSideView(TreeNode* root) 
    {
        vector<int> ans;                                  //store right side view
        queue<TreeNode*> q;                               //queue for BFS
        q.push(root);                                     //push root node


        if(root == NULL)                                  //edge case: empty tree
           return ans;
        

        while(!q.empty())                                 //process level by level
        {

            int size = q.size();                          //number of nodes in current level

            for(int i = 0; i<size; i++)                   //traverse current level
            {
                TreeNode* node = q.front();
                q.pop();

                if(i == size-1)                           //if last node of this level,add to answer
                   ans.push_back(node->val);

                if(node->left != NULL)                    //check node on both for next level
                   q.push(node->left);
                if(node->right != NULL)
                   q.push(node->right);   
            }

    
        }

        return ans;                                       //return right side view
    }
};