#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

typedef long long ll;
typedef pair<int, int> par;
typedef vector<vector<int> > graph;
                            
typedef vector<vector<par> > wgraph;   

#define rep(i,n) for(int i=0; i<(int)n;++i)
#define pb push_back

string ItoS(int n){
    string s = "";
    map<int, char> num;
    num[0]='Z';
    rep(i,26){
        num[i+1]='A'+i;
    }
    char temp;
    while(n!=0){
        temp = num[n%26];
        if (n%26!=0){
            n = (n-(n%26))/26;
        }else{
            n = n/26-1;
        }
        s = temp+s;
    } 
    return s;
}

int StoI(string s){
    int n = 0;
    map<char, int> num;
    rep(i,26){
        num['A'+i]=i+1;
    }
    rep(i,s.length()){
        n+=num[s.at(i)]*pow(26,s.length()-i-1);
    }
    return n;
}
int main(){
    int n;
    cin>>n;
    string s;
    rep(i,n){
        cin>>s;
        string s1="", s2="", s3="", s4="";
        int c = 0;
        //cout << s <<endl;
        rep(i,s.length()){
            if(c==0 && isalpha(s.at(i))){
                s1+=s.at(i);
            }else if(c==0){
                ++c;
            }
            if(c==1 && !(isalpha(s.at(i))) && isalnum(s.at(i))){
                s2+=s.at(i);
            }else if(c==1){
                ++c;
            }
            if(c==2 && isalpha(s.at(i))){
                s3+=s.at(i);
            }else if(c==2){
                ++c;
            }
            if(c==3 && !(isalpha(s.at(i))) && isalnum(s.at(i))){
                s4+=s.at(i);
            }else if(c==3){
                ++c;
            }
        }
        //cout << "S:" << s1 << s2 << s3 << s4 << endl;
        stringstream temp;
        if(s3==""){
            int n1;
            temp<<s2;
            temp>>n1;
            s = "R"+to_string(n1)+"C"+to_string(StoI(s1));
        }else{
            int n2;
            temp<<s4;
            temp>>n2;
            s = ItoS(n2)+s2;
        }
        cout << s << endl;
    }
    return 0;
}