#include <bits/stdc++.h>
using namespace std;
#define int long long
 
int N, q;
vector<int> v, segTree;
 
void build(int vertex, int tl, int tr) {
    if(tl == tr) {
        segTree[vertex] = v[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(vertex * 2, tl, tm);
        build(vertex * 2+1, tm+1, tr);
        segTree[vertex] = segTree[vertex*2] + segTree[vertex*2+1];
    }
    return;
}
 
int sum(int vertex, int tl, int tr, int l, int r) {
    if(l > r) return 0;
    if(tl == l && tr == r) {
        return segTree[vertex];
    }
 
    int tm = (tl + tr) / 2;
    return sum(vertex*2, tl, tm, l, min(r,tm)) 
    + sum(vertex*2+1, tm+1, tr, max(l,tm+1), r);
}
 
void update(int vertex, int tl, int tr, int index, int value) {
    if(tl == tr) {
        segTree[vertex] = value;
    }
    else {
        int tm = (tl + tr)/2;
        if(index <= tm) {
            update(vertex * 2, tl, tm, index, value);
        }
        else {
            update(vertex * 2 + 1, tm + 1, tr, index, value);
        }
        segTree[vertex] = segTree[vertex*2] + segTree[vertex*2+1];
    }
    return;
}
 
signed main() {
    cin >> N >> q;
    v.resize(N);
    segTree.resize(4*N);
    for(int i = 0; i < N; i++) cin >> v[i];
    build(1,0,N-1);
}
