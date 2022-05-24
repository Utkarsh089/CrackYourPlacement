// https://leetcode.com/problems/redundant-connection/

class Solution {
public:
    int find(vector<int> &parent, int v){
        if(v == parent[v]) return v;
        return parent[v] = find(parent, parent[v]);
    }
    
    bool Union(vector<int> &parent, int u, int v, vector<int> &ssize){
        u = find(parent, u);
        v = find(parent, v);
        if(u == v)
            return false;
        
        if(ssize[u] < ssize[v])
            swap(u, v);
        parent[v] = u;
        ssize[u] += ssize[v];
        return true;
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n+1), ssize(n+1);
        for(int i=1; i<=n; i++){
            parent[i] = i;
            ssize[i] = 1;
        }
        vector<int> ans;
        for(int i=0; i<n; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            if(!Union(parent, u, v, ssize)){
                ans.push_back(u);
                ans.push_back(v);
                break;
            }
        }
        return ans;
    }
};
