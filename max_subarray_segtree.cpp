#include <bits/stdc++.h>
using namespace std;

struct Node {
    int leftVal,rightVal,mxVal,sumVal;
};
 
struct SegmentTree {
    int n; 
    vector<int> left,mx,right,sum;
 
    void build(int u, int tl, int tr, const vector<int>&a) {
        if(tl==tr) {
            left[u] = mx[u] = right[u] = max(0ll,a[tl]);
            sum[u] = a[tl];
            return;
        }
 
        int tm=(tl+tr)/2;
        build(u*2,tl,tm,a);
        build(u*2+1,tm+1,tr,a);
 
        sum[u] = sum[u*2]+sum[u*2+1];
        left[u] = max(left[u*2],sum[u*2]+left[u*2+1]);
        right[u] = max(right[u*2+1],sum[u*2+1]+right[u*2]);
        mx[u] = max({mx[u*2],mx[u*2+1],left[u],right[u],right[u*2]+left[u*2+1]});
    }
 
    Node query(int u, int tl, int tr, int l, int r) {
        if(l>r) return {0,0,0,0};
        if(tl==l&&tr==r) return {left[u],right[u],mx[u],sum[u]};
        int tm=(tl+tr)/2;
        Node leftInfo = query(u*2,tl,tm,l,min(tm,r)), rightInfo = query(u*2+1,tm+1,tr,max(l,tm+1),r);
 
        Node curr;
        curr.leftVal = max(leftInfo.leftVal,leftInfo.sumVal+rightInfo.leftVal); 
        curr.rightVal = max(rightInfo.rightVal,rightInfo.sumVal+leftInfo.rightVal);
 
        curr.mxVal = max({leftInfo.mxVal,rightInfo.mxVal,curr.leftVal,curr.rightVal,leftInfo.rightVal+rightInfo.leftVal});
        curr.sumVal = leftInfo.sumVal+rightInfo.sumVal;
 
        return curr;
    }
    int query(int l, int r) {return query(1,0,n-1,l,r).mxVal;}
    
    SegmentTree(int n, const vector<int>& a) {
        this->n = n;
        left.resize(n*4,0); mx = right = sum = left;
        build(1,0,n-1,a);
    }
};