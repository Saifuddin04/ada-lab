#include <iostream>
#include <vector>
#include <ctime>
#include <iomanip>
#include <cstdlib>
#include <fstream>

using namespace std;

class Sort {
protected:
    vector<int> numList;
	int n;
public:
	Sort() {
		cout << "\nEnter number of elements to sort : "; cin >> n;
		fnGenRandArray(n);
		cout << "\nUnsorted Array" << endl;
		fnDispArray();
	}
    virtual void sortArray(int low, int high){}
    
	void fnGenRandArray(int n) {
        numList.clear();
        srand(time(NULL));
        for(int i = 0; i < n; i++) {
            int iVal = rand() % 10000;
            numList.push_back(iVal);
        }
    }

    void fnDispArray() {
        for(int i = 0; i < numList.size(); i++) {
            cout << setw(8) << numList[i] << endl;
        }
    }

    void fnSwap(int &a, int &b) {
        int t = a;
        a = b;
        b = t;
    }

    virtual void plotGraph(ofstream& fout) = 0;
};

class MergeSort : public Sort {
public:
    MergeSort(){
      sortArray(0, n - 1);
		  cout << "\nSorted Array using Merge Sort" << endl;
		  fnDispArray();
    }

    void sortArray(int low, int high) override {
        if (low < high) {
            int mid = low + (high - low) / 2;
            sortArray(low, mid);
            sortArray(mid + 1, high);
            merge(low, mid, high);
        }
    }

    void merge(int low, int mid, int high) {
        vector<int> temp(numList.begin() + low, numList.begin() + high + 1);
        int i = low, j = mid + 1, k = low;

        while (i <= mid && j <= high) {
            if (temp[i - low] <= temp[j - low]) {
                numList[k++] = temp[i - low];
                i++;
            } else {
                numList[k++] = temp[j - low];
                j++;
            }
        }

        while (i <= mid) {
            numList[k++] = temp[i - low];
            i++;
        }

        while (j <= high) {
            numList[k++] = temp[j - low];
            j++;
        }
    }
	
	void plotGraph(ofstream& fout) {
        for (int i = 100; i < 100000; i += 100) {
            fnGenRandArray(i);
            struct timespec tv;
            double dStart, dEnd;

            clock_gettime(CLOCK_REALTIME, &tv);
            dStart = tv.tv_sec + tv.tv_nsec / 1000000000.0;

            sortArray(0, i - 1);

            clock_gettime(CLOCK_REALTIME, &tv);
            dEnd = tv.tv_sec + tv.tv_nsec / 1000000000.0;

            fout << i << "\t" << setprecision(10) << dEnd - dStart << endl;
        }
        cout << "\nData File generated and stored in file < sort.dat >. Use a plotting utility\n";
    }
};

class QuickSort : public Sort {
public:

    QuickSort(){
		  sortArray(0, n - 1);
		  cout << "\nSorted Array using Quick Sort" << endl;
		  fnDispArray();
    }
    
    void sortArray(int low, int high) override {
        if (low < high) {
            int pivot = partition(low, high);
            sortArray(low, pivot - 1);
            sortArray(pivot + 1, high);
        }
    }

    int partition(int low, int high) {
        int pivot = numList[high];
        int i = low - 1;

        for (int j = low; j < high; j++) {
            if (numList[j] <= pivot) {
                i++;
                fnSwap(numList[i], numList[j]);
            }
        }

        fnSwap(numList[i + 1], numList[high]);
        return i + 1;
    }
	void plotGraph(ofstream& fout) {
        for (int i = 100; i < 100000; i += 100) {
            fnGenRandArray(i);
            struct timespec tv;
            double dStart, dEnd;

            clock_gettime(CLOCK_REALTIME, &tv);
            dStart = tv.tv_sec + tv.tv_nsec / 1000000000.0;

            sortArray(0, i - 1);

            clock_gettime(CLOCK_REALTIME, &tv);
            dEnd = tv.tv_sec + tv.tv_nsec / 1000000000.0;

            fout << i << "\t" << setprecision(10) << dEnd - dStart << endl;
        }
        cout << "\nData File generated and stored in file < sort.dat >. Use a plotting utility\n";
    }
};

class BubbleSort : public Sort {
public:
    BubbleSort(){
      sortArray(0, n - 1);
		  cout << "\nSorted Array using Bubble Sort" << endl;
		  fnDispArray();
    }

    void sortArray(int low, int high) override {
        int n = numList.size();
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (numList[j] > numList[j + 1]) {
                    fnSwap(numList[j], numList[j + 1]);
                }
            }
        }
    }
	void plotGraph(ofstream& fout) {
        for (int i = 100; i < 100000; i += 100) {
            fnGenRandArray(i);
            struct timespec tv;
            double dStart, dEnd;

            clock_gettime(CLOCK_REALTIME, &tv);
            dStart = tv.tv_sec + tv.tv_nsec / 1000000000.0;

            sortArray(0, i - 1);

            clock_gettime(CLOCK_REALTIME, &tv);
            dEnd = tv.tv_sec + tv.tv_nsec / 1000000000.0;

            fout << i << "\t" << setprecision(10) << dEnd - dStart << endl;
        }
        cout << "\nData File generated and stored in file < sort.dat >. Use a plotting utility\n";
    }
};

class SelectionSort : public Sort {
public:
    SelectionSort(){
      sortArray(0, n - 1);
		  cout << "\nSorted Array using Selection Sort" << endl;
		  fnDispArray();
    }

    void sortArray(int low, int high) override {
        int n = numList.size();
        for (int i = 0; i < n - 1; i++) {
            int minIdx = i;
            for (int j = i + 1; j < n; j++) {
                if (numList[j] < numList[minIdx]) {
                    minIdx = j;
                }
            }
            fnSwap(numList[minIdx], numList[i]);
        }
    }
	void plotGraph(ofstream& fout) {
        for (int i = 100; i < 100000; i += 100) {
            fnGenRandArray(i);
            struct timespec tv;
            double dStart, dEnd;

            clock_gettime(CLOCK_REALTIME, &tv);
            dStart = tv.tv_sec + tv.tv_nsec / 1000000000.0;

            sortArray(0, i - 1);

            clock_gettime(CLOCK_REALTIME, &tv);
            dEnd = tv.tv_sec + tv.tv_nsec / 1000000000.0;

            fout << i << "\t" << setprecision(10) << dEnd - dStart << endl;
        }
        cout << "\nData File generated and stored in file < sort.dat >. Use a plotting utility\n";
    }
};

int main() {
    ofstream fout("sort.dat", ios::out);
    Sort *sortObj = nullptr;

    int iChoice;
    for (;;) {
        cout << "\n1.MergeSort\n2.QuickSort\n3.BubbleSort\n4.SelectionSort\n5.Plot the Graph for Selection Sort\n6.Plot the Graph for Quick Sort\n7.Plot the Graph for Merge Sort\n8.Plot the Graph for Bubble Sort\n9.Exit\n";
        cout << "\nEnter your choice: ";
        cin >> iChoice;

        switch (iChoice) {
            case 1: sortObj = new MergeSort();
                    break;
            case 2: sortObj = new QuickSort();
                    break;
            case 3: sortObj = new BubbleSort();
                    break;
            case 4: sortObj = new SelectionSort();
                    break;
            case 5: sortObj->plotGraph(fout);
                    break;
	    case 6: sortObj->plotGraph(fout);
                    break;
	    case 7: sortObj->plotGraph(fout);
                    break;
	    case 8: sortObj->plotGraph(fout);
                    break;
            case 9: fout.close();
                  delete sortObj;
                  return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}
