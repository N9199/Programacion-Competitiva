#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

typedef long long ll;
typedef pair<int, int> par;
typedef tuple<int, int, int> iii;
typedef tuple<int, int, int, double> iiii;
typedef vector<int > vi;
typedef vector<double > vd;
typedef vector<iii > viii;
typedef vector<iiii > viiii;
typedef vector<vi > graph;
                            
typedef vector<viii > wgraph;   

#define rep(i,n) for(int i=0; i<(int)n;++i)
#define repx(i,x,n) for(int i=x; i<(int)n;++i)
#define invrep(i,n) for(int i=n;i--;)
#define pb push_back
#define ep emplace_back

wgraph offices;
vd tax;
bool cmp(iiii a, iiii b) {return get<1>(a)*get<3>(a)+get<2>(a) > get<1>(b)*get<3>(b)+get<2>(b);}

double dist(double t, int start){
    priority_queue<iiii, viiii, function<bool(iiii,iiii)>> q(cmp);
    tax[start] = 0;
    q.emplace(start,0,0,t);
    while(!q.empty()){
        iiii u = q.top();
        q.pop();
        double priority = get<1>(u)*t+get<2>(u);
        if (priority!=tax[get<0>(u)])
            continue;
        for(auto n : offices[get<0>(u)]){
            double w = get<1>(n)*t+get<2>(n);
            if (tax[get<0>(u)] + w < tax[get<0>(n)] or tax[get<0>(n)] < -0.5){
                tax[get<0>(n)] = tax[get<0>(u)] + w;
                q.emplace(get<0>(n),get<1>(n),get<2>(n),t);
            }
        }
    }
    return tax[tax.size()-1];
}

int main(){
    cout.setf(ios::fixed); cout.precision(5); 
    int n,m;
    while(cin>>n>>m){
        offices = wgraph(n);
        int i,j,a,b;
        rep(asdfghjkl,m){
            cin>>i>>j>>a>>b;
            offices[i-1].ep(j-1,a,b);
            offices[j-1].ep(i-1,a,b);
            //cout<<i-1<<" "<<j-1<<" "<<a<<" "<<b<<endl;
        }
        int iterations = 60;
        double right = 0, left = 24*60;
        double leftThird,rightThird,dist1,dist2;
        rep(i,iterations){
            //cout<<right<<" "<<left<<endl;
            leftThird = left + (right-left)/3.0;
            rightThird = right + (left-right)/3.0;
            tax = vd(n,-1);
            dist1 = dist(leftThird,0);
            tax = vd(n,-1);
            dist2 = dist(rightThird,0);
            if (dist1<dist2)
                left = leftThird;
            else
                right = rightThird;
        }
        cout<<dist((left+right)/2,0)<<"\n";
    }
    return 0;
}