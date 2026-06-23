class Solution {
public:
    void  fun ( int open , int close , string & temp , vector<string>& res , int n )
    {
        if( open == n && close == n)
        {
            res.push_back(temp);
            return ;
        }

        if ( open < n)
        {
            temp.push_back('(');
            fun ( open + 1  ,  close , temp , res , n   );
            temp.pop_back();  

        }
        if ( close < open)
        {
            temp.push_back(')');
            fun ( open   ,  close + 1 , temp , res , n   );
            temp.pop_back();  

        }
        return ;
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res ;
        string temp ;
        fun ( 0 ,  0 , temp , res , n  );
        return res ;
    }
};