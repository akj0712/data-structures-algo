// The first few Catalan numbers for n = 0, 1, 2, 3, … are 1, 1, 2, 5, 14, 42, 132, 429, 1430, 4862, …

#include <bits/stdc++.h>

using namespace std;

unsigned long int catalan(int n){
    if (n <= 1) {
        return 1;
    }
    // catalan(n) is sum catalan(i)*catalan(n-i-1)
    unsigned long int res = 0;
    for (int i = 0; i < n; i++) {
    res = res + catalan(i)*catalan(n - i - 1);
    }
    return res;
}

// Driver Code
int main(void)
{
    int n;
    cin >> n;
    for (int i = 0; i <= n; i++) {
        cout << catalan(i) << " ";
    }
    std::cout << "" << '\n';
    return 0;
}
