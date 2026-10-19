class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n = stones.size();
        priority_queue<int> pq;
        for(int stone : stones) pq.push(stone);
        while(pq.size() > 1)
        {
            int heaviestStone = pq.top(); pq.pop();
            int secondHeaviestStone = pq.top(); pq.pop();
            int remainingWeight = heaviestStone - secondHeaviestStone;
            if(remainingWeight != 0) pq.push(remainingWeight);
        }
        return pq.empty()? 0:pq.top();
    }
};
