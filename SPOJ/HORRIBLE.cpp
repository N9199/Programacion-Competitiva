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

#define debugx(x) cerr << #x << ": " << x << endl

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

struct RMaxQ
{
    static ll op(ll x, ll y) { return max(x, y); }
    static ll lazy_op(int size, ll x) { return x; }
};

struct RMinQ
{
    static ll op(ll x, ll y) { return min(x, y); }
    static ll lazy_op(int size, ll x) { return x; }
};

struct RSumQ
{
    static ll op(ll x, ll y) { return x + y; }
    static ll lazy_op(int size, ll x) { return (ll)size * x; }
};

template <class t>
class ST
{
    template <class T>
    struct node
    {
        int size;
        ll value;
        ll delta_v = 0;
        bool lazy = false;
        node *Left = nullptr, *Right = nullptr;
        node(int n) : size(n) {}
        // Query on range [l,r]
        ll query(int l, int r)
        {
            if (lazy)
            {
                lazy = false;
                node<t> *temp = new node(size / 2);
                temp->Left = Left->Left;
                temp->Right = Left->Right;
                temp->value = Left->value;
                Left = temp;
                Left->update(0, size / 2 - 1, delta_v);
                temp = new node(size - size / 2);
                temp->Left = Right->Left;
                temp->Right = Right->Right;
                temp->value = Right->value;
                Right = temp;
                Right->update(0, size - size / 2 - 1, delta_v);
                delta_v = 0;
            }
            if (l == 0 and r == size - 1)
                return value;
            else if (r < size / 2)
                return Left->query(l, r);
            else if (l >= size / 2)
                return Right->query(l - size / 2, r - size / 2);
            else
                return T::op(Left->query(l, size / 2 - 1), Right->query(0, r - size / 2));
        }
        // Update on range [l,r]
        void update(int l, int r, ll val)
        {
            if (size == 1)
                value += val;
            else if (l == 0 and r == size - 1)
            {
                Left->query(l, size / 2 - 1);
                Right->query(0, size - size / 2 - 1);
                value += T::lazy_op(size, val);
                delta_v = val;
                lazy = true;
            }
            else if (r < size / 2)
            {
                node<t> *temp = new node(size / 2);
                Left->query(l, r);
                temp->Left = Left->Left;
                temp->Right = Left->Right;
                temp->value = Left->value;
                Left = temp;
                Left->update(l, r, val);
                value = T::op(Left->value, Right->value);
            }
            else if (l >= size / 2)
            {
                node<t> *temp = new node(size - size / 2);
                Right->query(l - size / 2, r - size / 2);
                temp->Left = Right->Left;
                temp->Right = Right->Right;
                temp->value = Right->value;
                Right = temp;
                Right->update(l - size / 2, r - size / 2, val);
                value = T::op(Left->value, Right->value);
            }
            else
            {
                node<t> *temp = new node(size / 2);
                Left->query(l, size / 2 - 1);
                temp->Left = Left->Left;
                temp->Right = Left->Right;
                temp->value = Left->value;
                Left = temp;
                Left->update(l, size / 2 - 1, val);
                temp = new node(size - size / 2);
                Right->query(0, r - size / 2);
                temp->Left = Right->Left;
                temp->Right = Right->Right;
                temp->value = Right->value;
                Right = temp;
                Right->update(0, r - size / 2, val);
                value = T::op(Left->value, Right->value);
            }
        }

        void build(vector<ll>::iterator it)
        {
            if (size == 1)
                value = *it;
            else
            {
                Left = new node(size / 2);
                Left->build(it);
                Right = new node(size - size / 2);
                Right->build(it + size / 2);
                value = T::op(Left->value, Right->value);
            }
        }
        void build()
        {
            if (size == 1)
                value = 0;
            else
            {
                Left = new node(size / 2);
                Left->build();
                Right = new node(size - size / 2);
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
        nodes.eb(n);
        nodes[0].build();
        last_version = 0;
    }

    ST(vector<ll> &v)
    {
        n = v.size();
        nodes.eb(n);
        nodes[0].build(v.begin());
        last_version = 0;
    }

    // Update on range [l,r]
    void update(int l, int r, ll val, int ver)
    {
        nodes.eb(n);
        last_version++;
        nodes[last_version].Left = nodes[ver].Left;
        nodes[last_version].Right = nodes[ver].Right;
        nodes[last_version].value = nodes[ver].value;
        if (l <= r)
            nodes[last_version].update(l, r, val);
        else
        {
            nodes[last_version].update(0, r, val);
            nodes[last_version].update(l, n - 1, val);
        }
    }

    // Query on range [l,r]
    ll query(int l, int r, int ver)
    {
        if (l <= r)
            return nodes[ver].query(l, r);
        return t::op(nodes[ver].query(0, r), nodes[ver].query(l, n - 1));
    }
};

int main()
{
    int t;
    cin >> t;
    rep(__, t)
    {
        int n, q;
        cin >> n >> q;
        ST<RSumQ> st(n);
        debugx("Start Queries");
        rep(_, q)
        {
            int c;
            cin >> t;
            int l, r;
            cin >> l >> r;
            l--, r--;
            assert(l >= 0);
            assert(r < n);
            if (c)
            {
                cout << st.query(l, r, st.last_version) << '\n';
            }
            else
            {
                ll v;
                cin >> v;
                st.update(l, r, v, st.last_version);
            }
        }
    }
}