#include<bits/stdc++.h>
using namespace std;
class DisjointSet{
	vector<int> rank , parent ,size;
  public:
	DisjointSet(int n){
		rank.resize(n+1, 1);
		parent.resize(n+1, 1);
		rank.resize(n+1, 1);
		for(int i = 0 ; i <= n ; i++) parent[i] = i;
	}	
	
	int findUPar(int u){
		if(parent[u] == u) return u;
		return parent[u] = findUPar(parent[u]);
	}

	void unionBySize(int u , int v){
		int ult_par_u = findUPar(u);
		int ult_par_v = findUPar(v);

		if(ult_par_u == ult_par_v) return;

		if(size[ult_par_u] > size[ult_par_v]){
			parent[ult_par_v] = parent[ult_par_u];
			size[ult_par_u] += size[ult_par_v];
		}
		else{
			parent[ult_par_u] = parent[ult_par_v];
			size[ult_par_v] += size[ult_par_u];
		}
	}

	void unionByRank(int u , int v){
		int ult_par_u = findUPar(u);
		int ult_par_v = findUPar(v);

		if(ult_par_u == ult_par_v) return ;

		if(rank[ult_par_u] > rank[ult_par_v]){
			parent[ult_par_v] = parent[ult_par_u];
		}
		else if(rank[ult_par_v] < rank[ult_par_u]){
			parent[ult_par_u] = parent[ult_par_v];
		}
		else{
			parent[ult_par_u] = parent[ult_par_v];
			rank[ult_par_v]++;
		}
	}
};

int main(){
	DisjointSet ds1(7);

	ds1.unionByRank(1 , 2);
	ds1.unionByRank(1 , 3);
	
	if(findUPar(5) == findUPar(3)) cout<<"Belong to same root"<<endl;
	else cout<<"not same"<<endl;

	ds1.unionByRank(5 , 2);
	ds1.unionByRank(4 , 5);
	ds1.unionByRank(7 , 1);

}
