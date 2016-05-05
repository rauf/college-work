#include<stdio.h>
#include<iostream>
#include<stdexcept>

class matrix
{
    int row, col;
    int **mat;

    void assignMatrix(){
        
        mat = new int *[col];

        for (int j = 0; j < col; ++j) {
            mat[j] = new int [row];                
        }
    }

    void checkForOrder(matrix &m) {
        if (this->row != m.getRow() || this->col != m.getCol())
            throw new std::domain_error("Order does not match of both matrices");
    }
    

public:
    matrix(int n) {
        row = n;
        col = n;
        assignMatrix();
    }


    matrix(int r, int c) {
        row = r;
        col = c;
        assignMatrix();
    }

    int getRow() {
        return row;
    }


    int getCol() {
        return col;
    }

    int **getMatrix() {
        return mat;
    }

    matrix operator +(matrix &m) {

        checkForOrder(m);
        
        matrix m1(m.getRow(), m.getCol());

        for (int i = 0; i < row; ++i) {
            
            for (int j = 0; j < col; ++j) {
                m1.getMatrix()[i][j] = this->mat[i][j] + m.getMatrix()[i][j];
            }
        }

        return m1;
    }


    matrix operator -(matrix &m) {

        checkForOrder(m);
        
        matrix m1(m.getRow(), m.getCol());

        for (int i = 0; i < row; ++i) {
            
            for (int j = 0; j < col; ++j) {
                m1.getMatrix()[i][j] = this->mat[i][j] - m.getMatrix()[i][j];
            }
        }

        return m1;
    }


    void input(std::istream &in) {

        for (int i = 0; i < row; ++i) {
            
            for (int j = 0; j < col; ++j) {
                in >> mat[i][j];
            }
        }
    }

    void output(std::ostream &out) {
        for (int i = 0; i < row; ++i) {
            
            out << std::endl;
            for (int j = 0; j < col; ++j) {
                out << mat[i][j] << "  ";
            }
        }
    }
    
};

int main() {

   matrix m1(2), m2(2);

   std::cout << "Enter first matrix" << std::endl;
   m1.input(std::cin);
   std::cout << "Enter second matrix" << std::endl;
   m2.input(std::cin);

   matrix m3 = m1 + m2;
   std::cout << "Their sum is: " << std::endl;
   m3.output(std::cout);


   matrix m4 = m1 - m2;
   std::cout << "\n\nTheir difference is: " << std::endl;
   m4.output(std::cout);

}