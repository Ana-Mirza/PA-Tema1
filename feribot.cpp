#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long get_sum(vector<long long>& nums, long long mid, long long k) {
    long long sum = 0, max_sum = 0, n = nums.size();
    for (int i = 0; i < n; i++) {
        sum += nums[i];

        // sum is too large, start sum for next feribot
        if (sum > mid) {
            k--;
            sum -= nums[i];
            if (max_sum < sum)
                max_sum = sum;
            sum = nums[i];
        }

        // cars cannot be grouped in k groups with sum <= mid
        if (k == 0 && i != n)
            return mid + 1;
    }

    // return biggest sum
    return (max_sum > sum) ? max_sum : sum;
}

long long splitArray(vector<long long>& nums, long long k) {
    long long n = nums.size();
    long long maxi = 0, sum = 0;

    // compute total sum of cars
    for (int i = 0; i < n; i++) {
        if (nums[i] > maxi)
            maxi = nums[i];
        sum += nums[i];
    }

    // binary search for smallest cost for all feribots
    long long sol;
    long long l = maxi, r = sum, mid;
    while (l <= r) {
        mid = l + (r - l) / 2;
        long long tmp = get_sum(nums, mid, k);
        if (tmp <= mid) {
            sol = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return sol;
}

int main() {
    freopen("feribot.in", "r", stdin);
	freopen("feribot.out", "w", stdout);

    long long solution, n, k;
    cin >> n >> k;

    vector<long long> vec(n, 0);
    for (int i = 0; i < n; i++) {
        long x;
        cin >> x;
        vec.push_back(x);
    }

    solution = splitArray(vec, k);

    cout << solution << "\n";
    return 0;
}
