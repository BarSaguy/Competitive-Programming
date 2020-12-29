#include <bits/stdc++.h>

using namespace std;

#define int long long
#define vi vector<int>
#define vvi vector<vi>
#define vvvi vector<vvi>
#define ii pair<int,int>
#define vii vector<ii>
#define pqi priority_queue<int>
#define all(arr) arr.begin(), arr.end()
#define si stack<int>
#define qi queue<int>

const int INF = 1e18;

vector<string> a;
int c;
stringstream res;
int n, m;


void change_square2(int x, int y){
    if(a[x][y] == '1'){
        c++;
        res << x+1 << " " << y+1 << " ";
        res << x+1 << " " << y+1+1 << " ";
        a[x][y+1] = !(a[x][y+1] - '0') + '0';
        if(x < n-1){
            res << x+1+1 << " " << y+1+1 << " ";
            a[x+1][y+1] = !(a[x+1][y+1] - '0') + '0';
        }
        else
        {
            res << x-1+1 << " " << y+1+1 << " ";
            a[x-1][y+1] = !(a[x-1][y+1] - '0') + '0';
        }
        res << endl;
        a[x][y] = '0';
    }
}

void change_square(int x, int y){
    if(a[x][y] == '1'){
        c++;
        res << x+1 << " " << y+1 << " ";
        res << x+1+1 << " " << y+1 << " ";
        a[x+1][y] = !(a[x+1][y] - '0') + '0';
        if(y > 0){
            res << x+1+1 << " " << y-1+1 << " ";
            a[x+1][y-1] = !(a[x+1][y-1] - '0') + '0';
        }
        else
        {
            res << x+1+1 << " " << y+1+1 << " ";
            a[x+1][y+1] = !(a[x+1][y+1] - '0') + '0';
        }
        res << endl;
        a[x][y] = '0';
    }
}

void fix_last(int x, int y){
    vii one;
    vii zero;
    for(int i=x; i<x+2; i++){
        for(int j=y; j<y+2; j++){
            if(a[i][j] == '1')
                one.push_back({i, j});
            else
            {
                zero.push_back({i, j});
            }
        }
    }
    if(one.size() != 0) c++;
    if(one.size() == 3){
        for(int i=0; i<3; i++){
            res << one[i].first+1 << " " << one[i].second+1 << " ";
            a[one[i].first][one[i].second] = '0';
        }
        res << endl;
    }
    else if(one.size() == 2){
        res << one[0].first+1 << " " << one[0].second+1 << " ";
        res << zero[0].first+1 << " " << zero[0].second+1 << " ";
        res << zero[1].first+1 << " " << zero[1].second+1 << " ";
        a[one[0].first][one[0].second] = '0';
        a[zero[0].first][zero[0].second] = '1';
        a[zero[1].first][zero[1].second] = '1';
        res << endl;
        fix_last(x, y);
    }
    else if(one.size() == 4){
        for(int i=0; i<3; i++){
            res << one[i].first+1 << " " << one[i].second+1 << " ";
            a[one[i].first][one[i].second] = '0';
        }
        res << endl;
        fix_last(x, y);
    }
    else if(one.size() == 1){
        for(int i=0; i<2; i++){
            res << zero[i].first+1 << " " << zero[i].second+1 << " ";
            a[zero[i].first][zero[i].second] = '1';
        }
        res << one[0].first+1 << " " << one[0].second+1 << " ";
        a[one[0].first][one[0].second] = '0';
        res << endl;
        fix_last(x, y);
    }
}

void solve(){
    cin >> n >> m;
    a.clear();
    res.str("");
    c = 0;
    for(int i=0; i<n; i++){
        string t; cin >> t;
        a.push_back(t);
    }
    
    for(int i=0; i<n-2; i++){
        for(int j=0; j<m; j++){
            change_square(i, j);
        }
    }
    for(int j=0; j<m-2; j++){
        for(int i=n-2; i<n; i++){
            change_square2(i, j);
        }
    }
    //for(int j=0; j<m-2; j+=2){
    //    fix_last(n-2, j);
    //}
    fix_last(n-2, m-2);

    cout << c << endl;
    cout << res.str();
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    int t=1;
    cin >> t;
    for(int i=0; i<t; i++) solve();
    return 0;
}