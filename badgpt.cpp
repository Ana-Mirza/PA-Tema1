// #include <cstdint>
// #include <fstream>
// #include <vector>
// #include <string>
// #include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define mod (1000000000 + 7)
#define KMAX 2

// C = A * B
void multiply_matrix(uint64_t A[KMAX][KMAX], uint64_t B[KMAX][KMAX],
                     uint64_t C[KMAX][KMAX]) {
    uint64_t tmp[KMAX][KMAX];

    // tmp = A * B
    for (int i = 0; i < KMAX; ++i) {
        for (int j = 0; j < KMAX; ++j) {
            uint64_t sum = 0;

            for (int k = 0; k < KMAX; ++k) {
                sum += 1LL * A[i][k] * B[k][j];
            }

            tmp[i][j] = sum % mod;
        }
    }

    //  C = tmp
    memcpy(C, tmp, sizeof(tmp));
}

// R = C^p
void power_matrix(uint64_t C[KMAX][KMAX], uint64_t p, uint64_t R[KMAX][KMAX]) {
    // tmp = I (identity matrix)
    uint64_t tmp[KMAX][KMAX];
    for (int i = 0; i < KMAX; ++i) {
        for (int j = 0; j < KMAX; ++j) {
            tmp[i][j] = (i == j) ? 1 : 0;
        }
    }

    while (p != 1) {
        if  (p % 2 == 0) {
            multiply_matrix(C, C, C);     // C = C*C
            p /= 2;                       // C^(p/2) to be computed
        } else {
            // reduce previous case:
            multiply_matrix(tmp, C, tmp); // tmp = tmp*C
            --p;                          // C^(p-1) to be computed
        }
    }

    // part of the answer is in C and the other in tmp
    multiply_matrix(C, tmp, R);           // answer = tmp * C
}

uint64_t findNum(uint64_t n) {
    // base cases
    if (n <= 1)
        return 1;
    if (n == 2)
        return 2;

    // compute C matrix
    uint64_t C[KMAX][KMAX] = { {0, 1},
                               {1, 1}};

    // C = C^(n-2)
    power_matrix(C, n - 2, C);
    uint64_t sol = 1 * C[0][1] + (2 * C[1][1]) % mod;
    return sol % mod;
}

uint64_t SolveTask(string compString) {
    uint64_t res = 1, n = compString.size();

    // parse string
    for (uint64_t i = 0; i < n - 1; i++) {
        // go to next 'u' or 'n' letter
        if (compString[i] != 'u' && compString[i] != 'n')
            continue;
        
        i++;
        char num[20] = "";
        int index = 0;
        // find number n_i
        while (compString[i] >= '0' && compString[i] <= '9')
            num[index++] = compString[i++];
        i--;

        // compute answer
        uint64_t ans = findNum(stoll(num));
        res = (res * ans) % mod;
    }
    return res;
}

int main() {
    ifstream fin("badgpt.in");
    ofstream fout("badgpt.out");

    string compressed_string;
    fin >> compressed_string;

    uint64_t res = SolveTask(compressed_string);
    fout << res << "\n";

    return 0;
}
