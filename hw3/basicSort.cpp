#include <iostream>
#include <cmath>
#include <vector>


using namespace std;

void exchange(int& a, int& b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}


// basic sort
void selectionSort(vector<int> vec)
{
    int N = vec.size();
    for (int i = 0; i < N-1; i++)
    {
        int min_idx = i; 
        for (int j = i+1; j < N; j++)
        {
            if (vec[j] < vec[min_idx])
            {
                min_idx = j;
            }
        }
        exchange(vec[min_idx], vec[i]);
    }
    cout << "selection sort output:";
    for (auto & i: vec){
        cout << i << " ";
    }
    cout << endl;
}



void bubbleSort(vector<int> vec, bool flag=false)
{
    int N = vec.size();
    for (int i = N-1; i > 0; i--){
        int last = i;
        for (int j = 0; j < last; j++){
            if (vec[j] > vec[j+1]){
                exchange(vec[j], vec[j+1]);
                flag=true;
            }
        }
        if (flag==false) break;
    }
    cout << "bubble sort output:" ;
    for (auto & i : vec){
        cout << i << " ";
    }
    cout << endl;
}


void insertionSort(vector<int> vec)
{
    int loc;
    int N = vec.size();
    for (int i = 1; i < N ; i++)
    {
        loc = i - 1;
        int next_val = vec[i];
        while(loc >= 0 && vec[loc] > next_val)
        {
            vec[loc+1] = vec[loc];
            loc--;
        }
        vec[loc+1] = next_val;
    }
    cout << "insertion sort output:" ;

    for (auto &value : vec)
        cout << value << " ";
    cout << endl;
}

//advacned sort
void merge(vector<int> &vec, int start, int mid, int end){
    int temp[end-start+1];
    int idx = 0;
    int qq = (mid + 1);
    // 서로 비교 후 정렬
    while(start <= mid && qq <= end){
        if (vec[start] < vec[qq]){
        temp[idx++] = vec[start++];
        }

        else{
            temp[idx++] = vec[qq++];
        }
    }

    if (start > mid){
        for (int i = qq; i <= end; i++){
            temp[idx++] = vec[i];
        }
    }
    else{
        for (int i = start; i <= mid; i++){
            temp[idx++] = vec[i];
        }
    }


    for(int i = start ; i <= end; i++){
        vec[i] = temp[i - start];
    }
}

void mergeSort(vector<int> &vec, int p, int r){
    int q = int((p+r)/2);
    // int q = (p + r ) / 2;

    if (p < r){
    mergeSort(vec, p, q);
    mergeSort(vec, q + 1, r);
    merge(vec, p, q, r);   
    }
}

void mergeSort_print(vector<int> &vec, int p, int r){
    mergeSort(vec, p, r);
    cout << "merge sort output:";
    for (auto& value : vec)
    {
        cout << value << " ";
    }
    cout << endl;
}


int partition(vector<int> &vec, int p, int r){
    int i = p-1;
    // i = final index of region(less than p)
    // p = start index
    // r = final index
    // vec[r] = pivot
    for (int k = p; k < r; k++){
        if (vec[k] < vec[r]){
            i++;
            exchange(vec[i], vec[k]);
        }
    }
    exchange(vec[i+1],vec[r]);
    return i+1;
}


void quickSort(vector<int> &vec, int p, int r){
    int pivot;
    if (p < r){
        pivot = partition(vec, p, r);
        quickSort(vec, p, pivot-1);
        quickSort(vec, pivot+1, r);
    }
}

void quickSort_print(vector<int> &vec, int p, int r){
    quickSort(vec, p, r);
    cout << "Quick sort output:";
    for (auto & value : vec){
        cout << value << " ";
    }
    cout << endl;
}

int main()
{
    int size;
    cout << "Type the size:";
    cin >> size;
    vector<int> vec(size);

    cout << "Type the numbers: ";
    for (int i = 0; i < size ; i++){
        cin >> vec[i];
    }
    
    // selectionSort(vec);
    // bubbleSort(vec);
    // insertionSort(vec);

    quickSort_print(vec,0,size-1);
    // mergeSort_print(vec,0,size-1);

    
    return 0;
}