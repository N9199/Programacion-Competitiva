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

const int maxn = 8;

vector<vi> solutions;

bool check(vi &sols, int c, int f)
{
    //Check columna
    if (sols[c] != -1)
        return false;

    //Check vertical queue
    for (auto e : sols)
    {
        if (e == f)
            return false;
    }

    //Check diagonal
    rep(i, sols.size())
    {
        if (sols[i] != -1 && abs(sols[i] - f) == abs(i - c))
            return false;
    }
    return true;
}

void solver(vi sols, int c, int f)
{
    if (f != -1)
        sols[c] = f;

    if (c == maxn - 1 or (c == maxn - 2 and sols[c + 1] != -1))
    {
        solutions.emplace_back(sols);
        return;
    }

    if (c + 1 < maxn and sols[c + 1] != -1)
        c++;

    rep(i, maxn)
    {
        if (check(sols, c + 1, i))
            solver(sols, c + 1, i);
    }
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    rep(_, n)
    {
        int c, f;
        cin >> f >> c;
        f--, c--;
        vi sols(maxn);
        rep(i, maxn)
            sols[i] = (i == c) ? f : -1;

        solver(sols, -1, -1);

        sort(solutions.begin(), solutions.end(),
             [](const vi &a, const vi &b) -> bool {
                 rep(i, maxn)
                 {
                     if (a[i] < b[i])
                         return true;
                     if (a[i] > b[i])
                         return false;
                 }
                 return false;
             });
        cout << "SOLN       COLUMN\n";
        cout << " #      1 2 3 4 5 6 7 8\n\n";
        rep(i, solutions.size())
        {
            if (i + 1 < 10)
                cout << " ";
            cout << i + 1 << "      ";
            rep(j, solutions[i].size())
            {
                cout << solutions[i][j] + 1;
                if (j < solutions[i].size() - 1)
                    cout << " ";
            }
            cout << "\n";
        }
        solutions.clear();
        if (_ < n - 1)
            cout << "\n";
    }
    return 0;
}
