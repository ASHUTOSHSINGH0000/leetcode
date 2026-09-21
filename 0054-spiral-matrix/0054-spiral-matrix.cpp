class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> ans ;
        int srow = 0 ;
        int erow = n-1 ;
        int scol = 0 ;
        int ecol = m-1 ;

        while ( srow <= erow && scol <= ecol )
        {
            // top 

            for ( int i = scol ; i<=ecol ; i++ )
            {
                ans.push_back(matrix[srow][i]);
            }

            // right 
            for ( int i = srow + 1 ; i <=erow ; i++)
            {
                ans.push_back( matrix[i][ecol]);
            }
            // bottom 
            for ( int i = ecol-1 ; i >= scol ; i--)
            {
                if ( srow == erow )
                {
                    break ;
                }
            
                ans.push_back( matrix[erow][i]);
            }
            //left
            for ( int i = erow -1  ; i >= srow + 1; i--)
            {
                if ( scol == ecol )
                {
                    break ;
                }
                
                ans.push_back( matrix[i][scol]);
            }
            scol++ ;
            srow++ ;
            erow-- ;
            ecol-- ;
        }
        return ans ;  
    }
};