#include "symbol.hpp"
#include<map>
#include<iostream>

void printTable(std::map<std::string , Symbol*> &Table){
    for(auto it:Table){
        std::cerr<<it.second->name<<" : "<<it.second->relAddr<<'\n';
    }
}