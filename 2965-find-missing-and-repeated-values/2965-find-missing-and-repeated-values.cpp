class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> freq(n*n+1);
        vector<int> ans;

        for ( int i = 0 ; i < n ; i ++)
        {
            for ( int j = 0 ; j < n ; j++)
            {
                freq[grid[i][j]]++;
                if (  freq[grid[i][j]] == 2)
                {
                    ans.push_back(grid[i][j]) ;
                }
            }
        }

        for ( int i = 1 ; i <= n*n ; i++)
        {
            if ( freq[i] == 0)
            {
                ans.push_back(i);
            }
        }

        return ans ;
    }
};