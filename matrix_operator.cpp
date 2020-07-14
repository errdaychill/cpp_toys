#include <iostream>
#include <cmath>
#include <random>

using namespace std;


class KMatrix
{
    private:
        int row_;
        int col_;
        double **mat;

    public:
        KMatrix(const int& row=0, const int& column=0)
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


        ~KMatrix()
        {
            for(int i = 0; i < row_; i++)
                delete[] mat[i];
            delete[] mat;
        }

        // print KMatrix
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
        


        KMatrix randMat(const int& row, const int& column)
        {
            KMatrix m1;
            //mean = 0, std = 1
            // random_device로 난수 생성 엔진 초기화
            normal_distribution<> d{0,1};
            random_device rd;
            mt19937 gen(rd());
            for(int i = 0; i < row_; i++)
            {
                for(int j = 0; j < col_; j++)
                {
                    m1[i][j] = d(gen);
                }
            }
            return m1;
        }

        // 왜 파라미터 하나만?
        KMatrix operator+(KMatrix& m1)
        {
            KMatrix m2;
            if (m1.row_ != m2.row_ && m1.col_ != m2.col_)
            {
                throw out_of_range("Dimension doesn't match each other.");
            }

            for (int i = 0; i < row_ ; i++)
            {
                for (int j = 0; j < col_; j++)
                {
                    m1.mat[i][j] = mat[i][j] + m2.mat[i][j];
                    
                }
            }
            return m1;
            
        }
        
        KMatrix operator-(KMatrix& m1)
        {
            KMatrix m2;
            if (m1.row_ != m2.row_ && m1.col_ != m2.col_)
            {
                throw out_of_range("Dimension doesn't match each other.");
            }

            for (int i = 0; i < row_ ; i++)
            {
                for (int j = 0; j < col_; j++)
                {
                    m1.mat[i][j] = mat[i][j] - m2.mat[i][j];
                }
            }
            return m1;
        }

        KMatrix operator*(KMatrix& m1)
        {
            KMatrix m2;
            if (m1.col_ != m2.row_)
            {
                throw out_of_range("size of m1.axis 1 and m2.axis 0 doesn't match together.");
            }

            KMatrix mul_mat{};

            for(int i = 0; i < row_; i++)
                for(int j = 0; j < col_; j++)
                    for(int k = 0; k < col_; k++)
                        m1.mat[i][j] = mat[i][k] * m2.mat[k][j];

            return m1;
        }
        
        // 차원 크기는 따로 선언 안해줘도 되나???
        void getSubMat(KMatrix& big_mat, KMatrix& sub_mat, const int& p, const int& q)
        {
            
            int a = 0, b = 0;
            for (int i = 0; i < mat.row_ - 1; i++)
                for (int j = 0; j < mat.col_ - 1; j++)
                    if (i != p && j != q)
                        {
                            // 이해 X. 왜 그대로
                            sub_mat[a][b++] = big_mat[i][j];
                            if (b == mat.row_ - 1)
                            {
                                b = 0;
                                a++;
                            }
                        }

        }   



        // 행렬 차원 어떡하징
        double deterministic(KMatrix& mat)
        {
            int d = 0;
            static int n = mat.row_;

            if (mat.row_ == 1)
                return mat[0][0]

            double temp[mat.row_][mat.col_];
            int sign_num = -1;

            for (int col = 0; col < mat.col_; col++)
            {
                getSubMat(temp, 0, col);
                d += pow(sign_num, col) * mat[0][j] * deterministic(temp);

            }

            return d;
        }

        void adjoint(KMatrix& mat, KMatrix& adj_mat)
        {
            if (mat.row_ == 1)
                adj_mat[0][0] = 1;
                return ;

            int sign_num = 1, temp[mat.row_][mat.col_];
            for (int i = 0; i < row_; i++)
            {
                for (int j = 0; j < col_; j++)
                {
                    getSubMat(mat, temp, i, j);
                    sign_num = ((i+j) % 2 ==0?) 1 : -1;
                    
                    adj_mat[i][j] = sign_num * (deterministic(temp));
                }
            } 
            

        }


        // 전치 언제해줌??
        void inv(KMatrix& mat)
        {
            det = deterministic(mat);

            if (det == 0)
                cout << "KMatrix doesn't have a inverse KMatrix" << endl;


            if (mat.row_ !=  mat.col_)
            {
                cout << "It's not a square KMatrix" << endl;
            }

            double inv_mat[row_][col_];
            
            int adj_mat[row_][col_];
            adjoint(mat, adj_mat);

            for (int i = 0; i < row_; i++)
                for(int j = 0; j < col_; j++)
                {
                    inv_mat[i][j] = adj[i][j] / det;
                }
                    
            for (int i = 0; i < row_; i++)
            {
                for(int j = 0; j < col_; j++)
                {
                    cout << inv_mat[i][j] << " " ;
                }
                cout << endl;
            }    
        }

        
        void transpose(KMatrix& mat)
        {
             int array[mat.col_][mat.row_];

             for(int i = 0; i < row_; i++)
                for(int j = 0; j < col_; j++)
                    array[j][i] = mat[i][j];
             
             for(int i = 0; i < row_; i++)
                for(int j = 0; j < col_; j++)
                    cout << array[i][j] << " ";
                cout << endl;

            
        }
                  
        int* eye(const int& n)
        {
            int m1[n][n]{};
             for(int i = 0; i < row_; i++)
             {
                for(int j = 0; j < col_; j++)
                 {
                    m1[i][j] = (i == j ? 1 : 0);
                 }
             }
            return m1;
        }
        
        // 하나의 get 함수에 다 넣을 순 없을까
        // row, col 출력은 다른?
        void getRow(const int& row_idx)
        {
            cout << mat[row_idx] << endl;
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
