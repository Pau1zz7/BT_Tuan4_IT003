Thực nghiệm các thuật toán sắp xếp



Sinh viên: \[Nguyễn Hoàng Phúc - 24521388]  

Lớp: IT003.R17  

Mô tả

So sánh thời gian thực thi 4 thuật toán sắp xếp:

\- QuickSort (pivot = phần tử giữa)

\- HeapSort (max-heap)

\- MergeSort (đệ quy)

\- std::sort (C++ STL - introsort)



Trên bộ dữ liệu gồm 10 dãy, mỗi dãy 1.000.000 số thực.



Cách chạy



1\. Sinh dữ liệu

bash

g++ -O2 -std=c++17 src/generate\_data.cpp -o generate\_data

./generate\_data

2\. Chạy từng thuật toán

bash

g++ -O2 -std=c++17 src/quicksort.cpp -o quicksort

./quicksort

\# (tương tự cho heapsort, mergesort, stl\_sort)

3\. Xem kết quả

Mở file csv trong MaNguon



Kết quả tóm tắt

Thuật toán	Thời gian trung bình (ms)

QuickSort	401.176

sort (C++)	423.330

MergeSort	450.749

HeapSort	1098.005

Chi tiết xem trong BaoCao/BaoCao.pdf.





