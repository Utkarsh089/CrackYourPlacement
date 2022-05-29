// https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1/

class Solution {
  public:
    void dfs(vector<int> adj[], vector<bool> &visited, int x, vector<int> &ans){
        ans.push_back(x);
        visited[x] = true;
        
        for(int i=0; i<adj[x].size(); i++){
                int nbr = adj[x][i];
                if(!visited[nbr]){
                    dfs(adj, visited, nbr, ans);
                    visited[nbr] = true;
                }
        }
    }
    
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<bool> visited(V, false);
        vector<int> ans;
        dfs(adj, visited, 0, ans);
        return ans;
    }
};
