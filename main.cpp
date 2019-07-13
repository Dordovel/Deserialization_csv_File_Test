#include"Table/Table.h"

int main()
{
    
    Table table("Test_cpp.csv");

    std::cout<<"Max Index"<<std::endl;

    table.showMaxIndex();

    std::cout<<"Find Id 100"<<std::endl;

    table.findID(100);

    std::cout<<"Find Year 2019"<<std::endl;

    table.FindYear(2019);

    return EXIT_SUCCESS;
}
