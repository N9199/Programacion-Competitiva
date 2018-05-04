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


int n; int m; 
int t[2 * (100000 + 1)];
vector<long long> level_cost;
vector<int> R;

// Custom binary search for looking up the R values
int my_binary_search(int l, int r, long long value){
    // cout << "l: " << l << " r: " << r << endl;
    int mid =  (l + r)/2;
    int cost = level_cost[mid] - level_cost[l - 1];
    if (l == 0){
        cost = level_cost[mid];
    }
    //   cout << "mid: " << mid << " cost: " << cost << endl;
    if (l == n){
        return n;
    }
    if (l >= r){
        return r + 1;
    }
    if (cost == value){
        return mid + 1;
    }
    else if (cost > value){
        return my_binary_search(l, mid - 1, value - cost);
    }
    else if (cost < value){
        return my_binary_search(mid + 1, r, value - cost);
    }
}

// Segment tree, iterative implementation, see details for implementation modifications
void build()
{
    // we build the nodes of the trees, note that for this, we must already
    // have copied the input elements to the tree from n to 2n
    for (int i = n - 1; i > 0; i--) t[i] = min(t[i<<1],t[i<<1|1]);
}


void print_tree()
{
    for (int i = 0; i < 2 * (n + 1); i++)
    {
        cout << i << ": " << t[i] << endl;
    } 
}

void update(int p, int value) // set value at position p
{
    // we iterate through the values of p, initially displacing it by n and setting the value
    // we then propagate the value till we are in the second to last layer of the segment tree
    // Note* p^1 is the same as p XOR 1, so we can use it to switch between i (even) and i + 1 (odd) easily
    t[p += n] = value;
    for (; p > 1; p >>= 1) t[p>>1] = min(t[p], t[p^1]);
}

int query(int l, int r)
{  // min on interval [l, r]
    // This algorithm querys from the bottom to the top in an efficient way
    int res = INT32_MAX; // We need to start with a neutral value for the operation
    for (l += n, r += (n + 1); l < r; l >>= 1, r >>= 1)
    {
        if (l&1) res = min(res, t[l++]);
        if (r&1) res = min(res, t[--r]);
    }
    return res;
}

bool my_compare(const tuple<int, int, int> & a, const tuple <int, int, int> & b){
    return get<0>(a) > get<0>(b);
} 

int main(){

    cin >> n >> m;
    vector<int> levels; levels.reserve(n);
    vector<tuple <int, int, int> > shops; shops.reserve(m);
    level_cost.reserve(n);
    R.reserve(m);
    copy_n(istream_iterator<int>(cin), n, back_inserter(levels));
    for (int i = 0; i < m; i++){
        int l; int s; int c;
        cin >> l >> s >> c;
        shops.push_back(make_tuple(l, s, c));
    }
    // Sort the shops from highest level to lowest level
    sort(shops.begin(), shops.end(), my_compare);

    // Calculate the total cost to reach a level from the start
    long long sum = 0;
    for (const auto & level: levels){
        sum += level;
        level_cost.push_back(sum);
    }
    // Level n + 1 has infinite cost so that all paths end here
    level_cost.push_back(INT32_MAX);

    // Calculate the highest level we can reach from any shop
    for (const auto & shop: shops){
        R.push_back(my_binary_search(get<0>(shop) - 1, n, get<1>(shop)));
    }

    // We copy our starting values to the segment tree
    for (int i = 0; i < n ; i++){
        t[n + i] = INT32_MAX;
    }
    // We construct the segment tree 
    build();


    // print_tree();

    // we start doing the DP
    int last_level;
    int level = get<0>(shops[0]);
    last_level = level;
    for (int i = 0; i < shops.size(); i++){
        level = get<0>(shops[i]);
        int cost = get<2>(shops[i]);
        // cout << "level: " << level << " cost: " << cost << endl;
        if (last_level == level){
            int temp = INT32_MAX;
        }
        // Three cases: 
        // 1.- If we can reach the end, we update the level with the cost of the shop
        // 2.- If we cant reach the end, we update the level with the cost of the shop + the cost of the min level that we can reach
        // 3.- If we ..., and we cant reach levels with shops, we keep the level at infinity

        // case 1
        if (R[i] == n){ // level n is the end we created, not last level (levels go from 0...n-1)
            // cout << "debug" << endl;
            update(level - 1, cost);
        }
        else {
            int min_cost = query(level, R[i]);
            // cout << "min cost: " << min_cost << " R[i]: " << R[i] << endl;
            // we check for case 3
            if (min_cost != INT32_MAX){
                // we do case 2
                if (min_cost + cost < t[level + n + 1]){
                    update(level - 1, cost + min_cost);
                }
            }
        }
        // print_tree();
    }
    if (t[n] == INT32_MAX)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << t[n] << endl;
    }


}