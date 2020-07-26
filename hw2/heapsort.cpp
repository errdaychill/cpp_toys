#include <iostream>

using namespace std;


int number;
int heap[1000000];

// build heap
void makeHeap(int i)
{
    // left child
    int c = 2 * i + 1;
    
    // if right child > left child
    if (c < number && heap[c] < heap[c + 1])
    {
        c++;
    }

    // if child > parent , change value
    if (heap[i] < heap[c])
    {
        int temp = heap[i];
        heap[i] = heap[c];
        heap[c] = temp;
    }

    // do until number / 2 
    if (c <= number/ 2) makeHeap(c);
}

// O(nlogn)
// 힙 생성 : logN, 전체 데이터 N

int main()
{
   cin >> number;
   for (int i = 0; i < number; i++)
   {
       int x;
       cin >> heap[i];
   }
    
    //make heap
    for (int i = number / 2; i >= 0; i--)
    {
        makeHeap(i);
    }
    
    //execute sorting
    //heapify
    for (int i = number - 1; i >= 0; i--)
    {
        for (int j = 0; j < number; j++)
        {
            cout << heap[j] << " ";
        }
        cout << endl;
        int temp = heap[0];
        heap[0] = heap[i];
        heap[i] = temp;
        int root = 0;
        int c = 1;
        do
        {
            c = 2 * root + 1;
            if (c < i - 1 && heap[c] < heap[c + 1]) c++;
            if (c < i && heap[root] < heap[c])
            {
                temp = heap[root];
                heap[root] = heap[c];
                heap[c] =temp;
            }
            root = c;
        } while (c < i);
        
    }

    return 0;
}

