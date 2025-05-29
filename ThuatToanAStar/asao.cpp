#include<bits/stdc++.h>
using namespace std;

vector<pair<int, int> > adj[10000];
int h[10000], f[10000], g[10000], truoc[10000];
vector<int> mo, dong;
int n, m, s, t;

void inp() {
    cin >> n >> m >> s >> t;
    for (int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        adj[x].push_back({y, z});
        adj[y].push_back({x, z});
    }
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
    }
}

bool checkIndexInMo(int x) {
    return find(mo.begin(), mo.end(), x) != mo.end();
}

bool checkIndexInDong(int x) {
    return find(dong.begin(), dong.end(), x) != dong.end();
}

void removeMo(int x) {
    mo.erase(remove(mo.begin(), mo.end(), x), mo.end());
}

void removeDong(int x) {
    dong.erase(remove(dong.begin(), dong.end(), x), dong.end());
}

void capNhat(int p) {
    for (int i = 0;i< adj[p].size();i++) {
        int q = adj[p][i].first, cost = adj[p][i].second;
        if (checkIndexInMo(q)) {
            if (g[q] > g[p] + cost) {
                g[q] = g[p] + cost;
                f[q] = g[q] + h[q];
                truoc[q] = p;
            }
        } else {
            g[q] = g[p] + cost;
            f[q] = g[q] + h[q];
            truoc[q] = p;
            mo.push_back(q);
        }
        if (checkIndexInDong(q)) {
            if (g[q] > g[p] + cost) {
                removeDong(q);
                mo.push_back(q);
            }
        }
    }
}

int indexMin() {
    int index = 0, mi = INT_MAX;
    for (int i = 0; i < mo.size(); i++) {
        if (f[mo[i]] < mi) {
            mi = f[mo[i]];
            index = i;
        }
    }
    return mo[index];
}

void truyVet(int node) {
    vector<int> path;
    while (node != -1) {
        path.push_back(node);
        node = truoc[node];
    }
    reverse(path.begin(), path.end());
    cout << "Ðu?ng di ng?n nh?t: ";
    for (int i = 0;i<path.size();i++) cout << path[i] << " ";
    cout << endl;
}

void asao() {
    fill(g, g + 10000, INT_MAX);
    fill(f, f + 10000, INT_MAX);
    fill(truoc, truoc + 10000, -1);

    mo.push_back(s);
    g[s] = 0;
    f[s] = h[s];

    while (!mo.empty()) {
        int p = indexMin();
        removeMo(p);
        dong.push_back(p);

        if (p == t) {
            truyVet(t);
            return;
        }
        capNhat(p);
    }
    cout << "Không tìm th?y du?ng di!" << endl;
}

int main() {
    inp();
    asao();
    return 0;
}

