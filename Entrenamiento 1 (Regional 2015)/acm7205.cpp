#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define repx(i,x,n) for(int i=x;i<n;++i)
using namespace std;
typedef long long intt;
typedef vector<int> vi;
typedef pair<intt,intt> par;
typedef vector<vi> graph;
typedef vector<par> wgraph;

intt inline area(par A, par B, par C){
    return abs((A.first-C.first)*(B.second-A.second) - (A.first - B.first)*(C.second - A.second));
}

int main(){
    int n;
    while(cin>>n){
        wgraph vert(n);
        rep(i,n) cin>>vert[i].first>>vert[i].second;
        intt total = 0l;
        repx(i,1,n-1) total += area(vert[0],vert[i],vert[i+1]);
        intt local = 0;
        int i=0;
        int j=1;
        intt optimum = 0;
        while(i < n){
            while(total - local > local){
                j++;
                j%=n;
                if(j!=0)
                    local+=area(vert[i],vert[j-1],vert[j]);
                else
                    local+=area(vert[i],vert[n-1],vert[0]);
            }
            intt prev=0;
            if(j!=0)
                prev = local - area(vert[i],vert[j-1],vert[j]);
            else
                prev = local - area(vert[i],vert[n-1],vert[0]);
            optimum = max(optimum,min(local,total-prev));
            if(i<n-1)
                local -= area(vert[i],vert[i+1],vert[j]);
            /*else
                local -= area(vert[n-1],vert[0],vert[j]); redundant*/
            i++;

        }
        cout<<optimum<<" "<<total-optimum<<endl;
    }
}