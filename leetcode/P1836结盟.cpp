#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <climits>
#include <cmath>
#include <string>
#include <queue>
#include <utility>
#include <algorithm>
#include <set>


//TODO： 这段代码是有问题的，没有考虑123321的情况

using namespace std;

void findL(double x, std::vector<double>& temp) {
    std::vector<double>::iterator it = std::lower_bound(temp.begin(), temp.end(), x);
    if (it != temp.end()) {
        *it = x;
    } else {
        temp.push_back(x);
    }
}

void findU(double x, std::vector<double>& temp) {
    std::vector<double>::iterator it = std::upper_bound(temp.begin(), temp.end(), x);
    if (it != temp.end()) {
        *it = x;
    } else {
        temp.push_back(x);
    }
}


int main() {
    int n;
    cin >> n;
    vector<double> team(n+1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> team[i];
    }

    int ans = INT_MAX;

    for (int i = 1; i <= n; i++) {
        double solider = team[i];

        vector<double> temp;
        for (int j = 1; j < i; j++) {
            if (team[j] < solider) {
                findL(team[j], temp);
            }
        }

        int left = i - 1 - (int)temp.size();

        temp.clear();

        for (int j = n; j > i + 1; j--) {
            if (team[j] < solider) {
                findL(team[j], temp);
            }
        }


        int right = n - i - (int)temp.size();


        ans = min(ans, left + right);
    }

    cout << ans;


    return 0;
}