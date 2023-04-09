#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int task1(int n, int m, int x, vector <int>& p, vector <vector <int> >& g) {
	// task 1
    long max_cost = n * x;
    vector<long> grades_sum(m + 1, 0);
    vector<vector<long>> dp(m + 1, vector<long>(max_cost + 1, 0));

    // compute sum of grades
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            grades_sum[j + 1] += g[i][j];
    }

    // populate dp matrix
    for (int i = 1; i <= m; i++) {
        for (int cost = 0; cost <= max_cost; cost++) {
            dp[i][cost] = dp[i - 1][cost];

            // check if current plate fits in price range
            if (cost - p[i - 1] >= 0) {
                long tmp = dp[i - 1][cost - p[i - 1]] + grades_sum[i];
                dp[i][cost] = max(dp[i][cost], tmp);
            }
        }
    }

	return dp[m][max_cost];
}

int task2(int n, int m, int x, vector <int> &p, vector <vector <int> > &g) {
	// task 2
    long max_cost = n * x;
    vector<long> grades_sum(m + 1, 0);
    vector<vector<long>> dp(2 * (m + 1), vector<long>(max_cost + 1, 0));

    // compute sum of grades
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            grades_sum[j] += g[i][j];
    }

    // populate dp matrix
    for (int i = 1; i <= 2 * m; i++) {
        for (int cost = 0; cost <= max_cost; cost++) {
            dp[i][cost] = dp[i - 1][cost];

            // check if current plate fits in price range
            if (cost - p[i % m] >= 0) {
                long tmp = dp[i - 1][cost - p[i % m]] + grades_sum[i % m];
                dp[i][cost] = max(dp[i][cost], tmp);
            }
        }
    }

	return dp[2 * m][max_cost];
}

int task3(int n, int m, int x, vector <int> &p, vector <vector <int> > &g) {
	// TODO solve task 3
    long max_cost = n * x;
    vector<long> grades_sum(m + 1, 0);
    vector<vector<vector<long>>> dp(n + 1, vector(2 * (m + 1), vector<long>(max_cost + 1, 0)));

    // compute sum of grades
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            grades_sum[j] += g[i][j];
    }

    // populate dp matrix
    for (int count = 1; count <= n; count++) {
        for (int i = 1; i <= 2 * m; i++) {
            for (int cost = 0; cost <= max_cost; cost++) {
                // don't use current plate
                dp[count][i][cost] = dp[count][i - 1][cost];

                // check if current plate fits in price range
                if (cost - p[i % m] >= 0) {
                    long tmp = dp[count - 1][i - 1][cost - p[i % m]] + grades_sum[i % m];
                    dp[count][i][cost] = max(dp[count][i][cost], tmp);
                }
            }
        }
    }
	return dp[n][2 * m][max_cost];
}

int main() {
	freopen("sushi.in", "r", stdin);
	freopen("sushi.out", "w", stdout);

	int task;  // task number

	int n;  // number of friends
	int m;  // number of sushi types
	int x;  // how much each of you is willing to spend

	vector <int> prices;  // prices of each sushi type
	// the grades you and your friends gave to each sushi type
	vector <vector <int> > grades;

	cin >> task;
	cin >> n >> m >> x;

	prices.assign(m, 0);
	grades.assign(n, vector <int> (m, 0));

	// price of each sushi
	for(int i = 0; i < m; ++i) {
		cin >> prices[i];
	}

	// each friends rankings of sushi types
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			cin >> grades[i][j];
		}
	}

	int ans = -1;

	switch(task) {
		case 1:
			ans = task1(n, m, x, prices, grades);
			break;
		case 2:
			ans = task2(n, m, x, prices, grades);
			break;
		case 3:
			ans = task3(n, m, x, prices, grades);
			break;
		default:
			cout << "wrong task number" << endl;
	}

	cout << ans << endl;

	return 0;
}
