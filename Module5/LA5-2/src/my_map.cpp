#include <iostream>
#include <map>  //for maps
#include <string>

int main()
{
    //Maps are a key -> value pair of elements
    //key needs to be unique

    std::map<int, std::string> info;
    //to add elements use insert which takes a pair of key-values.  
    //to make key-value pair use make_pair() built-in function

    info.insert(std::make_pair(1, "Waldo Weber"));
    info.insert(std::make_pair(2, "Utah Jazz"));
    std::cout << "size of map " << info.size() << std::endl;

    //find key value
    auto position = info.find(1);
    if(position != info.end())
    {
        std::cout << "found, the key is " << position->first << " and the value is "
        << position->second << std::endl;//de-reference pointer with ->

    }

    std::cout << "Iterators" << std::endl;
    for(auto it = std::begin(info); it != std::end(info); ++it)
    {
        std::cout<< it->first << " " << it->second << "\t";
    }
    std::cout << std::endl;

    std::cout << "range based" << std::endl;
    for(std::pair<int, std::string> element : info)
    {
        std::cout<< element.first << " " << element.second << "\t";
    }

    std::cout << std::endl;

    return 0;
}