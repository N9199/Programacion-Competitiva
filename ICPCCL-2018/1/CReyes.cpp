#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<string> vs;
typedef vector<int> vi;
typedef vector<vi> vvi;

#define rep(i,n) for(int i=0;i<n;++i)
#define eb emplace_back


vi visited(26,-1);
vvi graph(26);
string result;
bool dfs(int node){
	if(visited[node]!= -1)
		return false;
	visited[node] = 0;
	for(int a: graph[node]){
		dfs(a);
	}
	result += 'a' + node;
	return false;
}

bool dfs2(int node){
	if(visited[node]!=0)
		return true;
	visited[node] = 1;
	for(int a: graph[node]){
		if(dfs2(a)) return true;
	}
	return false;
}

int main(){
	int n;
	cin>>n;
	string last;
	cin>> last;
	string current;
	rep(i,n-1){
		cin>> current;
		if(current.size() < last.size() && current == last.substr(0,current.size())){
			cout<<"Impossible"<<endl;
			return 0;
		}
		rep(j,min(current.size(),last.size())){
			if(current[j] == last[j])
				continue;
			if(find(graph[current[j]-'a'].begin(), graph[current[j]-'a'].end(),last[j]-'a') == graph[current[j]-'a'].end())
				graph[current[j]-'a'].eb(last[j]-'a');
			break;
		}
		last = current;
	}
	//rep(i,26) {for(int a: graph[i]) cout<<a<<" "; cout<<endl;}
	rep(i,26){
		visited = vi(26,0);
		if(dfs2(i)){
			cout<<"Impossible"<<endl;
			return 0;
		}
	}
	visited = vi(26,-1);
	rep(i,26){
		if(visited[i]==-1)
			dfs(i);
	}
	cout<<result<<endl;
}