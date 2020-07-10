#include <iostream>
#include <cmath>
#include <cstdlib> //srand, rand
#include <vector>
#include <ctime>

using namespace std;


class Matrix
{
    private:
        int row_;
        int col_;
        int **mat;

    public:
        Matrix(const int& row=0, const int& column=0)
        {

            row_ = row;
            col_ = column;
            // vector<int> row_vec[row_]{};
            // vector<int> col_vec[col_]{};
            
            // 2차원 배열 동적 할당 
            mat = new int*[row_];
            for(int i = 0; i < row_; i++)
                mat[i] = new int[col_];
            
            // 0으로 초기화
            for(int i = 0; i < row_; i++)
                for(int j = 0; j < col_; j++)
                    mat[i][j] = 0;
    
            
            // randmat을 위한 시드넘버
            srand(static_cast<unsigned int>(time(0)));
             
            
        }

        ~Matrix()
        {
            for(int i = 0; i < row_; i++)
                delete[] mat[i];
            delete[] mat;
        }


        void matrix()
        {
            for(int i = 0; i < row_; i++)
                for(int j = 0; j < col_; j++)
                    cout << mat[j] << " ";
                cout << endl;
        }
        


        double randMat(const int& row, const int& column)
        {

              double rand_mat[row][column]{};
              rand();
        }


        //어떻게 객체인 자기자신을 받나??? 조금 이해가 안된다.
        Matrix add(const Matrix& m1, const Matrix& m2)
        {
            if (m1.row_ != m2.row_ && m1.col_ != m2.col_)
            {
                cout << "dimension isn't matched" << endl;
            }
            
            for(int i = 0; i < row_; i++)
                for(int j = 0; j < col_; j++)
                    m1[i][j] += m2[i][j];
        }
        
        Matrix minus(const Matrix& m1, const Matrix& m2)
        {
            if (m1.row_ != m2.row_ && m1.col_ != m2.col_)
            {
                cout << "dimension isn't matched" << endl;
            }

            for(int i = 0; i < row_; i++)
                for(int j = 0; j < col_; j++)
                    m1[i][j] += m2[i][j];
        }

        Matrix mult(const Matrix& m1, const Matrix& m2)
        {
            if (m1.col_ != m2.row_)
            {
                cout << "dimension isn't matched" << endl;
            }

            for(int i = 0; i < row_; i++)
                for(int j = 0; j < col_; j++)
                    m1[i][j] += m2[i][j];
        }

        Matrix inverse(const Matrix& mat)
        {
            if (mat.col_ != mat.row_)
                cout << "matrix isn't squre" << endl;
            


        }
        Matrix transpose(const Matrix& m1, const Matrix& m2))
        Matrix eye(const Matrix& m1, const Matrix& m2))
        int mult(const Matrix& m1, const Matrix& m2))

        
};





int main()
{





    return 0;
}