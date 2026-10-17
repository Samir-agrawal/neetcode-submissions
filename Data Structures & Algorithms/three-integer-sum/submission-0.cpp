class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        set<vector<int>> uniqueTriplets;
        int n = nums.size();
        int target = 0;
        for(int k=0;k<n-2;k++)
        {
            if(target < nums[k]) break;
            int l = k+1, r = n-1;
            while(l<r){
                int sum = nums[l]+nums[r]+nums[k];
                if(sum == target){
                    uniqueTriplets.insert({nums[l],nums[r],nums[k]});
                    l++; r--;
                }
                else if(sum < target) l++;
                else r--;
            }
        }
        vector<vector<int>> res;
        for(vector<int> arr : uniqueTriplets)
        {
            res.push_back(arr);
        }
        return res;
    }
};
