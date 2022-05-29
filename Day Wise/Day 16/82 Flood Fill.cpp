// https://leetcode.com/problems/flood-fill/

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
         int m = image.size();
         int n = image[0].size();
         int srcColor = image[sr][sc];
        
         vector<vector<bool>> vis(m, vector<bool> (n, false));
         dfs(sr, sc, m, n, srcColor, newColor, image, vis);
         return image;
    }
    
     void dfs(int r, int c, int m, int n, int srcColor, int newColor, vector<vector<int>>& image, vector<vector<bool>>&vis){
         if(r<0 || c<0 || r>=m || c>=n || image[r][c] != srcColor || vis[r][c])
            return;
         vis[r][c] = true;
         image[r][c] = newColor;
         dfs(r+1, c, m, n, srcColor, newColor, image, vis);
         dfs(r-1, c, m, n, srcColor, newColor, image, vis);
         dfs(r, c+1, m, n, srcColor, newColor, image, vis);
         dfs(r, c-1, m, n, srcColor, newColor, image, vis);
    }
};
