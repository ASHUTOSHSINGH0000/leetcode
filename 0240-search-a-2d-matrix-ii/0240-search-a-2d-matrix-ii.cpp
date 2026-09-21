class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        int srow = n-1 ;
        int erow = 0 ;
        int scol = 0 ;
        int ecol = m-1 ;


        while ( srow >= erow && scol <= ecol)
        {
            if ( matrix[srow][scol] == target )
            {
                return true ;
            }

            else if ( matrix[srow][scol] > target )
            {
                srow--;
            }
            else if ( matrix[srow][scol] < target )
            {
                scol++;
            }
        }
        return false;
        
    }
};