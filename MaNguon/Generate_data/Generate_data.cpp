#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <random>
#include <iomanip>
using namespace std;

const int N = 1000000;
const double MAX_VAL = 1000000.0;

int writeToFile(const vector<double>& a, const string& filename) {
    ofstream fout(filename);
    if (!fout) {
        cerr << "Loi: khong mo duoc file " << filename << "\n";
        exit(1);
    }
    fout << fixed << setprecision(6);
    int count = 0;
    for (double x : a) {
        fout << x << "\n";
        count++;
    }
    fout.close();
    return count;
}

int main() {
    mt19937 rng(42);
    uniform_real_distribution<double> dist(0.0, MAX_VAL);

    vector<double> a(N);

    for (int i = 0; i < N; i++) a[i] = i * 1.0;
    int c1 = writeToFile(a, "input1.txt");
    cout << "input1.txt: " << c1 << " phan tu\n";

    for (int i = 0; i < N; i++) a[i] = (N - i) * 1.0;
    int c2 = writeToFile(a, "input2.txt");
    cout << "input2.txt: " << c2 << " phan tu\n";

    for (int k = 3; k <= 10; k++) {
        for (int i = 0; i < N; i++) a[i] = dist(rng);
        string filename = "input" + to_string(k) + ".txt";
        int c = writeToFile(a, filename);
        cout << filename << ": " << c << " phan tu\n";
    }

    cout << "\nHoan tat! Tat ca file phai co dung " << N << " phan tu.\n";
    return 0;
}