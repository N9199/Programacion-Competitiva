#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> par;
typedef vector<ll> vi;
typedef vector<par> vp;
typedef vector<vi> graph;
typedef vector<vp> wgraph;

#define rep(i, n) for (int i = 0; i < (int)n; ++i)

#define debugx(x) //cerr << #x << ": " << x << endl
#define debugp(p) //cerr<<#p<<": ("<<p.first<<", "<<p.second<<")"<<endl

#define pb push_back
#define eb emplace_back

int main()
{
    int ts, tf, dt;
    cin >> ts >> tf >> dt;
    int n;
    cin >> n;
    vi v(n);
    rep(i, n) cin >> v[i];

    int unoccupied = ts;
    int queue = 0;
    ll min_queue_start = -1;
    ;
    ll min_queue_time = 1e12;
    int i = 0;
    ll current_time;
    while (true)
    {
        if (i == n or min_queue_time == 0 or unoccupied >= tf)
            break;
        current_time = v[i];
        if (current_time < unoccupied)
        {
            queue++;
            unoccupied += dt;
            if (min_queue_time > unoccupied - current_time)
            {
                min_queue_time = unoccupied - current_time;
                min_queue_start = current_time - 1;
            }
        }
        else
        {

            unoccupied = current_time + dt;
        }
    }
}