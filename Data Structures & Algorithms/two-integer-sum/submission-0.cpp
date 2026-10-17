class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> mp; // storing {num,idx} pair
        for(int i=0;i<nums.size();i++)
        {
            if(mp.contains(target-nums[i]))
            {
                return {min(i,mp[target-nums[i]]),max(i,mp[target-nums[i]])};
            }
            mp[nums[i]] = i;
        }
        return {-1,-1};

        // TC = nlogn SC = n
    }
};
