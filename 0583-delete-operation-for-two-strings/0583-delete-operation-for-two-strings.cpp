class Solution {
public:

    int t [501][501];

    int solve ( string word1, string word2 , int n , int m)
    {
        for ( int i = 0 ; i < n+1; i++)
        {
            for ( int j = 0 ; j < m+1 ; j++)
            {
                if ( i== 0 || j== 0)
                {
                    t[i][j] = 0 ;
                }
            }
        }


        for ( int i =1 ; i < n +1 ; i++)
        {
            for ( int j = 1 ; j < m +1 ; j++)
            {
                if ( word1[i-1] == word2[j-1])
                {
                    t[i][j] = 1 + t[i-1][j-1];
                }

                else
                {
                    t[i][j] = max ( t[i-1][j] , t[i][j-1]);
                }
            }
        }

        return t[n][m];
    }


    int minDistance(string word1, string word2) {
        int n1  = word1.size() ;
        int n2 = word2.size() ;
        int temp = solve ( word1 , word2 , n1 , n2 );

        return abs ( ( n1-temp) + ( n2-temp) );
        
    }
};