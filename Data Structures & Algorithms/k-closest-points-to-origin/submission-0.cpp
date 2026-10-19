class Solution {
private:
    struct comp{
        bool operator()(vector<int>& v1,vector<int>& v2)
        {
            int dist1 = v1[0]*v1[0] + v1[1]*v1[1];
            int dist2 = v2[0]*v2[0] + v2[1]*v2[1];
            return  dist1 < dist2;
        }
    };
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>,vector<vector<int>>,comp> kClosestPoint;
        for(vector<int>& point : points)
        {
            if (kClosestPoint.size() < k) kClosestPoint.push(point);
            else{
                vector<int> top = kClosestPoint.top();
                int dist1 = point[0]*point[0] + point[1]*point[1];
                int dist2 = top[0]*top[0] + top[1]*top[1];
                if(dist1 < dist2) {
                    kClosestPoint.pop();
                    kClosestPoint.push(point);
                }
            }
        }
        vector<vector<int>> res;
        while(!kClosestPoint.empty())
        {
            res.push_back(kClosestPoint.top());
            kClosestPoint.pop();
        }
        return res;
    }
};
