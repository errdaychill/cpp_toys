#include <iostream>
#include <cmath>
#include <random>

using namespace std;


class Matrix
{
    private:
        int row_;
        int col_;
        double **mat;

    public:
        Matrix(const int& row, const int& column)
        {

            row_ = row;
            col_ = column;

            mat = new double*[row_];
            for(int i = 0; i < row_; i++)
                mat[i] = new double[col_];
            
            // 0으로 초기화
            for(int i = 0; i < row_; i++)
            {
                for(int j = 0; j < col_; j++)
                {
                    mat[i][j] = 0;
                }
            }
            
        }
        
        Matrix(const int& row, const int& col, int* array)
        {
            for (int i=0; i<row; i++)
            {
                for (int j=0; j<col; j++)
                {
                    mat[i][j] = array[row*i + j];
                }
            }
        }

        ~Matrix()
        {
            for(int i = 0; i < row_; i++)
                delete[] mat[i];
            delete[] mat;
        }

        // print matrix
        void print()
        {
            for(int i = 0; i < row_; i++)
            {
                cout << " | "; 
                for(int j = 0; j < col_; j++)
                {
                    cout << mat[i][j] << " ";
                }
                cout << " | " << endl;
            }
        }
        


        Matrix randMat(const int& row, const int& column)
        {
            Matrix m1(row, column);
            //mean = 0, std = 1
            // random_device로 난수 생성 엔진 초기화
            normal_distribution<> d{0,1};
            random_device rd;
            mt19937 gen(rd());
            for(int i = 0; i < row_; i++)
            {
                for(int j = 0; j < col_; j++)
                {
                    m1.mat[i][j] = d(gen);
                }
            }
            return m1;
        }

        // 왜 파라미터 하나만?
        Matrix operator+(Matrix& m1)
        {
            Matrix m2(row_, col_);
            if (m1.row_ != m2.row_ && m1.col_ != m2.col_)
            {
                throw out_of_range("Dimension doesn't match each other.");
            }

            for (int i = 0; i < row_ ; i++)
            {
                for (int j = 0; j < col_; j++)
                {
                    m1.mat[i][j] = this->mat[i][j] + m2.mat[i][j];
                    
                }
            }
            return m1;
            
        }
        
        Matrix operator-(Matrix& m1)
        {
            Matrix m2(row_, col_);
            if (m1.row_ != m2.row_ && m1.col_ != m2.col_)
            {
                throw out_of_range("Dimension doesn't match each other.");
            }

            for (int i = 0; i < row_ ; i++)
            {
                for (int j = 0; j < col_; j++)
                {
                    m1.mat[i][j] = this->mat[i][j] - m2.mat[i][j];
                }
            }
            return m1;
        }

        Matrix operator*(Matrix& m1)
        {
            Matrix m2(row_, col_);
            if (m1.col_ != m2.row_)
            {
                throw out_of_range("size of m1.axis 1 and m2.axis 0 doesn't match together.");
            }

            Matrix mul_mat(row_, col_);

            for(int i = 0; i < row_; i++)
                for(int j = 0; j < col_; j++)
                    for(int k = 0; k < col_; k++)
                        m1.mat[i][j] = this->mat[i][k] * m2.mat[k][j];

            return m1;
        }
        
        // compute deterministic for matrix m1. 
        // 
        double deterministic(Matrix m1, const int n)
        {
            if (n == 1) return m1.mat[0][0];
            else if (n == 2) return m1.mat[0][0] * m1.mat[1][1] - m1.mat[0][1] * m1.mat[1][0];
            else
            {   int sum = 0;
                int sign = -1;
                for (int i = 0; i < n; i++)
                {
                    Matrix sub_m1(m1.row_-1, m1.col_-1);
                    for (int j = 0; j < m1.row_ - 1; j++)
                    {
                        for (int k = 0; k < m1.col_ - 1; k++)
                        {
                            sub_m1.mat[j][k] = m1.mat[j+1][k+1];
                        }
                    }
                    sum += m1.mat[0][i] * pow(-1,i) * deterministic(sub_m1, n-1);
                }
                return sum;
            }
        }


        Matrix minorMat(Matrix& m1, const int& out_rowidx, const int& out_colidx)
        {
            Matrix minor_mat(m1.row_,m1.col_);
            int a = 0, b = 0;
                for (int i=0; i<m1.row_; i++)
                {
                    if (i == out_rowidx) continue;
                    for(int j =0; j<m1.col_; j++)
                    {
                        if (j==out_colidx) continue;
                        minor_mat.mat[a][b] = m1.mat[i][j];
                        b++;
                        if (b == m1.col_)
                        {
                            b=0;
                            a++;
                        }
                }
            }
            return minor_mat;   
        }


        Matrix inverse(Matrix& m1)
        {
            Matrix cofac_mat(m1.row_, m1.col_);
            int sign = -1;
            int row_idx = 0, col_idx = 0;

            // i,j : m1's index
            for (int i=0; i<m1.row_; i++){
                for (int j=0; j<m1.col_; j++){   
                    cofac_mat.mat[i][j] = pow(sign, i+j) * deterministic(minorMat(m1,i,j), m1.row_-1) / deterministic(m1, m1.row_);
                        }
                    }
            return transpose(cofac_mat);

        }


        
        Matrix transpose(Matrix& m1)
        {
             Matrix trans_mat(m1.row_, m1.col_);

             for(int i = 0; i < row_; i++)
                for(int j = 0; j < col_; j++)
                    trans_mat.mat[j][i] = m1.mat[i][j];
             
             return trans_mat;
        }
                  
        void eye()
        {   
             int array[row_][col_]{};
             for(int i = 0; i < row_; i++)
             {
                for(int j = 0; j < col_; j++)
                 {
                    array[i][j] = (i == j ? 1 : 0);
                 }
             }
        }
        
        // row, col 출력은 다른?
        void getRow(const int& row_idx)
        {   
            for (int i = 0; i < row_; i++)
            cout << mat[row_idx][i] << " ";
        }
        void getCol(const int& col_idx)
        {
            for (int i = 0; i < row_; i++)
            cout << mat[i][col_idx] << endl;
        }

        void getIndex(const int& row_idx, const int& col_idx)
        {
            cout<< mat[row_idx][col_idx] << endl;
        }
};
