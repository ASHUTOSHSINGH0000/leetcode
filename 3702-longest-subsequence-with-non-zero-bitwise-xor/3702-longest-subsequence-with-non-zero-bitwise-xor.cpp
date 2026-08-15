class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        bool allzero = true ;
        for( int i = 0 ; i < n ; i++)
        {
            ans = ans ^ nums[i];
            if (nums[i] !=  0  ) allzero = false ;
        }
        if ( allzero == true )
        {
            return 0 ;
        }

        if ( ans == 0)
        {
            return n-1;
        }

        return n ;
        
    }
};