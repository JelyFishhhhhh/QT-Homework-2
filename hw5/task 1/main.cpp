#include <iostream>
#include "Fraction.h"     // from ch3 ex1

using namespace std;

template <typename T>
T theMax(T& a, T& b) {
    // if(a> b){

    //     return a;
    // }
    // else{
    //     return b;
    // }
    return (a < b) ? b : a;
}

template <typename T>
T theMin(T& a, T& b) {
    return (a > b) ? b : a;
}

template<typename T>
T smallestNeg(T* arr, size_t size) {
    T minNeg = T();
    for (size_t i = 0; i < size; i++) {
        if (arr[i] < T() && arr[i] < minNeg) {
            minNeg = arr[i];
        }
    }
    return minNeg;
}

template<typename T>
T largestPos(T* arr, size_t size) {
    T maxPos = T();
    for (size_t i = 0; i < size; i++) {
        if (arr[i] > T() && arr[i] > maxPos) {
            maxPos = arr[i];
        }
    }
    return maxPos;
}

template<typename T>
void sort(T* arr, size_t size) {
    for (size_t i = 0; i < size - 1; i++) {
        for (size_t j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                T tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}

int main(){

    // integer
    cout<< "::INTEGER::\n";
    int i_a= 5, i_b= 1, i_d[7]= {1, 5, 9, 100, 3, -1, 9};
    int* i_c= new int[7]();
    for(int i= 0; i< 7; i++){

        i_c[i]= i_d[i];
    }
    cout<< "The maximum between a and b: "<< theMax<int>(i_a, i_b)<< '\n';
    cout<< "The minimum between a and b: "<< theMin<int>(i_a, i_b)<< '\n';
    cout<< "\nThe array\n";
    for(int i= 0; i< 7; i++){

        cout<< i_c[i]<< ' ';
    }
    cout<< '\n';
    cout<< "The Smallest Negative element is: "<< smallestNeg<int>(i_c, 7)<< '\n';
    cout<< "The Largest Position element is: "<< largestPos<int>(i_c, 7)<< '\n';
    cout<< "\nThe original array\n";
    for(int i= 0; i< 7; i++){

        cout<< i_c[i]<< ' ';
    }
    cout<< '\n';
    cout<< "* sorted array. *\n";
    sort<int>(i_c, 7);
    cout<< "The sorted array\n";
    for(int i= 0; i< 7; i++){

        cout<< i_c[i]<< ' ';
    }
    cout<< '\n';

    delete[] i_c;

    cout<< "\n\n";
    
    // double
    cout<< "::DOUBLE::\n";
    double d_a= 5.5, d_b= 1.1, d_d[7]= {1.1, 5.3, 9.5, 100.0, 3.2, -1.4, 9.6};
    double* d_c= new double[7]();
    for(int i= 0; i< 7; i++){

        d_c[i]= d_d[i];
    }
    cout<< "The maximum between a and b: "<< theMax<double>(d_a, d_b)<< '\n';
    cout<< "The minimum between a and b: "<< theMin<double>(d_a, d_b)<< '\n';
    cout<< "\nThe array\n";
    for(int i= 0; i< 7; i++){

        cout<< d_c[i]<< ' ';
    }
    cout<< '\n';
    cout<< "The Smallest Negative element is: "<< smallestNeg<double>(d_c, 7)<< '\n';
    cout<< "The Largest Position element is: "<< largestPos<double>(d_c, 7)<< '\n';
    cout<< "\nThe original array\n";
    for(int i= 0; i< 7; i++){

        cout<< d_c[i]<< ' ';
    }
    cout<< '\n';
    cout<< "* sorted array. *\n";
    sort<double>(d_c, 7);
    cout<< "The sorted array\n";
    for(int i= 0; i< 7; i++){

        cout<< d_c[i]<< ' ';
    }
    cout<< '\n';

    delete[] d_c;
    
    // Fraction
    cout << "::FRACTION::\n";
    Fraction f_a(5, 3), f_b(5, 4);
    Fraction* f_c = new Fraction[7]();
    for (int i = 0; i < 7; i++) {
        f_c[i] = (f_a + Fraction(i+ 1, (i+ 1) * (i % 2 ? -1 : 1)))* (i % 2 ? -1 : 1);
        // cout<< f_c[i]<< ' ';
    }

    Fraction buf= theMax<Fraction>(f_a, f_b);
    cout << "The maximum between a and b: " << buf << '\n';
    buf= theMin<Fraction>(f_a, f_b);
    cout << "The minimum between a and b: " << buf << '\n';
    cout << "\nThe array\n";
    for (int i = 0; i < 7; i++) {
        cout << f_c[i] << ", ";
    }
    cout << '\n';
    buf= smallestNeg<Fraction>(f_c, 7);
    cout << "The Smallest Negative element is: " << buf << '\n';
    buf= largestPos<Fraction>(f_c, 7);
    cout << "The Largest Position element is: " << buf << '\n';
    cout << "\nThe original array\n";
    for (int i = 0; i < 7; i++) {
        cout << f_c[i] << ' ';
    }
    cout << '\n';
    cout << "* sorted array. *\n";
    sort<Fraction>(f_c, 7);
    cout << "The sorted array\n";
    for (int i = 0; i < 7; i++) {
        cout << f_c[i] << ' ';
    }
    cout << '\n';

    delete[] f_c;

}