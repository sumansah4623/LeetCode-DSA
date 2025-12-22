// //Approach 1 : using Unordered_map
// //time complexity : O(n)
// //space complexity : O(n)
// class Solution 
// {
// public:
//     int singleNumber(vector<int>& nums) 
//     {
//         unordered_map<int, int> mp;
        
//         //keep in map
//         for(int i = 0; i<nums.size(); i++)
//         {
//             mp[nums[i]]++;
//         }   

//         //iterate map
//         for(auto x : mp)
//         {
//             if(x.second == 1)
//             {
//                 return x.first;
//             }
//         }

//         return -1;
//     }
// };




//Approach 1 : XOR operator
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