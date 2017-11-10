#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

typedef long long ll;
typedef pair<double, int> par;
typedef vector<int > vi;
typedef vector<double > vd;
typedef vector<par > vii;
typedef vector<vi > graph;
                            
typedef vector<vii > wgraph;   

#define rep(i,n) for(int i=0; i<(int)n;++i)
#define repx(i,x,n) for(int i=x; i<(int)n;++i)
#define invrep(i,n) for(int i=n;i--;)
#define pb push_back
#define ep emplace_back
#define MAXSIZE 1000

int n,m;
int A[MAXSIZE][MAXSIZE];
int B[MAXSIZE][MAXSIZE];

graph g;
double tax[MAXSIZE];

double get_tax(double t){
    rep(i,n) tax[i] = -1.0;
    priority_queue<par, vii, greater<par> > q;
    q.emplace(0,0);
    tax[0] = 0;
    while(!q.empty()){
        //rep(i,n) cout<<tax[i]<<" ";
        //cout<<"\n";
        par u = q.top(); q.pop();
        double ctax = u.first;
        if(ctax > tax[u.second])
            continue;
        if(u.second==n-1)
            break;
        for(int v : g[u.second]){
            double w = A[u.second][v]*t+B[u.second][v];
            if(tax[u.second] + w < tax[v] or tax[v] < -0.5){
                tax[v] = tax[u.second] + w;
                q.emplace(tax[v], v);
            }
        }
    }
    return tax[n-1];
}

int main(){
    cout.setf(ios::fixed); cout.precision(5); 
    while(cin>>n>>m){
        g = graph(n);
        int i,j,a,b;
        rep(asdfghjkl,m){
            cin>>i>>j>>a>>b;
            g[i-1].pb(j-1);
            g[j-1].pb(i-1);
            A[j-1][i-1] = a;
            A[i-1][j-1] = a;
            B[j-1][i-1] = b;
            B[i-1][j-1] = b;
        }
        int iterations = 60;
        double right = 0, left = 24*60;
        double leftThird,rightThird,dist1,dist2;
        rep(i,iterations){
            //cout<<right<<" "<<left<<endl;
            leftThird = left + (right-left)/3.0;
            rightThird = right + (left-right)/3.0;
            dist1 = get_tax(leftThird);
            dist2 = get_tax(rightThird);
            if (dist1<dist2)
                left = leftThird;
            else
                right = rightThird;
        }
        cout<<(dist1+dist2)*0.5<<"\n";
    }
    return 0;
}