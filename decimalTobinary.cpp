#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mod 1000000007
#define yes cout<<"yes\n"
#define no cout<<"no\n"

using namespace std;

string decimalTobinary(int n){
	if(n == 0) return "0";

	string str;
	while(n){
		if(n%2 != 0) str += "1";
		else str += "0";

		n/=2;
	}
	reverse(str.begin(),str.end());
	return str;
}

int32_t main() {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   

   string str = decimalTobinary(0);
   cout<<str<<'\n';
   return 0;
}