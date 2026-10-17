class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(int num : nums) mp[num]++;

        vector<vector<int>> buckets(nums.size()+1);
        for(auto [num,freq] : mp)
        {
            buckets[freq].push_back(num);
        }

        vector<int> topK;
        for(int i=buckets.size()-1;i>=0;i--)
        {
            for(int num : buckets[i])
            {
                topK.push_back(num);
                if(topK.size()==k) return topK;
            }
        }
        return topK;
    }
};
