#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    int n, q;
    cin >> n >> q;
    int **a = new int*[n];
    int **qr = new int*[q];
    for (int i = 0; i < n; i++)
    {
        int length;
        cin >> length;
        a[i] = new int[length];
        for (int j = 0; j < length; ++j)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < q; i++)
    {
        qr[i] = new int[2];
        for (int j = 0; j < 2; j++)
        {
            cin >> qr[i][j];
        }
    }

    for (int i = 0; i < q; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << qr[i][j] << " ";
        }
        cout << endl;
    }
    
    // for (int i = 0; i < q; i++)
    // {
    //     int index = qr[i][0];
    //     cout << a[index][qr[0][1]] << endl;
    // }
    return 0;
}