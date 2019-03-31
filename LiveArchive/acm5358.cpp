#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define rep(i, n) for (int i = 0; i < n; i++)

#define debugx(x) cerr << #x << ": " << x << endl
#define debugv(v)         \
    cerr << #v << ": ";   \
    for (auto e : v)      \
        cerr << e << " "; \
    cerr << endl;

#define log(x) (32 - __builtin_clz(x))

const int maxn = 8;

vi solutions;

inline int pos(int num, int i, int size)
{
    return (num >> ((7 - i) * size)) & ((1 << size) - 1);
}

bool check(int sols, int c, int f, int marked)
{
    //Check vertical
    if (pos(marked, c, 1))
        return false;

    //Check horizontal and diagonal
    rep(i, 8)
    {
        //Horizontal
        if (pos(sols, i, 3) == f)
            return false;

        //Diagonal
        if (pos(marked, c, 1) && abs(pos(sols, i, 3) - f) == abs(i - c))
            return false;
    }
    if (c > 6)
    {
        debugx(c);
        debugx(f);
    }
    return true;
}

void solver(int sols, int c, int marked)
{
    if (marked == (1 << 8) - 1 or c == 8)
    {
        solutions.emplace_back(sols);
        return;
    }

    rep(i, 8)
    {
        if (pos(marked, i, 1))
            continue;

        if (check(sols, c + 1, i, marked))
            solver(sols + (i << (3 * (6 - c))), c + 1, marked + (1 << (c + 1)));
    }
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    rep(k, n)
    {
        int c, f;
        cin >> f >> c;
        f--, c--;
        int sols = f << (3 * c);
        int mark = 1 << c;

        solver(sols, -1, mark);

        sort(solutions.begin(), solutions.end());
        debugv(solutions);

        cout << "SOLN       COLUMN\n";
        cout << " #      1 2 3 4 5 6 7 8\n\n";
        rep(i, solutions.size())
        {
            if (i + 1 < 10)
                cout << " ";
            cout << i + 1 << "      ";
            rep(j, 8)
            {
                cout << pos(solutions[i], j, 3) + 1;
                if (j < 7)
                    cout << " ";
            }
            cout << "\n";
        }
        solutions.clear();
        if (k < n - 1)
            cout << "\n";
    }
    return 0;
}
