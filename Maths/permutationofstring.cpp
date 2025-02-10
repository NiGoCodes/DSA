#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mod 1000000007
#define yes cout<<"yes\n"
#define no cout<<"no\n"

using namespace std;

void permutaion(string s){
	sort(s.begin(),s.end());
	sort(s.begin(),s.end());
	do{
		cout<<s<<"\n";
	}while(next_permutation(s.begin() , s.end()));
}

int32_t main() {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int test = 1; 
   string s;
   s = "3215";
   while(test--){
      permutaion(s);
   }
   return 0;
}

//n is the size of string
//TC -> O(nlogn) + O(n*n!) -> O(n*n!)