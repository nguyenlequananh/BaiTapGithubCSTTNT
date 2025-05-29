#include <bits/stdc++.h>
using namespace std;

long n, a[1000][1000];

struct adj {
    int dinh;
    int bac;
    int mau;
    int cam = 0;
    vector<int> dinhKe;
    vector<int> camMau;
};

vector<adj> dinh;

void inp() {
    fstream fin("text.txt");
    fin >> n;
    for (int i = 1; i <= n; i++) {
        adj temp;
        temp.dinh = i;
        for (int j = 1; j <= n; j++) {
            fin >> a[i][j];
            if (a[i][j] > 0) {
                temp.dinhKe.push_back(j);
            }
        }
        temp.bac = temp.dinhKe.size();
        temp.mau = 0;
        dinh.push_back(temp);
    }
    fin.close();
}

bool soSanh(adj x, adj y) {
    return x.bac > y.bac;
}

void sapXep() {
    sort(dinh.begin(), dinh.end(), soSanh);
}

bool checkBac() {
    for (int i = 0; i < dinh.size(); i++) {
        if (dinh[i].mau == 0)
            return true;
    }
    return false;
}

bool checkMau(adj x,int mau) {
	for(int i = 0;i<x.dinhKe.size();i++){
		if(x.dinhKe[i] == mau)
		{
			return false;
		}
	}
	return true;
}
int timMauMin(adj x){
//	sort(x.dinhKe.begin(),x.dinhKe.end(),[](int x,int y){
//		return x.dinhKe[x] < x.dinhKe[y];
//	});
	for(int i = 0;i<x.dinhKe.size();i++){
		int index = 0;
		int mi = INT_MAX;
		for(int j = 0;j<x.dinhKe.size();i++){
			if(mi > x.dinhKe[j]){
				mi = x.dinhKe[j];
				index = j;
			}
			swap(x.dinhKe[i],x.dinhKe[index]);
		}
	}
	for(int i = 0;i<x.dinhKe.size();i++){
		if(i != x.dinhKe[i]){
			return i;
		}	
	}
	return 0;
}
void camMau(adj x, int mau) {
    if (checkMau(x, mau)) {
        x.camMau.push_back(mau);
    }
}

void toMau() {
   // int mau = 0;
    while (checkBac()) {
        //mau++;
        sapXep();
        int mau = timMauMin(dinh[0]);
		dinh[0].mau = mau;
		dinh[0].bac = 0;
		for(int i = 0;i<dinh[0].dinhKe.size();i++){
			if(dinh[i].mau== 0 ){
				camMau(dinh[dinh[0].dinhKe[i]],mau);
			}
		}

    }

    for(int i = 0;i<dinh.size();i++){
    	cout<<dinh[i].dinh<<" "<<dinh[i].mau<<endl;
	}
}

int main() {
    inp();
    toMau();
    return 0;
}

