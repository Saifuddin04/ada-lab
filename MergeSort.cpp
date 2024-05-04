//This code is copied from https://gitlab.com/lab_manuals/current/iv-semester/bcdl404_analysis_and_design_of_algorithms_lab/-/blob/main/Programs/P11/11MergeSort.cpp?ref_type=heads
/******************************************************************************
*File		: 11MergeSort.cpp
*Description	: Program to sort an array using Merge Sort
*Author: Prabodh C P
*Compiler	: g++ compiler 11.4.0, Ubuntu 22.04
*Date		: 31 Mar 2024
******************************************************************************/
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

class MergeSort{
    vector <int> numList;
    int iNum;
    public:

    void fnGenRandArray(int);
    void fnSortArray(int, int);
    void fnDispArray();
    void fnMerge(int ,int ,int);
};

int main( int argc, char **argv)
{

    struct timespec tv;
    int iChoice, i, iNum;
    double dStart, dEnd;
    MergeSort myListObj;
	ofstream fout("MergePlot.dat", ios::out);
    for(;;)
    {
        cout << "\n1.MergeSort\n2.Plot the Graph\n3.Exit" ;
        cout << "\nEnter your choice\n";
        cin >> iChoice;
        switch(iChoice)
        {
            case 1:
                    cout << "\nEnter number of elements to sort : "; cin >> iNum;
                    myListObj.fnGenRandArray(iNum);
                    cout << "\nUnsorted Array" << endl;
                    myListObj.fnDispArray();
                    myListObj.fnSortArray(0,iNum-1);
                    cout << "\nSorted Array" << endl;
                    myListObj.fnDispArray();
                    break;

            case 2: for(i=100;i<100000;i+=100)
                    {
                        myListObj.fnGenRandArray(i);
                        clock_gettime(CLOCK_REALTIME, &tv);
                        dStart = tv.tv_sec + tv.tv_nsec/1000000000.0;
                        myListObj.fnSortArray(0,i-1);
                        clock_gettime(CLOCK_REALTIME, &tv);
                        dEnd = tv.tv_sec + tv.tv_nsec/1000000000.0;

                        fout << i << "\t" << setprecision(10) << dEnd - dStart << endl;
                    }
                    cout << "\nData File generated and stored in file < MergePlot.dat >.\n Use a plotting utility\n";
                    break;
            case 3:
                    exit(0);
        }
    }
    fout.close();
    return 0;
}

void MergeSort::fnGenRandArray(int n)
{
    int i, iVal;
	numList.clear();
	srand(time(NULL));
	for(i=0;i<n;i++)
	{
        iVal = rand()%10000;
        numList.push_back(iVal);
	}
	iNum = n;
}

void MergeSort::fnDispArray()
{
    int i;
	for(i=0;i<iNum;i++)
	{
        cout << setw(8) << numList[i] << endl;
    }
}


void MergeSort::fnSortArray(int low,int high)
{
	int mid;
	if(low<high)
	{
		mid=(low+high)/2;
		fnSortArray(low,mid);
		fnSortArray(mid+1,high);
		fnMerge(low,mid,high);
	}
}

void MergeSort::fnMerge(int low,int mid,int high)
{
    vector <int> b(0);
	int  i,j;
	i=low;
	j=mid+1;
	int k=0;
	while(i<=mid && j<=high)
	{
		if(numList[i]<numList[j])
            b.push_back(numList[i++]);
		else
            b.push_back(numList[j++]);
	}
	while(i<=mid)
        b.push_back(numList[i++]);
	while(j<=high)
        b.push_back(numList[j++]);
    for (i=low;i<=high;i++)
    {
    	numList[low+k] = b[k];
    	k++;
    }
}
