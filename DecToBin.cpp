#include <bits/stdc++.h>

using namespace std;

void decToBin(int n){
    int binaryNum[32];
    int i, count = 0;
    while (n > 0) {
        binaryNum[i] = n % 2;
        n = n / 2;
        i = i + 1;
    }
    for (int j = i - 1; j >= 0; j--) {
        cout << binaryNum[j];
    }
    cout << "\n" ;
    for (int k = i - 1; k >= 0; k--) {
        if (binaryNum[k] == 1) {
            count = count + 1;
        }
        else{
            count = count;
        }
    }
    cout << count << "\n";
}

int main() {
    int n;
    cin >> n;
    decToBin(n);
    return 0;
}
