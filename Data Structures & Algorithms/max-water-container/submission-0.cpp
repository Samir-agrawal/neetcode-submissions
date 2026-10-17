class Solution {
public:
    int maxArea(vector<int>& heights) {
        int mxArea = INT_MIN;
        int l = 0, r = heights.size()-1;
        while(l<r)
        {
            int area = (r-l)*min(heights[l],heights[r]);
            mxArea = max(area,mxArea);
            if(heights[l]<heights[r]) l++;
            else r--;
        }
        return mxArea;
    }
};
