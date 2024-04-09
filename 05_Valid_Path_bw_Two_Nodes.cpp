bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int>adj[n];
        for(auto itm:edges){
            adj[itm[0]].push_back(itm[1]);
            adj[itm[1]].push_back(itm[0]);
        }
        vector<int>isVisited(n,0);
        stack<int>st;
        st.push(source);
        isVisited[source]=1;
        while(!st.empty()){
            int t = st.top();
            st.pop();
            for(int itm:adj[t]){
                if(isVisited[itm]==0){
                    isVisited[itm]=1;
                    st.push(itm);
                }
            }
        }
        return isVisited[destination];
    }