class Solution {
public:
    int  t[13][10001] ;

    int solve (vector<int>& coins, int amount , int n )
    {
        for ( int i = 0 ; i< n+1 ; i ++)
        {
            for ( int j = 0 ; j < amount +1 ; j++)
            {
                if ( i == 0)
                {
                    t[i][j] = INT_MAX - 1 ;
                }
                else if ( j == 0 )
                {
                    t[i][j] = 0 ;
                }
            }
        }

        int x = 1 ;

        for ( int j = 0  ; j < amount + 1 ; j++ )
        {
            if ( j % coins[0] == 0)
            {
                t[x][j] = j / coins[0];
            }
            else 
            {
                t[x][j] = INT_MAX - 1 ;
            }
        }

        for ( int i = 2 ; i < n+1 ; i++ )
        {
            for ( int j = 1 ; j < amount + 1 ; j++)
            {
                if ( coins[i-1] <= j)
                {
                    t[i][j] = min(t[i][j-coins[i-1]]  + 1 , t[i-1][j] );
                }
                else 
                {
                    t[i][j] = t[i-1][j];
                }
                
            }
        }
        return t[n][amount];
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        int ans =  solve ( coins , amount , n);

        if (ans == INT_MAX - 1)
            return -1;

        return ans ;
        
    }
};