#include<iostream>
#include<vector>
#include<vector>
using namespace std;

void adjecencyMatrix(){
    int adj,edge;
    cout<<"Enter adj and edge"<<endl;
    cin>>adj>>edge;

    vector<vector<int>>G(adj+1,vector<int>(edge+1,0));

    for(int i=0;i<edge;i++){
        int n1,n2;
        cin>>n1>>n2;
        G[n1][n2]=1;
        G[n2][n1]=1;
    }

    for(auto arr:G){
        for(auto itm:arr){
            cout<<itm<<" ";
        }
        cout<<endl;
    }
}

void adjecencyList(){
    int adj,edge;
    cout<<"Enter adj and edge"<<endl;
    cin>>adj>>edge;

    vector<vector<pair<int , int>>>G(adj+1);

    for(int i=0;i<edge;i++){
        int n1,n2,w;
        cin>>n1>>n2>>w;
        G[n1].push_back({n2,w});
        G[n2].push_back({n1,w});
    }

    for(auto arr:G){
        for(auto itm:arr){
            cout<<"( "<<itm.first<<" , "<<itm.second<<" )";
        }
        cout<<endl;
    }
}

int main(){
    
    adjecencyList();
    return 0;
}