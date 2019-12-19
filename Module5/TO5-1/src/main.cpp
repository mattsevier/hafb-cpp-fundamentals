#include <iostream>
#include "containers.h"
using namespace std;

// Main Function
int main()
{

  std::vector<Data> info;
  std::string infile = "../data/sample_data.scv";
  Load_Data(info, infile);
  std::cout << "you loaded " << info.size() << "records" << std::endl;
  return 0;
}