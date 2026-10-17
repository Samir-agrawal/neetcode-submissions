class Solution {
private:
    bool checkEachRow(vector<vector<char>>& board)
    {
        unordered_set<int> uniques;
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                char c = board[i][j];
                if(c == '.') continue;
                if(uniques.contains(c)) return false;
                uniques.insert(c);
            }
            uniques.clear();
        }
        return true;
    }
    bool checkEachColoumn(vector<vector<char>>& board)
    {
        unordered_set<int> uniques;
        for(int j=0;j<9;j++)
        {
            for(int i=0;i<9;i++)
            {
                char c = board[i][j];
                if(c == '.') continue;
                if(uniques.contains(c)) return false;
                uniques.insert(c);
            }
            uniques.clear();
        }
        return true;
    }
    bool checkEachSubcubes(vector<vector<char>>& board)
    {
        unordered_set<int> uniques;
        for(int k=0;k<9;k++)
        {
            int startRow = (k/3)*3;
            int startCol = (k%3)*3;
            for(int i=startRow;i<startRow+3;i++)
            {
                for(int j=startCol;j<startCol+3;j++)
                {
                    char c = board[i][j];
                    if(c == '.') continue;
                    if(uniques.contains(c)) return false;
                    uniques.insert(c);
                }
            }
            uniques.clear();
        }
        return true;
    }
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        return checkEachRow(board) && checkEachColoumn(board) && checkEachSubcubes(board);
    }
};
