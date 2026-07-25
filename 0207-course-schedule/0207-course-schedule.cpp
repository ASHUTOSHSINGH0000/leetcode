class Solution {
public:

    bool isCylce ( int src , vector<bool> &vis , vector<bool> &rec , vector<vector<int>>& prerequisites)
    {
        vis[src] = true ;
        rec[src] = true ;
        for ( int i = 0 ; i< prerequisites.size() ; i++ )
        {
            int u =  prerequisites[i][1];
            int v =  prerequisites[i][0];
            if ( u == src)
            {
                if ( !vis[v])
                {
                    if ( isCylce (v ,vis ,rec  , prerequisites  ))
                    {
                        return true ;
                    }
                }
                else {
                    if ( rec[v])
                    {
                        return true ;
                    }
                }
            }
        }

        rec[src] = false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int V = numCourses ;
        vector<bool> vis(V ,false);
        vector<bool> rec(V ,false);

        for ( int i = 0 ; i< V ; i++)
        {
            if ( !vis[V])
            {
                if (isCylce ( i , vis , rec ,prerequisites ))
                {
                    return false ;
                }
            }
        }
        return true ;
    }
};