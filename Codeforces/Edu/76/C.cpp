w
int main()
{
    int t;
    cin >> t;
    rep(_, t)
    {
        int n;
        cin >> n;
        if (n == 1)
        {
            cout << -1 << '\n';
            continue;
        }
        vi a(n);
        graph nums(n + 1);
        graph accumnums(n + 1, vi(n, 0));
        rep(i, n)
        {
            cin >> a[i];
            nums[a[i]].eb(i);
        }
        rep(i, n + 1)
        {
            rep(j, nums[i].size())
            {
                accumnums[i][nums[i][j]] = (j > 0) ? accumnums[i][nums[i][j - 1]] + 1 : 1;
            }
        }
    }
}