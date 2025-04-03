#include <iostream>

long long powerMod(long long a, long long b, long long m) {
    long long result = 1;
    a = a % m;

    while (b > 0) {
        if (b & 1) result = (result * a) % m;
        a = (a * a) % m;
        b >>= 1; 
    }
    return result;
}

int main() {
    // (a pow b) % m
    long long a = 2, b = 1000000000, m = 1000000007;
    std::cout << powerMod(a, b, m) << std::endl;
    return 0;
}
