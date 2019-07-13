#pragma once
#include<iostream>
#include<vector>
#include<sstream>


struct Collection
{
    uint64_t id;
    std::string partner;
    uint32_t number;
    unsigned int date;
    bool status;
};


std::vector<Collection> deserialization(const std::vector<std::string>& list);

std::vector<std::string> str_parse(std::string str);