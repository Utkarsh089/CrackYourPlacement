// https://leetcode.com/problems/sum-of-distances-in-tree/
// https://youtu.be/gmEsErNo84g

class Solution {
public:
    int ansat0 = 0;
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        
        for(int i=0; i<n-1; i++){                  
            int u = edges[i][0];
            int v = edges[i][1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        
        vector<int> count(n);
        postorder(0, -1, 0, count, graph);
        
        // for(int i=0; i<n; i++){
        //     cout<<count[i]<<" ";
        // }
        
        vector<int> ans(n);
        ans[0] = ansat0;
        preorder(0, -1, ans, count, graph);
        return ans;
        
    }
    
    int postorder(int root, int prev, int level, vector<int> &count, vector<vector<int>> &graph){
        for(int i=0; i<graph[root].size(); ++i){
            int x = graph[root][i];
            if(x != prev)
                count[root] += postorder(x, root, level+1, count, graph);
        }
        count[root]++;
        ansat0 += level; 
        
        return count[root];
    }
    
    void preorder(int root, int prev, vector<int> &ans, vector<int> &count, vector<vector<int>> &graph){
        
        for(int i=0; i<graph[root].size(); ++i){
            int x = graph[root][i];
            if(x != prev){
                ans[x] = ans[root] - count[x] + (count.size()-count[x]);
                // cout<<endl<<ans[x]<<" "<<x;
                preorder(x, root, ans, count, graph);
            }
        }
    }
    
};
