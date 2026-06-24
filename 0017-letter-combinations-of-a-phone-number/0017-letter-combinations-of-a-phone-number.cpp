class Solution {
public:
    vector<string> res ;
    void solve ( int idx , string &temp , string &digits,  unordered_map< char , string> mp ) 
    {
        if ( idx == digits.size())
        {
            res.push_back( temp);
            return ;
        }

        char ch = digits[idx];
        string num = mp[ch];

        for ( int i = 0 ; i < num.size() ; i++)
        {
            temp.push_back(num[i]);
            solve( idx+1 , temp , digits , mp);
            temp.pop_back() ;
        }

    }
    vector<string> letterCombinations(string digits) {
        unordered_map< char , string> mp ;

        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";

        string temp = "";
        solve (  0 ,temp , digits , mp );

        return res ;
        
    }
};