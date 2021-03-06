#include <bits/stdc++.h>

using namespace std;

#define int long long
#define vi vector<int>
#define vvi vector<vi>
#define vvvi vector<vvi>
#define ii pair<int,int>
#define vii vector<ii>
#define pqi priority_queue<int>
#define pqii priority_queue<ii>
#define all(arr) arr.begin(), arr.end()
#define si stack<int>
#define qi queue<int>
#define GET_MACRO(_1,_2,_3,NAME,...) NAME
#define rep(...) GET_MACRO(__VA_ARGS__, rep3, rep2, rep1)(__VA_ARGS__)
#define rep1(n) for (int i = 0; i < (n); i++)
#define rep2(i, n) for (int i = 0; i < (n); i++)
#define rep3(i, s, n) for (int i = (s); i < (n); i++)
#define repr(...) GET_MACRO(__VA_ARGS__, repr3, repr2, repr1)(__VA_ARGS__)
#define repr1(n) for (int i = (n)-1; i >= 0; i--)
#define repr2(i, n) for (int i = (n)-1; i >= 0; i--)
#define repr3(i, n, s) for (int i = (n)-1; i >= (s); i--)
#define x first
#define y second
#define pb push_back
#define eb emplace_back
#define chkmax(a,b) a=max(a,b)
#define chkmin(a,b) a=min(a,b)

const int INF = 1e18;

struct p2d{
    int x, y;
};

int cross(p2d a, p2d b){
    return a.x*b.y - a.y*b.x;
}

p2d operator-(p2d a, p2d b){
    return {a.x-b.x, a.y-b.y};
}

void solve(){
    p2d p1, p2, k1, k2;
    cin >> p1.x >> p1.y >> p2.x >> p2.y >> k1.x >> k1.y >> k2.x >> k2.y;
    p2d l1 = p2-p1, l2 = k2-k1;
    if(cross(l1,l2) == 0){
        if(cross(k1-p1, l1) == 0 && ((l1.x == 0 && !(min(k1.y, k2.y) > max(p1.y, p2.y) || min(p1.y, p2.y) > max(k1.y, k2.y)))||(l1.x != 0 &&!(min(k1.x, k2.x) > max(p1.x, p2.x) || min(p1.x, p2.x) > max(k1.x, k2.x))))){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
        return;
    }
    int iv = cross(k1-p1, l2);
    int jv = cross(k1-p1, l1);
    int v = cross(l1, l2);
    if(v < 0){
        v = -v;
        iv = -iv;
        jv = -jv;
    }
    // iv = iv/v;
    // jv = jv/v;
    if(iv >= 0 && iv <= v && jv >= 0 && jv <= v){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
    
}

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t=1;
    cin >> t;
    while(t--) solve();
    return 0;
}