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
    bool fun ( TreeNode * root )
    {
        if ( root == NULL)
        {
            return true ;
        }

        queue< TreeNode *> q ;
        q.push(root);
        bool flag = false ;

        while ( !q.empty())
        {
            TreeNode * t = q.front();
            q.pop();

            if ( t == NULL)
            {
                flag = true ;
            }
            else {
                if ( flag == true )
                {
                    return false ;
                }
                else
                {
                    q.push(t->left );
                    q.push(t -> right );
                }
            }
        }
        return true ;
    }
    bool isCompleteTree(TreeNode* root) {
        return fun( root);
        
    }
};