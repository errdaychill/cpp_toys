#include <iostream>

using namespace std;

void exchange(int& a, int& b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}


void selectionSort(int* array){
    int max = 1;
    int last;
    int N = sizeof(array) / sizeof(int);
    for (int i = N; i >= 1; i--)
    {
        int max_idx = 0; 
        last = i;
        for (int j = 0; j <= last; j++)
        {
            if (array[j] > array[max_idx])
            {
                max_idx = j;
            }
        }
        exchange(array[max_idx], array[last])
    }

}

void bubbleSort(int* array)
{
    int N = sizeof(array) / sizeof(int);
    for (int i = N; i > 0; i--){
        int last = i;
        for (int j = 0; j < last; j++){
            if (array[j] > array[j+1]){
                exchange(array[i], array[i+1]);
            }
        }
    }
}

void insertionSort(int* array)
{
    int loc;
    int N = sizeof(array) / sizeof(int);
    for (int i = 1; i < N ; i++)
    {
        loc = i - 1;
        int next = array[i];
        while(loc >= 0 && next < array[loc])
        {
            array[loc+1] = array[loc];
            loc--;
        }
        array[loc+1] = next;
    }
}



int main()
{
    int A[] = {5,2,3,4,8,1,9};
    cout << selectionSort(A) << endl;
    cout << bubbleSort(A) << endl;
    cout << insertionSort(A) << endl;





    return 0;
}