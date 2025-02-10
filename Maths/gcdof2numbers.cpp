#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mod 1000000007

using namespace std;
int gcd(int m , int n){
	if(m == 0 || n == 0) return 0;
	while(m!=0 && n!= 0){
		if(m >= n) m = m%n;
		else n = n%m;
	}
	if(m == 0) return n;
	if(n == 0) return m;
}
int32_t main() {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int t = 1; 
   //cin >> t;  
   while(t--){
        int m,n;
        cin>>m>>n;
       int x = gcd(m,n);
       cout<<x;
   }
   return 0;
}