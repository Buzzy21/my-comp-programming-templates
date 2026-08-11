#include <bits/extc++.h>
using namespace std;
#define int long long
 
struct SegmentTree {
    int n; 
    vector<int> tree;
 
    SegmentTree(int n) {
        this->n = n;
        tree.resize(n*4,INT_MAX);
    }
 
    void update(int u, int tl, int tr, int index, int val) {
        if(tl==tr) {
            tree[u] = val;
            return;
        }
 
        int tm=(tl+tr)/2;
        if(index <= tm) update(u*2,tl,tm,index,val);
        else update(u*2+1,tm+1,tr,index,val);
        
        tree[u] = min(tree[u*2],tree[u*2+1]);
    }
    void update(int index, int val) {update(1,0,n-1,index,val);}
 
    int query(int u, int tl, int tr, int l, int r) {
        if(l>r) return INT_MAX;
        if(tl==l&&tr==r) return tree[u];
 
        int tm=(tl+tr)/2;
        return min(query(u*2,tl,tm,l,min(tm,r)),query(u*2+1,tm+1,tr,max(l,tm+1),r));
    }
    int query(int l, int r) {return query(1,0,n-1,l,r);}
};