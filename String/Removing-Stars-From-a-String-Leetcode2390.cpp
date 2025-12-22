//Approach 1 : Using Stack
//time complexity : O(n)
//space complexity : O(n)
class Solution 
{
public:
    string removeStars(string s) 
    {
        //take a stack
        stack<char> st;

        //iterating a string
        for(int i = 0; i<s.length(); i++)
        {
            //if found '*'
            if(s[i] == '*')
            {
                if(!st.empty())
                {
                    st.pop();     //Remove the closest non-star character to left
                }
            }
            else
            {
                st.push(s[i]);     //otherwise push in stack
            }

        }
 
        //answer string
        string ans = "";

        //keep back char to string from stack
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
      
        //then reverse string
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};