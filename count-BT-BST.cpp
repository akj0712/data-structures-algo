// C++ code for finding count of BSTs and Binary Trees with n numbers

#include <bits/stdc++.h>

using namespace std;

unsigned long int fact(int n){
    if (n <= 1) {
        return 1;
    }
    return n*fact(n-1);
}
unsigned long int catalan(int n){
    if (n <= 1) {
        return 1;
    }
    unsigned long int res = 0;
    for (int i = 0; i < n; i++) {
        res = res + catalan(i)*catalan(n-i-1);
    }
    return res;
}

int main(void){
    unsigned long int n, count1, count2;
    std::cout << "Enter the number of nodes: ";
    std::cin >> n;

    count1 = catalan(n);
    count2 = fact(n)*count1;

    std::cout << "Count of BST with " << n << " nodes is : " << count1 << "\n";

    std::cout << "Count of BT with " << n << " nodes is : " << count2 << "\n";

    return 0;
}
