class Solution {
public:
    int t[21][21001] ;
    int solve (vector<int>& nums, int sum , int n)
    {
        for (int i = 0 ; i < n+1 ; i++)
        {
            for ( int j = 0 ; j < sum +1 ; j++)
            {
                if ( j==0) t[i][j] = 1 ;
                else if ( i ==0 ) t[i][j] = 0 ;
            }
        }



        for (int i = 1 ; i < n+1 ; i++)
        {
            for ( int j = 0 ; j < sum +1 ; j++)
            {
                if ( nums[i-1] <= j)
                {
                    t[i][j] = t[i-1][j-nums[i-1]] + t[i-1][j];
                }
                else
                {
                    t[i][j] = t[i-1][j];
                }
                
            }
        }
        return t[n][sum];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0 ;
        for ( int i = 0 ; i < n ; i++)
        {
            sum += nums[i];
        }

        if (abs(target) > sum)
        return 0;

        if ( (sum + target) %2 != 0  )
        {
            return 0;
        }
        int temp = (sum + target) /2 ;

        return solve(nums , temp , n);
    }
};