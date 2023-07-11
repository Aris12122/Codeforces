#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define ull unsigned long long

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int test;
    cin >> test;

    while (test--)
    {
        int n;
        cin >> n;

        vector <int> p(n);

        for (int i = 0; i < n; i++)
            cin >> p[i];

        int pos_n, pos_n1;

        for (int i = 0; i < n; i++)
            if (p[i] == n)
                pos_n = i;
            else if (p[i] == n - 1)
                pos_n1 = i;

        vector <int> ans;

        if (pos_n == 0)
            pos_n = pos_n1;

        for (int i = pos_n; i < n; i++)
            ans.push_back(p[i]);

        int ptr = pos_n - 2;

        if (pos_n == n - 1)
            ptr = pos_n - 1;

        while (ptr >= 0 && p[ptr] > p[0])
            ptr--;

        for (int i = pos_n - 1; i > ptr; i--)
            ans.push_back(p[i]);

        for (int i = 0; i <= ptr; i++)
            ans.push_back(p[i]);

        for (auto x : ans)
            cout << x << " ";

        cout << "\n";
    }
}
