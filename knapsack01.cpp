#include <iostream>
#include <vector>
using namespace std;

int knapsack(int W, vector<int>& wt, vector<int>& val, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int w = 1; w <= W; ++w) {
            if (wt[i - 1] <= w)
                dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
            else 
                dp[i][w] = dp[i - 1][w];
        }
    }
    return dp[n][W];
}
int main() {
    int n;
    cout << "Enter the number of items: \n"; 	cin >> n;

    vector<int> val(n), wt(n);
    cout << "Enter the values of items:\n";
    for (int i = 0; i < n; ++i) 
        cin >> val[i];

    cout << "Enter the weights of items:\n";
    for (int i = 0; i < n; ++i) 
        cin >> wt[i];

    int W;
    cout << "Enter the capacity of knapsack: \n"; 	cin >> W;

    int maxVal = knapsack(W, wt, val, n);
    cout << "Maximum value that can be achieved: " << maxVal << endl;

    return 0;
} // https://onecompiler.com/cpp/42e2k5ssw
