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
    void fun(TreeNode* root, int targetSum ,   vector<vector<int>> & res , vector<int> &temp , int sum  )
    {
        if ( root == NULL)
        {
            return ;
        }
        temp.push_back(root->val) ;
        sum = sum + root ->val ;

        if ( root -> left == NULL && root -> right == NULL)
        {
            if ( sum == targetSum )
            {
                res.push_back(temp);
            }
        }

        if ( root->left != NULL)
        {
            fun ( root->left , targetSum , res , temp  , sum );
        }
        if ( root->right != NULL)
        {
            fun ( root->right , targetSum , res , temp  , sum );
        } 
        temp.pop_back();
        return ; 
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res ;
        vector<int> temp ;
        int sum = 0 ;
        fun ( root , targetSum , res , temp  , sum );
        return res ;
        
    }
};