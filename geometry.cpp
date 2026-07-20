#include <bits/stdc++.h>
using namespace std;

int ori(const vector<pair<int,int>>& pts) {
    int val = 0;
    for(int i = 0; i < 3; i++) {
        val += pts[i].first * pts[(i+1)%3].second - pts[i].second * pts[(i+1)%3].first;
    }

    if(val>0) return 1;
    if(val==0) return 0;
    return -1;
}

bool onSeg(const pair<int,int>& a, const pair<int,int>& b, const pair<int,int>& c) {
    return min(a.first,b.first) <= c.first && c.first <= max(a.first,b.first) && 
    min(a.second,b.second) <= c.second && c.second <= max(a.second,b.second);
}

bool intersect(const vector<int>& A, const vector<int>& B) {
    pair<int,int> a1 = {A[0],A[1]}, a2 = {A[2],A[3]}, b1 = {B[0],B[1]}, b2 = {B[2],B[3]};

    int o1 = ori({a1,a2,b1}), o2 = ori({a1,a2,b2}), o3 = ori({b1,b2,a1}), o4 = ori({b1,b2,a2});
    if(o1!=o2&&o3!=o4) return true;

    if(o1==0 && onSeg(a1,a2,b1)) return true;
    if(o2==0 && onSeg(a1,a2,b2)) return true;
    if(o3==0 && onSeg(b1,b2,a1)) return true;
    if(o4==0 && onSeg(b1,b2,a2)) return true;

    return false;
}
