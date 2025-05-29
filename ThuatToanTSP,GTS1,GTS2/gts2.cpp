#include <bits/stdc++.h>
using namespace std;

int n, k;
int a[2000][2000];
int b[2000];
int tham[2000];

void inp() {
    ifstream fin("GTS2c.txt");
    fin >> n >> k;
    for (int i = 1; i <= k; i++) {
        fin >> b[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            fin >> a[i][j];
        }
    }
    fin.close();
}

int minRow(int x) {
    int mi = INT_MAX;
    int index = -1;
    for (int i = 1; i <= n; i++) {
        if (tham[i] == 0 && i != x && a[x][i] < mi) {
            mi = a[x][i];
            index = i;
        }
    }
    return index;
}

int gts1(int start) {
    memset(tham, 0, sizeof(tham));
    int cost = 0;
    int u = start;
    int count = 1;

    while (count < n) {
        tham[u] = 1;
        int v = minRow(u);
        if (v == -1) break;
        cost += a[u][v];
        u = v;
        count++;
    }

    cost += a[u][start];
    return cost;
}

void gts2() {
    int mi = INT_MAX;

    for (int i = 1; i <= k; i++) {
        int cost = gts1(b[i]);
        if (cost < mi) {
            mi = cost;
        }
    }

    cout << "Min cost: " << mi << endl;
}

int main() {
    inp();
    gts2();
    return 0;
}

