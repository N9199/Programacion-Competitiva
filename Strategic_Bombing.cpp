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
#define pb push_back
#define eb emplace_back

int MAX_SIZE = 26;

graph nodes(MAX_SIZE);
vi visited(MAX_SIZE);
vi low(MAX_SIZE);
vi num(MAX_SIZE);
int counter = 0;

void find_art(int v){
    visited[v]++;
    
}

int main(){
    string temp;
    cin>>temp;
    while(temp!="**"){
        nodes[temp.at(0)-'A'].pb(temp.at(1)-'A');
        nodes[temp.at(1)-'A'].pb(temp.at(0)-'A');
        cin>>temp;
    }
    
    return 0;
}