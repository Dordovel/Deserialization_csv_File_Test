#include"deserialization.h"


std::vector<std::string> str_parse(std::string str)
{

    std::vector<std::string> list;

    std::string temp="";

    std::string temp1="";

    std::stringstream string_stream;



    string_stream<<str;

    std::getline(string_stream,temp,'\r');

    string_stream.clear();

    string_stream<<temp;



    while(std::getline(string_stream,temp1,';'))
    {
        list.push_back(temp1);
    }

    
    
    return list;

}

std::vector<Collection> deserialization(const std::vector<std::string>& list)
{
    Collection collection;

    std::vector<std::string> temp;

    std::vector<Collection> deserialization_list;

    for (int a=0; a<list.size();++a)
    {
        temp=str_parse(list.at(a));

        if(!temp.empty())
        {
            collection.id=std::stoull(temp.at(0));
            collection.partner=temp.at(1);
            collection.number=std::stoull(temp.at(2));
            collection.date=std::stoi(temp.at(3));
            collection.status=std::stoi(temp.at(4));

            deserialization_list.push_back(collection);
        }
    }

    return deserialization_list;
    
}