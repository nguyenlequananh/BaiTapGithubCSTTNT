#include<bits/stdc++.h>
using namespace std;
	int n,k;
	int a[10000][10000];
	int tham[10000];
	vector<int> tour;
	int cost = 0;
	void inp(){
		ifstream fin("tsp.txt");
		fin>>n>>k;
		for(int i = 1;i<=n;i++){
			for(int j = 1;j<=n;j++){
				fin>>a[i][j];
			}
		}
		fin.close();
	}
	int minRow(int x){
		int mi= INT_MAX;
		int index = 1;
		for(int i = 1;i<=n;i++){
			if(mi > a[x][i] &&tham[i]==0&& i != x){
				mi = a[x][i];
				index = i;
			}
		}
		return index;
	}
	void gts1(){
		memset(tham,0,sizeof(tham));
		tour.push_back(k);
		int count = 1;
		int u , v;
		u = k;
		//1->n-1
		tour.push_back(u);
		while(count < n){
			tham[u]=1;
			v = minRow(u);
			cost = cost + a[u][v];
			tour.push_back(v);
			u = v;
			count++;
		}
		cost = cost + a[v][k];
		tour.push_back(k);
		for(int i = 1;i< tour.size();i++){
			cout<<tour[i]<<" ";
		}
		cout<<endl;
		cout<<cost;
	}
int main(){
	inp();
	gts1();
	return 0;
}
