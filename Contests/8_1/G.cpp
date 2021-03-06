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

const int INF = 1e18;

struct pos{
    int x, y, z;
    pos(){

    }
    pos(int x1, int y1, int z1){
        x=x1;y=y1;z=z1;
    }
    void copy(const pos& other){
        x=other.x;
        y=other.y;
        z=other.z;
    }

    bool operator!=(const pos& other){
        return !(x==other.x && y==other.y && z==other.z);
    }
    bool operator==(const pos& other){
        return x==other.x && y==other.y && z==other.z;
    }
    void print(){
        cout << "("<< x <<" "<<y<<" "<<z<<")";
    }
};


pos p1;
pos p2;
pos end1;
pos end2;

int xd1, yd1, zd1;
int xd2, yd2, zd2;

bool last = false;

// void move1(){
//     if(xd1 > 0 && !z_f){
//         if(p2 == pos(p1.x+1, p1.y, p1.z) && p2 == end2){
//             p1.y++;
//         }
//         else{
//             p1.x++;
//         }
//     }
//     else if(xd1 < 0 && !z_f){
//         if(p2 == pos(p1.x-1, p1.y, p1.z) && p2 == end2){
//             p1.y++;
//         }
//         else{
//             p1.x--;
//         }
//     }
//     else if(yd1 > 0){
//         if(p2 == pos(p1.x, p1.y+1, p1.z) && p2 == end2){
//             p1.z++;
//         }
//         else{
//             p1.y++;
//         }
//     }
//     else if(yd1 < 0){
//         if(p2 == pos(p1.x, p1.y-1, p1.z) && p2 == end2){
//             p1.z++;
//         }
//         else{
//             p1.y--;
//         }
//     }
//     else if(zd1 > 0){
//         if(p2 == pos(p1.x, p1.y, p1.z+1) && p2 == end2){
//             p1.x++;
//             z_f=true;
//         }
//         else{
//             p1.z++;
//             z_f=false;
//         }
//     }
//     else if(zd1 < 0){
//         if(p2 == pos(p1.x, p1.y, p1.z-1) && p2 == end2){
//             p1.x++;
//             z_f=true;
//         }
//         else{
//             p1.z--;
//             z_f=false;
//         }
//     }
// }

void move1(){
    if(xd1 != 0){
        p1.x += abs(xd1)/xd1;
    }
    else if(yd1 != 0){
        last = true;
        p1.y += abs(yd1)/yd1;
    }
    else if(zd1 != 0){
        last = false;
        p1.z += abs(zd1)/zd1;
    }
}

void move2(){
    if(xd2 != 0){
        p2.x += abs(xd2)/xd2;
    }
    else if(yd2 != 0){
        //last = true;
        p2.y += abs(yd2)/yd2;
    }
    else if(zd2 != 0){
        //last = false;
        p2.z += abs(zd2)/zd2;
    }
}


void away(){
    int add=1;
    while(add--){
        if(last){
            if(zd2 == 0) p2.z++;
            else p2.z += abs(zd2)/zd2;
        }
        else{
            if(yd2 == 0) p2.y++;
            else p2.y += abs(yd2)/yd2;
        }
        p1.print();
        cout <<" ";
        p2.print();
        cout << endl;
    }
}

void solve(){
    int x0, y0, z0, x1, y1, z1; cin >> x0 >> y0 >> z0 >> x1 >> y1 >> z1;
    int a0, b0, c0, a1, b1, c1; cin >> a0 >> b0 >> c0 >> a1 >> b1 >> c1;
    p1.copy(pos(x0,y0,z0)); end1.copy(pos(x1,y1,z1));
    p2.copy(pos(a0,b0,c0)); end2.copy(pos(a1,b1,c1));
    p1.print();
    cout <<" ";
    p2.print();
    cout << endl;
    while(p1 != end1 || p2 != end2){
        xd1=end1.x-p1.x; yd1=end1.y-p1.y; zd1=end1.z-p1.z;
        move1();
        if(p1  == p2){
            away();
        }
        xd2=end2.x-p2.x; yd2=end2.y-p2.y; zd2=end2.z-p2.z;
        move2();
        if(p2 == p1){
            away();
        }
        else{
            p1.print();
            cout <<" ";
            p2.print();
            cout << endl;
        }
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t=1;
    //cin >> t;
    while(t--) solve();
    return 0;
}