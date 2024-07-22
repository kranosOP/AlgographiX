#include <bits/stdc++.h>
using namespace std;
class DisjointSet{
    vector<int> parent,rank,size;
    public:
    DisjointSet(int n){
        rank.resize(n+1,0);
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }
    int findUpar(int node){
        if(node=parent[node]) return node;
        return parent[node]=findUpar(parent[node]);
    }
    void UnionByRank(int u,int v){
        int ulp_u=findUpar(u);
        int ulp_v=findUpar(v);
        if(ulp_u==ulp_v) return;
        else if(rank[ulp_u]<rank[ulp_v]){
            parent[ulp_u]=ulp_v;
        }
        else if(rank[ulp_u]>rank[ulp_v]){
            parent[ulp_v]=ulp_u;
        }
        else{
            parent[ulp_v]=ulp_u;
            rank[ulp_u]++;
        }
    }
    void UnionBySize(int u,int v){
         int ulp_u=findUpar(u);
        int ulp_v=findUpar(v);
        if(ulp_u==ulp_v) return;
        if(size[ulp_u]<size[ulp_v]){
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
        else{
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
    }
};


int main() 
{
   DisjointSet ds(7);
   ds.UnionByRank(1,2);
   ds.UnionByRank(3,4);
   if(ds.findUpar(3)==ds.findUpar(7)){
    cout<<"same";}
    else{
        cout<<"diff";
    }
    
    ds.UnionByRank(5,6);
    ds.UnionByRank(3,7);
   if(ds.findUpar(3)==ds.findUpar(7)){
    cout<<"same";}
    else{
        cout<<"diff";
    }

}