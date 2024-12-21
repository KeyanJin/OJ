#include <climits>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> ingredients(n);

    for (int i = 0; i < n; i++)
    {
        cin >> ingredients[i].first >> ingredients[i].second;
    }

    int min_diff = INT_MAX;

    for (int mask = 1; mask < (1 << n); mask++)
    {
        long long acidity = 1;
        int bitterness = 0;

        for (int i = 0; i < n; i++)
        {
            if (mask & (1 << i))
            {
                acidity *= ingredients[i].first;
                bitterness += ingredients[i].second;
            }
        }

        int diff = abs(acidity - bitterness);
        min_diff = min(min_diff, diff);
    }

    cout << min_diff << endl;

    return 0;
}
