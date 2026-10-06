
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

void heapify(vector<double>& a, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left  < n && a[left]  > a[largest]) largest = left;
    if (right < n && a[right] > a[largest]) largest = right;

    if (largest != i) {
        swap(a[i], a[largest]);
        heapify(a, n, largest);  
    }
}

void heapSort(vector<double>& a) {
    int n = (int)a.size();

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i);

    for (int i = n - 1; i > 0; i--) {
        swap(a[0], a[i]);
        heapify(a, i, 0);
    }
}

int main() {
    ofstream fout("heapsort_results.csv");
    fout << "input,time_ms\n";

    for (int k = 1; k <= 10; k++) {
        string filename = "input" + to_string(k) + ".txt";
        cout << "[" << k << "/10] Dang doc " << filename << " ... ";

        vector<double> a = readFile(filename);
        cout << a.size() << " phan tu. ";

        auto start = high_resolution_clock::now();
        heapSort(a);
        auto end = high_resolution_clock::now();

        double ms = duration<double, milli>(end - start).count();
        cout << "=> " << fixed << setprecision(3) << ms << " ms\n";
        fout << k << "," << fixed << setprecision(3) << ms << "\n";
    }

    fout.close();
    cout << "\nHoan tat! Ket qua: heapsort_results.csv\n";
    return 0;
}