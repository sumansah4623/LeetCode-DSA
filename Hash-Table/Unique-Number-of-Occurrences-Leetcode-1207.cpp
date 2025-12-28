//Approach : Using unordered_map and unordered_set
//time complexity : O(n)
//space complexity : O(n)
class Solution 
{
public:
    bool uniqueOccurrences(vector<int>& arr) 
    {
        //take unordered_map 
        unordered_map<int, int> mp;

        //store in map and count its frequency
        for(int i = 0; i<arr.size(); i++)
        {
            mp[arr[i]]++;
        }
        
        //take unordered_set
        unordered_set<int> st;
        
        //iterate map
        for(auto x : mp)
        {
            int freq = x.second;
            if(st.find(freq) != st.end())     //frequency already present
            {
                return false;
            }

            //if not in set then store in set
            st.insert(freq);
        }

        return true;
    }
};