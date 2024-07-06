//To print prime numbers 2 to n
#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mod 1000000007

using namespace std;

void SeiveOfEratosthenes(int n) {
    vector<int> prime(n+1 , 1);
    prime[0] = prime[1] = 0; // 0 and 1 are not primes
    for(int i = 2; i * i <= n; i++) {
        if(prime[i] == 1) {
            for (int j = i * i; j <= n; j += i) {
                prime[j] = 0;
            }
        }
    }

    for(int i = 2; i <= n; i++) {
        if(prime[i] == 1) cout << i << " ";
    }
    cout << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; 
    //cin >> t;  
    while(t--) {
        int n;
        cin >> n;
        SeiveOfEratosthenes(n);
    }
    return 0;
}
