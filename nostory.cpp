#include <bits/stdc++.h>

using namespace std;

struct Object {
    uint64_t value;
    int index;

    Object(uint64_t _value1, int _index)
        : value(_value1)
        , index(_index) { }
};

int64_t SolveTask1(const vector<int>& a, const vector<int>& b) {
    int64_t sum = 0, n = a.size();
    vector<uint64_t> nums(2 * n, 0);

    for (int64_t i = 0; i < n; i++) {
        nums[i] = a[i];
        nums[i + n] = b[i];
    }

    // sort numbers decreasingly
    sort(nums.begin(), nums.end(), [](auto& ob1, auto& ob2) {
        return (ob2 < ob1);
    });

    // take greatest n numbers
    for (int64_t i = 0; i < n; i++) {
        sum += nums[i];
    }
    return sum;
}

int64_t SolveTask2(const vector<int>& a, const vector<int>& b, int moves) {
    int64_t sum = 0, n = a.size(), cont = 0;
    vector<Object> nums(2 * n, Object(0, 0));
    vector<uint64_t> freq(n, 0);

    for (int64_t i = 0; i < n; i++) {
        nums[i] = Object(a[i], i);
        nums[i + n] = Object(b[i], i);
    }

    // sort numbers decreasingly
    sort(nums.begin(), nums.end(), [](Object ob1, Object ob2) {
        return (ob2.value < ob1.value);
    });

    // take first n greatest numbers possible
    for (int64_t i = 0; i < 2 * n; i++) {
        // found first n biggest numbers possible
        if (cont == n)
            return sum;
        // index already used
        if (freq[nums[i].index] != 0 && moves == 0)
            continue;
        // make move
        if (freq[nums[i].index] != 0)
            moves--;
        freq[nums[i].index]++;
        sum += nums[i].value;
        cont++;
    }
    return sum;
}

vector<int> ReadVector(istream& is, int size) {
    vector<int> vec(size);
    for (auto& num : vec) {
        is >> num;
    }
    return vec;
}

int main() {
    ifstream fin("nostory.in");
    ofstream fout("nostory.out");

    int task;
    fin >> task;

    int n, moves;
    if (task == 1) {
        fin >> n;
    } else {
        fin >> n >> moves;
    }

    auto a = ReadVector(fin, n);
    auto b = ReadVector(fin, n);

    auto res = task == 1 ? SolveTask1(a, b) : SolveTask2(a, b, moves);
    fout << res << "\n";

    return 0;
}
