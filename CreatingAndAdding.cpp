#include<bits/stdc++.h>
using namespace std;
class graph{
    public:
    unordered_map<int, list<int>> adg;
    void insertEdge(int u, int v, bool direction){
        //directed=1
        //undirected=0
        adg[u].push_back(v);
        if(direction==0){
            adg[v].push_back(u);
        }
    }

    void print(){
        for(auto i:adg){
            cout<<i.first<<"->";
            for(auto j:i.second){
                cout<<j<<",";
            }
            cout<<endl;
        }
    }

};

int main(){
    graph g;
    int n,m;
    cin>>n>>m;
    for(int i=0; i<m; i++){
        int u,v;
        cin>>u>>v;
        g.insertEdge(u,v,0);
    }
  g.print();
}