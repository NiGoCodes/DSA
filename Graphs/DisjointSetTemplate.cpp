class DisjointSet{
    vector<int> rank , parent;
    int n;
    public:
    DisjointSet(int x){
        n = x;
        rank.resize(n+1, 0);
        parent.resize(n+1);
        for(int i = 0 ; i <= n ; i++) parent[i] = i;
    }   
    
    int find(int u){
        if(parent[u] == u) return u;
        return parent[u] = find(parent[u]);
    }
    
    void merge(int u , int v){
        int ult_par_u = find(u);
        int ult_par_v = find(v);

        if(ult_par_u == ult_par_v) return ;

        if(rank[ult_par_u] > rank[ult_par_v]){
            parent[ult_par_v] = ult_par_u;
        }
        else if(rank[ult_par_v] > rank[ult_par_u]){
            parent[ult_par_u] = ult_par_v;
        }
        else{
            parent[ult_par_u] = ult_par_v;
            rank[ult_par_v]++;
        }
    }
  };
