#include <iostream>
#include <vector>

using namespace std;

const int mod = 1000000007;

int type1(int x, int y) {
    // Compute the number of type 1 signals.
	int column = max(y, x);
	vector<vector<long long>> dp(y + 1, vector<long long>(column + 1, 0));

	// intialize matrix
	for (int i = 0; i <= x; i++)
		dp[0][i] = 1;

	for (int i = 1; i <= y; i++)
		dp[i][i - 1] = 1;

	// complete dp matrix
	for (int i = 1; i <= y; i++) {
		for (int j = i; j <= x; j++)
			dp[i][j] = (dp[i][j - 1] + dp[i - 1][j - 1]) % mod;
	}

    return dp[y][x];
}

int type2(int x, int y) {
    // Compute the number of type 2 signals.
	int column = max(y, x);
	vector<vector<long long>> dp(y + 1, vector<long long>(column + 1, 0));

	// intialize matrix
	for (int i = 0; i <= x; i++)
		dp[0][i] = 1;

	int tmp = min(2, y);
	for(int i = 0; i <= tmp; i++)
		dp[i][0] = 1;

	// complete dp matrix
	for (int i = 1; i <= y; i++) {
		for (int j = 1; j <= x; j++) {
			if (i < 2) {
				dp[i][j] = dp[i][j - 1] + dp[i - 1][j - 1];
				continue;
			}
			dp[i][j] = (dp[i][j - 1] + dp[i - 1][j - 1] + dp[i - 2][j - 1]) % mod;
		}
	}

    return dp[y][x];
}

int main() {
    freopen("semnale.in", "r", stdin);
	freopen("semnale.out", "w", stdout);

	int sig_type, x, y;

	cin >> sig_type >> x >> y;

    switch (sig_type) {
		case 1:
			cout << type1(x, y);;
			break;
		case 2:
			cout << type2(x, y);
			break;
		default:
			cout << "wrong task number" << endl;
	}

    return 0;
}
