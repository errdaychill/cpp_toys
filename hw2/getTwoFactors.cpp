#include <iostream>

using namespace std;

int getAnswer(const int& x, const int& y)
{
  

    int count = 0;
    int fac_counts = 0;
    for (int num = x; num <= y; num++)
    {
        for (int i = 1; i <= num; i++)
        {
            if (num % i ==0)
            {
                fac_counts++;
            }
        }
        if (fac_counts % 2 ==0) {
            count++;
            fac_counts = 0;
        }
        else fac_counts = 0;
    }
    return count;
}

int main()
{
    unsigned int x,y;
    while(1)
    {
    cout << "write 2 numbers (x,y > 0) :" ;
    cin >> x >> y;
    if (x == 0 || y == 0) {
        cout << "they must be larger than 0, try again" << endl;
        continue;
    }
    cout << "The answer is " << ((x<=y)? getAnswer(x,y) : getAnswer(y,x)) << endl; 
    break;   
    }

    return 0;
}