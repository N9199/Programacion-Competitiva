#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

typedef long long ll;
typedef pair<int, int> par;
typedef vector<int > vi;
typedef vector<par > vp;
typedef vector<vi > graph;
                            
typedef vector<vp > wgraph;   

#define rep(i,n) for(int i=0; i<(int)n;++i)
#define repx(i,x,n) for(int i=x; i<(int)n;++i)
#define invrep(i,n) for(int i=n;i--;)
#define pb push_back

int find(int arr[], int len, int seek)
{
    for (int i = 0; i < len; ++i)
    {
        if (arr[i] == seek) return i;
    }
    return -1;
}

int main(){
    int c[] = {1,10,100,1000,10000};
    int n,m;
    while(cin>>n>>m){
        graph g = graph(m,vi(n,-1));
        vi budget = vi(m,-1);
        ll sum = 0;
        rep(i,m){
            cin>>budget[i];
            rep(j,n){
                cin>>g[i][j];
            }
        }
        rep(i,m){
            int temp2 = 0;
            repx(k,1,n){
                temp2+=g[i][k];
            }
            invrep(j,5){
                if(c[j]+temp2<=budget[i]){
                    if(c[j]>=g[i][0]){
                        sum+=c[j]-g[i][0];
                    }else{
                        sum+=c[j];
                    }
                    break;
                }
            }
        }
        cout<<sum<<"\n";
    }
    return 0;
}