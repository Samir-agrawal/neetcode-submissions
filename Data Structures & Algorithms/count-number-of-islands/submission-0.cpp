class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        stack<pair<int,int>> st;

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j] == '1') st.push({i,j});
            }
        }
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        int cntOfIslands = 0;
        vector<vector<int>> dir = {{-1,0},{1,0},{0,1},{0,-1}};
        while(!st.empty())
        {
            auto coord = st.top(); st.pop();
            int x = coord.first;
            int y = coord.second;
            if(vis[x][y]) continue;
            // apply bfs
            vis[x][y] = true;
            cntOfIslands++;
            stack<pair<int,int>> currSt;
            currSt.push({x,y});
            while(!currSt.empty())
            {
                int curr_x = currSt.top().first;
                int curr_y = currSt.top().second;
                currSt.pop();
                vis[curr_x][curr_y] = true;
                for(vector<int>& d : dir)
                {
                    int new_x = curr_x + d[0];
                    int new_y = curr_y + d[1];
                    if(new_x >=0 && new_y >= 0 && new_x < m && new_y < n && grid[new_x][new_y]=='1' && !vis[new_x][new_y])
                    {
                        currSt.push({new_x,new_y});
                    }
                }
            }
        }
        return cntOfIslands;
    }
};
