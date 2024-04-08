int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int>isVisited(n,0);
        stack<int>st;
        int count=0;

        for(int i=0;i<n;i++){
            if(isVisited[i]==1)continue;
            st.push(i);
            isVisited[i]=1;

            while(!st.empty()){
                int top = st.top();
                st.pop();

                for(int j=0;j<n; j++){
                    if(isConnected[top][j]==1&&isVisited[j]==0){
                        isVisited[j]=1;
                        st.push(j);
                    }
                }
            }
            count++;
        }
        return count;
    }