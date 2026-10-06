
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>     
#include <chrono>
#include <iomanip>
using namespace std;
using namespace chrono;

vector<double> readFile(const string& filename) {
    ifstream fin(filename);
    if (!fin) {
        cerr << "Khong mo duoc file: " << filename << "\n";
        exit(1);
    }
    vector<double> a;
    a.reserve(1000000);
    double x;
    while (fin >> x) a.push_back(x);
    fin.close();
    return a;
}

int main() {
    ofstream fout("stl_sort_results.csv");
    fout << "input,time_ms\n";

    for (int k = 1; k <= 10; k++) {
        string filename = "input" + to_string(k) + ".txt";
        cout << "[" << k << "/10] Dang doc " << filename << " ... ";

        vector<double> a = readFile(filename);
        cout << a.size() << " phan tu. ";

        auto start = high_resolution_clock::now();
        sort(a.begin(), a.end());       
        auto end = high_resolution_clock::now();

        double ms = duration<double, milli>(end - start).count();
        cout << "=> " << fixed << setprecision(3) << ms << " ms\n";
        fout << k << "," << fixed << setprecision(3) << ms << "\n";
    }

    fout.close();
    cout << "\nHoan tat! Ket qua: stl_sort_results.csv\n";
    return 0;
}