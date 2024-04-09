 int orangesRotting(vector<vector<int>>& grid) {
      queue<pair<pair<int,int>,int>>q;
      int m = grid.size();
      int n = grid[0].size();
      vector<vector<int>>isVisited(m,vector<int>(n,0));

      for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==2){
                q.push({{i,j},0});
                isVisited[i][j]=2;
            }
        }
      }
      
      int count =0;
      while(!q.empty()){
        auto front = q.front();
        q.pop();

        int i = front.first.first;
        int j = front.first.second;
         count = front.second;
        // ans = max(ans,count);

        if(i-1>=0&& grid[i-1][j]==1&&isVisited[i-1][j]==0){
            q.push({{i-1,j},count+1});
            isVisited[i-1][j]=2;
        }
        if(j-1>=0&& grid[i][j-1]==1&&isVisited[i][j-1]==0){
            q.push({{i,j-1},count+1});
            isVisited[i][j-1]=2;
        }
        if(i+1<m&& grid[i+1][j]==1&&isVisited[i+1][j]==0){
            q.push({{i+1,j},count+1});
            isVisited[i+1][j]=2;
        }
        if(j+1<n&& grid[i][j+1]==1&&isVisited[i][j+1]==0){
            q.push({{i,j+1},count+1});
            isVisited[i][j+1]=2;
        }
      }

      for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==1&&isVisited[i][j]!=2)return -1;
        }
      }

      return count;
    }