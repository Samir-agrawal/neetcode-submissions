class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int singleNo = 0;
        for(int i=0;i<nums.size();i++) singleNo ^= nums[i];
        return singleNo;
    }
};
