class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        set<int> found;
        for(int i=0;i<nums.size();i++){
            if (found.contains(nums[i])) return true;
            found.insert(nums[i]);
        }
        return false;
    }
};