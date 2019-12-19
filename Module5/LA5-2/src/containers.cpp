#include "containers.h"
#include "csvstream.h"
#include <iostream>
#include <algorithm>
#include <iterator>
#include <string>

void Load_Data(std::vector<Data> &data, const std::string &input_file)
{
    csvstream csvinput(input_file);//open the file
  // rows have a key = column name, value = cell data
  std::map<std::string, std::string> row;
  Data temp;
  //extract the animal column
  while(csvinput >> row)
  {
    //the key is the column name, must be exactly the same
    //std::cout <<row["id"] << "," << row["name"] <<
    //", " << row["animal"] << std::endl;

    temp.name = row["name"];
    temp.animal = row["animal"];
    temp.id = std::stoi(row["id"]);//cast string to integer

    data.push_back(temp); //load data struct into vector
}

}




