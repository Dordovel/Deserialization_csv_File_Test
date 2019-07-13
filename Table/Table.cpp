#include"Table.h"

Table::Table(std::string path)
{
    this->initialization(path);
}

void Table::showCollection(Collection collection)
{
    std::cout<<collection.id
             <<"    "<<collection.partner
             <<"    "<<collection.number
             <<"    "<<collection.date
             <<"    "<<collection.status
             <<std::endl;
}


void Table::showMaxIndex()
{
    // temporary index:
    std::vector<boost::reference_wrapper<Collection const> > temporary(table.begin(), table.end());

    std::sort(temporary.begin(),temporary.end(),compare);

    Collection collection=temporary.at(temporary.size()-1);

    this->showCollection(collection);

}

bool Table::compare(const Collection & c1,const Collection & c2)
{
    return c1.id<c2.id;
}


void Table::findID(uint64_t id)
{
    typedef CollectionTable::index<ById>::type List;
    const List & ls = this->table.get<ById>();
    List::const_iterator it = ls.find(id);
    if ( it != ls.end() )
    {
        this->showCollection((*it));
    }
}

void Table::FindYear(unsigned int findTime)
{
    std::vector<boost::reference_wrapper<Collection const> > temporary(table.begin(), table.end());

    time_t t;

    for(const Collection &var : temporary)
    {
        t=var.date;

        if(((gmtime (& t)->tm_year)+1900) == findTime)
        {
            this->showCollection(var);
        }

    }
}


void Table::initialization(std::string filePath)
{
    auto list=readFile(filePath.c_str());

    auto des_list=deserialization(list);

    for(int a=0;a<des_list.size();++a)
    {
        this->insertToTable(des_list.at(a));
    }

}

void Table::insertToTable(Collection collection)
{
    this->table.insert(collection);
}