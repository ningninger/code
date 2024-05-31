#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int main() {
    int t, m;
    cin>>t>>m;
    vector<int> time(m);
    vector<int> value(m);

    for (int i = 0; i < m; i++) {
        cin>>time[i]>>value[i];
    }

//    vector<vector<long long>> dp3(m + 1, vector<long long>(t + 1, 0));
//
//    for (int i = 1; i < m + 1; i++) {
//        for (int j = 1; j < t + 1; j++) {
//            dp3[i][j] = dp3[i-1][j];
//            if (j >= time[i - 1]) {
//                dp3[i][j] = max(dp3[i][j], dp3[i][j - time[i - 1]] + value[i - 1]);
//            }
//        }
//    }
//
//    cout << dp3[m][t];

//    vector<vector<long long>> dp2(2, vector<long long>(t + 1, 0));
//
//    for (int i = 1; i < m + 1; i++) {
//        int k = i % 2;
//        for (int j = 1; j < t + 1; j++) {
//            dp2[k][j] = dp2[1-k][j];
//            if (j >= time[i - 1]) {
//                dp2[k][j] = max(dp2[k][j], dp2[k][j - time[i - 1]] + value[i - 1]);
//            }
//        }
//    }
//
//    int index = m % 2 == 0 ? 0 : 1;
//
//    cout << dp2[index][t];

    vector<long long> dp(t + 1, 0);
    for (int i = 1; i < m + 1; i++) {
        for (int j = 1; j < t + 1; j++) {
            if (j >= time[i - 1]) {
                dp[j] = max(dp[j], dp[j - time[i - 1]] + value[i - 1]);
            }
        }
    }

    cout << dp[t];


//    vector<vector<int>> dp3(m + 1, vector<int>(t + 1, 0));
//    for (int i = 1; i < m + 1; i++) {
//        for (int j = t; j >= 0; j--) {
//            dp3[i][j] = dp3[i-1][j];
//            int k = 1;
//            while(j >= k * time[i - 1]) {
//                dp3[i][j] = max(dp3[i][j], dp3[i - 1][j - k * time[i - 1]] + k * value[i - 1]);
//                k++;
//            }
//        }
//    }

//    vector<vector<long long>> dp2(2, vector<long long>(t + 1, 0));
//    for (int i = 1; i < m + 1; i++) {
//        int k = i % 2;
//        for (int j = 1; j < t + 1; j++) {
//            if (j >= time[i - 1]) {
//                dp2[k][j] = max(dp2[1-k][j], dp2[k][j - time[i - 1]] + value[i - 1]);
//            } else {
//                dp2[k][j] = dp2[1-k][j];
//            }
//        }
//    }
//    int index = (m % 2 == 0) ? 0 : 1;
//
//    cout<<dp2[index][t]<<endl;

//    vector<long long> dp(t + 1, 0);
//    for (int i = 1; i < m + 1; i++) {
//        for (int j = 1; j < t + 1; j++) {
//            if (j >= time[i - 1])
//                dp[j] = max(dp[j], dp[j - time[i - 1]] + value[i - 1]);
//        }
//    }
//
//    cout<<dp[t]<<endl;


    return 0;
}