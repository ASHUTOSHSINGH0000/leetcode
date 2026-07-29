class Solution {
public:
    bool isCycle ( int src , vector<bool> &vis , vector<bool> &recpath , vector<vector<int>>&edge )
    {
        vis[src] = true ;
        recpath[src] = true ;

        for ( int i = 0 ; i < edge.size() ; i++)
        {
            int v = edge[i][0];
            int u = edge[i][1];

            if ( u == src )
            {
                if ( !vis[v])
                {
                    if (isCycle ( v , vis ,recpath , edge ) )
                    {
                        return true ;
                    }
                }
                else if ( recpath[v])
                {
                    return true ;
                }

            } 
        }
        recpath[src] = false ;
        return false ;
    }

    void topo ( int src , vector<bool> & vis , stack<int> &st , vector<vector<int>>&edge)
    {
        vis[src] = true ;

        for ( int i = 0 ; i<edge.size() ; i++)
        {
            int v = edge[i][0];
            int u = edge[i][1];

            if ( u == src )
            {
                if (!vis[v])
                {
                    topo( v , vis , st , edge  ) ;
                }
            }
        }

        st.push(src) ;
    }
    vector<int> findOrder(int n, vector<vector<int>>&edge ) {
        vector<bool> vis (n , false);
        vector<bool> recpath(n , false); 
        vector<int> ans ; 

        for ( int i = 0 ; i < n ; i++)
        {
            if ( !vis[i])
            {
                 if (isCycle ( i , vis ,recpath , edge ) )
                 {
                    return ans ;
                 }
            } 
        }

        stack<int> st ;
        vis.assign(n,false );

        for ( int i = 0 ; i< n ; i++)
        {
            if ( !vis[i])
            {
                topo(i , vis, st , edge );
            }
        }
        
        while ( st.size() > 0)
        {
            ans.push_back(st.top());
            st.pop();
        }

        return ans ;
    }
};