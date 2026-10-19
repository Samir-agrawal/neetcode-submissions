class Solution {
private:
    void getSubsets(vector<int>& nums,vector<vector<int>>& subsets,vector<int>& tmp,int idx){
        if(idx == nums.size()){
            subsets.push_back(tmp);
            return;
        }
        // not pick
        getSubsets(nums,subsets,tmp,idx+1);
        // pick
        tmp.push_back(nums[idx]);
        getSubsets(nums,subsets,tmp,idx+1);
        tmp.pop_back();

        return;

    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subsets;
        vector<int> tmp;
        getSubsets(nums,subsets,tmp,0);
        return subsets;
    }
};
