#include <bits/stdc++.h>
using namespace std;
int main() {
    try {
        int num;
        cout << "Enter a number: ";
        cin >> num;

        if (num == 0) {
            throw runtime_error("Error! Division by zero is not allowed.");
        }

        double result = 10.0 / num;
        cout << "The result is: " << result << endl;
    }
    catch (const runtime_error& e) {
        cerr << e.what() << endl;
    }

    cout << "Execution completed." << endl;
    return 0;
}
