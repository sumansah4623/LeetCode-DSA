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


//Approach : Recursive DFS(Preorder Traversal)
//time complexity : O(n)
//space complexity : O(H) -> H is height of Binary tree
class Solution 
{
public:
    void preorder(TreeNode* node, vector<int> &ans)
    {
        //base case
        if(node == NULL)
        {
            return;
        }

        ans.push_back(node->val);                                //Visit node
        preorder(node->left, ans);                               //then go left
        preorder(node->right, ans);                              //go right

    }

    vector<int> preorderTraversal(TreeNode* root) 
    {
        vector<int> ans;
        preorder(root, ans);
        return ans;
    }
};




//Approach : Iterative using Stack(DFS)
//time complexity : O(n)
//space complexity : O(H)-> stack used for traversal
class Solution 
{
public:
    vector<int> preorderTraversal(TreeNode* root) 
    {
        vector<int> ans;                                   //store preorder result

        if(root == NULL)                                   //edge case: empty tree
           return ans;
        

        stack<TreeNode*> st;                               //stack for iterative DFS
        st.push(root);                                     //push root node


        while(!st.empty())                                 //process until stack is empty
        {
            TreeNode* node = st.top();                     //get top node
            st.pop();

            ans.push_back(node->val);                      //visit root(Root)

            if(node->right)                                //push right child first
            { 
                st.push(node->right);
            }
            if(node->left)                                 //push left child so it is processed first
            {
                st.push(node->left);
            }
        }

        return ans;                                        //return preorder traversal
    }
};