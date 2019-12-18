#include "carton_fileio.h"
#include <fstream>

std::string ReadDataFormatFromFile(std::string filename,
 std::array<Carton, kMaxArraySize>& cartons, int& rec_num)
 {
     std::ifstream data_input(filename);//create file handler for reading
     if(data_input.fail())
     {
         return "Unable to open file";
     }
     //good to go
     std::string message = "";

     double side1, side2, side3;//read data from file
     while(rec_num <KmaxArraySize && data_input >> side1)
     {
         data_input >> side2 >> side3;
         //load data into array
         try
         {
        cartons[rec_num] = Carton(side1, side2, side3);
        rec_num += 1;//keep track of number of records loaded from file
         }
         catch(std::out_of_range error)
         {
             message += error.what();
             message += "\n";
         }
         
     }

     data_input.close();


     return message;
 }

 void WriteData(std::string filename,
 std::array<Carton, kMaxArraySize>& cartons, int& rec_num);
 {
     std::ofstream file_out(filename);
     for(int index =0; index < rec_num; ++index)
     {
         cartons[index].WriteData(file_out);
     }
 }