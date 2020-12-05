#include <iostream>

#include "../libs/lib_matrix.h" 
int main(){

    Matrix<int>  i1 (42);
    i1[1][1] = 43;
    std::cout << "i1[1][1] = " << i1[1][1] << std::endl;
    std::cout << "i1[1][2] = " << i1[1][2] << std::endl;
    i1[1][3];
return 0;
}
