class Solution {
private:
    bool isPossible(vector<int>& piles, int h,int k)
    {
        int totalHourTaken = 0;
        for(int pile : piles)
        {
            totalHourTaken += (pile+k-1)/k;
        }
        return totalHourTaken <= h ; 
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int high = *max_element(piles.begin(),piles.end());
        int low = 1;
        int ans ;
        while(low<=high)
        {
            int mid = low+(high-low)/2;
            if(isPossible(piles,h,mid)){
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        return ans;
    }
};
