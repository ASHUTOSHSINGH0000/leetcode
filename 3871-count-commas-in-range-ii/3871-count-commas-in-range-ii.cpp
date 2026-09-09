#define ll long long 
class Solution {
public:
    ll countCommas( ll n) {

        ll ans =0 ;
        ll th = 1000 ;

        while( th <= n )
        {
            ans += ( n-th + 1 );

            th *= 1000 ;
        }

        return ans ;
       
    }
};