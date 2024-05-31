#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <cmath>
#include <string>
#include <queue>
#include <utility>
#include <algorithm>
#include <set>
#include <cstring>
using namespace std;

int f[73][73][73][73];
int grid[73][73];

int main() {
    int rows, cols;
    cin >> rows >> cols;

    memset(f, ~0x3f3f3f3f, sizeof(f));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> grid[i][j];
        }
    }

    f[0][0][0][0] = grid[0][0];
    vector<int> cons[] = {{-1, 0, -1, 0}, {-1, 0, 0, -1}, {0, -1, -1, 0}, {0, -1, 0, -1}};

    for (int k = 1; k <= rows + cols - 2; k++) {
        for (int i = max(0, k - cols + 1); i < min(rows, k + 1); i++) {
            int j = k - i;

            for (int m = max(0, k - cols + 1); m < min(rows, k + 1); m++) {
                int n = k - m;

                if (i == m) {
                    if (!(i == rows-1 && j == cols-1)) {
                        continue;
                    }
                }

                for (auto it : cons) {
                    int pi = i + it[0];
                    int pj = j + it[1];
                    int pm = m + it[2];
                    int pn = n + it[3];

                    if (pi < 0 || pj < 0 || pm < 0 || pn < 0) {
                        continue;
                    }

                    f[i][j][m][n] = max(f[i][j][m][n], f[pi][pj][pm][pn] + grid[i][j] + grid[m][n]);
                }

            }
        }
    }

    cout << f[rows-1][cols-1][rows-1][cols-1] << endl;

    return 0;
}