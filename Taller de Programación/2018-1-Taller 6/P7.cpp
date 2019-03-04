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
#define invrep(i,n) for(int i=n;i--;)
#define repx(i,a,n) for(int i=a; i<(int)n;++i)
#define pb push_back
#define eb emplace_back

vi fence;

int paint(int i, int j){
    if(i==j) return 0;
    //cout<<"i: "<<i<<" j: "<<j<<endl;
    int out = 0;
    int m = 1e9;
    //cout<<"Min Search:"<<endl;
    repx(index, i, j){
        m = min(m, fence[index]);
    }

    //cout<<"Min = "<<m<<endl;
    if(m >= j-i){
        repx(index, i, j)
            fence[index] = 0;
        return j-i;
    }else{
        out += m;
        int temp_i = i;
        bool flag = (fence[i] != 0);
        repx(index, i, j){
            fence[index] -= m;
            //cout<<"Fence "<<index<<": "<<fence[index]<<" Flag: "<<flag<<endl;
            //cout<<"Temp: "<<temp_i<<endl;
            if(fence[index] == 0){
                if(flag){
                    //cout<<temp_i<<" "<<index<<endl;
                    out += paint(temp_i, index);
                    temp_i = index + 1;
                    flag = false;
                    if(index+1<j)
                        flag = (fence[index+1] != 0);
                }else{
                    if(index+1<j)
                        if(fence[index+1] == 0) continue;
                    //cout<<"Hola"<<endl;
                    temp_i = index + 1;
                    flag =  true;
                }
            }
        }
        return min(out + paint(temp_i, j), j-i);
    }
}

int main(){
    int n;
    cin>>n;

    fence.resize(n);
    rep(i,n)
        cin>>fence[i];

    cout<<paint(0, n)<<endl;
    return 0;
}