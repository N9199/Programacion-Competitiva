#include <bits/stdc++.h>
using namespace std;
#define debugx(x) cerr << #x << ": " << x << endl
#define rep(i, n) for (int i = 0; i < n; ++i)
#define eb emplace_back
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> par;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<vector<int>> graph;
typedef vector<char> vc;
typedef vector<vector<char>> cgraph;
typedef vector<vector<par>> wgraph;
char rotate(char c){
    if(c=='+' or c=='*') return c;
    if(c=='-') return '|';
    if(c=='|') return '-';
    if(c=='^') return '>';
    if(c=='>') return 'V';
    if(c=='V') return '<';
    if(c=='<') return '^';
    if(c=='L') return 'U';
    if(c=='U') return 'R';
    if(c=='R') return 'D';
    if(c=='D') return 'L';
    return 0;
}

void bfs(par start, vector<graph> &g, vvi &dist)
{
    queue<par> q;
    q.push(start);
    dist[start.first][start.second] = 0;
    while (not q.empty())
    {
        par u = q.front();
        q.pop();
        for (int v : g[u.first][u.second])
            if (dist[u.first][v] == 1e9)
            {
                dist[u.first][v] = dist[u.first][u.second] + 1;
                q.push({u.first,v});
            }
        if(dist[(u.first+1)%4][u.second]==1e9){
            dist[(u.first+1)%4][u.second] = dist[u.first][u.second] + 1;
            q.push({(u.first+1)%4,u.second});
        }
    }
}

int main()
{
    int n; int m;
    cin >> n >> m;
    vector<graph> g(4,graph(n*m));
    vector<cgraph> c(4,cgraph(n+1,vc(m+1,'*')));
    rep(row, n) rep(col, m)
    {
        cin >> c[0][row][col];
        c[1][row][col] = rotate(c[0][row][col]);
        c[2][row][col] = rotate(c[1][row][col]);
        c[3][row][col] = rotate(c[2][row][col]);
    }
    rep(i,4) rep(r,n) rep(q,m){
        if (c[i][r][q] == '+' or c[i][r][q] == '-' or c[i][r][q] == '>' or c[i][r][q] == 'L' or c[i][r][q] == 'U' or c[i][r][q] == 'D')
        {
            if (c[i][r][q + 1] == '+' or c[i][r][q + 1] == '-' or c[i][r][q + 1] == '<' or c[i][r][q + 1] == 'R' or c[i][r][q + 1] == 'U' or c[i][r][q + 1] =='D'){
                g[i][r*m + q].eb(r*m+q+1);
                g[i][r*m+q+1].eb(r*m+q);
            }
        }
        if (c[i][r][q] == '+' or c[i][r][q] == '|' or c[i][r][q] == 'V' or c[i][r][q] == 'L' or c[i][r][q] == 'R' or c[i][r][q] == 'U')
        {
            if (c[i][r + 1][q] == '+' or c[i][r + 1][q] == '|' or c[i][r + 1][q] == '^' or c[i][r + 1][q] == 'L' or c[i][r + 1][q] == 'R' or c[i][r + 1][q] == 'D'){
                g[i][r*m+q].eb(r*m+q+m);
                g[i][r*m+q+m].eb(r*m+q);
            }
        }
    }
    vvi dist(4,vi(n*m,1e9));
    int a,b,x,y;
    cin>>a>>b>>x>>y;
    a--;b--;x--;y--;
    bfs(make_pair(0,a*m + b),g,dist);
    int result = min(min(dist[0][x * m + y], dist[1][x * m + y]), min(dist[2][x * m + y], dist[3][x * m + y]));
    if(result == 1e9) cout<< -1 <<endl;
    else cout<<result<<endl;
}