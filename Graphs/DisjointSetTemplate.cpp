class DisjointSet{
	vector<int> rank , parent ,size;
	public:
	DisjointSet(int n){
		rank.resize(n+1, 1);
		parent.resize(n+1, 1);
		rank.resize(n+1, 1);
		for(int i = 0 ; i <= n ; i++) parent[i] = i;
	}	
	
	int find(int u){
		if(parent[u] == u) return u;
		return parent[u] = find(parent[u]);
	}
	
	void merge(int u , int v){
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

	void reset(){
		for(int i = 0 ; i <= n ; i++) parent[i] = i;
		for(int i = 0 ; i <= n ; i++) rank[i] = 0;	
	}
};
