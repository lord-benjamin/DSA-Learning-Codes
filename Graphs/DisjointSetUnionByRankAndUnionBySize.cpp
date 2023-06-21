#include<iostream>
#include<vector>
using namespace std;

class DisjointSet{
    vector<int> rank,size,parent;
public:
    DisjointSet(int n){
        rank.resize(n+1,0);
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i{0}; i<=n; ++i){
            parent[i] = i;
        }
    }
    int findUltParent(int node){
        if(node==parent[node]){
            return node;
        }
        return parent[node] = findUltParent(parent[node]); //path compression
    }
    void unionByRank(int u,int v){
        int ultP_u = findUltParent(u);
        int ultP_v = findUltParent(v);
        if(ultP_u == ultP_v){
            return;
        }
        if(rank[ultP_u] < rank[ultP_v]){
            parent[ultP_u] = ultP_v;
        }
        else if(rank[ultP_u] > rank[ultP_v]){
            parent[ultP_v] = ultP_u;
        }
        else{
            parent[ultP_v] = ultP_u;
            rank[ultP_u]++;
        }
    }
    void unionBySize(int u,int v){
        int ultP_u = findUltParent(u);
        int ultP_v = findUltParent(v);
        if(ultP_u == ultP_v){
            return;
        }
        if(size[ultP_u] < size[ultP_v]){
            parent[ultP_u] = ultP_v;
            ultP_v += size[ultP_u];
        }
        else{
            parent[ultP_v] = ultP_u;
            ultP_u += size[ultP_v];
        }
    }
};

int main()
{
    DisjointSet ds(7);
    ds.unionBySize(1,2);
    ds.unionBySize(2,3);
    ds.unionBySize(4,5);
    ds.unionBySize(6,7);
    ds.unionBySize(5,6);
    // check if 3 and 7 belong to the same parent or not
    if(ds.findUltParent(3) == ds.findUltParent(7)){
        cout << "Same\n";
    }
    else{
        cout << "Not Same\n"; 
    }
    ds.unionBySize(3,7);
    if(ds.findUltParent(3) == ds.findUltParent(7)){
        cout << "Same\n";
    }
    else{
        cout << "Not Same\n"; 
    }
    return 0;
}