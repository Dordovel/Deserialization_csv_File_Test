#include"Read.h"

std::vector<std::string> readFile(const char* filePath)
{
    std::ifstream fileReadStream(filePath,std::ios_base::in);

    std::vector<std::string> list;

    try
    {

        if(fileReadStream.is_open())
        {
            std::string str="";

            while(getline(fileReadStream,str))
            {
                list.push_back(str);

                str="";
            }

        }

    }catch(std::exception & except)
    {
        std::cout<<"Read Error"<<std::endl;
    }
    
    fileReadStream.close();
    
    return list;
}
