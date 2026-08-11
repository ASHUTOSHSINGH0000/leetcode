class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int sum = nums[0] ;
        unordered_set<int> result ;
        for ( auto el : nums) result.insert(el);
        for ( int i = 1 ; i<nums.size() ; i++)
        {
            if ( nums[i]-1 == nums[i-1])
            {
                sum += nums[i];
            }
            else
            {
                break ;
            }
        }

        while( result.find(sum) != result.end())
        {
            sum++ ;
        }

        return sum ;
    }
};