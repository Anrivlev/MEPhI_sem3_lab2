#include <complex.h>
#include "sortFunctions.h"
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;


void interface()
{

    int choose = 0;
    int size = -1;
    cout << "Enter the size of a sequence" << endl;
    while (size < 0)
    {
        cin >> size;
    }
    cout << endl;
    ArraySequence<int> *seq;
    cout << "Enter 1 to fill in the sequence with random numbers" << endl;
    cout << "Enter 2 to fill in the sequence manually" << endl;
    cout << "Enter 3 to generate a sorted sequence" << endl;
    cin >> choose;
    cout << endl;
    int arr[size];
    switch (choose)
    {
        case 1:
            seq = new ArraySequence<int>(size);
            srand(time(0));
            for (int i = 0; i < size; i++)
            {
                seq->set(rand(), i);
            }
            break;
        case 2:
            cout << "Enter " << size << " numbers to fill in the sequence" << endl;
            for (int i = 0; i < size; i++)
            {
                cin >> arr[i];
            }
            cout << endl;
            seq = new ArraySequence<int>(arr, size);
            break;
        case 3:
            cout << "Enter 1 to generate a sequence sorted in descending order" << endl;
            cout << "Enter 2 to generate a sequence sorted in ascending order" << endl;
            cin >> choose;
            cout << endl;
            seq = new ArraySequence<int>(size);
            if (choose == 1)
            {
                for (int i = 0; i < size; i++)
                {
                    seq->set(size - i - 1, i);
                }
            } else if (choose == 2)
            {
                for (int i = 0; i < size; i++)
                {
                    seq->set(i, i);
                }
            }
            break;
        default:
            break;
    }
    delete arr;
    ofstream fout("out.txt");
    cout << "The sequence is saved in out.txt" << endl;
    fout << "The sequence:" << endl;
    for (int i = 0; i < size; i++)
    {
        fout << seq->get(i) << " ";
    }
    cout << endl;
    fout << endl << endl;
    cout << "Enter 1 to sort in descending order" << endl;
    cout << "Enter 2 to sort in ascending order" << endl;
    cin >> choose;
    bool (*cmp)(int, int);
    switch (choose)
    {
        case 1:
            cmp = desc;
            break;
        case 2:
            cmp = asc;
            break;
        default:
            break;
    }
    cout << endl;
    cout << "Enter 1 to use Bubble sort" << endl;
    cout << "Enter 2 to use Merge sort" << endl;
    cout << "Enter 3 to use Quick sort" << endl;
    cout << "Enter 4 to run all of them and compare time spent" << endl;
    cout << "Enter 5 to use Bogosort. DO NOT USE on sequences with size >10)" << endl;
    cin >> choose;
    cout << endl;
    ArraySequence<int> *seq1;
    void (*algSort)(Sequence<int>*, bool (*)(int, int));
    double seconds = 0;
    switch (choose)
    {
        case 1:
            algSort = bubbleSort;
            seconds = getTimeSort(seq, algSort, cmp);
            cout << "Time spent on Bubble Sort: " << seconds << "seconds" << endl;
            break;
        case 2:
            algSort = mergeSort;
            seconds = getTimeSort(seq, algSort, cmp);
            cout << "Time spent on Merge Sort: " << seconds << "seconds" << endl;
            break;
        case 3:
            algSort = quickSort;
            seconds = getTimeSort(seq, algSort, cmp);
            cout << "Time spent on Quick Sort: " << seconds << "seconds" << endl;
            break;
        case 4:
            seq1 = new ArraySequence<int>(size);
            for (int i = 0; i < size; i++)
            {
                seq1->set(seq->get(i), i);
            }
            algSort = bubbleSort;
            seconds = getTimeSort(seq1, algSort, cmp);
            cout << "Time spent on Bubble Sort: " << seconds << "seconds" << endl;
            if (isSorted(seq1, cmp)) cout << "The sequence is sorted successfully" << endl;
            else cout << "The sequence is NOT sorted successfully" << endl;
            for (int i = 0; i < size; i++)
            {
                seq1->set(seq->get(i), i);
            }
            algSort = mergeSort;
            seconds = getTimeSort(seq1, algSort, cmp);
            cout << "Time spent on Merge Sort: " << seconds << "seconds" << endl;
            if (isSorted(seq1, cmp)) cout << "The sequence is sorted successfully" << endl;
            else cout << "The sequence is NOT sorted successfully" << endl;
            for (int i = 0; i < size; i++)
            {
                seq1->set(seq->get(i), i);
            }
            algSort = quickSort;
            seconds = getTimeSort(seq1, algSort, cmp);
            cout << "Time spent on Quick Sort: " << seconds << "seconds" << endl;
            if (isSorted(seq1, cmp)) cout << "The sequence is sorted successfully" << endl;
            else cout << "The sequence is NOT sorted successfully" << endl;
            break;
        case 5:
            algSort = bogoSort;
            seconds = getTimeSort(seq, algSort, cmp);
            cout << "Time spent on BogoSort: " << seconds << "seconds" << endl;
            break;
        default:
            break;
    }
    cout << endl;
    if (choose != 4)
    {
        if (isSorted(seq, cmp)) cout << "The sequence is sorted successfully" << endl;
        else cout << "The sequence is NOT sorted successfully" << endl;
        cout << "Sorted sequence is saved in out.txt:" << endl;
        fout << "Sorted sequence:" << endl;
        for (int i = 0; i < size; i++)
        {
            fout << seq->get(i) << " ";
        }
        cout << endl;
        fout << endl;
    }
    else if (choose == 4)
    {
        cout << "Sorted sequence is saved in out.txt" << endl;
        fout << "Sorted sequence:" << endl;
        for (int i = 0; i < size; i++)
        {
            fout << seq1->get(i) << " ";
        }
        cout << endl;
        fout << endl;
        delete seq1;
    }
    fout.close();
}

int main(int argc, const char *argv[])
{
    int choose = 0;
    while(true)
    {
        interface();
        cout << "Enter 1 to start again" << endl;
        cin >> choose;
        cout << endl;
        if (choose != 1) break;
    }
	return 0;
}