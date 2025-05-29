#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

vector<int> a;

int ran(int min, int max) {
    return min + rand() % (max - min + 1);
}

int check(int x) {
    for(int i = 0; i < a.size(); i++) {
        if(a[i] == x) return 0;
    }
    return 1;
}

void taoMaTran(int n) {
    a.clear();
    int tong = n * n;

    while(a.size() < tong) {
        int x = ran(0, tong - 1);
        if(check(x)) a.push_back(x);
    }

    cout << n << endl;
    for(int i = 0; i < tong; i++) {
        cout << a[i] << " ";
        if((i + 1) % n == 0) cout << endl;
    }

}

int main() {
    srand(time(0));
    int n = 10; // Ð?i n = 3, 4, 10, 15... tùy b?n
    taoMaTran(n);
    return 0;
}

