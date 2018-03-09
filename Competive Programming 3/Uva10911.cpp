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
#define repx(i,a,n) for(int i=a; i<(int)n;++i)
#define pb push_back
#define eb emplace_back

double dist(par a, par b){
    return sqrt((a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second));
}

double backtracking(vp points, double dmin, double current){
    if(points.size()==0)
        return current;
    cout << "points.size() " << points.size() << "\n";
    cout << "dmin: " << dmin << '\n';
    /*for( auto point : points){
        cout << "Point: " << point.first << "," << point.second << " ";
    }*/
    //cout << '\n';
    repx(i,1,points.size())
        rep(j,i){
            if(current + dist(points[i], points[j]) < dmin){
                cout << current << " " << dmin << " " << points[i].first << "," << points[i].second<< " " << points[j].first << "," << points[j].second << endl;
                if(points.size()>2){
                    vp temp = points;
                    double asdf = dist(points[i], points[j]);
                    vp::iterator it1 = find(temp.begin(), temp.end(), points[i]);
                    temp.erase(it1);
                    vp::iterator it2 = find(temp.begin(), temp.end(), points[j]);
                    temp.erase(it2);
                    asdf = backtracking(temp, dmin, current + asdf);
                    //cout << "dmin: " << dmin << " asdf: " << asdf << endl;
                    dmin = min(dmin, current + asdf);
                }else{
                    dmin = current + dist(points[i], points[j]);
                }
            }
        }
    //cout << "dmin: " << dmin << " current: " << current << endl;
    return dmin;
}

int main(){
    int n;
    cin>>n;
    while(n!=0){
        vp points;
        int a,b;
        string trash;
        rep(i,2*n){
            cin>>trash>>a>>b;
            points.eb(a,b);
        }
        cout<<backtracking(points, 1e9, 0)<<'\n';
        cin>>n;
    }
    return 0;
}