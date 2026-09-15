#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <cmath>
#include <iomanip>
#include <algorithm>
using namespace std;

// bubble sort
template <typename T>
void bubbleSort(vector<T>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
    }
}

// Insertion Sort 
template <typename T>
void insertionSort(vector<T>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        T key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

//  Merge Sort 
template <typename T>
void merge(vector<T>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<T> L(n1), R(n2);
    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int i = 0; i < n2; i++) R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2)
        arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

template <typename T>
void mergeSort(vector<T>& arr, int left, int right) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

template <typename T>
void printVector(const vector<T>& v) {
    for (const auto& x : v) cout << x << " ";
    cout << endl;
}



void question2(vector<float>& bigArray) {
    int size = 100000;
    bigArray.resize(size);

    for (int i = 0; i < size; i++) {
        bigArray[i] = static_cast<float>(rand()) / RAND_MAX * 50000.0f;
    }


    cout << "random numbers:\n";
    for (int i = 0; i < 30; i++)
        cout << bigArray[i] << " ";
    cout << endl;

    // Mean
    double sum = 0;
    for (float x : bigArray) sum += x;
    double mean = sum / size;

    // Standard dev
    double sqSum = 0;
    for (float x : bigArray) sqSum += (x - mean) * (x - mean);
    double stdDev = sqrt(sqSum / size);

    cout << "Mean = " << mean << endl;
    cout << "Standard Deviation = " << stdDev << endl;
}


template <typename T>
long long measureSortTime(void (*sortFunc)(vector<T>&),
    vector<T> arr,
    string name) {
    auto start = chrono::high_resolution_clock::now();
    sortFunc(arr);   
    auto end = chrono::high_resolution_clock::now();

    long long duration = chrono::duration_cast<chrono::milliseconds>(end - start).count();
    cout << name << " sort time: " << duration << " ms" << endl;
    return duration;
}

template <typename T>
long long measureMergeTime(vector<T> arr, string name) {
    auto start = chrono::high_resolution_clock::now();
    mergeSort(arr, 0, arr.size() - 1);
    auto end = chrono::high_resolution_clock::now();

    long long duration = chrono::duration_cast<chrono::milliseconds>(end - start).count();
    cout << name << " sort time: " << duration << " ms" << endl;
    return duration;
}



int main() {
    srand(time(NULL));

    int x[] = { 1,2,3,4,5,6,8,7,8,9,10,11,12,13,0,14,15,16,17,18,19 };
    char y[] = { 'C','h','a','t','G','p','t' };
    string z[] = { "good","morning","Dearborn","Data","Structure","class" };

    vector<int> vx(x, x + 21);
    vector<char> vy(y, y + 7);
    vector<string> vz(z, z + 6);

   
    cout << " Bubble sorted: ";
    vector<int> bx = vx; bubbleSort(bx);
    cout << "Bubble sorted int: "; printVector(bx);

    vector<char> by = vy; bubbleSort(by);
    cout << "Bubble sorted char: "; printVector(by);

    vector<string> bz = vz; bubbleSort(bz);
    cout << "Bubble sorted string: "; printVector(bz);

    
    cout << "Insertion sorted: ";
    vector<int> ix = vx; insertionSort(ix);
    cout << "Insertion sorted int: "; printVector(ix);

    vector<char> iy = vy; insertionSort(iy);
    cout << "Insertion sorted char: "; printVector(iy);

    vector<string> iz = vz; insertionSort(iz);
    cout << "Insertion sorted string: "; printVector(iz);

    // Merge
    cout << "Merge sorted: ";
    vector<int> mx = vx; mergeSort(mx, 0, mx.size() - 1);
    cout << "Merge sorted int: "; printVector(mx);

    vector<char> my = vy; mergeSort(my, 0, my.size() - 1);
    cout << "Merge sorted char: "; printVector(my);

    vector<string> mz = vz; mergeSort(mz, 0, mz.size() - 1);
    cout << "Merge sorted string: "; printVector(mz);


    
    vector<float> bigArray;
    question2(bigArray);


   

    vector<float> arr1 = bigArray;
    vector<float> arr2 = bigArray;
    vector<float> arr3 = bigArray;

    measureSortTime<float>(bubbleSort, arr1, "Bubble");
    measureSortTime<float>(insertionSort, arr2, "Insertion");
    measureMergeTime<float>(arr3, "Merge");




    return 0;
}

