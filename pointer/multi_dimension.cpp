#include <iostream>


int main(int argc, char const *argv[])
{
    int rows = 3;
    int cols = 3;
    
    int **table = new int*[rows];
    for (int i = 0; i < rows; i ++)
    {
        table[i] = new int[cols];
    }

    for (int i = 0; i < rows; i ++)
    {
        std::cout << "Value: " << table[i] << " address " << &table[i] << std::endl;
    }


    std::cout << "Sizeof " << sizeof(table) << std::endl; 
    std::cout << "Sizeof int" << sizeof(int) << std::endl; 

    table[0][100] = 100;
    std::cout <<  table[0][9] << std::endl;
    // for (int i = 0; i < rows; i++)
    // {
    //     for (int j = 0; j < cols; j++)
    //     {
    //         table[i][j] = i + j;
    //     }
    // }

    // // std::cout << "===================" << std::endl;
    // for (int i = 0; i < rows; i++)
    // {
    //     for (int j = 0; j < cols; j++)
    //     {
    //         std::cout << "Value " << table[i][j] << " Add " << &table[i][j] << std::endl;
    //     }
    //     std::cout << std::endl;
    // }

    return 0;
}
