#include<bits/stdc++.h>
using namespace std;
void dfs( unordered_map<int,bool>&visited,  unordered_map<int,list<int>>&adg,vector<int>&component, int node){
    component.push_back(node);
    visited[node]=1;
    for(auto i:adg[node]){
        if(!visited[i]){
            dfs(visited, adg, component,i);
        }
    }
}


vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
  vector<vector<int>>ans;
  unordered_map<int,list<int>>adg;
  unordered_map<int,bool>visited;
  for(int i=0; i<E; i++){
      int u=edges[i][0];
      int v=edges[i][1];
      adg[u].push_back(v);
      adg[v].push_back(u);
  }
  for(int i=0; i<V; i++){
      if(!visited[i]){
          vector<int>component;
          dfs(visited,adg,component,i);
          ans.push_back(component);
      }
  }
    return ans;
}