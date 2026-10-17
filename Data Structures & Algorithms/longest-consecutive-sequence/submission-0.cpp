class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> dp;
        int maxLen = 0;
        for(int i=0;i<nums.size();i++)
        {
            dp.insert(nums[i]);
        }
        for(int num : nums)
        {
            if(dp.contains(num-1)) continue;

            // else
            int len = 1;
            while(dp.contains(num+1)){
                len++;
                num += 1;
            }
            maxLen = max(maxLen,len);
        }
        return maxLen;
    }
};
