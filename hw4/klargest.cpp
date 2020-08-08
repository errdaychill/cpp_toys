#include <iostream>
#include <vector>

using namespace std;

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

// 내림차순
void sort(vector<int> &vec){
    int size = vec.size();
    for (int i = 0; i < size; i++){
        int max_idx = i;
        for (int j = size-1; j > i; j--){
            if (vec[j] > vec[max_idx])
                max_idx = j;
        }
        swap(vec[max_idx], vec[i]);
    }
}


int findKthMax(vector<int> vec, const int &k){
    sort(vec);
    return vec[k-1];
}


int main(){
    int n;
    int k;

    cout << "write the size of array: " << endl;
    cin >> n;
    vector<int> vec(n);

    cout << "write the element:";
    for(int i = 0; i < n; i++){
        cin >> vec[i];
    }

    cout << "write the k:" ;
    cin >> k;
    

    cout << "answer is " << findKthMax(vec, k) << endl;
    return 0;

}