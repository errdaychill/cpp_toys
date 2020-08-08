#include <iostream>

using namespace std;

int factorial(int n){
    if (n==1){
        return 1;
    }
    return n * factorial(n-1);
}


int countPath(int &row, int &column){
    int d_right = row - 1;
    int n_right = column - 1;
    return factorial(d_right + n_right) / factorial(d_right) / factorial(n_right);
}

int main(){
    
    int row, column;
    cout << "# row:";
    cin >> row;
    cout << "# column:";
    cin >> column;
    cout << "the number of paths is :" << countPath(row, column) << endl;
    
    return 0;
}