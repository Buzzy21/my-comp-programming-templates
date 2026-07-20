#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> parent,sizes;
    DSU(int n) {
        parent.resize(n+1); sizes.resize(n+1,1);
        for(int i = 0; i < parent.size(); i++) parent[i] = i;
    }   
    
    int find(int u) {return u==parent[u]?u:parent[u]=find(parent[u]);}

    int unite(int u, int v) {
        u = find(u); v = find(v);
        if(u==v) return 0;

        if(sizes[u] > sizes[v]) swap(u,v); // u will < v
        sizes[v] += sizes[u];
        parent[u] = v;
    
        return 1;
    }
};