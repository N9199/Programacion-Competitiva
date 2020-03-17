#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

typedef long long ll;
typedef pair<int, int> par;
typedef vector<int> vi;
typedef vector<par> vp;
typedef vector<vi> graph;

typedef vector<vp> wgraph;

#define rep(i, n) for (int i = 0; i < (int)n; ++i)
#define repx(i, a, n) for (int i = a; i < (int)n; ++i)
#define pb push_back
#define eb emplace_back

#define debugx(x) //cerr << #x << ": " << x << endl

#define debugv(v)         \
    cerr << #v << ":";    \
    for (auto e : v)      \
    {                     \
        cerr << " " << e; \
    }                     \
    cerr << endl

template <typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p)
{
    os << '(' << p.first << ',' << p.second << ')';
    return os;
}

struct RMinQ
{
    static const ll identity = 1e18;
    static ll op(ll x, ll y) { return min(x, y); }
    static ll lazy_op(int size, ll x) { return x; }
};

template <class t>
class ST
{
    template <class T>
    struct node
    {
        // !! Pading may be important
        // It's using 32 bytes
        bool lazy = false;
        int delta_v = 0;
        ll value;
        node *Left = nullptr, *Right = nullptr;
        node() {}
        // Query on range [l,r] for node representing range [i,j]
        ll query(int l, int r, int i, int j)
        {
            if (j < l or r < i)
                return T::identity;
            if (lazy)
            {
                lazy = false;
                node<t> *temp = new node();
                temp->Left = Left->Left;
                temp->Right = Left->Right;
                temp->value = Left->value;
                Left = temp;
                Left->update(l, r, i, (i + j) / 2, delta_v);
                temp = new node();
                temp->Left = Right->Left;
                temp->Right = Right->Right;
                temp->value = Right->value;
                Right = temp;
                Right->update(l, r, (i + j) / 2 + 1, j, delta_v);
                delta_v = 0;
            }
            if (i == j)
                return value;
            if (l <= i and j <= r)
                return value;
            else
                return T::op(Left->query(l, r, i, (i + j) / 2), Right->query(l, r, (i + j) / 2 + 1, j));
        }

        // Update on range [l,r] for node representing range [i,j]
        void update(int l, int r, int i, int j, ll val)
        {
            debugx(make_pair(l, r));
            debugx(make_pair(i, j));
            debugx(val);
            if (i == j)
            {
                value += val;
                debugx(value);
            }
            else if (l <= i and j <= r)
            {
                Left->query(l, r, i, (i + j) / 2);
                Right->query(l, r, (i + j) / 2 + 1, j);
                value += T::lazy_op(j - i + 1, val);
                delta_v = val;
                lazy = true;
            }
            else if (j < l or r < i)
                return;
            else
            {
                assert(Left != nullptr);
                assert(Right != nullptr);
                node<t> *temp = new node();
                Left->query(l, r, i, (i + j) / 2);
                temp->Left = Left->Left;
                temp->Right = Left->Right;
                temp->value = Left->value;
                Left = temp;
                Left->update(l, r, i, (i + j) / 2, val);
                temp = new node();
                Right->query(l, r, (i + j) / 2 + 1, j);
                temp->Left = Right->Left;
                temp->Right = Right->Right;
                temp->value = Right->value;
                Right = temp;
                Right->update(l, r, (i + j) / 2 + 1, j, val);
                value = T::op(Left->value, Right->value);
            }
        }

        void build(vector<ll> &v, int i, int j)
        {
            if (i == j)
                value = v[i];
            else
            {
                Left = new node();
                Left->build(v, i, (i + j) / 2);
                Right = new node();
                Right->build(v, (i + j) / 2 + 1, j);
                value = T::op(Left->value, Right->value);
            }
        }
        void build(int i, int j)
        {
            if (i == j)
                value = 0;
            else
            {
                Left = new node();
                Left->build(i, (i + j) / 2);
                Right = new node((i + j) / 2 + 1, j);
                Right->build();
                value = value = T::op(Left->value, Right->value);
            }
        }
    };
    int n;
    vector<node<t>> nodes;

public:
    int last_version;
    ST(int n)
    {
        this->n = n;
        nodes.eb();
        nodes[0].build(0, n-1);
        last_version = 0;
        debugx(sizeof(nodes[0]));
    }

    ST(vector<ll> &v)
    {
        n = v.size();
        nodes.eb();
        nodes[0].build(v, 0, n-1);
        last_version = 0;
        debugx(sizeof(nodes[0]));
    }

    // Update on range [l,r]
    void update(int l, int r, ll val, int ver)
    {
        debugx("ST Update");
        debugx(make_pair(l, r));
        debugx(val);
        debugx("Nodes Updates");
        nodes.eb();
        last_version++;
        nodes[last_version].Left = nodes[ver].Left;
        nodes[last_version].Right = nodes[ver].Right;
        nodes[last_version].value = nodes[ver].value;
        if (l <= r)
            nodes[last_version].update(l, r, 0, n - 1, val);
        else
        {
            nodes[last_version].update(0, r, 0, n - 1, val);
            nodes[last_version].update(l, n - 1, 0, n - 1, val);
        }
    }

    // Query on range [l,r]
    ll query(int l, int r, int ver)
    {
        if (l <= r)
            return nodes[ver].query(l, r, 0, n - 1);
        return t::op(nodes[ver].query(0, r, 0, n - 1), nodes[ver].query(l, n - 1, 0, n - 1));
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    ST<RMinQ> st(a);
    a.clear();
    debugx(sizeof(st));
    int q;
    cin >> q;
    cin.ignore();
    vector<int> v(3, 1e8);
    rep(_, q)
    {
        string s;
        getline(cin, s);
        stringstream ss;
        ss << s;
        int i = 0;
        rep(i, 3) v[i] = 1e8;
        while (ss >> v[i++])
            ;
        if (v[2] == 1e8)
            cout << st.query(v[0], v[1], st.last_version) << '\n';
        else
            st.update(v[0], v[1], v[2], st.last_version);
    }
}