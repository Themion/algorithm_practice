#include <iostream>
#include <algorithm>

#define MAX_N 100000
#define MAX_SCORE 1000

using namespace std;

void sort_and_rank(int N, int score[MAX_N]) {
    int sorted[MAX_N];
    int rank[3 * MAX_SCORE + 1] = { 0, };

    for (int i = 0; i < N; i++)
        sorted[i] = score[i];

    sort(sorted, sorted + N);

    for (int i = N - 1; i >= 0; i--)
        if (!rank[sorted[i]])
            rank[sorted[i]] = N - i;

    for (int i = 0; i < N; i++) 
        cout << rank[score[i]] << ' ';
    cout << '\n';
}

int main(int argc, char **argv) {
    int N;
    int score[MAX_N];
    int sum[MAX_N] = { 0, };

    cin >> N;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < N; j++) {
            cin >> score[j];
            sum[j] += score[j];
        }

        sort_and_rank(N, score);
    }

    sort_and_rank(N, sum);

    return 0;
}