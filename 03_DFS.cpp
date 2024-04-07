// Recursive solution
 void helper(int top , int V, vector<int>&isVisited, vector<int>adj[], vector<int>&ans){
        if(isVisited[top]!=0)return;
        ans.push_back(top);
        isVisited[top]=1;
        for(int itm:adj[top]){
            helper(itm,V,isVisited,adj,ans);
        }
    }
    
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
       vector<int>isVisited(V+1,0);
       vector<int>ans;
       helper(0,V,isVisited,adj,ans);
       return ans;
    }


// iterative solution

vector<int> dfsOfGraph(int V, vector<int> adj[]) {

        stack<int>st;
        vector<int>isVisited(V+1,0);
        vector<int>ans;
        st.push(0);
        isVisited[0]=1;
        
        while(!st.empty()){
            int top = st.top();
            st.pop();
            ans.push_back(top);
            
            for(auto itm:adj[top]){
                if(isVisited[itm]==0){
                    isVisited[itm]=1;
                    st.push(itm);
                }
            }
        }
        return ans;
    }