// //Approach 1 : using Unordered_map
// //time complexity : O(n)
// //space complexity : O(n)
class Solution 
{
public:
    int singleNumber(vector<int>& nums) 
    {
        unordered_map<int, int> mp;                       //take a map

        for(int i = 0; i<nums.size(); i++)                //iterate array 
        {
            mp[nums[i]]++;                                //Keep in map and its freq
        } 


        for(auto x : mp)                                  //Iterate Map
        {
            if(x.second == 1)                             //if its freq is 1 
              return x.first;
        }

        return -1;
    }
};




//Approach 1 : XOR operator , 1 ^ 1 = 0, 1 ^ 0 = 1
//time complexity : O(n)
//space complexity : O(1)
class Solution 
{
public:
    int singleNumber(vector<int>& nums) 
    {
        int ans = 0;

        //Use XOR operator
        for(int i = 0; i<nums.size(); i++)
        {
            ans = ans ^ nums[i];
        }

        return ans;
    }
};