#include<bits/stdc++.h>
using namespace std;
	long n, a[10000][10000];
	vector<int> adj[10000];
	vector<int> camMau[10000];
	//int visited[10000];
	long bac[10000];
	long mau[10000];
	void inp(){
		fstream fin("color2b.txt");
		fin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				fin>>a[i][j];
				if(a[i][j]>0){
					adj[i].push_back(j);
					//adj[j].push_back(i);
				}
			}
		}
		fin.close();
		for(int i=1;i<=n;i++){
			bac[i]=adj[i].size();
		}
	}
	bool checkBac(){
    	for(int i = 1; i <= n; i++){
      	  	if(bac[i] > 0){
        	    return true;
        	}
    	}
   	 	return false;
	}
	int timMax(){
		if(checkBac()==false) return -1;
		int ma = 0;
		int index;
		for(int i=1;i<=n;i++){
			if(ma < bac[i]){
				ma=bac[i];
				index =i;
			} 
		}
		return index;
	}
	void locTrungCamMau(int x) {
    	set<int> uniqueColors(camMau[x].begin(), camMau[x].end()); 
    	camMau[x].assign(uniqueColors.begin(), uniqueColors.end());
	}

	int timMau(int x){
		if(camMau[x].size()==0) return 1;
		locTrungCamMau(x);
		sort(camMau[x].begin(), camMau[x].end());
		
		int color = 1;
		for(int i=0;i<camMau[x].size();i++){
			if(color < camMau[x][i]){
				return color;
			}
			else{
				color++;
			}
		}
		return color;
	}
	void toMau(){
		//int count = 0;
		//int mauu = 1;
		while(checkBac()==true){
			//int mauu = 1;
			int index = timMax();
			if(index < 0) break;
			mau[index]=timMau(index);
			bac[index]=0;
			camMau[index].clear();
			for(int i=0;i<adj[index].size();i++){
				camMau[adj[index][i]].push_back(mau[index]);	
				bac[adj[index][i]]--;
			}
		}
		for(int i=1;i<=n;i++){
			if(mau[i]==0){
				mau[i]=timMau(i);
			}
		}
//		for(int i=1;i<=n;i++){
//			cout<<i<<" "<<mau[i]<<endl;
//		}
		long ma = 0;
		for(int i=1;i<=n;i++){
			ma = max(ma,mau[i]);
		}
		cout<<ma;
	}
int main(){
	inp();
	toMau();
	return 0;
}
