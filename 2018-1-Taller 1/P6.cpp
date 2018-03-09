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

bool vowel(char c){
    return c=='a' or c=='e' or c=='i' or c=='o' or c=='u';
}

int main(){

    string S;
    hola:
    while(cin>>S){
        vi vowels(S.length()+1);
        rep(i,S.length()){
            if(vowel(S[i])){
                vowels[i+1] = vowels[i]+1;
            }
            else vowels[i+1]=vowels[i];
        }
        bool reversed = false;
        int init = 0;
        int fin = S.length();
        if(vowels[fin]==0){
            cout<<1<<endl;
            goto hola;
        }
        if(vowels[fin]==1){
            if(vowels[1]==1){
                cout<<fin<<endl;
            }
            else{
                cout<<0<<endl;
            }
            goto hola;
        }
        while(vowels[fin]-vowels[init]>1){
            if(!reversed){
                if(!vowel(S[init])){
                    cout<<0<<endl;
                    goto hola;
                }
                if(vowel(S[fin-1])){
                    init++;
                    reversed = true;
                    continue;
                }
                else{
                    fin--;
                    continue;
                }
            }
            else{
                if(!vowel(S[fin-1])){
                    cout<<0<<endl;
                    goto hola;
                }
                if(vowel(S[init])){
                    fin--;
                    reversed = false;
                    continue;
                }
                else{
                    init++;
                    continue;
                }
            }
        }
        cout<<fin-init<<endl;
    }
    return 0;
}