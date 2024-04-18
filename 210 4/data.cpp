#include "data.h"
#include <map>
#include <iostream>
//#include <list>
//#include <vector>
#include <string>

bool zamuzh(std::map<const char*, int>& mP, const char* oldf, const char* newf)
{
    typename std::map<const char*, int>::iterator it = mP.find(oldf);
    if(it == mP.end())
        return false;
    int tmp = it->second;
    mP.erase(it);
    std::pair <const char*, int> pa = { newf, tmp };
    mP.insert(pa);
    return true;
}


//extern 
