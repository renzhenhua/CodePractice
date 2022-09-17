#include <algorithm>
#include <iostream>

using namespace std;

const int N = 110;

int n;
int a[N][N];

int gauss() {
    int c, r;
    for (c = 0, r = 0; c < n; c++) {
        int t = r;
        for (int i = r; i < n; i++)
            if (a[i][c]) t = i;

        if (!a[t][c]) continue;

        for (int j = 0; j <= n; j++) swap(a[t][j], a[r][j]);
        for (int i = r + 1; i < n; i++)
            if (a[i][c])
                for (int j = n; j >= c; j--) a[i][j] ^= a[r][j] * a[i][c];

        r++;
    }

    if (r < n) {
        for (int i = r; i < n; i++)
            if (a[i][n]) return 2;
        return 1;
    }

    for (int i = n - 1; i >= 0; i--)
        for (int j = i + 1; j <= n; j++) a[i][n] ^= a[j][n] * a[i][j];

    return 0;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n + 1; j++) cin >> a[i][j];

    int t = gauss();

    if (t == 0) {
        for (int i = 0; i < n; i++) cout << a[i][n] << endl;
    } else if (t == 1)
        cout << "Multiple sets of solutions" << endl;
    else
        cout << "No solution" << endl;

    return 0;
}
