class Solution {
public:

    int tb[101][10001];

    int solve ( string s , string t , int n , int m )
    {
        for ( int i = 0 ; i < n +1 ; i++)
        {
            for ( int j = 0 ; j < m +1 ; j++)
            {
                if ( i ==0 || j == 0)
                {
                    tb[i][j] = 0 ;
                }
            }
        }


        for ( int i = 1 ; i < n +1 ; i++)
        {
            for ( int j =1 ; j < m+1 ; j++)
            {
                if ( s[i-1] == t[j-1])
                {
                    tb[i][j] = 1 + tb[i-1][j-1];
                }

                else
                {
                    tb[i][j] = max ( tb[i-1][j] , tb[i][j-1]);
                }
            }
        }
        return tb[n][m];
    }

    bool isSubsequence(string s, string t) {
        int n1 = s.size();
        int n2 = t.size();

        int temp  = solve ( s, t , n1, n2);

        if ( temp == n1)
        {
            return true ;
        }

        return false ;
        
    }
};