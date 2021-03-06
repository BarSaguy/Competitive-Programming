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

const int INF = 1e18;
const int MOD = 1e9+7;

// Mat = (4 1)
//       (1 2)


vi mat_mul(vi& a1, vi& a2){
    vi res(4);
    res[0] = (a1[0]*a2[0]%MOD + a1[1]*a2[2]%MOD)%MOD;
    res[1] = (a1[0]*a2[1]%MOD + a1[1]*a2[3]%MOD)%MOD;
    res[2] = (a1[2]*a2[0]%MOD + a1[3]*a2[2]%MOD)%MOD;
    res[3] = (a1[2]*a2[1]%MOD + a1[3]*a2[3]%MOD)%MOD;
    return res;
}


// 2x2 matrix
vi mat_pow(vi& mat, int p){
    if(p <= 1) return mat;
    vi m = mat_pow(mat, p/2);
    vi res = mat_mul(m, m);
    if(p&1) res = mat_mul(res, mat);
    return res;
}

void solve(){
    int n; cin >> n;

    if(n == 1){
        cout << 2 << endl;
        return;
    }
    vi mat = {4, 1, 1, 2};
    mat = mat_pow(mat, n-1);
    cout << (mat[0] + mat[1] + mat[2] + mat[3])%MOD<<endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t=1;
    cin >> t;
    while(t--) solve();
    return 0;
}
