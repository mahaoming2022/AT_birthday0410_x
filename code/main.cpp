/*
AT_birthday0410_x Code by [da_ke](https://mahaoming2022.github.io)

Start coding: 2025/02/23

- 代码仓库：<https://github.com/mahaoming2022/AT_birthday0410_x>
- https://mahaoming2022.github.io/2025/02/23/AT-birthday0410-x-%E8%A7%A3%E9%A2%98%E6%8A%A5%E5%91%8A/
*/

#include <bits/stdc++.h>

#define i64 long long
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define fdn(i,r,l) for(int i=(r);i>=(l);i--)
#define pii pair<int,int>
using namespace std;

typedef long long ll;
typedef double db;
typedef __int128 i128;

std::mt19937 rnd(std::chrono::steady_clock::now().time_since_epoch().count());
std::mt19937_64 rnd64(std::chrono::steady_clock::now().time_since_epoch().count());

const int fyy=0;
const double PI=3.14169265358979323846;
const int Iloveufyy[]={1,1,1,-1,-1,-1,0,0}; // x
const int iLOVEUFYY[]={-1,0,1,-1,0,1,-1,1}; // y

int raw_H,raw_W;
vector<vector<char>> raw_S(66);

void denoise() // 降噪
{
    vector<vector<char>> raw_new(66);
    rep(i,1,raw_H){ 
        raw_new[i].resize(raw_W+1); 
        rep(j,1,raw_W)
        {
            int black=0,white=0;
            rep(_d,0,7)
            {
                int x=i,y=j;
                x+=Iloveufyy[_d],y+=iLOVEUFYY[_d];
                if(x<1||x>raw_H||y<1||y>raw_W) continue;
                if(raw_S[x][y]=='#') black++;
                else white++;
            }
            if(black>=white) raw_new[i][j]='#';
            else raw_new[i][j]='.';
        }
    }
    raw_S=raw_new;
}

void print_raw()
{
    rep(i,1,raw_H){rep(j,1,raw_W) cout<<raw_S[i][j];cout<<endl;}
}

struct character
{
    int H,W; // 长、宽
    vector<vector<bool>> S;
};

vector<character> L;

void bfs()
{
    vector<vector<bool>> vis(66,vector<bool>(raw_W+1,0));
    rep(i,1,raw_H) rep(j,1,raw_W) if(raw_S[i][j]=='#')
    {
        vector<pii> st;
        queue<pii> Q;
        Q.push({i,j});
        while(!Q.empty())
        {
            auto [x,y]=Q.front(); Q.pop();
            if(vis[x][y]) continue;
            vis[x][y]=1;
            st.push_back({x,y});
            rep(_d,0,7)
            {
                int xx=x,yy=y;
                xx+=Iloveufyy[_d],yy+=iLOVEUFYY[_d];
                if(xx<1||xx>raw_H||yy<1||yy>raw_W||raw_S[xx][yy]=='.') continue;
                Q.push({xx,yy});
            }
        }
        int _minx=114514119,_maxx=0,_miny=114514119,_maxy=0;
        // working...
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
#endif
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int testcase;
    cin>>testcase>>raw_W>>raw_H;
    rep(i,1,raw_H){raw_S[i].resize(raw_W+1); rep(j,1,raw_W) cin>>raw_S[i][j];} // 入力
    denoise(),denoise();
#ifndef ONLINE_JUDGE
    print_raw(); rep(i,1,10) cout<<endl;
#endif
}

// 路虽远行则将至，事虽难做则必成。
// 本当の本当に終わり