class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        bool atleastoneodd = false ;
        int smallestnum = INT_MAX ;
        for ( int i = 0  ; i < nums1.size() ; i++)
        {
            smallestnum = min ( smallestnum  , nums1[i]);
            if ( nums1[i] % 2 != 0 )
            {
                atleastoneodd = true ;
                
            }
        }

        if ( atleastoneodd == false )  return true ;

        if (smallestnum % 2 != 0 )
        {
            return true ;
        }
        
        return false ;
    }
};