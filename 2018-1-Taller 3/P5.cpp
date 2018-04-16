#include <bits/stdc++.h>

using namespace std;


int n; int m; 
int t[100000 + 1];
vector<long long> level_cost;
vector<int> R;

int search(int l, int r, long long value){
    int m =  (l + r)/2;
    if (l >= r){
        return l;
    }
    if (level_cost[m] == value){
        return m;
    }
    else if (level_cost[m] > value){
        return search(l, m - 1, value);
    }
    else{
        return search(m + 1, r, value);
    }
}

void build()
{
    // we build the nodes of the trees, note that for this, we must already
    // have copied the input elements to the tree from n to 2n
    for (int i = n - 1; i > 0; i--) t[i] = min(t[i<<1],t[i<<1|1]);
}

void update(int p, int value) // set value at position p
{
    // we iterate through the values of p, initially displacing it by n and setting the value
    // we then propagate the value till we are in the second to last layer of the segment tree
    // Note* p^1 is the same as p XOR 1, so we can use it to switch between i (even) and i + 1 (odd) easily
    if (value == 0) t[p += n] = 0;
    else if (value > 0) t[p += n] = 1;
    else t[p += n] = -1;
    for (; p > 1; p >>= 1) t[p>>1] = min(t[p], t[p^1]);
}

int query(int l, int r)
{  // product on interval [l, r]
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
    level_cost.reserve(n+1);
    R.reserve(m);
    copy_n(istream_iterator<int>(cin), n, back_inserter(levels));
    for (int i = 0; i < m; i++){
        int l; int s; int c;
        cin >> l >> s >> c;
        shops.push_back(make_tuple(l, s, c));
    }
    sort(shops.begin(), shops.end(), my_compare);

    long long sum = 0;
    for (const auto & level: levels){
        sum += level;
        level_cost.push_back(sum);
    }
    level_cost.push_back(sum);

    for (const auto & shop: shops){
        int temp = search(get<0>(shop), n - 1, get<1>(shop));
        if(temp == n)
            temp++;
        R.push_back(temp);
    }

    for (int i = 0; i < 100000 + 1; i++){
        update(i, INT32_MAX);
        cout<<query(i, i)<<" ";
    }
    cout<<endl;
    update(n+1, 0);

    int level = get<0>(shops[0]);
    int last_level = level;
    int temp = INT32_MAX;
    for (int i = 0; i < shops.size(); i++){
        level = get<0>(shops[i]);
        cout<<"Level: "<<level<<endl;
        if (last_level != level){
            int asdf = get<2>(shops[i]);
            cout<<"Asdf: "<<asdf<<endl;
            update(last_level, temp + asdf);
            cout<<"Query: "<<query(last_level, last_level)<<endl;
            temp = INT32_MAX;
        }    
        temp = min(temp, query(level, R[i]));
        last_level = level;
    }
    cout<<"Hola"<<endl;
    update(level, temp);
    int q = query(1, 1);
    if(q == INT32_MAX)
        cout<<-1<<endl;
    else
        cout<<q<<endl;
    for(int i = 0; i < n+3; i++)
        cout<<query(i, i)<<" ";
    cout<<endl;
    return 0;
}