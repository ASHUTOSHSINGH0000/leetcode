/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void fun (TreeNode* root  , vector<int> & temp )
    {
        if (root == NULL)
        {
            return ;
        }
        fun(root->left , temp);
        temp.push_back(root-> val);
        fun(root-> right , temp);
        return ;
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int > temp ;
        fun ( root , temp) ;
        int i = 0 ;
        int j = temp.size() -1 ;
        while ( i < j)
        {
            if ( temp[i] + temp[j] == k)
            {
                return true ;
            }
            if ( temp[i] + temp[j] > k)
            {
                j--;
            }
            if ( temp[i] + temp[j] < k)
            {
                i++ ;
            }
        }
        return false ;
    }
};