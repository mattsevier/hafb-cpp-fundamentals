#include <array>  //array containers
#include <iostream> //basic I/O
#include <string>  //strings
#include <fstream> //file stream

//using namespace std;

/**
 * @brief Shows how to define and use an ifstream object to read from a file.
 *
 * We will define ifstream objects and then see some operators
 * and methods that work with these objects.
 *
 * @return int 0 means function exited with success
 */

const int kMaxSize = 24;

int main() {
  // create an ojbect of type ifstream

  std::ifstream in; //input file stream


  // open the file age.txt

  in.open("../age.txt"); //relative location from the executable file, dotdot is up a file
  if(in.fail())//did the file open?
  {
    std::cout << "unable to open file\n shutting down\n";
    return 1;
  }


  // read from the age file and store values in an array

  std::array<int, kMaxSize> ages;
  ages.fill(-1); //initialize elements of the array to -1
  int age_size = 0;
  //in >> ages[age_size];

  // read to the end of the file

  while(age_size < kMaxSize && in >> ages[age_size])
  {
    age_size++;
  }
  


  // print out the values in the array
  for(auto age: ages)
  {
    std::cout << age << std::endl;
  }

in.close();//close input file, always good practice


std::ifstream infile; //input file stream

 infile.open("../name.txt"); //relative location from the executable file, dotdot is up a file
  if(infile.fail())//did the file open?
  {
    std::cout << "unable to open file\n shutting down\n";
    return 1;
  }
  
  std::array<std::string, kMaxSize> names;
  names.fill("N/A"); //initialize elements of the array to -1
  int name_size = 0;

  
  while(name_size < kMaxSize && std::getline(infile, names[name_size]))
  {
    name_size++;
  }

   // print out the values in the array
  for(auto name: names)
  {
    std::cout << name << std::endl;
  }

infile.close();//close input file, always good practice


  

  // print out the valid values in the array


  // print out the all the values in the array


  // Define an ifstream object and open the file name.txt

  // read one name, store it in the array, and print it


  // read the rest of the names in the file


  // print valid elements in the names array


  // print all the elements in the names array


  // Use a file with mixed values
  // Define an ifstream object and open the file name_age.txt


  // reset age and name arrays


  // read all the values from the name_age.txt file

    std::ifstream NaA; //input file stream


  // open the file age.txt

  NaA.open("../name_age.txt"); //relative location from the executable file, dotdot is up a file
  if(NaA.fail())//did the file open?
  {
    std::cout << " unable to open file\n shutting down\n";
    return 1;
  }


  // read from the age file and store values in an array

  //std::array<int, kMaxSize> ages;
  ages.fill(-1); //initialize elements of the array to -1
  
  //in >> ages[age_size];
  //std::array<std::string, kMaxSize> names;
  names.fill("N/A"); //initialize elements of the array to -1

  // read to the end of the file
  int size = 0;
   while(size < kMaxSize && NaA >> ages[size])
  {
    //need to load the next record
    //any extra characters?  yes
    NaA.ignore();
    std::getline(NaA, names[size]);
    size++;
  }

  
  


  // print out the values in the array


  for(int num = 0; num < size; ++num)
  {
    std::cout << ages[num] << " for " << names[num] << std::endl;
  }

NaA.close();//close input file, always good practice


  // print valid elements in the names and ages array


  // print all elements in the names and ages array


  return 0;
}
