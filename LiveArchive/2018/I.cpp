#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> graph;

#define rep(i, n) for (int i = 0; i < n; i++)
#define invrep(i, a, b) for (int i = b; --i >= a;)

#define eb emplace_back

#define debugv(v)         \
    cerr << #v << ": ";   \
    for (auto e : v)      \
        cerr << e << " "; \
    cerr << endl;

class Node
{
  public:
    vi childs;
    Node *Parent = nullptr;
    int self = -1;

    Node(int self) : self(self) {}

    void addChild(int c)
    {
        childs.emplace_back(c);
    }
    void addParent(Node p)
    {
        Parent = &p;
    }
};

class Tree
{
    vector<Node> Nodes;
    priority_queue<int> removal;
    int size = 0;

  public:
    Tree(int root, graph &g)
    {
        size = g.size();
        rep(i, size) Nodes.emplace_back(i);
        queue<int> q;
        q.emplace(root);
        vi visited(g.size(), 1);
        while (!q.empty())
        {
            int u = q.front;
            q.pop();
            visited[u] = 0;
            for (auto v : g[u])
            {
                if (visited[v])
                {
                    Nodes[v].addParent(u);
                    Nodes[u].addChild(v);
                    q.emplace(v);
                }
            }
        }
    }

    int count()
    {
        int c = 0;
        while (size >= 7)
        {
            for (auto &n : Nodes)
            {
                c += isTorso(&n);
            }
            clean();
        }
    }

  private:
    bool isTorso(Node *n)
    {
        bool test = (*n).childs.size() == 3 && (*n).Parent;
        if (test)
        {
            bool test1 = isWaist(&Nodes[(*n).childs[0]]) && isArm(&Nodes[(*n).childs[1]]) && isArm(&Nodes[(*n).childs[2]]);
            bool test2 = isWaist(&Nodes[(*n).childs[1]]) && isArm(&Nodes[(*n).childs[0]]) && isArm(&Nodes[(*n).childs[2]]);
            bool test3 = isWaist(&Nodes[(*n).childs[2]]) && isArm(&Nodes[(*n).childs[0]]) && isArm(&Nodes[(*n).childs[1]]);
            test = (test1 || test2 || test3);
        }

        if (test)
        {
            remove(n);
        }
        return test;
    }
    bool isArm(Node *n)
    {
        if ((*n).childs.size() == 0)
        {
            remove(n);
            return true;
        }
        return false;
    }
    bool isWaist(Node *n)
    {
        bool test = (*n).childs.size() == 2;
        if (test)
        {
            for (int &child : (*n).childs)
            {
                test = test && isFoot(&Nodes[child]);
            }
            if (test)
                remove(n);
        }
        return test;
    }
    bool isFoot(Node *n)
    {
        if ((*n).childs.size() == 0)
        {
            remove(n);
            return true;
        }
        return false;
    }

    void remove(Node *n)
    {
        (*n).Parent = nullptr;
        (*n).childs.clear();
        removal.emplace((*n).self);
    }
    void clean()
    {
        size -= removal.size();
        while (!removal.empty())
        {
            int u = removal.top();
            removal.pop();
            Nodes.erase(Nodes.begin() + u);
        }
    }
};

int main()
{
    int n;
    cin >> n;
    graph g(n);
    int temp;
    rep(i, n)
    {
        cin >> temp;
        --temp;
        g[temp].emplace_back(i);
        g[i].emplace_back(temp);
    }
    Tree t(1, g);

    cout << t.count() << endl;
}