#include <iostream>
#include "Matrix.h"

using namespace std;
int main()
{
    int a[] = {1,2,3,4,5,6,7,8,9};
    int b[] = {1,2,3,4,5,6};
    int c[] = {1,2,3,4,5,6};

    Matrix mat(3,3);
    mat.print();
    
    
    return 0;
}
