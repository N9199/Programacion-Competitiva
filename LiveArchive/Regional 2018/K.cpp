#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;

typedef vector<vi> graph;
typedef vector<vll> vvll;

#define rep(i, n) for (int i = 0; i < n; i++)
#define repx(i, a, b) for (int i = a; i < (int)b; i++)
#define invrep(i, a, b) for (int i = b; i-- > (int)a;)

#define eb emplace_back

vector<int> sol_neg(18);
vector<int> sol_pos(18);
vector<vector<int>> solution;
int n;
int index_neg = 0;
int index_pos = 0;

void dfs(map<int,int>& S, int last_checked){
    if(S.size() == 1){
        solution.eb(n);
        rep(i,index_neg){
            solution.back()[i] = sol_neg[index_neg - i - 1];
        }
        rep(i,index_pos){
            solution.back()[i + index_neg] = sol_pos[i];
        }
        return;
    }
    //Some prunning
    auto m_it = S.begin();
    auto M_it = S.rbegin();
    int min1 = m_it->first;
    int min2 = (m_it->second == 1)? (++m_it)->first : min1;
    int max1 = M_it->first;
    int max2 = (M_it->second == 1)? (++M_it)->first : max1;
    int dif = max1 - max2;
    if(dif != min2 - min1) return;
    if(dif < abs(last_checked)) return;
    if(S.find(max1 + min1) == S.end()) return;
    if(S.find(0) == S.end()) return;
    if(dif == 0){
        map<int,int> newS;
        for(auto it = S.begin(); it != S.end(); ++it){
            newS[it->first] = it->second/2;
        }
        sol_pos[index_pos++] = 0;
        dfs(newS, 0);
        index_pos--;
        return;
    }
    if(((last_checked >= 0) || (dif > -last_checked)) && (S.find(dif) != S.end())){
        map<int,int> newS;
        for(auto it = S.rbegin(); it != S.rend(); ++it){
            auto it_2 = S.find(it->first - dif);
            auto it_used = newS.find(it->first);
            if(it_used != newS.end()){
                if(it->second == it_used->second) continue;
                if((it_2 == S.end()) || (it->second - it_used->second > it_2->second)) return;
                newS[it_2->first] = it->second - it_used->second;
            }
            else{
                if((it_2 == S.end()) || (it->second > it_2->second)) return;
                newS[it_2->first] = it->second;
            }
        }
        sol_pos[index_pos++] = dif;
        dfs(newS, dif);
        index_pos--;
    }
    if(S.find(-dif) != S.end()){
        map<int,int> newS;
        for(auto it = S.begin(); it != S.end(); ++it){
            auto it_2 = S.find(it->first + dif);
            auto it_used = newS.find(it->first);
            if(it_used != newS.end()){
                if(it->second == it_used->second) continue;
                if((it_2 == S.end()) || (it->second - it_used->second > it_2->second)) return;
                newS[it_2->first] = it->second - it_used->second;
            }
            else{
                if((it_2 == S.end()) || (it->second > it_2->second)) return;
                newS[it_2->first] = it->second;
            }
        }
        sol_neg[index_neg++] = -dif;
        dfs(newS, -dif);
        index_neg--;
    }
}


int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> n;
    map<int,int> S;
    rep(i,1<<n){
        int x;
        cin >> x;
        auto it = S.find(x);
        if(it != S.end())
            it->second++;
        else
            S[x] = 1;
    }
    dfs(S,0);

    sort(solution.begin(),solution.end(),[](const vector<int>& A, const vector<int>& B) -> bool{
        rep(i,n){
            if(A[i] != B[i]) return A[i] < B[i];
        }
        return false;
    });
    rep(i,solution.size()){
        //just because
        bool same = false;
        if(i != 0) rep(j,n+1){
            if(j == n) {same = true; break;}
            if(solution[i-1][j] != solution[i][j]) break;
        }
        if(same) continue;
        rep(j,n-1) cout << solution[i][j] << ' ';
        cout<< solution[i][n-1] << '\n';
    }
}