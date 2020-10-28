#include <bits/stdc++.h>

using namespace std;

#define int long long
#define vi vector<int>
#define vvi vector<vi>
#define ii pair<int,int>
vi g1, g2;
vi t1, t2;

void query(){
    cout << g1.size() << " " << g2.size() << " ";
    for(int i=0; i<g1.size();i++){
        cout << g1[i] << " ";
    }
    for(int i=0; i<g2.size();i++){
        if(i == g2.size()-1)
            cout << g2[i] << endl;
        else
        {
            cout << g2[i] << " ";
        }
        
    }
    //cout.flush();
}

void solve(){
    int n; cin >> n;
    int ans = 0, c;
    g1.clear();
    g2.clear();
    for(int i=0; i<n; i++){
        if(i%2 == 0)
            g1.push_back(i+1);
        else
            g2.push_back(i+1);
    }
    query();
    cin >> c;
    ans = max(ans, c);
    int itr = 8;
    while(itr--){
        t1.clear();
        t2.clear();
        for(int i=0; i<g1.size();i++){
            if(i%2==0)
                t1.push_back(g1[i]);
            else
                t2.push_back(g1[i]);
        }
        for(int i=0; i<g2.size();i++){
            if(i%2==0)
                t1.push_back(g2[i]);
            else
                t2.push_back(g2[i]);
        }
        if(t1.size() == 0 || t2.size() == 0)
            break;
        g1.clear();
        g2.clear();
        for(int i=0; i<t1.size();i++)
            g1.push_back(t1[i]);
        for(int i=0; i<t2.size();i++)
            g2.push_back(t2[i]);
        query();
        cin >> c;
        ans = max(ans, c);
    }
    cout << -1 << " " << ans << endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    int t; cin >> t;
    for(int i=0; i<t; i++) solve();
    return 0;
}