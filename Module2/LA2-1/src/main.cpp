#include <iostream>

#include <string> //for string objects

/**
 * @brief Shows how to define and use a string object
 *
 * We will define string variables and then see what operators and
 * functions work with these variables.
 *
 * @return int 0 means function exited with success
 */
int main() {
  // create a variable of type string
  std::string name = "Matt"; 
  // print it out
  std::cout << name << std::endl;

  // // get a string from a user
  // std::cout << "enter your name" << std::endl;
  // //std::cin >> name; //sees space as null character and stops reading into cin
  // //to get strings with spaces use getline() instead of cin
  // getline(std::cin, name);
  // std::cout << "Hi " << name << std::endl;

  // add two strings together
  std::string title = "Dr.";
  std::string formal;
  std::string space = " ";
  formal = title + space + name;
  //formal = title + " " + name; //works also
  std::cout << "Hi: " << formal << std::endl;

  // how long is the string
  std::cout << "the length of name is " << name.size() << std::endl;
  std::cout << "the length of title is " << title.size() << std::endl;
  std::cout << "the length of title is " << title.length() << std::endl;
  std::cout << "the length of formal is " << formal.length() << std::endl;

  // use [] to get an individual character
  std::cout << "the first character of name is " << name[0] << std::endl;
  std::cout << "the third character of name is " << name[2] << std::endl;

  // get name and commute information from a user
  int minutes, miles;
  std::cout << "enter your name" << std::endl;
  getline(std::cin, name);
  std::cout << "How long is your commute in minutes" << std::endl;
  std::cin >> minutes;
  std::cout << "How many miles is your commute" << std::endl;
  std::cin >> miles;
  std::cout << name << " has a " << minutes << " minutes, " << miles <<
  " miles commute" << std::endl;



  // get commute information and name from a user

  // the string function find
  std::string story = "Now is the time for all good men to come to the aid of their country";
  std::cout << "men is at location " << story.find("men") << std::endl;



  // the string function replace

  std::cout << story << std::endl;
  story.replace(29, 3, "xxxxx");//replace men with xxxxx
  std::cout << story << std::endl;

  //could use variables in this and combine last two activities or use to replace all magic numbers
  
 

  return 0;
}

/*
      "The dragons are flying over the mountains. They are hunting for a "
      "place to settle for the waldo night. What they see is endless horizon."
*/
