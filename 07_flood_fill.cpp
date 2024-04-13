vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        int startColor = image[sr][sc];
        vector<vector<int>>isVisited(m , vector<int>(n,0));
        stack<pair<int,int>>st;
        isVisited[sr][sc] = 1;
        st.push({sr,sc});
        while(!st.empty()){
            auto top = st.top();
            st.pop();
            int row = top.first;
            int col = top.second;
            image[row][col] = color;

            int rows[] = {-1,0,1,0};
            int cols[] = {0,-1,0,1};

            for(int i=0;i<4;i++){
                if(row+rows[i]>=0&&row+rows[i]<m && col+cols[i]>=0&&col+cols[i]<n && isVisited[row+rows[i]][col+cols[i]]==0 && image[row+rows[i]][col+cols[i]]==startColor){
                    isVisited[row+rows[i]][col+cols[i]]=1;
                    st.push({row+rows[i] ,col+cols[i]});
                }
            }
        }
        return image;
    }