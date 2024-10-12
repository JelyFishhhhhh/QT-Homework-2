#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

template<class T>
class List {
private:
    T** data;
    int n;
public:
    List()
        : data(nullptr),
        n(0)
    {
    }

    List(int n)
        : n(n)
    {
        data = new T * [n];
        for (int i = 0; i < n; ++i) {
            data[i] = new T();
        }
    }

    ~List() {
        for (int i = 0; i < n; ++i) {
            delete data[i];
        }
        delete[] data;
    }

    void insertAt(int x, const T& value) { // Pass value by reference
        if (x >= n) {
            T** newData = new T * [x + 1];
            for (int i = 0; i < n; ++i) {
                newData[i] = data[i];
            }
            for (int i = n; i <= x; ++i) {
                newData[i] = new T();
            }
            delete[] data;
            data = newData;
            n = x + 1;
        }
        *data[x] = value;
    }

    T getAt(int x) {
        if (x < n) {
            return *data[x];
        }
        throw out_of_range("Index out of range");
    }

    void sort() {
        std::sort(data, data + n, [](T* a, T* b) { return *a < *b; });
    }

    void unique() {
        set<T> seen;
        int uniqueCount = 0;
        for (int i = 0; i < n; ++i) {
            if (seen.find(*data[i]) == seen.end()) {
                seen.insert(*data[i]);
                if (uniqueCount != i) {
                    *data[uniqueCount] = *data[i];
                }
                ++uniqueCount;
            }
        }

        for (int i = uniqueCount; i < n; ++i) {
            delete data[i];
        }
        n = uniqueCount;
    }

    List operator+(const List& list) {
        List newList(n + list.n);
        for (int i = 0; i < n; ++i) {
            *newList.data[i] = *data[i];
        }
        for (int i = 0; i < list.n; ++i) {
            *newList.data[n + i] = *list.data[i];
        }
        return newList;
    }

    friend istream& operator>>(istream& is, List& list) {
        for (int i = 0; i < list.n; ++i) {
            is >> *list.data[i];
        }
        return is;
    }

    friend ostream& operator<<(ostream& os, const List& list) { // Pass list by reference
        for (int i = 0; i < list.n; ++i) {
            os << *list.data[i] << " ";
        }
        return os;
    }
};

int main() {
    int n;
    cout << "Input number of elements of list A: ";
    cin >> n;
    List<int> A(n);
    cout << "Enter elements: ";
    cin >> A;

    int m;
    cout << "\nInput number of elements of list B: ";
    cin >> m;
    List<int> B(m);
    cout << "Enter elements: ";
    cin >> B;

    List<int> C = A + B;
    cout << "List C = A + B: " << C << endl;

    C.insertAt(9, 6);
    cout << "List C after insert 6: " << C << endl;

    C.sort();
    cout << "List C after sorting: " << C << endl;

    C.unique();
    cout << "List C after unique: " << C << endl;

    return 0;
}