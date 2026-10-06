#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <chrono>   // đo thời gian
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
    a.reserve(1000000);   // cấp trước bộ nhớ cho 1 triệu phần tử 
    double x;
    while (fin >> x) {
        a.push_back(x);
    }
    fin.close();
    return a;
}

int partition(vector<double>& a, int low, int high) {
    int mid = low + (high - low) / 2;
    double pivot = a[mid];

    swap(a[mid], a[low]);

    int i = low + 1;
    int j = high;

    while (true) {
        while (i <= j && a[i] < pivot) i++;
        while (i <= j && a[j] > pivot) j--;

        if (i >= j) break;
        swap(a[i], a[j]);
        i++;
        j--;
    }
    swap(a[low], a[j]);
    return j;
}

void quickSort(vector<double>& a, int low, int high) {
    if (low >= high) return;
    int p = partition(a, low, high);
    quickSort(a, low, p - 1);
    quickSort(a, p + 1, high);
}

int main() {
    for (int k = 1; k <= 10; k++) {
        string filename = "input" + to_string(k) + ".txt";
        vector<double> a = readFile(filename);

        auto start = high_resolution_clock::now();
        quickSort(a, 0, (int)a.size() - 1);
        auto end = high_resolution_clock::now();

        double ms = duration<double, milli>(end - start).count();
        cout << "input" << k << ".txt: " << fixed << setprecision(3)
            << ms << " ms\n";
    }
    return 0;
}