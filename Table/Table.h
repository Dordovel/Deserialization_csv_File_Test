#pragma  once
#include "../File/Read.h"
#include<boost/multi_index_container.hpp>
#include<boost/multi_index/member.hpp>
#include<boost/multi_index/hashed_index.hpp>
#include"../Deserialization/deserialization.h"
#include <time.h>

using namespace boost::multi_index;

class Table
{
    private:

    struct ById{};
    struct ByPartner{};
    struct ByNumber{};
    struct ByDate{};
    struct ByStatus{};

    typedef multi_index_container<Collection,
        indexed_by<
            hashed_non_unique<
                tag<ById>,
                member<
                    Collection,uint64_t,&Collection::id
                >
            >,
            hashed_non_unique<
                tag<ByPartner>,
                member<
                    Collection,std::string,&Collection::partner
                >
            >,
            hashed_non_unique<
                tag<ByNumber>,
                member<
                    Collection,uint32_t,&Collection::number
                >
            >,
            hashed_non_unique<
                tag<ByDate>,
                member<
                    Collection,unsigned int,&Collection::date
                >
            >,
            hashed_non_unique<
                tag<ByStatus>,
                member<
                    Collection,bool,&Collection::status
                >
            >
        >
    >CollectionTable;

    CollectionTable table;


    void initialization(std::string filePath);

    static bool compare(const Collection & c1,const Collection & c2);

    void showCollection(Collection collection);

    public:
       void showMaxIndex();

        void insertToTable(Collection collection);

        void findID(uint64_t id);

        void FindYear(unsigned int findTime);

        Table (std::string filePath);

};