vector<int> bfsOfGraph(int V, vector<int> adj[]) {

        vector<int>ans;
        vector<int>isVisited(V+1,0);
        isVisited[0]=1;
        queue<int>q;
        q.push(0);
        ans.push_back(0);
        
        while(!q.empty()){
            int front = q.front();
            q.pop();
            ans.push_back(front);

            for(int itm:adj[front]){
                if(isVisited[itm]==0){
                q.push(itm);
                isVisited[itm]=1;
                }
            }
        }
        return ans;
    }