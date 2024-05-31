#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;


int main() {
    int N, M;

    scanf("%d%d", &N, &M);
    vector<int> W(N + 1, 0);
    vector<int> D(N + 1, 0);
    for (int i = 1; i <= N; i++) {
        scanf("%d%d", &W[i], &D[i]);
    }

    vector<vector<int>> f(2, vector<int>(M + 1, 0));

    int k = 0;
    for (int i = 1; i <= N; i++) {
        k = 1-k;
        for (int j = M; j >= 0; j--) {
            f[k][j] = f[1-k][j];
            if (j >= W[i]) {
                f[k][j] = max(f[k][j], f[1-k][j - W[i]] + D[i]);
            }
        }
    }

    int ans = 0;
    int index = N%2;

    for (int i = 0; i <= M; i++) {
        ans = max(ans, f[index][i]);
    }

    cout << ans << endl;
    return 0;
}