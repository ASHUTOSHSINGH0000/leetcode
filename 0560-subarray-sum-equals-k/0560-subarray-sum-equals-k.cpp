class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        


        int n = nums.size();

        int count = 0 ;
        vector<int> prefixsum ( n , 0);

        prefixsum[0] = nums[0];

        for ( int i = 1 ; i< n ; i++)
        {
            prefixsum[i] = prefixsum[i-1] + nums[i];
        }


        unordered_map<int , int> mp ;

        for ( int i = 0 ; i < n ; i++)
        {
            if( prefixsum[i] == k)
            {
                count++ ;
            }

            int val = prefixsum[i] - k ;

            if( mp.find(val) != mp.end())
            {
                count += mp[val];
            }

            

            mp[prefixsum[i]] ++ ;
        }

        return count ;
    }
};


