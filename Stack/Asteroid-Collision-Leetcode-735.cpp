//Approach : Using Stack to simulate asteroid collisions
//time complexity : O(n)
//space complexity : O(n), stack is use here
class Solution 
{
public:
    vector<int> asteroidCollision(vector<int>& asteroids) 
    {
        stack<int> st;                        //stack to keep track of active asteroids
        
        //Traverse each asteroid
        for(int i = 0; i<asteroids.size(); i++)             
        {
            //If asteroid is moving right OR stack is empty → no collision
            if(asteroids[i] > 0 || st.empty())              
            {
                st.push(asteroids[i]);
            }
            else     //asteroid is moving left (possible collision)                                      
            {
                //Remove smaller right-moving asteroids
                while(!st.empty() && st.top() > 0 &&  st.top() < abs(asteroids[i]))
                { 
                    st.pop();
                }
                //If both asteroids are same size → both explode
                if(!st.empty() && st.top() == abs(asteroids[i]))
                {
                    st.pop();
                }
                else
                {
                    //If stack is empty or top is left-moving → push current
                    if(st.empty() || st.top() < 0)
                    {
                        st.push(asteroids[i]);
                    }
                }
            }
        }


        //Convert stack to result vector (reverse order)
        vector<int> ans(st.size());
        for(int i = (int)st.size()-1; i>=0; i--)
        {
            ans[i] = st.top();
            st.pop();
        }

        return ans;
        
    }
};