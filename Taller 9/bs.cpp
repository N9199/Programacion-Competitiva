#include <bits/stdc++.h>
using namespace std;

int bs(vector<int>& sol, int a, int b, int c){
    int mid = (a+b)/2;
    if(a == b)
        return a;
    if(b==a+1){
        if(sol[b]>c) return a;
        else return b;
    }
    if(sol[mid] > c)
        return bs(sol,a,mid-1,c);
    else
        return bs(sol,mid,b,c);
}

int main()
{
    int N,Q;
    cin>>N;
    vector<int> sol(N);
    for(int i=0;i<N;++i)
        cin>>sol[i];
    sort(sol.begin(),sol.end());
    vector<int> sum(N+1);
    sum[0] = 0;
    for(int i=0;i<N;++i)
        sum[i+1] = sol[i] + sum[i];
    cin>>Q;
    for(;Q--;){
        int c;
        cin>>c;
        int x=bs(sol,0,N-1,c);
        if(sol[0]>c)
            cout<<"0 0"<<endl;
        else{
            cout<<x+1<<" "<<sum[x+1]<<endl;
        }
    }
    return 0;
}
