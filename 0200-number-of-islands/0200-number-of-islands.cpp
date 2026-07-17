class Solution {
public:
    void dfs (int i , int j , vector<vector<char>>& grid , int n , int m ,  vector<vector<bool>> &vis  )
    {
        if ( i >= n || i<0 || j>=m || j<0 ||  vis[i][j] || grid[i][j]!= '1')
        {
            return ;
        }
        vis[i][j]= true ;

        dfs(i-1 , j , grid , n , m , vis);
        dfs(i+1 , j , grid , n , m , vis);
        dfs(i , j-1 , grid , n , m , vis);
        dfs(i , j+1 , grid , n , m , vis);
    }
    int numIslands(vector<vector<char>>& grid) {
        int island= 0  ;
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> vis( n , vector<bool>(m ,false) ) ;

        for ( int i = 0 ; i< n ; i++)
        {
            for ( int j = 0; j< m ; j++)
            {
                if ( grid[i][j] == '1' && !vis[i][j]) 
                {
                    dfs(i , j , grid , n , m , vis );
                    island++ ;
                }
            }
        }

        return island ;
        
    }
};