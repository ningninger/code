#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <utility>
#include <climits>

using namespace std;

int maxbend = 0;
int minbend = INT_MAX;

void solve() {
    //n表示组数

    int n = 0;
    scanf("%d", &n);

    vector<vector<pair<int, int>>> group(n);
    int cnt = 0;
    int b, p;
    for (int i = 0; i < n; i++) {
        scanf("%d", &cnt);
        group[i].resize(cnt);
        for (int j = 0; j < cnt; j++) {
            scanf("%d%d", &b, &p);
            maxbend = max(maxbend, b);
            minbend = min(minbend, b);
            group[i][j].first = b;
            group[i][j].second = p;
        }
    }

    //现在我们已经收集了所有组的内容了

    vector<vector<int>> f(n, vector<int> (maxbend + 1, 0x3f3f3f3f));

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < group[k].size(); i++) {
            for (int j = minbend; j <= maxbend; j++) {
                if (group[k][i].first >= j) {
                    f[k][j] = min(f[k][j], (k > 0 ? f[k-1][j] : 0) + group[k][i].second);
                }
            }
        }
    }

    double ans = 0;
    for (int i = minbend; i <=  maxbend; i++) {
        ans = max(ans, (double)i/(double)f[n-1][i]);
    }

    printf("%.3f\n", ans);
}


int main() {
    int t;
    scanf("%d", &t);

    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}
