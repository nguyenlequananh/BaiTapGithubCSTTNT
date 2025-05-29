#include<bits/stdc++.h>
using namespace std;
	int n, a[2000][2000],b[2000][2000];
	int dx[]={-1,0,0,1};
	int dy[]={0,-1,1,0};
	int x,y;
	void inp(){
		ifstream fin("taci3.txt");
		fin>>n;
		for(int i =1;i<=n;i++){
			for(int j=1;j<=n;j++){
				fin>>a[i][j];
				
			}
		}
		for(int i = 1;i<=n;i++){
			for(int j = 1;j<=n;j++){
				fin>>b[i][j];
			}
		}
		fin.close();
	}
	int heuristic(){
	int count = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(a[i][j] != b[i][j]){
				count++;
			}
		}
	}
	return count;
}

int checkArray(){
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(a[i][j] != b[i][j]){
				return 1;
			}
		}
	}
	return 0;
}
	void timXY(){
		for(int i = 1;i<=n;i++){
			for(int j =1;j<=n;j++){
				if(a[i][j]==0){
					x = i;
					y = j;
					return;
				}
			}
		}
	}
	void timDuongDi(){
//		for(int i = 1; i <= n; i++){
//			for(int j = 1; j <= n; j++){
//				cout<<a[i][j]<<" ";
//			}
//			cout<<endl;
//		}
		int bestX = x;
		int bestY = y;
		int h = INT_MAX;
		for(int i = 0;i<4;i++){
			int xTemp = x + dx[i];
			int yTemp = y + dy[i];
			if(xTemp >= 1 && xTemp <= n && yTemp<=n &&yTemp>=1){
				swap(a[x][y],a[xTemp][yTemp]);
				int count = heuristic();
				if(h >= count){
					h = count;
					bestX = xTemp;
					bestY = yTemp;
				}
				swap(a[x][y],a[xTemp][yTemp]);
			}
		}
		swap(a[x][y],a[bestX][bestY]);
		//cout<<"x "<<x<<" y "<<y<<endl;
		x = bestX;
		y = bestY;
	}
	void taci(){
		int count = 0;
		timXY();
		while(checkArray() != 0){
			timDuongDi();
			count++;
//			if(count > 1000){
//				cout<<"khong tim thay";
//				return;
//			}
		cout<<count<<endl;
		}
		
	}
int main(){
	inp();
	taci();
//	cout<<checkArray();
	return 0;
}
