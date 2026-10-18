
#include <iostream>
using namespace std;

int main() {
    double nilai;

    cout << "=== Program Huruf Mutu ===\n";
    cout << "Masukkan nilai: ";
    cin >> nilai;

    switch (static_cast<int>(nilai) / 10) {
        case 10:
        case 9:
        case 8:
            cout << "Huruf mutu: A\n";
            break;

        case 7:
            cout << "Huruf mutu: B\n";
            break;

        case 6:
            cout << "Huruf mutu: C\n";
            break;

        case 5:
        case 4:
            cout << "Huruf mutu: D\n";
            break;

        default:
            cout << "Huruf mutu: E\n";
            break;
    }

    return 0;
}
