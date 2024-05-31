#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int main() {
    int n, W;
    scanf("%d%d", &n, &W);

    vector<int> v;

    vector<int> w;


    int vi, wi, mi;
    int c, index = 0;

    for (int i = 1; i <= n; i++) {
        scanf("%d%d%d", &vi, &wi, &mi);
        c = 1;
        while(mi > c) {
            mi -= c;
            v.push_back(c * vi);
            w.push_back(c * wi);
            c *= 2;
        }
        if (mi > 0) {
            v.push_back(mi * vi);
            w.push_back(mi * wi);
        }
    }

    //这样使用了二进制分组，我们就将混合背包实现成了分组背包

    int k = 0;
    vector<vector<int>> f(2, vector<int>(W + 1));

    for (int i = 1; i <= v.size(); i++) {
        k = 1-k;
        for (int j = W; j >= 0; j--) {
            f[k][j] = f[1-k][j];
            if (j >= w[i-1]) {
                f[k][j] = max(f[k][j], f[1-k][j - w[i-1]] + v[i-1]);
            }
        }
    }

    int ans = 0;
    int in = v.size()%2;

    for (int i = 1; i <= W; i++) {
        ans = max(ans, f[in][i]);
    }

    printf("%d", ans);

    return 0;
}