#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;
	int n = 3;
	int a[1000][1000];b[1000][1000],c[1000][1000];
	int randomm(int min, int max) {
    	return rand() % (max - min + 1) + min;
	}
	int check(int x){
		for(int i = 1;i<= n;i++){
			for(int j = 1;j<=n;j++){
				if(x != -1 && x == a[i][j]){
					return 0;
					break;
				}
			}
		}
		return 1;
	}
	void inp(){
	//	n = randomm(3,99);
		memset(a,-1,sizeof(a));
		for(int i = 1;i<= n;i++){
			for(int j = 1;j<=n;j++){
				int kt = 0;
				int x;
				while(kt==0){
					x = randomm(0,n*n-1);
					kt = check(x);	
				}
				a[i][j] = x;
			}
		}
		for(int i = 1;i<= n;i++){
			for(int j = 1;j<=n;j++){
				int kt = 0;
				int x;
				while(kt==0){
					x = randomm(0,n*n-1);
					kt = check(x);	
				}
				a[i][j] = x;
			}
		}
	}
	void outp(){
		for(int i = 1;i<= n;i++){
			for(int j = 1;j<=n;j++){
				cout<<a[i][j]<<" ";
			}
			cout<<endl;
		}
	}
	int h(){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if()
			}
		}
	}
int main() {
	inp();
	outp();
    return 0;
}

