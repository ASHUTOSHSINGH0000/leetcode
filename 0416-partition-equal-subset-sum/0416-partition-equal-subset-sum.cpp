class Solution {
public:
    
    int t [201][10001];
    bool solve (vector<int>& nums , int j , int i )
    {
        if ( j == 0)
        {
            return true  ;
        }

        if ( i == 0 )
        {
            return false ;
        }

        if ( t[i][j]!= -1)
        {
            return t[i][j];
        }

        if ( nums[i-1] <= j )
        {
            t[i][j] = solve( nums ,j - nums[i-1] , i -1) || solve( nums , j , i -1);
        }
        
        else
        {
            t[i][j] = solve( nums , j , i -1) ;
        }

        return  t[i][j] ;


    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        int sum = 0 ;

        for ( int i = 0 ; i < n ; i++)
        {
            sum  += nums[i];
        }

        if ( sum % 2 != 0)
        {
            return false ;
        }

        memset( t ,-1 ,sizeof(t));

        return solve( nums , sum/2 , n) ;
        
    }
};