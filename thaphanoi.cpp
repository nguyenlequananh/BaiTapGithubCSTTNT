#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
using namespace std;

int main() {
    srand(time(0)); 

    ofstream fout("HNtower4.txt");

    int n = rand() % 14 + 3; // Random t? 3 d?n 16
    fout << n << endl;

    vector<int> dia(n);
    for (int i = 0; i < n; ++i) dia[i] = i + 1;

    random_shuffle(dia.begin(), dia.end());// tron ngau nhien

    vector<int> a, b, c;
    for (int i = 0; i < n; ++i) {
        int cot = rand() % 3; // 0 = A, 1 = B, 2 = C
        if (cot == 0) a.push_back(dia[i]);
        else if (cot == 1) b.push_back(dia[i]);
        else c.push_back(dia[i]);
    }

    sort(a.rbegin(), a.rend());
    sort(b.rbegin(), b.rend());
    sort(c.rbegin(), c.rend());
    
    if(a.size() == 0){
    	fout<<0;
    }
  //  fout<<endl;
    for(int i = 0;i<a.size();i++){
    	fout<<a[i]<<" ";
    }
    fout<<endl;
    if(b.size() == 0){
    	fout<<0;
    }
    //fout<<endl;
     for(int i = 0;i<b.size();i++){
    	fout<<b[i]<<" ";
    }
    if(c.size() == 0){
    	fout<<0;
    }
   // fout<<endl;
    fout<<endl;
     for(int i = 0;i<c.size();i++){
    	fout<<c[i]<<" ";
    }
    fout<<endl;

    //fout << a.size();
//    for (int d : A) fout << " " << d;
//    fout << endl;
//
//    fout << "B " << B.size();
//    for (int d : B) fout << " " << d;
//    fout << endl;
//
//    fout << "C " << C.size();
//    for (int d : C) fout << " " << d;
//    fout << endl;

    fout.close();
    cout << "Ðã t?o file input ng?u nhiên cho Tháp Hà N?i (n = " << n << ")" << endl;
    return 0;
}

