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


//Approach : Recursive DFS(Post-order Traversal)
//time complexity : O(n)
//space complexity : O(H) -> H is height of binary tree
class Solution 
{
public:
    void postorder(TreeNode* node, vector<int> &ans)
    {
        //base case
        if(node == NULL)
        {
            return;
        }

        postorder(node->left, ans);                               //go left
        postorder(node->right, ans);                              //go right
        ans.push_back(node->val);                                 //Visit node
    }

    vector<int> postorderTraversal(TreeNode* root) 
    {
        vector<int> ans;
        postorder(root, ans);
        return ans;
    }
};




//Approach : Iterative using Stack(DFS)
//time complexity : O(n)
//space complexity : O(H) -> H is height of binary tree
class Solution 
{
public:
    vector<int> postorderTraversal(TreeNode* root) 
    {

        vector<int> ans;                                //store postorder result


        if(root == NULL)                                //edge case: empty tree
            return ans;
        
        stack<TreeNode*> st;                            //stack for iterative DFS
        st.push(root);                                  //push root node
 

        while(!st.empty())                              //process until stack is empty
        {
            TreeNode* node = st.top();                  //get top node
            st.pop();


            ans.push_back(node->val);                    //store root value


            if(node->left != NULL)                       //push left child first
            {
                st.push(node->left);
            }
            if(node->right != NULL)                      //push right child
            {
                st.push(node->right);
            }
        }

        reverse(ans.begin(), ans.end());                 //convert Root-Right-Left → Left-Right-Root

        return ans;                                      //return postorder traversal
    }
};