//https://www.codingninjas.com/codestudio/problems/prim-s-mst_1095633?topList=love-babbar-dsa-sheet-problems&leftPanelTab=1&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar 

#include<bits/stdc++.h>
#include<unordered_map>
#include<limits.h>
#include<list>
using namespace std;
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
   //making adg list
    unordered_map<int, list<pair<int,int>>>adg;
    for(int i=0; i<g.size(); i++){
        int u=g[i].first.first;
        int v=g[i].first.second;
        int w=g[i].second;
        adg[u].push_back(make_pair(v,w));
        adg[v].push_back(make_pair(u,w));
    }
    
    //initialize key,mst,parent
    vector<int>key(n+1);
    vector<bool>mst(n+1);
    vector<int>parent(n+1);
    for(int i=0 ;i<=n;i++){
        key[i]=INT_MAX;
        mst[i]=false;
        parent[i]=-1;
        
    }
    //for source key=0, parent=-1
    //let src be 1, src can be anything in prims
    key[1]=0;
    //in this qstn nodes start from 1 so that why we assume 1
    for(int i=1; i<n; i++){
        int mini=INT_MAX;
        int u;
        //n times finding minimum in key and processing
        for(int j=1; j<=n;j++){
          if(key[j]<mini && mst[j]==false){
              u=j;
              mini=key[j];
          }  
            
        }
        mst[u]=true;
        for(auto it:adg[u]){
            int v=it.first;
            int w=it.second;
            if(mst[v]==false && w<key[v]){
                key[v]=w;
                parent[v]=u;
            }
        }
    }
   //now retreiving answer from parent array;
   vector<pair<pair<int, int>, int>>result;
                         //starting from 2 becos 1 has its parent 1
   for(int i=2; i<=n;i++){
       result.push_back({{parent[i],i},key[i]});
   }
    return result;
}
