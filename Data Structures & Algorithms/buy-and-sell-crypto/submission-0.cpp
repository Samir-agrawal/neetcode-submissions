class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mxPft = 0;
        int minPriceSoFar = INT_MAX;
        for(int price : prices){
            if(price < minPriceSoFar){
                minPriceSoFar = price;
            }else{
                mxPft = max(mxPft,price-minPriceSoFar);
            }
        }
        return mxPft;
    }
};
