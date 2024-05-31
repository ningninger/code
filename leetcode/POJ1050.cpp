#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <utility>
#include <climits>

using namespace std;


int matrix[101][101];
int sums[101][101];


//这道题使用了前缀和，并且采用的是n^3的版本，可以使用dp进行优化，来进行n^4

int main() {
    int N = 0;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &matrix[i][j]);

            if (i > 0 && j > 0) {
                sums[i][j] = sums[i-1][j] + sums[i][j-1] - sums[i-1][j-1] + matrix[i][j];
            } else if (i > 0 && j == 0) {
                sums[i][j] = sums[i-1][j] + matrix[i][j];
            } else if (i == 0 && j > 0){
                sums[i][j] = sums[i][j - 1] + matrix[i][j];
            } else {
                sums[i][j] = 0;
            }
        }
    }

    int ans = INT_MIN;

    for (int x1 = 0; x1 < N; x1++) {
        for (int y1 = 0; y1 < N; y1++) {
            for (int x2 = x1+1; x2 <= N; x2++) {
                for (int y2 = y1+1; y2 <= N; y2++) {
                    if (x1 > 0 && y1 > 0) {
                        ans = max(ans, sums[x2-1][y2-1] - sums[x1-1][y2-1] - sums[x2-1][y1-1] + sums[x1-1][y1-1]);
                    } else if (x1 > 0 && y1 == 0) {
                        ans = max(ans, sums[x2-1][y2-1] - sums[x1-1][y2-1]);
                    } else if (x1 == 0 && y1 > 0){
                        ans = max(ans, sums[x2 - 1][y2 - 1] - sums[x2-1][y1 - 1]);
                    } else {
                        ans = max(ans, sums[x2-1][y2-1]);
                    }
                }
            }
        }
    }


    cout << ans;

    return 0;
}
