#include <iostream>
#include <fstream>
#include <vector>
#include <string>
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

void mergeSortBottomUp(vector<double>& a) {
    int n = (int)a.size();
    vector<double> temp(n);
    vector<double>* src = &a;
    vector<double>* dst = &temp;

    for (int width = 1; width < n; width *= 2) {
        for (int low = 0; low < n; low += 2 * width) {
            int mid = min(low + width - 1, n - 1);
            int high = min(low + 2 * width - 1, n - 1);

            int i = low, j = mid + 1, k = low;
            while (i <= mid && j <= high) {
                if ((*src)[i] <= (*src)[j]) (*dst)[k++] = (*src)[i++];
                else                        (*dst)[k++] = (*src)[j++];
            }
            while (i <= mid)  (*dst)[k++] = (*src)[i++];
            while (j <= high) (*dst)[k++] = (*src)[j++];
        }
        swap(src, dst);
    }

    if (src != &a) a = temp;
}

int main() {
    ofstream fout("mergesort_results.csv");
    fout << "input,time_ms\n";

    for (int k = 1; k <= 10; k++) {
        string filename = "input" + to_string(k) + ".txt";
        cout << "[" << k << "/10] Dang doc " << filename << " ... ";

        vector<double> a = readFile(filename);
        cout << a.size() << " phan tu. ";

        auto start = high_resolution_clock::now();
        mergeSortBottomUp(a);
        auto end = high_resolution_clock::now();

        double ms = duration<double, milli>(end - start).count();
        cout << "=> " << fixed << setprecision(3) << ms << " ms\n";
        fout << k << "," << fixed << setprecision(3) << ms << "\n";
    }

    fout.close();
    cout << "\nHoan tat! Ket qua: mergesort_results.csv\n";
    return 0;
}