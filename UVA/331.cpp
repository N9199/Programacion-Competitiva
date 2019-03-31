#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;

#define rep(i, n) for (int i = 0; i < n; ++i)

int bfs()
{
}

int main(int argc, char const *argv[])
{
    int n;
    int count = 0;
    vi nums;
    vi temp;
    unordered_map<ll, int> range;
    while (cin >> n)
    {
        if (n == 0)
            return 0;
        count++;
        nums.resize(n);
        rep(i, n)
        {
            cin >> nums[i];
        }

        temp = nums;
        sort(temp.begin(), temp.end());
        int c = 0;
        rep(i, n)
        {
            if (i > 0 and temp[i] != temp[i - 1])
                c++;

            range[temp[i]] = c;
        }
        rep(i, n)
        {
            nums[i] = range[nums[i]];
        }

        cout << "There are ";
        cout << bfs();
        cout << " swap maps for input data set ";
        cout << count;
        cout << ".\n";
    }
    return 0;
}
