class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixProduct(n,1);
        vector<int> suffixProduct(n,1);
        for(int i=1;i<n;i++) prefixProduct[i] = nums[i-1] * prefixProduct[i-1]; // O(n)
        for(int i=n-2;i>=0;i--) suffixProduct[i] = nums[i+1] * suffixProduct[i+1]; //O(n)
        vector<int> result(n) ;
        for(int i=0;i<n;i++){
            result[i] = prefixProduct[i] * suffixProduct[i];
        }
        return result;

        // tc = O(n) , sc = O(n)
    }
};
