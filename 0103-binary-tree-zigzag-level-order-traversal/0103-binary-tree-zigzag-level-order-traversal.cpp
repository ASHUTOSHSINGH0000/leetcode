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
    void fun ( TreeNode * root ,  vector<vector<int>> &res  )
    {
        if ( root == NULL)
        {
            return ;
        }

        queue<TreeNode * > q ;
        q.push(root);
        int flag = 1 ;
        while ( !q.empty())
        {
            
            int lvlsize = q.size() ;
            vector<int> temp ; 
            while ( lvlsize--)
            {
                TreeNode* t = q.front();
                q.pop();
                temp.push_back( t->val);
                if ( t->left )
                {
                    q.push(t->left);
                }
                if( t->right)
                {
                    q.push( t->right);
                }
            }
            if ( !flag)
            {
                reverse( temp.begin() , temp.end());
            }
            flag = 1 - flag ;
            res.push_back(temp);
        }
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res ;
        fun (root , res  );
        return res ;
    }
};