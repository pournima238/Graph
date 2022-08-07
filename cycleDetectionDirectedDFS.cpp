#include<list>
#include<unordered_map>
#include<bits/stdc++.h>
using namespace std;

bool isDfsC( unordered_map<int,bool> &visited,unordered_map<int,bool>&dfsV,
          unordered_map<int, list<int>> &adg, int node ){
    visited[node]=1;
    dfsV[node]=1;
    for(auto i:adg[node]){
        if(!visited[i]){
            bool isCycle=isDfsC(visited,dfsV, adg,i);
            if(isCycle){
                return true;
            }
        }else{
            if(dfsV[i]==true){
                return true;
            }
        }
    }
    dfsV[node]=0;
    return false;
}


int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
//adjacency list
    unordered_map<int, list<int>> adg;
    for(int i=0; i<edges.size(); i++){
        int u=edges[i].first;
        int v=edges[i].second;
        
        adg[u].push_back(v);
    }
    unordered_map<int,bool> visited;
    unordered_map<int,bool>dfsV;
    for(int i=0; i<n; i++){
        if(!visited[i]){
            bool isCycle=isDfsC(visited, dfsV, adg, i);
            if(isCycle){
                return true;
            }
        }
    }
    return false;
}