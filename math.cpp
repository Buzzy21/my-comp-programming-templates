#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MOD = 1e9+7;

vector<int> inv,fact;

void setup(int n) {
    inv.resize(n+1); fact.resize(n+1);
    inv[1] = 1; fact[1] = 1;
    
    for(int i = 2; i <= n; i++) fact[i] = fact[i-1]*i%MOD;
    for(int i = 2; i <= n; i++) inv[i] = MOD-MOD/i*inv[MOD%i]%MOD;
}

int binom(int n, int k) {
    return fact[n]*inv[fact[k]]%MOD*inv[fact[n-k]]%MOD;
}

int multinom(const vector<int>& a) {
    int sum = accumulate(a.begin(),a.end()), res = fact[sum];
    for(int k : a) res = res*inv[fact[k]];
    return res;
}

int exp(int b, int e) {
    int res = 1;
    while(e>0) {
        if(e%2==1) res = res*b%MOD;
        e/=2;
        b=b*b%MOD;
    }
    return res;
}