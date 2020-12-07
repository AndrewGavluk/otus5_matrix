#include <iostream>

#include "../libs/lib_matrix.h" 

template <typename T>
void show(Matrix<T>& Matr, 
            std::tuple<int,int>& from, 
            std::tuple<int,int>& to );

int main(){

    Matrix<int>  i1 (42);
    
    i1[0][0] = 0;
    i1[1][1] = 1;
    i1[2][2] = 2;

    i1[3][3] = 3;
    i1[4][4] = 4;
    i1[5][5] = 5;

    i1[6][6] = 6;
    i1[7][7] = 7;
    i1[8][8] = 8;
    i1[9][9] = 9;


    i1[0][9] = 9;
    i1[1][8] = 8;
    i1[2][7] = 7;

    i1[3][6] = 6;
    i1[4][5] = 5;
    i1[5][4] = 4;

    i1[6][3] = 3;
    i1[7][2] = 2;
    i1[8][1] = 1;
    i1[9][0] = 0;

    // set to default value
    i1[5][3] = 42;
    i1[2][9] = 42;

    auto from = std::make_tuple<int, int>(1,1);
    auto to = std::make_tuple<int, int>(8,8);
    //show(i1, from, to);
    i1.show(from, to);

    std::cout << std::endl;

    std::cout << "size =" << i1.capacity() << std::endl;

return 0;
}


template <typename T>
void show(Matrix<T>& Matr, 
            std::tuple<int,int>& from, 
            std::tuple<int,int>& to )
{   
    for (auto i=std::get<0>(from); i<=std::get<0>(to); ++i){
        for (auto j=std::get<1>(from); j<=std::get<1>(to); ++j)
            std::cout << Matr[i][j] << " ";
        std::cout << std::endl;
        }
}