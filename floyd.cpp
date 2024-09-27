//wap in cpp to print recursive floyd triangle
#include <iostream>
using namespace std;
void floyd(int row, int n, int &val) {
    if (row > n) return;
    for (int i = 1; i <= row; ++i) {
        cout << val << " ";
        ++val;
    }
    cout << endl;
    floyd(row + 1, n, val);
}
int main() {
    int n, val = 1;
    cout << "Enter number of rows: ";
    cin >> n;
    floyd(1, n, val);
    return 0;
}

