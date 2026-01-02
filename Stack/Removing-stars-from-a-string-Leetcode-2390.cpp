//Approach 1 : Using Stack
//time complexity : O(n)
//space complexity : O(n)
class Solution 
{
public:
    string removeStars(string s) 
    {
        stack<char> st;                                     //stack for storing char

        for(int i = 0; i<s.length(); i++)                   //iterating string
        {
            //if '*' found
            if(s[i] == '*')
            {
                //means, stack is not empty we can pop from stack
                if(!st.empty())
                {
                    st.pop();
                }
            }
            //if s[i] is char 
            else
            {
                st.push(s[i]);
            }
        }

        //take string result
        string result = "";
        while(!st.empty())
        {
            result.push_back(st.top());                 //move char from stack to result string
            st.pop();
        }

        reverse(result.begin(), result.end());          //then reverse
        return result;
    }
};