#include <iostream>
#include <vector>
#include <limits.h> 
#include <cstring>
#include <fstream>
using namespace std;
	// thuat toan Welsh-Powell
	
	long n, a[10000][10000];
	long mau[10000];
	vector<int> adj[10000];
	pair<int, int> dinhBac[10000];
	
	void inp() {    
	ifstream fin("color1b.txt");
	    fin >> n;
	    for (int i = 1; i <= n; i++) {
	        for (int j = 1; j <= n; j++) {
	            fin >> a[i][j];
	        }
	    }
	    fin.close();
	}
	
	void timBac() {
	    for (int i = 1; i <= n; i++) {
	    	for(int j=1;j<=n;j++){	
	    		if(a[i][j]==1){
	    			adj[i].push_back(j);
				}
			}
	    }
		for(int i=1;i<=n;i++){
			dinhBac[i].first=i;
			dinhBac[i].second=adj[i].size();
		}
	    for (int i=1;i<=n; i++) {
	    	int index =i;
	    	int ma=dinhBac[i].second;
	        for (int j = i+1 ; j <= n; j++) {
	            if (ma < dinhBac[j].second ) {
	            	index = j;
	            	ma = dinhBac[j].second;
	            }
	        }
	        swap(dinhBac[i],dinhBac[index]);
	    }
//	    for (int i = 1; i <= n; i++) {
//	      cout<<i<<" "<<dinhBac[i].first<<" "<<dinhBac[i].second<<endl;
//	    }
	}
	void toMau(){
		memset(mau,-1,sizeof(mau));
		int count =0;
		int color = 0;
		while(count<n){
			color++;
			for(int i=1;i<=n;i++){
				if (mau[dinhBac[i].first] != -1) continue;
				int check=1;
				for(int j=0;j<adj[dinhBac[i].first].size();j++){
					int v = adj[dinhBac[i].first][j];
					if(mau[v]==color){
						check =0;
						break;
					}
				}
				if(check==1){
					mau[dinhBac[i].first]=color;
					count++;
				}
			}
		}
		cout<<color;
		ofstream fout("colors.txt");
//		for(int i=1;i<=n;i++){
//			cout<<dinhBac[i].first<<" co mau "<<mau[dinhBac[i].first]<<endl;
//		}
	//	cout.close();
	}

int main() {
    inp();
    timBac();
    toMau();
    return 0;
}

