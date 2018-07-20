#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

typedef long long ll;
typedef pair<ll, int> par;
typedef vector<int > vi;
typedef vector<ll > vll;
typedef vector<par > vp;
typedef vector<vi > graph;
                            
typedef vector<vp > wgraph;   

#define rep(i,n) for(int i=0; i<(int)n;++i)
#define pb push_back
#define eb emplace_back

#define print(x) copy(x.begin(), x.end(), ostream_iterator<int>(cout, "")), cout<<endl
#define debugv(v) //cerr<<#v<<":";for(auto e : v)cerr<<" "<<e;cerr<<endl
#define debugx(x) //cerr<<#x<<": "<<x<<endl
#define debugp(p) //cerr<<#p<<": ("<<p.first<<", "<<p.second<<")"<<endl
#define lg(x) (31 - __builtin_clz(x))
#define lgg(x) (63 - __builtin_clzll(x))

int main(){
    string s;
    while(cin>>s){
        string s1 = "";
        string currname = "";
        string curr = "";
        int flag = 0;
        rep(i, s.size()){
            char c = s[i];
            if(flag == 0){
                if(c == ' '){
                    flag++;
                    continue;
                }
                s1 += c;
            } else if(flag == 1){
                switch (c)
                {
                    case '*':
                    case '&':
                        flag++;
                        curr = c + curr;
                        continue;
                    case '[':
                        flag++;
                        curr = (c + s[++i]) + curr;
                        continue;
                }
                currname += c;
            } else if(flag == 2){
                if(c == ','){
                    flag--;
                    cout<<s1<<curr<<currname<<";\n";
                    i++;
                }else if(c == '['){
                    curr = (c + s[++i]) + curr; 
                }else{
                    curr = c + curr;
                }
            }
        }
        cout<<'\n';
    }
    return 0;
}