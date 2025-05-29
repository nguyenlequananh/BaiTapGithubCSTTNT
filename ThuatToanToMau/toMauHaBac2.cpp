#include<bits/stdc++.h>
using namespace std;	
	vector<int> ke[2000];
	vector<int> camMau[2000];
	int bac[2000];
	int tham[2000];
	int mau[2000];
	int n;
	int a[2000][2000];
	void inp(){
		fstream fin("color1b.txt");
	    fin >> n;
	    for (int i = 1; i <= n; i++) {
	        for (int j = 1; j <= n; j++) {
	            fin >> a[i][j];
	            if (a[i][j] > 0) {
	                ke[i].push_back(j);
	            }
	        }
	    }
	    fin.close();
	    for(int i = 1;i<=n;i++){
	    	bac[i] = ke[i].size();
		}
		memset(tham,0,sizeof(tham));
	}
	void haBacCamTo(int x,int color){
		for(int i = 0;i<camMau[x].size();i++){
			if(camMau[x][i] == color){
				return;
			}
		}
		camMau[x].push_back(color);
		bac[x]--;
	}
	int timViTriMax(){
		int index = 0 ;
		int ma = INT_MIN;
		for(int i = 1;i<=n;i++){
			if(bac[i] > ma && tham[i]==0){
				ma = bac[i];
				index = i;
			}
		}
		return index;
	}
	int timMauMin(int x){
		if (camMau[x].size() == 0) return 1;
		
		sort(camMau[x].begin(),camMau[x].end());
		int colorMin = 1;
		for(int i = 0;i<camMau[x].size();i++){
			if(colorMin == camMau[x][i]){
				colorMin++;
			}
			else{
				break;
			}
		}
		return colorMin;
	}
	int checkBac(){
		for(int i = 1;i<=n;i++){
			if(tham[i] == 0){
				return 0;
			}
		}
		return 1;
	}
	void toMau(){
		while(checkBac() == 0){
			int index = timViTriMax();
			int color = timMauMin(index);
			tham[index] = 1;
			mau[index] = color;
			for(int i = 0;i<ke[index].size();i++){
				haBacCamTo(ke[index][i],color);
			}
		}
		for(int i = 1;i<=n;i++){
			if ( tham[i] == 0){
				mau[i] = timMauMin(i);
			}
		}
		int ma =INT_MIN;
		for(int i = 1;i<=n;i++){
		//	cout<<i<<" "<<mau[i]<<endl;
			ma = max(ma,mau[i]);
		}
		cout<<ma;
	}
int main(){
	inp();
	toMau();
	return 0;
}
