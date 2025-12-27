//Approach : Using ordered_set(c++ STL)
//time complexity : O(n)
//space complexity : O(n)
class Solution 
{
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) 
    {
        //take two set
        set<int> s1;
        set<int> s2;
        

        //take vector<vector<int>> for result
        vector<vector<int>> ans(2);


        //keep in set from array
        for(int i = 0; i<nums1.size(); i++)
        {
            s1.insert(nums1[i]);
        }

        //same for array 2
        for(int i = 0; i<nums2.size(); i++)
        {
            s2.insert(nums2[i]);
        }

        //now put in result vector
        for(auto x : s1)
        {
            //if not found in s2 then put in result
            if(s2.find(x) == s2.end())
            {
                ans[0].push_back(x);
            }
        }

        for(auto x : s2)
        {
            if(s1.find(x) == s1.end())
            {
                ans[1].push_back(x);
            }
        }

        return ans;
    }
};