// https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1#

class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        queue<int> q;
        vector<bool> visited(V, false);
        vector<int> ans;
        q.push(0);
        visited[0] = true;
        
        while(!q.empty()){
            int x = q.front();
            q.pop();
            
            for(int i=0; i<adj[x].size(); i++){
                int nbr = adj[x][i];
                if(!visited[nbr]){
                    q.push(nbr);
                    visited[nbr] = true;
                }
            }
            
            ans.push_back(x);
        }
        return ans;
    }
};
