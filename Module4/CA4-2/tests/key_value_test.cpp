// this tells catch to provide a main()
// only do this in one cpp file
#define CATCH_CONFIG_MAIN
#include "../externals/catch2/catch.hpp"

#include <array>
#include <fstream>
#include <string>
#include "carton.h"
#include "key_value.h"

using namespace std;

const int kSize = 5;

//******************************constructors******************************
TEST_CASE(
    "Default constructor creates a KeyValue container of size zero for keys of "
    "type int and values of type int",
    "[start]") {
  KeyValue<int, int, kSize> key_value;
  CHECK(key_value.size() == 0);
}

TEST_CASE(
    "Default constructor creates a KeyValue container of size zero for keys of "
    "type int and values of type double",
    "[start]") {
  KeyValue<int, double, kSize> key_value;
  CHECK(key_value.size() == 0);
}

TEST_CASE(
    "Default constructor creates a KeyValue container of size zero for keys of "
    "type int and values of type string",
    "[start]") {
  KeyValue<int, string, kSize> key_value;
  CHECK(key_value.size() == 0);
}

TEST_CASE(
    "Default constructor creates a KeyValue container of size zero for keys of "
    "type int and values of type Carton",
    "[start]") {
  KeyValue<int, Carton, kSize> key_value;
  CHECK(key_value.size() == 0);
}

TEST_CASE(
    "Default constructor creates a KeyValue container of size zero for keys of "
    "type string and values of type int",
    "[start]") {
  KeyValue<string, int, kSize> key_value;
  CHECK(key_value.size() == 0);
}

TEST_CASE(
    "Default constructor creates a KeyValue container of size zero for keys of "
    "type string and values of type double",
    "[start]") {
  KeyValue<string, double, kSize> key_value;
  CHECK(key_value.size() == 0);
}

TEST_CASE(
    "Default constructor creates a KeyValue container of size zero for keys of "
    "type string and values of type string",
    "[start]") {
  KeyValue<string, string, kSize> key_value;
  CHECK(key_value.size() == 0);
}

TEST_CASE(
    "Default constructor creates a KeyValue container of size zero for keys of "
    "type string and values of type Carton",
    "[start]") {
  KeyValue<string, Carton, kSize> key_value;
  CHECK(key_value.size() == 0);
}

//******************************int, int, 5******************************
TEST_CASE(
    "Add method adds keys and values expected in loop"
    "for keys of type int and values of type int "
    "throws out_of_range exception when Add called after full",
    "[add][value]") {
  KeyValue<int, int, kSize> key_value;
  // add key value pairs to container
  for (int i = 0; i < kSize; i++) {
    key_value.Add(i, i * 10);
  }
  // test size
  CHECK(key_value.size() == kSize);

  // test key and value are in the KeyValue container
  for (int i = 0; i < kSize; i++) {
    CHECK(key_value.ValueAt(i) == i * 10);
  }

  // add one after full, expect exception
  CHECK_THROWS_AS(key_value.Add(101, 1010), out_of_range);
}

TEST_CASE(
    "Add method adds keys and values expected and ValueAt finds them"
    "for keys of type int and values of type int "
    "throws out_of_range exception when Add called after full",
    "[add][value]") {
  KeyValue<int, int, kSize> key_value;
  // add key value pairs to container
  key_value.Add(7, 22);
  key_value.Add(3, 12);
  key_value.Add(9, 18);
  key_value.Add(5, 91);
  key_value.Add(17, 35);

  // test size
  CHECK(key_value.size() == 5);

  // test key and value are in the KeyValue container
  CHECK(key_value.ValueAt(7) == 22);
  CHECK(key_value.ValueAt(3) == 12);
  CHECK(key_value.ValueAt(9) == 18);
  CHECK(key_value.ValueAt(5) == 91);
  CHECK(key_value.ValueAt(17) == 35);

  // add one after full, expect exception
  CHECK_THROWS_AS(key_value.Add(101, 99), out_of_range);
}

TEST_CASE(
    "Add method adds keys and values expected and ValueAt finds them"
    "for keys of type int and values of type int "
    "ValueAt method throws out_of_range when key not found",
    "[add][value]") {
  KeyValue<int, int, kSize> key_value;
  // add key value pairs to container
  key_value.Add(7, 22);
  key_value.Add(3, 12);
  key_value.Add(9, 18);
  key_value.Add(5, 91);
  key_value.Add(17, 35);

  // test size
  CHECK(key_value.size() == 5);

  // call ValueAt with key not used, expect exception
  CHECK_THROWS_AS(key_value.ValueAt(107), out_of_range);
}

TEST_CASE(
    "RemoveOne method removes key and value expected and returns true "
    "for keys of type int and values of type int",
    "[remove_one]") {
  KeyValue<int, int, kSize> key_value;
  // add key value pairs to container
  key_value.Add(7, 22);
  key_value.Add(3, 12);
  key_value.Add(7, 18);
  key_value.Add(5, 91);
  key_value.Add(7, 35);

  // test size
  CHECK(key_value.size() == 5);

  CHECK(key_value.RemoveOne(7));

  // test key and value are in the KeyValue container
  CHECK(key_value.ValueAt(7) > 17);
  CHECK(key_value.ValueAt(3) == 12);
  CHECK(key_value.ValueAt(5) == 91);

  // test size
  CHECK(key_value.size() == 4);

  CHECK(key_value.RemoveOne(3));

  // test key and value are in the KeyValue container
  CHECK(key_value.ValueAt(7) > 17);
  CHECK(key_value.ValueAt(5) == 91);

  // test size
  CHECK(key_value.size() == 3);

  CHECK(key_value.RemoveOne(7));

  // test key and value are in the KeyValue container
  CHECK(key_value.ValueAt(7) > 17);
  CHECK(key_value.ValueAt(5) == 91);

  // test size
  CHECK(key_value.size() == 2);

  CHECK(key_value.RemoveOne(7));

  // test key and value are in the KeyValue container
  CHECK(key_value.ValueAt(5) == 91);

  // test size
  CHECK(key_value.size() == 1);

  CHECK(key_value.RemoveOne(5));

  // test size
  CHECK(key_value.size() == 0);

  CHECK(!key_value.RemoveOne(5));

  // test size
  CHECK(key_value.size() == 0);
}

TEST_CASE(
    "RemoveOne method removes nothing and returns false when key not found "
    "for keys of type int and values of type int",
    "[remove_one]") {
  KeyValue<int, int, kSize> key_value;
  // add key value pairs to container
  key_value.Add(7, 22);
  key_value.Add(3, 12);
  key_value.Add(7, 18);
  key_value.Add(5, 91);
  key_value.Add(7, 35);

  // test size before remove
  CHECK(key_value.size() == 5);

  CHECK(!key_value.RemoveOne(17));

  // test size after remove
  CHECK(key_value.size() == 5);

  // test key and value are in the KeyValue container
  CHECK(key_value.ValueAt(7) > 17);
  CHECK(key_value.ValueAt(3) == 12);
  CHECK(key_value.ValueAt(5) == 91);
}

TEST_CASE(
    "RemoveOne method removes nothing and returns false container is empty "
    "for keys of type int and values of type int",
    "[remove_one]") {
  KeyValue<int, int, kSize> key_value;

  CHECK(!key_value.RemoveOne(7));

  // test size after remove
  CHECK(key_value.size() == 0);
}

TEST_CASE(
    "RemoveAll method removes keys and values expected and returns number when "
    "key is found multiple times "
    "for keys of type int and values of type int ",
    "[remove_all]") {
  KeyValue<int, int, kSize> key_value;
  // add key value pairs to container
  key_value.Add(7, 22);
  key_value.Add(3, 12);
  key_value.Add(7, 18);
  key_value.Add(5, 91);
  key_value.Add(7, 35);

  // test size
  CHECK(key_value.size() == 5);

  CHECK(key_value.RemoveAll(7) == 3);

  // test key and value are in the KeyValue container
  CHECK(key_value.ValueAt(3) == 12);
  CHECK(key_value.ValueAt(5) == 91);

  // test size
  CHECK(key_value.size() == 2);
  CHECK_THROWS_AS(key_value.ValueAt(7), out_of_range);
}

TEST_CASE(
    "RemoveAll method removes keys and values expected and returns 1 when "
    "key is found one time "
    "for keys of type int and values of type int ",
    "[remove_all]") {
  KeyValue<int, int, kSize> key_value;
  // add key value pairs to container
  key_value.Add(7, 22);
  key_value.Add(3, 12);
  key_value.Add(7, 18);
  key_value.Add(5, 91);
  key_value.Add(7, 35);

  // test size
  CHECK(key_value.size() == 5);

  CHECK(key_value.RemoveAll(5) == 1);

  // test key and value are in the KeyValue container
  CHECK(key_value.ValueAt(3) == 12);
  CHECK(key_value.ValueAt(7) > 17);
  CHECK_THROWS_AS(key_value.ValueAt(5), out_of_range);
  // test size
  CHECK(key_value.size() == 4);
}

TEST_CASE(
    "RemoveAll method removes nothing and returns zero when key not found "
    "for keys of type int and values of type int ",
    "[remove_all]") {
  KeyValue<int, int, kSize> key_value;
  // add key value pairs to container
  key_value.Add(7, 22);
  key_value.Add(3, 12);
  key_value.Add(9, 18);
  key_value.Add(5, 91);
  key_value.Add(17, 35);

  // test size
  CHECK(key_value.size() == 5);

  CHECK(key_value.RemoveAll(22) == 0);

  // test key and value are in the KeyValue container
  CHECK(key_value.ValueAt(7) == 22);
  CHECK(key_value.ValueAt(3) == 12);
  CHECK(key_value.ValueAt(9) == 18);
  CHECK(key_value.ValueAt(5) == 91);
  CHECK(key_value.ValueAt(17) == 35);

  // test size
  CHECK(key_value.size() == 5);
}

TEST_CASE(
    "Found method returns true when key found and false when key not found "
    "for keys of type int and values of type int ",
    "[found]") {
  KeyValue<int, int, kSize> key_value;
  // add key value pairs to container
  key_value.Add(7, 22);
  key_value.Add(3, 12);
  key_value.Add(9, 18);
  key_value.Add(5, 91);
  key_value.Add(17, 35);

  // test size
  CHECK(key_value.size() == 5);

  CHECK(!key_value.Found(22));

  // test key and value are in the KeyValue container
  CHECK(key_value.Found(7));
  CHECK(key_value.Found(3));
  CHECK(key_value.Found(9));
  CHECK(key_value.Found(5));
  CHECK(key_value.Found(17));

  // test size
  CHECK(key_value.size() == 5);
}

TEST_CASE(
    "Empty method returns true when empty and false when not empty "
    "for keys of type int and values of type int ",
    "[empty]") {
  KeyValue<int, int, kSize> key_value;
  // add key value pairs to container

  CHECK(key_value.Empty());
  // test size
  CHECK(key_value.size() == 0);
  key_value.Add(7, 22);
  CHECK(!key_value.Empty());
  // test size
  CHECK(key_value.size() == 1);
  key_value.RemoveOne(7);
  CHECK(key_value.Empty());
  // test size
  CHECK(key_value.size() == 0);
}

TEST_CASE(
    "Full method returns true when full and false when not full "
    "for keys of type int and values of type int "
    "Also, tests size method",
    "[full]") {
  KeyValue<int, int, kSize> key_value;
  // add key value pairs to container

  CHECK(!key_value.Full());
  CHECK(key_value.size() == 0);
  key_value.Add(7, 22);
  CHECK(!key_value.Full());
  CHECK(key_value.size() == 1);
  key_value.Add(3, 12);
  CHECK(!key_value.Full());
  CHECK(key_value.size() == 2);
  key_value.Add(9, 18);
  CHECK(!key_value.Full());
  CHECK(key_value.size() == 3);
  key_value.Add(5, 91);
  CHECK(!key_value.Full());
  CHECK(key_value.size() == 4);
  key_value.Add(17, 35);
  CHECK(key_value.Full());
  CHECK(key_value.size() == 5);
  key_value.RemoveOne(7);
  CHECK(!key_value.Full());
  // test size
  CHECK(key_value.size() == 4);
}

TEST_CASE(
    "The << operator works and outputs key, space, value, carriage return for "
    "all elements in the KeyValue container "
    "for keys of type int and values of type int ",
    "[remove_all]") {
  KeyValue<int, int, kSize> key_value;
  // add key value pairs to container
  key_value.Add(7, 22);
  key_value.Add(3, 12);
  key_value.Add(9, 18);
  key_value.Add(5, 91);
  key_value.Add(17, 35);

  // test <<size>>
  ofstream out("test_output.txt");
  out << key_value;
  out.close();

  ifstream in("test_output.txt");
  string line;
  getline(in, line);
  CHECK("7: 22" == line);
  getline(in, line);
  CHECK("3: 12" == line);
  getline(in, line);
  CHECK("9: 18");
  getline(in, line);
  CHECK("5: 91" == line);
  getline(in, line);
  CHECK("17: 35" == line);
  getline(in, line);
  CHECK("" == line);

  in.close();
}

//******************************int, string, 5******************************
TEST_CASE(
    "Add method adds keys and values expected in loop"
    "for keys of type int and values of type string "
    "throws out_of_range exception when Add called after full",
    "[add][value]") {
  KeyValue<int, string, kSize> key_value;
  // add key value pairs to container
  for (int i = 0; i < kSize; i++) {
    key_value.Add(i, "blue" + i);
  }
  // test size
  CHECK(key_value.size() == kSize);

  // test key and value are in the KeyValue container
  for (int i = 0; i < kSize; i++) {
    CHECK(key_value.ValueAt(i) == "blue" + i);
  }

  // add one after full, expect exception
  CHECK_THROWS_AS(key_value.Add(101, "orange"), out_of_range);
}

TEST_CASE(
    "Add method adds keys and values expected and ValueAt finds them"
    "for keys of type int and values of type string "
    "throws out_of_range exception when Add called after full",
    "[add][value]") {
  KeyValue<int, string, kSize> key_value;
  // add key value pairs to container
  key_value.Add(7, "blue");
  key_value.Add(3, "gray");
  key_value.Add(9, "purple");
  key_value.Add(5, "yellow");
  key_value.Add(17, "green");

  // test size
  CHECK(key_value.size() == 5);

  // test key and value are in the KeyValue container
  CHECK(key_value.ValueAt(7) == "blue");
  CHECK(key_value.ValueAt(3) == "gray");
  CHECK(key_value.ValueAt(9) == "purple");
  CHECK(key_value.ValueAt(5) == "yellow");
  CHECK(key_value.ValueAt(17) == "green");

  // add one after full, expect exception
  CHECK_THROWS_AS(key_value.Add(101, "orange"), out_of_range);
}

TEST_CASE(
    "Add method adds keys and values expected and ValueAt finds them"
    "for keys of type int and values of type string "
    "ValueAt method throws out_of_range when key not found",
    "[add][value]") {
  KeyValue<int, string, kSize> key_value;
  // add key value pairs to container
  key_value.Add(7, "blue");
  key_value.Add(3, "gray");
  key_value.Add(9, "purple");
  key_value.Add(5, "yellow");
  key_value.Add(17, "green");

  // test size
  CHECK(key_value.size() == 5);

  // call ValueAt with key not used, expect exception
  CHECK_THROWS_AS(key_value.ValueAt(107), out_of_range);
}

TEST_CASE(
    "RemoveOne method removes key and value expected and returns true "
    "for keys of type int and values of type string",
    "[remove_one]") {
  KeyValue<int, string, kSize> key_value;
  // add key value pairs to container
  key_value.Add(7, "blue");
  key_value.Add(3, "gray");
  key_value.Add(7, "purple");
  key_value.Add(5, "yellow");
  key_value.Add(7, "green");

  // test size
  CHECK(key_value.size() == 5);

  CHECK(key_value.RemoveOne(7));

  // test key and value are in the KeyValue container
  CHECK(key_value.ValueAt(3) == "gray");
  CHECK(key_value.ValueAt(5) == "yellow");

  // test size
  CHECK(key_value.size() == 4);

  CHECK(key_value.RemoveOne(3));

  // test key and value are in the KeyValue container
  CHECK(key_value.size() == 3);

  CHECK(key_value.RemoveOne(7));

  // test key and value are in the KeyValue container
  CHECK(key_value.ValueAt(5) == "yellow");

  // test size
  CHECK(key_value.size() == 2);

  CHECK(key_value.RemoveOne(7));

  // test key and value are in the KeyValue container
  CHECK(key_value.ValueAt(5) == "yellow");

  // test size
  CHECK(key_value.size() == 1);

  CHECK(key_value.RemoveOne(5));

  // test size
  CHECK(key_value.size() == 0);

  CHECK(!key_value.RemoveOne(5));

  // test size
  CHECK(key_value.size() == 0);
}

TEST_CASE(
    "RemoveOne method removes nothing and returns false when key not found "
    "for keys of type int and values of type string",
    "[remove_one]") {
  KeyValue<int, string, kSize> key_value;
  // add key value pairs to container
  key_value.Add(7, "blue");
  key_value.Add(3, "gray");
  key_value.Add(7, "purple");
  key_value.Add(5, "yellow");
  key_value.Add(7, "green");

  // test size before remove
  CHECK(key_value.size() == 5);

  CHECK(!key_value.RemoveOne(17));

  // test size after remove
  CHECK(key_value.size() == 5);

  // test key and value are in the KeyValue container
  CHECK(key_value.ValueAt(3) == "gray");
  CHECK(key_value.ValueAt(5) == "yellow");
}

TEST_CASE(
    "RemoveOne method removes nothing and returns false container is empty "
    "for keys of type int and values of type string",
    "[remove_one]") {
  KeyValue<int, string, kSize> key_value;

  CHECK(!key_value.RemoveOne(7));

  // test size after remove
  CHECK(key_value.size() == 0);
}

TEST_CASE(
    "RemoveAll method removes keys and values expected and returns number when "
    "key is found multiple times "
    "for keys of type int and values of type string ",
    "[remove_all]") {
  KeyValue<int, string, kSize> key_value;
  // add key value pairs to container
  key_value.Add(7, "blue");
  key_value.Add(3, "gray");
  key_value.Add(7, "purple");
  key_value.Add(5, "yellow");
  key_value.Add(7, "green");

  // test size
  CHECK(key_value.size() == 5);

  CHECK(key_value.RemoveAll(7) == 3);

  // test key and value are in the KeyValue container
  CHECK(key_value.ValueAt(3) == "gray");
  CHECK(key_value.ValueAt(5) == "yellow");

  // test size
  CHECK(key_value.size() == 2);
  CHECK_THROWS_AS(key_value.ValueAt(7), out_of_range);
}

TEST_CASE(
    "RemoveAll method removes keys and values expected and returns 1 when "
    "key is found one time "
    "for keys of type int and values of type string ",
    "[remove_all]") {
  KeyValue<int, string, kSize> key_value;
  // add key value pairs to container
  key_value.Add(7, "blue");
  key_value.Add(3, "gray");
  key_value.Add(7, "purple");
  key_value.Add(5, "yellow");
  key_value.Add(7, "green");

  // test size
  CHECK(key_value.size() == 5);

  CHECK(key_value.RemoveAll(5) == 1);

  // test key and value are in the KeyValue container
  CHECK(key_value.ValueAt(3) == "gray");
  CHECK_THROWS_AS(key_value.ValueAt(5), out_of_range);
  // test size
  CHECK(key_value.size() == 4);
}

TEST_CASE(
    "RemoveAll method removes nothing and returns zero when key not found "
    "for keys of type int and values of type string ",
    "[remove_all]") {
  KeyValue<int, string, kSize> key_value;
  // add key value pairs to container
  key_value.Add(7, "blue");
  key_value.Add(3, "gray");
  key_value.Add(9, "purple");
  key_value.Add(5, "yellow");
  key_value.Add(17, "green");

  // test size
  CHECK(key_value.size() == 5);

  CHECK(key_value.RemoveAll(22) == 0);

  // test key and value are in the KeyValue container
  CHECK(key_value.ValueAt(7) == "blue");
  CHECK(key_value.ValueAt(3) == "gray");
  CHECK(key_value.ValueAt(9) == "purple");
  CHECK(key_value.ValueAt(5) == "yellow");
  CHECK(key_value.ValueAt(17) == "green");

  // test size
  CHECK(key_value.size() == 5);
}

TEST_CASE(
    "Found method returns true when key found and false when key not found "
    "for keys of type int and values of type string ",
    "[found]") {
  KeyValue<int, string, kSize> key_value;
  // add key value pairs to container
  key_value.Add(7, "blue");
  key_value.Add(3, "gray");
  key_value.Add(9, "purple");
  key_value.Add(5, "yellow");
  key_value.Add(17, "green");

  // test size
  CHECK(key_value.size() == 5);

  CHECK(!key_value.Found(22));

  // test key and value are in the KeyValue container
  CHECK(key_value.Found(7));
  CHECK(key_value.Found(3));
  CHECK(key_value.Found(9));
  CHECK(key_value.Found(5));
  CHECK(key_value.Found(17));

  // test size
  CHECK(key_value.size() == 5);
}

TEST_CASE(
    "Empty method returns true when empty and false when not empty "
    "for keys of type int and values of type string ",
    "[empty]") {
  KeyValue<int, string, kSize> key_value;
  // add key value pairs to container

  CHECK(key_value.Empty());
  // test size
  CHECK(key_value.size() == 0);
  key_value.Add(7, "green");
  CHECK(!key_value.Empty());
  // test size
  CHECK(key_value.size() == 1);
  key_value.RemoveOne(7);
  CHECK(key_value.Empty());
  // test size
  CHECK(key_value.size() == 0);
}

TEST_CASE(
    "Full method returns true when full and false when not full "
    "for keys of type int and values of type string "
    "Also, tests size method",
    "[full]") {
  KeyValue<int, string, kSize> key_value;
  // add key value pairs to container

  CHECK(!key_value.Full());
  CHECK(key_value.size() == 0);
  key_value.Add(7, "blue");
  CHECK(!key_value.Full());
  CHECK(key_value.size() == 1);
  key_value.Add(3, "gray");
  CHECK(!key_value.Full());
  CHECK(key_value.size() == 2);
  key_value.Add(9, "purple");
  CHECK(!key_value.Full());
  CHECK(key_value.size() == 3);
  key_value.Add(5, "yellow");
  CHECK(!key_value.Full());
  CHECK(key_value.size() == 4);
  key_value.Add(17, "green");
  CHECK(key_value.Full());
  CHECK(key_value.size() == 5);
  key_value.RemoveOne(7);
  CHECK(!key_value.Full());
  // test size
  CHECK(key_value.size() == 4);
}

TEST_CASE(
    "The << operator works and outputs key, space, value, carriage return for "
    "all elements in the KeyValue container "
    "for keys of type int and values of type string ",
    "[remove_all]") {
  KeyValue<int, string, kSize> key_value;
  // add key value pairs to container
  key_value.Add(7, "blue");
  key_value.Add(3, "gray");
  key_value.Add(9, "purple");
  key_value.Add(5, "yellow");
  key_value.Add(17, "green");

  // test <<size>>
  ofstream out("test_output.txt");
  out << key_value;
  out.close();

  ifstream in("test_output.txt");
  string line;
  getline(in, line);
  CHECK("7: blue" == line);
  getline(in, line);
  CHECK("3: gray" == line);
  getline(in, line);
  CHECK("9: purple");
  getline(in, line);
  CHECK("5: yellow" == line);
  getline(in, line);
  CHECK("17: green" == line);
  getline(in, line);
  CHECK("" == line);

  in.close();
}

//******************************int, Carton, 5******************************

TEST_CASE(
    "The << operator prints Cartons as Carton length x width x height with a "
    "precision of one digit after the decimal",
    "[insertion]") {
  // test size
  Carton one(22, 7, 19.38);
  Carton two(8, 20, 9.54);

  std::ofstream out("test.out");
  out << one << std::endl;
  out << two << std::endl;
  out.close();

  std::ifstream in("test.out");
  std::string line;
  getline(in, line);
  if (fabs(one.width() - 7.0) < .001) {
    CHECK("Carton 22.0 x 7.0 x 19.4" == line);
  } else {
    CHECK("Carton 22.0 x 19.4 x 7.0" == line);
  }

  getline(in, line);

  if (fabs(one.width() - 8.0) < .001) {
    CHECK("Carton 20.0 x 8.0 x 9.5" == line);
  } else {
    CHECK("Carton 20.0 x 9.5 x 8.0" == line);
  }
  getline(in, line);
  CHECK("" == line);
}

TEST_CASE(
    "Add method adds keys and values expected and ValueAt finds them"
    "for keys of type int and values of type Carton "
    "throws out_of_range exception when Add called after full",
    "[add][value]") {
  KeyValue<int, Carton, kSize> key_value;
  // add key value pairs to container
  key_value.Add(7, Carton(22, 7, 19.3));
  key_value.Add(3, Carton(16, 8, 20));
  key_value.Add(9, Carton(6, 8.5, 16));
  key_value.Add(5, Carton(14, 9.6, 12));
  key_value.Add(17, Carton(20.8, 12, 14.2));

  // test size
  CHECK(key_value.size() == 5);

  // test key and value are in the KeyValue container
  CHECK(fabs(key_value.ValueAt(7).Volume() - 2972.2) < .1);
  CHECK(fabs(key_value.ValueAt(3).Volume() - 2560) < .1);
  CHECK(fabs(key_value.ValueAt(9).Volume() - 816) < .1);
  CHECK(fabs(key_value.ValueAt(5).Volume() - 1612.8) < .1);
  CHECK(fabs(key_value.ValueAt(17).Volume() - 3544.32) < .1);

  // add one after full, expect exception
  CHECK_THROWS_AS(key_value.Add(101, Carton(22, 7, 19.3)), out_of_range);
}

TEST_CASE(
    "Add method adds keys and values expected and ValueAt finds them"
    "for keys of type int and values of type Carton "
    "ValueAt method throws out_of_range when key not found",
    "[add][value]") {
  KeyValue<int, Carton, kSize> key_value;
  // add key value pairs to container
  key_value.Add(7, Carton(22, 7, 19.3));
  key_value.Add(3, Carton(16, 8, 20));
  key_value.Add(9, Carton(6, 8.5, 16));
  key_value.Add(5, Carton(14, 9.6, 12));
  key_value.Add(17, Carton(20.8, 12, 14.2));

  // test size
  CHECK(key_value.size() == 5);

  // call ValueAt with key not used, expect exception
  CHECK_THROWS_AS(key_value.ValueAt(107), out_of_range);
}

TEST_CASE(
    "RemoveOne method removes key and value expected and returns true "
    "for keys of type int and values of type Carton",
    "[remove_one]") {
  KeyValue<int, Carton, kSize> key_value;
  // add key value pairs to container
  key_value.Add(7, Carton(22, 7, 19.3));
  key_value.Add(3, Carton(16, 8, 20));
  key_value.Add(7, Carton(6, 8.5, 16));
  key_value.Add(5, Carton(14, 9.6, 12));
  key_value.Add(7, Carton(20.8, 12, 14.2));

  // test size
  CHECK(key_value.size() == 5);

  CHECK(key_value.RemoveOne(7));

  // test key and value are in the KeyValue container
  CHECK(fabs(key_value.ValueAt(3).Volume() - 2560) < .1);
  CHECK(fabs(key_value.ValueAt(5).Volume() - 1612.8) < .1);

  // test size
  CHECK(key_value.size() == 4);

  CHECK(key_value.RemoveOne(3));

  // test key and value are in the KeyValue container
  CHECK(key_value.size() == 3);

  CHECK(key_value.RemoveOne(7));

  // test key and value are in the KeyValue container
  CHECK(fabs(key_value.ValueAt(5).Volume() - 1612.8) < .1);

  // test size
  CHECK(key_value.size() == 2);

  CHECK(key_value.RemoveOne(7));

  // test key and value are in the KeyValue container
  CHECK(fabs(key_value.ValueAt(5).Volume() - 1612.8) < .1);

  // test size
  CHECK(key_value.size() == 1);

  CHECK(key_value.RemoveOne(5));

  // test size
  CHECK(key_value.size() == 0);

  CHECK(!key_value.RemoveOne(5));

  // test size
  CHECK(key_value.size() == 0);
}
//*******************************
TEST_CASE(
    "RemoveOne method removes nothing and returns false when key not found "
    "for keys of type int and values of type Carton",
    "[remove_one]") {
  KeyValue<int, Carton, kSize> key_value;
  // add key value pairs to container
  key_value.Add(7, Carton(22, 7, 19.3));
  key_value.Add(3, Carton(16, 8, 20));
  key_value.Add(9, Carton(6, 8.5, 16));
  key_value.Add(5, Carton(14, 9.6, 12));
  key_value.Add(17, Carton(20.8, 12, 14.2));

  // test size before remove
  CHECK(key_value.size() == 5);

  CHECK(!key_value.RemoveOne(28));

  // test size after remove
  CHECK(key_value.size() == 5);

  // test key and value are in the KeyValue container
  CHECK(fabs(key_value.ValueAt(3).Volume() - 2560) < .1);
  CHECK(fabs(key_value.ValueAt(5).Volume() - 1612.8) < .1);
}

TEST_CASE(
    "RemoveOne method removes nothing and returns false container is empty "
    "for keys of type int and values of type Carton",
    "[remove_one]") {
  KeyValue<int, string, kSize> key_value;

  CHECK(!key_value.RemoveOne(7));

  // test size after remove
  CHECK(key_value.size() == 0);
}

TEST_CASE(
    "RemoveAll method removes keys and values expected and returns number when "
    "key is found multiple times "
    "for keys of type int and values of type Carton ",
    "[remove_all]") {
  KeyValue<int, Carton, kSize> key_value;
  // add key value pairs to container
  key_value.Add(7, Carton(22, 7, 19.3));
  key_value.Add(3, Carton(16, 8, 20));
  key_value.Add(7, Carton(6, 8.5, 16));
  key_value.Add(5, Carton(14, 9.6, 12));
  key_value.Add(7, Carton(20.8, 12, 14.2));

  // test size
  CHECK(key_value.size() == 5);

  CHECK(key_value.RemoveAll(7) == 3);

  // test key and value are in the KeyValue container
  CHECK(fabs(key_value.ValueAt(3).Volume() - 2560) < .1);
  CHECK(fabs(key_value.ValueAt(5).Volume() - 1612.8) < .1);

  // test size
  CHECK(key_value.size() == 2);
  CHECK_THROWS_AS(key_value.ValueAt(7), out_of_range);
}

TEST_CASE(
    "RemoveAll method removes keys and values expected and returns 1 when "
    "key is found one time "
    "for keys of type int and values of type Carton ",
    "[remove_all]") {
  KeyValue<int, Carton, kSize> key_value;
  // add key value pairs to container
  key_value.Add(7, Carton(22, 7, 19.3));
  key_value.Add(3, Carton(16, 8, 20));
  key_value.Add(7, Carton(6, 8.5, 16));
  key_value.Add(5, Carton(14, 9.6, 12));
  key_value.Add(7, Carton(20.8, 12, 14.2));

  // test size
  CHECK(key_value.size() == 5);

  CHECK(key_value.RemoveAll(5) == 1);

  // test key and value are in the KeyValue container
  CHECK(fabs(key_value.ValueAt(3).Volume() - 2560) < .1);
  CHECK_THROWS_AS(key_value.ValueAt(5), out_of_range);
  // test size
  CHECK(key_value.size() == 4);
}

TEST_CASE(
    "RemoveAll method removes nothing and returns zero when key not found "
    "for keys of type int and values of type Carton ",
    "[remove_all]") {
  KeyValue<int, Carton, kSize> key_value;
  // add key value pairs to container
  key_value.Add(7, Carton(22, 7, 19.3));
  key_value.Add(3, Carton(16, 8, 20));
  key_value.Add(9, Carton(6, 8.5, 16));
  key_value.Add(5, Carton(14, 9.6, 12));
  key_value.Add(17, Carton(20.8, 12, 14.2));

  // test size
  CHECK(key_value.size() == 5);

  CHECK(key_value.RemoveAll(22) == 0);

  // test key and value are in the KeyValue container
  CHECK(fabs(key_value.ValueAt(7).Volume() - 2972.2) < .1);
  CHECK(fabs(key_value.ValueAt(3).Volume() - 2560) < .1);
  CHECK(fabs(key_value.ValueAt(9).Volume() - 816) < .1);
  CHECK(fabs(key_value.ValueAt(5).Volume() - 1612.8) < .1);
  CHECK(fabs(key_value.ValueAt(17).Volume() - 3544.32) < .1);

  // test size
  CHECK(key_value.size() == 5);
}

TEST_CASE(
    "Found method returns true when key found and false when key not found "
    "for keys of type int and values of type Carton ",
    "[found]") {
  KeyValue<int, Carton, kSize> key_value;
  // add key value pairs to container
  key_value.Add(7, Carton(22, 7, 19.3));
  key_value.Add(3, Carton(16, 8, 20));
  key_value.Add(9, Carton(6, 8.5, 16));
  key_value.Add(5, Carton(14, 9.6, 12));
  key_value.Add(17, Carton(20.8, 12, 14.2));

  // test size
  CHECK(key_value.size() == 5);

  CHECK(!key_value.Found(22));

  // test key and value are in the KeyValue container
  CHECK(key_value.Found(7));
  CHECK(key_value.Found(3));
  CHECK(key_value.Found(9));
  CHECK(key_value.Found(5));
  CHECK(key_value.Found(17));

  // test size
  CHECK(key_value.size() == 5);
}

TEST_CASE(
    "Empty method returns true when empty and false when not empty "
    "for keys of type int and values of type Carton ",
    "[empty]") {
  KeyValue<int, Carton, kSize> key_value;
  // add key value pairs to container

  CHECK(key_value.Empty());
  // test size
  CHECK(key_value.size() == 0);
  key_value.Add(7, Carton(6, 8.5, 16));
  CHECK(!key_value.Empty());
  // test size
  CHECK(key_value.size() == 1);
  key_value.RemoveOne(7);
  CHECK(key_value.Empty());
  // test size
  CHECK(key_value.size() == 0);
}

TEST_CASE(
    "Full method returns true when full and false when not full "
    "for keys of type int and values of type Carton "
    "Also, tests size method",
    "[full]") {
  KeyValue<int, Carton, kSize> key_value;

  CHECK(!key_value.Full());
  CHECK(key_value.size() == 0);
  key_value.Add(7, Carton(22, 7, 19.3));
  CHECK(!key_value.Full());
  CHECK(key_value.size() == 1);
  key_value.Add(3, Carton(16, 8, 20));
  CHECK(!key_value.Full());
  CHECK(key_value.size() == 2);
  key_value.Add(9, Carton(6, 8.5, 16));
  CHECK(!key_value.Full());
  CHECK(key_value.size() == 3);
  key_value.Add(5, Carton(14, 9.6, 12));
  CHECK(!key_value.Full());
  CHECK(key_value.size() == 4);
  key_value.Add(17, Carton(20.8, 12, 14.2));
  CHECK(key_value.Full());
  CHECK(key_value.size() == 5);
  key_value.RemoveOne(7);
  CHECK(!key_value.Full());
  // test size
  CHECK(key_value.size() == 4);
}

TEST_CASE(
    "The << operator works and outputs key, space, value, carriage return for "
    "all elements in the KeyValue container "
    "for keys of type int and values of type Carton ",
    "[remove_all]") {
  KeyValue<int, Carton, kSize> key_value;
  // add key value pairs to container
  key_value.Add(7, Carton(22, 7, 19.3));
  key_value.Add(3, Carton(16, 8, 20));
  key_value.Add(9, Carton(6, 8.5, 16));
  key_value.Add(5, Carton(14, 9.6, 12));
  key_value.Add(17, Carton(20.8, 12, 14.2));
  // test size
  CHECK(key_value.size() == 5);

  // test <<
  ofstream out("test_output.txt");
  out << key_value;
  out.close();

  ifstream in("test_output.txt");
  string line;
  getline(in, line);
  if (key_value.ValueAt(7).width() == 7) {
    CHECK("7: Carton 22.0 x 7.0 x 19.3" == line);
  } else {
    CHECK("7: Carton 22.0 x 19.3 x 7.0" == line);
  }

  getline(in, line);
  if (key_value.ValueAt(3).width() == 16) {
    CHECK("3: Carton 20.0 x 16.0 x 8.0" == line);
  } else {
    CHECK("3: Carton 20.0 x 8.0 x 16.0" == line);
  }

  getline(in, line);
  if (key_value.ValueAt(9).width() == 6) {
    CHECK("9: Carton 16.0 x 6.0 x 8.5" == line);
  } else {
    CHECK("9: Carton 16.0 x 8.5 x 6.0" == line);
  }

  getline(in, line);
  if (key_value.ValueAt(5).width() == 12) {
    CHECK("5: Carton 14.0 x 12.0 x 9.6" == line);
  } else {
    CHECK("5: Carton 14.0 x 9.6 x 12.0" == line);
  }

  getline(in, line);
  if (key_value.ValueAt(17).width() == 12) {
    CHECK("17: Carton 20.8 x 12.0 x 14.2" == line);
  } else {
    CHECK("17: Carton 20.8 x 14.2 x 12.0" == line);
  }

  getline(in, line);
  CHECK("" == line);

  in.close();
}

//******************************string, int, 5******************************

TEST_CASE(
    "Add method adds keys and values expected and ValueAt finds them"
    "for keys of type string and values of type int "
    "throws out_of_range exception when Add called after full",
    "[add][value]") {
  KeyValue<string, int, kSize> key_value;
  // add key value pairs to container
  key_value.Add("John", 22);
  key_value.Add("Carol", 12);
  key_value.Add("Walter", 18);
  key_value.Add("Samantha", 91);
  key_value.Add("Kelly", 35);

  // test size
  CHECK(key_value.size() == 5);

  // test key and value are in the KeyValue container
  CHECK(key_value.ValueAt("John") == 22);
  CHECK(key_value.ValueAt("Carol") == 12);
  CHECK(key_value.ValueAt("Walter") == 18);
  CHECK(key_value.ValueAt("Samantha") == 91);
  CHECK(key_value.ValueAt("Kelly") == 35);

  // add one after full, expect exception
  CHECK_THROWS_AS(key_value.Add("Pat", 99), out_of_range);
}

TEST_CASE(
    "Add method adds keys and values expected and ValueAt finds them"
    "for keys of type string and values of type int "
    "ValueAt method throws out_of_range when key not found",
    "[add][value]") {
  KeyValue<string, int, kSize> key_value;
  // add key value pairs to container
  key_value.Add("John", 22);
  key_value.Add("Carol", 12);
  key_value.Add("Walter", 18);
  key_value.Add("Samantha", 91);
  key_value.Add("Kelly", 35);

  // test size
  CHECK(key_value.size() == 5);

  // call ValueAt with key not used, expect exception
  CHECK_THROWS_AS(key_value.ValueAt("Pat"), out_of_range);
}

TEST_CASE(
    "RemoveOne method removes key and value expected and returns true "
    "for keys of type string and values of type int",
    "[remove_one]") {
  KeyValue<string, int, kSize> key_value;
  // add key value pairs to container
  key_value.Add("John", 22);
  key_value.Add("Carol", 12);
  key_value.Add("John", 18);
  key_value.Add("Samantha", 91);
  key_value.Add("John", 35);

  // test size
  CHECK(key_value.size() == 5);

  CHECK(key_value.RemoveOne("John"));

  // test key and value are in the KeyValue container
  CHECK(key_value.ValueAt("Carol") == 12);
  CHECK(key_value.ValueAt("Samantha") == 91);

  // test size
  CHECK(key_value.size() == 4);

  CHECK(key_value.RemoveOne("Carol"));

  // test key and value are in the KeyValue container
  CHECK(key_value.ValueAt("Samantha") == 91);

  // test size
  CHECK(key_value.size() == 3);

  CHECK(key_value.RemoveOne("John"));

  // test key and value are in the KeyValue container
  CHECK(key_value.ValueAt("Samantha") == 91);

  // test size
  CHECK(key_value.size() == 2);

  CHECK(key_value.RemoveOne("John"));

  // test key and value are in the KeyValue container
  CHECK(key_value.ValueAt("Samantha") == 91);

  // test size
  CHECK(key_value.size() == 1);

  CHECK(key_value.RemoveOne("Samantha"));

  // test size
  CHECK(key_value.size() == 0);

  CHECK(!key_value.RemoveOne("Samantha"));

  // test size
  CHECK(key_value.size() == 0);
}

TEST_CASE(
    "RemoveOne method removes nothing and returns false when key not found "
    "for keys of type string and values of type int",
    "[remove_one]") {
  KeyValue<string, int, kSize> key_value;
  // add key value pairs to container
  key_value.Add("John", 22);
  key_value.Add("Carol", 12);
  key_value.Add("John", 18);
  key_value.Add("Samantha", 91);
  key_value.Add("John", 35);

  // test size before remove
  CHECK(key_value.size() == 5);

  CHECK(!key_value.RemoveOne("Pat"));

  // test size after remove
  CHECK(key_value.size() == 5);

  // test key and value are in the KeyValue container
  CHECK(key_value.ValueAt("Carol") == 12);
  CHECK(key_value.ValueAt("Samantha") == 91);
}

TEST_CASE(
    "RemoveOne method removes nothing and returns false container is empty "
    "for keys of type string and values of type int",
    "[remove_one]") {
  KeyValue<string, int, kSize> key_value;

  CHECK(!key_value.RemoveOne("John"));

  // test size after remove
  CHECK(key_value.size() == 0);
}

TEST_CASE(
    "RemoveAll method removes keys and values expected and returns number when "
    "key is found multiple times "
    "for keys of type string and values of type int ",
    "[remove_all]") {
  KeyValue<string, int, kSize> key_value;
  // add key value pairs to container
  key_value.Add("John", 22);
  key_value.Add("Carol", 12);
  key_value.Add("John", 18);
  key_value.Add("Samantha", 91);
  key_value.Add("John", 35);

  // test size
  CHECK(key_value.size() == 5);

  CHECK(key_value.RemoveAll("John") == 3);

  // test key and value are in the KeyValue container
  CHECK(key_value.ValueAt("Carol") == 12);
  CHECK(key_value.ValueAt("Samantha") == 91);

  // test size
  CHECK(key_value.size() == 2);
  CHECK_THROWS_AS(key_value.ValueAt("John"), out_of_range);
}

TEST_CASE(
    "RemoveAll method removes keys and values expected and returns 1 when "
    "key is found one time "
    "for keys of type string and values of type int ",
    "[remove_all]") {
  KeyValue<string, int, kSize> key_value;
  // add key value pairs to container
  key_value.Add("John", 22);
  key_value.Add("Carol", 12);
  key_value.Add("John", 18);
  key_value.Add("Samantha", 91);
  key_value.Add("John", 35);

  // test size
  CHECK(key_value.size() == 5);

  CHECK(key_value.RemoveAll("Samantha") == 1);

  // test key and value are in the KeyValue container
  CHECK(key_value.ValueAt("Carol") == 12);
  CHECK_THROWS_AS(key_value.ValueAt("Samantha"), out_of_range);
  // test size
  CHECK(key_value.size() == 4);
}

TEST_CASE(
    "RemoveAll method removes nothing and returns zero when key not found "
    "for keys of type string and values of type int ",
    "[remove_all]") {
  KeyValue<string, int, kSize> key_value;
  // add key value pairs to container
  key_value.Add("John", 22);
  key_value.Add("Carol", 12);
  key_value.Add("Walter", 18);
  key_value.Add("Samantha", 91);
  key_value.Add("Kelly", 35);

  // test size
  CHECK(key_value.size() == 5);

  CHECK(key_value.RemoveAll("Kim") == 0);

  // test key and value are in the KeyValue container
  CHECK(key_value.ValueAt("John") == 22);
  CHECK(key_value.ValueAt("Carol") == 12);
  CHECK(key_value.ValueAt("Walter") == 18);
  CHECK(key_value.ValueAt("Samantha") == 91);
  CHECK(key_value.ValueAt("Kelly") == 35);

  // test size
  CHECK(key_value.size() == 5);
}

TEST_CASE(
    "Found method returns true when key found and false when key not found "
    "for keys of type string and values of type int ",
    "[found]") {
  KeyValue<string, int, kSize> key_value;
  // add key value pairs to container
  key_value.Add("John", 22);
  key_value.Add("Carol", 12);
  key_value.Add("Walter", 18);
  key_value.Add("Samantha", 91);
  key_value.Add("Kelly", 35);

  // test size
  CHECK(key_value.size() == 5);

  CHECK(!key_value.Found("Kim"));

  // test key and value are in the KeyValue container
  CHECK(key_value.Found("John"));
  CHECK(key_value.Found("Carol"));
  CHECK(key_value.Found("Walter"));
  CHECK(key_value.Found("Samantha"));
  CHECK(key_value.Found("Kelly"));

  // test size
  CHECK(key_value.size() == 5);
}

TEST_CASE(
    "Empty method returns true when empty and false when not empty "
    "for keys of type string and values of type int ",
    "[empty]") {
  KeyValue<string, int, kSize> key_value;
  // add key value pairs to container

  CHECK(key_value.Empty());
  // test size
  CHECK(key_value.size() == 0);
  key_value.Add("John", 22);
  CHECK(!key_value.Empty());
  // test size
  CHECK(key_value.size() == 1);
  key_value.RemoveOne("John");
  CHECK(key_value.Empty());
  // test size
  CHECK(key_value.size() == 0);
}

TEST_CASE(
    "Full method returns true when full and false when not full "
    "for keys of type string and values of type int "
    "Also, tests size method",
    "[full]") {
  KeyValue<string, int, kSize> key_value;
  // add key value pairs to container

  CHECK(!key_value.Full());
  CHECK(key_value.size() == 0);
  key_value.Add("John", 22);
  CHECK(!key_value.Full());
  CHECK(key_value.size() == 1);
  key_value.Add("Carol", 12);
  CHECK(!key_value.Full());
  CHECK(key_value.size() == 2);
  key_value.Add("Walter", 18);
  CHECK(!key_value.Full());
  CHECK(key_value.size() == 3);
  key_value.Add("Samantha", 91);
  CHECK(!key_value.Full());
  CHECK(key_value.size() == 4);
  key_value.Add("Kelly", 35);
  CHECK(key_value.Full());
  CHECK(key_value.size() == 5);
  key_value.RemoveOne("John");
  CHECK(!key_value.Full());
  // test size
  CHECK(key_value.size() == 4);
}

TEST_CASE(
    "The << operator works and outputs key, space, value, carriage return for "
    "all elements in the KeyValue container "
    "for keys of type string and values of type int ",
    "[remove_all]") {
  KeyValue<string, int, kSize> key_value;
  // add key value pairs to container
  key_value.Add("John", 22);
  key_value.Add("Carol", 12);
  key_value.Add("Walter", 18);
  key_value.Add("Samantha", 91);
  key_value.Add("Kelly", 35);

  // test <<size>>
  ofstream out("test_output.txt");
  out << key_value;
  out.close();

  ifstream in("test_output.txt");
  string line;
  getline(in, line);
  CHECK("John: 22" == line);
  getline(in, line);
  CHECK("Carol: 12" == line);
  getline(in, line);
  CHECK("Walter: 18");
  getline(in, line);
  CHECK("Samantha: 91" == line);
  getline(in, line);
  CHECK("Kelly: 35" == line);
  getline(in, line);
  CHECK("" == line);

  in.close();
}

//******************************string, string, 5******************************

TEST_CASE(
    "Add method adds keys and values expected and ValueAt finds them"
    "for keys of type string and values of type string "
    "throws out_of_range exception when Add called after full",
    "[add][value]") {
  KeyValue<string, string, kSize> key_value;
  // add key value pairs to container
  key_value.Add("John", "blue");
  key_value.Add("Carol", "gray");
  key_value.Add("Walter", "purple");
  key_value.Add("Samantha", "yellow");
  key_value.Add("Kelly", "green");

  // test size
  CHECK(key_value.size() == 5);

  // test key and value are in the KeyValue container
  CHECK(key_value.ValueAt("John") == "blue");
  CHECK(key_value.ValueAt("Carol") == "gray");
  CHECK(key_value.ValueAt("Walter") == "purple");
  CHECK(key_value.ValueAt("Samantha") == "yellow");
  CHECK(key_value.ValueAt("Kelly") == "green");

  // add one after full, expect exception
  CHECK_THROWS_AS(key_value.Add("Pat", "orange"), out_of_range);
}

TEST_CASE(
    "Add method adds keys and values expected and ValueAt finds them"
    "for keys of type string and values of type string "
    "ValueAt method throws out_of_range when key not found",
    "[add][value]") {
  KeyValue<string, string, kSize> key_value;
  // add key value pairs to container
  key_value.Add("John", "blue");
  key_value.Add("Carol", "gray");
  key_value.Add("Walter", "purple");
  key_value.Add("Samantha", "yellow");
  key_value.Add("Kelly", "green");

  // test size
  CHECK(key_value.size() == 5);

  // call ValueAt with key not used, expect exception
  CHECK_THROWS_AS(key_value.ValueAt("Pat"), out_of_range);
}

TEST_CASE(
    "RemoveOne method removes key and value expected and returns true "
    "for keys of type string and values of type string",
    "[remove_one]") {
  KeyValue<string, string, kSize> key_value;
  // add key value pairs to container
  key_value.Add("John", "blue");
  key_value.Add("Carol", "gray");
  key_value.Add("John", "purple");
  key_value.Add("Samantha", "yellow");
  key_value.Add("John", "green");

  // test size
  CHECK(key_value.size() == 5);

  CHECK(key_value.RemoveOne("John"));

  // test key and value are in the KeyValue container
  CHECK(key_value.ValueAt("Carol") == "gray");
  CHECK(key_value.ValueAt("Samantha") == "yellow");

  // test size
  CHECK(key_value.size() == 4);

  CHECK(key_value.RemoveOne("Carol"));

  // test key and value are in the KeyValue container
  CHECK(key_value.size() == 3);

  CHECK(key_value.RemoveOne("John"));

  // test key and value are in the KeyValue container
  CHECK(key_value.ValueAt("Samantha") == "yellow");

  // test size
  CHECK(key_value.size() == 2);

  CHECK(key_value.RemoveOne("John"));

  // test key and value are in the KeyValue container
  CHECK(key_value.ValueAt("Samantha") == "yellow");

  // test size
  CHECK(key_value.size() == 1);

  CHECK(key_value.RemoveOne("Samantha"));

  // test size
  CHECK(key_value.size() == 0);

  CHECK(!key_value.RemoveOne("Samantha"));

  // test size
  CHECK(key_value.size() == 0);
}

TEST_CASE(
    "RemoveOne method removes nothing and returns false when key not found "
    "for keys of type string and values of type string",
    "[remove_one]") {
  KeyValue<string, string, kSize> key_value;
  // add key value pairs to container
  key_value.Add("John", "blue");
  key_value.Add("Carol", "gray");
  key_value.Add("Walter", "purple");
  key_value.Add("Samantha", "yellow");
  key_value.Add("Kelly", "green");

  // test size before remove
  CHECK(key_value.size() == 5);

  CHECK(!key_value.RemoveOne("Pat"));

  // test size after remove
  CHECK(key_value.size() == 5);

  // test key and value are in the KeyValue container
  CHECK(key_value.ValueAt("John") == "blue");
  CHECK(key_value.ValueAt("Carol") == "gray");
  CHECK(key_value.ValueAt("Walter") == "purple");
  CHECK(key_value.ValueAt("Samantha") == "yellow");
  CHECK(key_value.ValueAt("Kelly") == "green");
}

TEST_CASE(
    "RemoveOne method removes nothing and returns false container is empty "
    "for keys of type string and values of type string",
    "[remove_one]") {
  KeyValue<string, string, kSize> key_value;

  CHECK(!key_value.RemoveOne("John"));

  // test size after remove
  CHECK(key_value.size() == 0);
}

TEST_CASE(
    "RemoveAll method removes keys and values expected and returns number when "
    "key is found multiple times "
    "for keys of type string and values of type string ",
    "[remove_all]") {
  KeyValue<string, string, kSize> key_value;
  // add key value pairs to container
  key_value.Add("John", "blue");
  key_value.Add("Carol", "gray");
  key_value.Add("John", "purple");
  key_value.Add("Samantha", "yellow");
  key_value.Add("John", "green");

  // test size
  CHECK(key_value.size() == 5);

  CHECK(key_value.RemoveAll("John") == 3);

  // test key and value are in the KeyValue container
  CHECK(key_value.ValueAt("Carol") == "gray");
  CHECK(key_value.ValueAt("Samantha") == "yellow");

  // test size
  CHECK(key_value.size() == 2);
  CHECK_THROWS_AS(key_value.ValueAt("John"), out_of_range);
}

TEST_CASE(
    "RemoveAll method removes keys and values expected and returns 1 when "
    "key is found one time "
    "for keys of type string and values of type string ",
    "[remove_all]") {
  KeyValue<string, string, kSize> key_value;
  // add key value pairs to container
  key_value.Add("John", "blue");
  key_value.Add("Carol", "gray");
  key_value.Add("John", "purple");
  key_value.Add("Samantha", "yellow");
  key_value.Add("John", "green");

  // test size
  CHECK(key_value.size() == 5);

  CHECK(key_value.RemoveAll("Samantha") == 1);

  // test key and value are in the KeyValue container
  CHECK(key_value.ValueAt("Carol") == "gray");
  CHECK_THROWS_AS(key_value.ValueAt("Samantha"), out_of_range);
  // test size
  CHECK(key_value.size() == 4);
}

TEST_CASE(
    "RemoveAll method removes nothing and returns zero when key not found "
    "for keys of type string and values of type string ",
    "[remove_all]") {
  KeyValue<string, string, kSize> key_value;
  // add key value pairs to container
  key_value.Add("John", "blue");
  key_value.Add("Carol", "gray");
  key_value.Add("Walter", "purple");
  key_value.Add("Samantha", "yellow");
  key_value.Add("Kelly", "green");

  // test size
  CHECK(key_value.size() == 5);

  CHECK(key_value.RemoveAll("Pat") == 0);

  // test key and value are in the KeyValue container
  CHECK(key_value.ValueAt("John") == "blue");
  CHECK(key_value.ValueAt("Carol") == "gray");
  CHECK(key_value.ValueAt("Walter") == "purple");
  CHECK(key_value.ValueAt("Samantha") == "yellow");
  CHECK(key_value.ValueAt("Kelly") == "green");

  // test size
  CHECK(key_value.size() == 5);
}

TEST_CASE(
    "Found method returns true when key found and false when key not found "
    "for keys of type string and values of type string ",
    "[found]") {
  KeyValue<string, string, kSize> key_value;
  // add key value pairs to container
  key_value.Add("John", "blue");
  key_value.Add("Carol", "gray");
  key_value.Add("Walter", "purple");
  key_value.Add("Samantha", "yellow");
  key_value.Add("Kelly", "green");

  // test size
  CHECK(key_value.size() == 5);

  CHECK(!key_value.Found("Pat"));

  // test key and value are in the KeyValue container
  CHECK(key_value.Found("John"));
  CHECK(key_value.Found("Carol"));
  CHECK(key_value.Found("Walter"));
  CHECK(key_value.Found("Samantha"));
  CHECK(key_value.Found("Kelly"));

  // test size
  CHECK(key_value.size() == 5);
}

TEST_CASE(
    "Empty method returns true when empty and false when not empty "
    "for keys of type string and values of type string ",
    "[empty]") {
  KeyValue<string, string, kSize> key_value;
  // add key value pairs to container

  CHECK(key_value.Empty());
  // test size
  CHECK(key_value.size() == 0);
  key_value.Add("John", "green");
  CHECK(!key_value.Empty());
  // test size
  CHECK(key_value.size() == 1);
  key_value.RemoveOne("John");
  CHECK(key_value.Empty());
  // test size
  CHECK(key_value.size() == 0);
}

TEST_CASE(
    "Full method returns true when full and false when not full "
    "for keys of type string and values of type string "
    "Also, tests size method",
    "[full]") {
  KeyValue<string, string, kSize> key_value;
  // add key value pairs to container

  CHECK(!key_value.Full());
  CHECK(key_value.size() == 0);
  key_value.Add("John", "blue");
  CHECK(!key_value.Full());
  CHECK(key_value.size() == 1);
  key_value.Add("Carol", "gray");
  CHECK(!key_value.Full());
  CHECK(key_value.size() == 2);
  key_value.Add("Walter", "purple");
  CHECK(!key_value.Full());
  CHECK(key_value.size() == 3);
  key_value.Add("Samantha", "yellow");
  CHECK(!key_value.Full());
  CHECK(key_value.size() == 4);
  key_value.Add("Kelly", "green");
  CHECK(key_value.Full());
  CHECK(key_value.size() == 5);
  key_value.RemoveOne("John");
  CHECK(!key_value.Full());
  // test size
  CHECK(key_value.size() == 4);
}

TEST_CASE(
    "The << operator works and outputs key, space, value, carriage return for "
    "all elements in the KeyValue container "
    "for keys of type string and values of type string ",
    "[remove_all]") {
  KeyValue<string, string, kSize> key_value;
  // add key value pairs to container
  key_value.Add("John", "blue");
  key_value.Add("Carol", "gray");
  key_value.Add("Walter", "purple");
  key_value.Add("Samantha", "yellow");
  key_value.Add("Kelly", "green");

  // test <<size>>
  ofstream out("test_output.txt");
  out << key_value;
  out.close();

  ifstream in("test_output.txt");
  string line;
  getline(in, line);
  CHECK("John: blue" == line);
  getline(in, line);
  CHECK("Carol: gray" == line);
  getline(in, line);
  CHECK("Walter: purple");
  getline(in, line);
  CHECK("Samantha: yellow" == line);
  getline(in, line);
  CHECK("Kelly: green" == line);
  getline(in, line);
  CHECK("" == line);

  in.close();
}

//******************************string, Carton, 5******************************

TEST_CASE(
    "Add method adds keys and values expected and ValueAt finds them"
    "for keys of type string and values of type Carton "
    "throws out_of_range exception when Add called after full",
    "[add][value]") {
  KeyValue<string, Carton, kSize> key_value;
  // add key value pairs to container
  key_value.Add("SLC", Carton(22, 7, 19.3));
  key_value.Add("Ogden", Carton(16, 8, 20));
  key_value.Add("Layton", Carton(6, 8.5, 16));
  key_value.Add("Roy", Carton(14, 9.6, 12));
  key_value.Add("Taylor", Carton(20.8, 12, 14.2));

  // test size
  CHECK(key_value.size() == 5);

  // test key and value are in the KeyValue container
  CHECK(fabs(key_value.ValueAt("SLC").Volume() - 2972.2) < .1);
  CHECK(fabs(key_value.ValueAt("Ogden").Volume() - 2560) < .1);
  CHECK(fabs(key_value.ValueAt("Layton").Volume() - 816) < .1);
  CHECK(fabs(key_value.ValueAt("Roy").Volume() - 1612.8) < .1);
  CHECK(fabs(key_value.ValueAt("Taylor").Volume() - 3544.32) < .1);

  // add one after full, expect exception
  CHECK_THROWS_AS(key_value.Add("Willard", Carton(22, 7, 19.3)),
                    out_of_range);
}

TEST_CASE(
    "Add method adds keys and values expected and ValueAt finds them"
    "for keys of type string and values of type Carton "
    "ValueAt method throws out_of_range when key not found",
    "[add][value]") {
  KeyValue<string, Carton, kSize> key_value;
  // add key value pairs to container
  key_value.Add("SLC", Carton(22, 7, 19.3));
  key_value.Add("Ogden", Carton(16, 8, 20));
  key_value.Add("Layton", Carton(6, 8.5, 16));
  key_value.Add("Roy", Carton(14, 9.6, 12));
  key_value.Add("Taylor", Carton(20.8, 12, 14.2));

  // test size
  CHECK(key_value.size() == 5);

  // call ValueAt with key not used, expect exception
  CHECK_THROWS_AS(key_value.ValueAt("Willard"), out_of_range);
}

TEST_CASE(
    "RemoveOne method removes key and value expected and returns true "
    "for keys of type string and values of type Carton",
    "[remove_one]") {
  KeyValue<string, Carton, kSize> key_value;
  // add key value pairs to container
  key_value.Add("SLC", Carton(22, 7, 19.3));
  key_value.Add("Ogden", Carton(16, 8, 20));
  key_value.Add("SLC", Carton(6, 8.5, 16));
  key_value.Add("Roy", Carton(14, 9.6, 12));
  key_value.Add("SLC", Carton(20.8, 12, 14.2));

  // test size
  CHECK(key_value.size() == 5);

  CHECK(key_value.RemoveOne("SLC"));

  // test key and value are in the KeyValue container
  CHECK(fabs(key_value.ValueAt("Ogden").Volume() - 2560) < .1);
  CHECK(fabs(key_value.ValueAt("Roy").Volume() - 1612.8) < .1);

  // test size
  CHECK(key_value.size() == 4);

  CHECK(key_value.RemoveOne("Ogden"));

  // test key and value are in the KeyValue container
  CHECK(key_value.size() == 3);

  CHECK(key_value.RemoveOne("SLC"));

  // test key and value are in the KeyValue container
  CHECK(fabs(key_value.ValueAt("Roy").Volume() - 1612.8) < .1);

  // test size
  CHECK(key_value.size() == 2);

  CHECK(key_value.RemoveOne("SLC"));

  // test key and value are in the KeyValue container
  CHECK(fabs(key_value.ValueAt("Roy").Volume() - 1612.8) < .1);

  // test size
  CHECK(key_value.size() == 1);

  CHECK(key_value.RemoveOne("Roy"));

  // test size
  CHECK(key_value.size() == 0);

  CHECK(!key_value.RemoveOne("Roy"));

  // test size
  CHECK(key_value.size() == 0);
}
//*******************************
TEST_CASE(
    "RemoveOne method removes nothing and returns false when key not found "
    "for keys of type string and values of type Carton",
    "[remove_one]") {
  KeyValue<string, Carton, kSize> key_value;
  // add key value pairs to container
  key_value.Add("SLC", Carton(22, 7, 19.3));
  key_value.Add("Ogden", Carton(16, 8, 20));
  key_value.Add("Layton", Carton(6, 8.5, 16));
  key_value.Add("Roy", Carton(14, 9.6, 12));
  key_value.Add("Taylor", Carton(20.8, 12, 14.2));

  // test size before remove
  CHECK(key_value.size() == 5);

  CHECK(!key_value.RemoveOne("Willard"));

  // test size after remove
  CHECK(key_value.size() == 5);

  // test key and value are in the KeyValue container
  CHECK(fabs(key_value.ValueAt("Ogden").Volume() - 2560) < .1);
  CHECK(fabs(key_value.ValueAt("Roy").Volume() - 1612.8) < .1);
}

TEST_CASE(
    "RemoveOne method removes nothing and returns false container is empty "
    "for keys of type string and values of type Carton",
    "[remove_one]") {
  KeyValue<string, string, kSize> key_value;

  CHECK(!key_value.RemoveOne("SLC"));

  // test size after remove
  CHECK(key_value.size() == 0);
}

TEST_CASE(
    "RemoveAll method removes keys and values expected and returns number when "
    "key is found multiple times "
    "for keys of type string and values of type Carton ",
    "[remove_all]") {
  KeyValue<string, Carton, kSize> key_value;
  // add key value pairs to container
  key_value.Add("SLC", Carton(22, 7, 19.3));
  key_value.Add("Ogden", Carton(16, 8, 20));
  key_value.Add("SLC", Carton(6, 8.5, 16));
  key_value.Add("Roy", Carton(14, 9.6, 12));
  key_value.Add("SLC", Carton(20.8, 12, 14.2));

  // test size
  CHECK(key_value.size() == 5);

  CHECK(key_value.RemoveAll("SLC") == 3);

  // test key and value are in the KeyValue container
  CHECK(fabs(key_value.ValueAt("Ogden").Volume() - 2560) < .1);
  CHECK(fabs(key_value.ValueAt("Roy").Volume() - 1612.8) < .1);

  // test size
  CHECK(key_value.size() == 2);
  CHECK_THROWS_AS(key_value.ValueAt("SLC"), out_of_range);
}

TEST_CASE(
    "RemoveAll method removes keys and values expected and returns 1 when "
    "key is found one time "
    "for keys of type string and values of type Carton ",
    "[remove_all]") {
  KeyValue<string, Carton, kSize> key_value;
  // add key value pairs to container
  key_value.Add("SLC", Carton(22, 7, 19.3));
  key_value.Add("Ogden", Carton(16, 8, 20));
  key_value.Add("SLC", Carton(6, 8.5, 16));
  key_value.Add("Roy", Carton(14, 9.6, 12));
  key_value.Add("SLC", Carton(20.8, 12, 14.2));

  // test size
  CHECK(key_value.size() == 5);

  CHECK(key_value.RemoveAll("Roy") == 1);

  // test key and value are in the KeyValue container
  CHECK(fabs(key_value.ValueAt("Ogden").Volume() - 2560) < .1);
  CHECK_THROWS_AS(key_value.ValueAt("Roy"), out_of_range);
  // test size
  CHECK(key_value.size() == 4);
}

TEST_CASE(
    "RemoveAll method removes nothing and returns zero when key not found "
    "for keys of type string and values of type Carton ",
    "[remove_all]") {
  KeyValue<string, Carton, kSize> key_value;
  // add key value pairs to container
  key_value.Add("SLC", Carton(22, 7, 19.3));
  key_value.Add("Ogden", Carton(16, 8, 20));
  key_value.Add("Layton", Carton(6, 8.5, 16));
  key_value.Add("Roy", Carton(14, 9.6, 12));
  key_value.Add("Taylor", Carton(20.8, 12, 14.2));

  // test size
  CHECK(key_value.size() == 5);

  CHECK(key_value.RemoveAll("Willard") == 0);

  // test key and value are in the KeyValue container
  CHECK(fabs(key_value.ValueAt("SLC").Volume() - 2972.2) < .1);
  // Carton(22, 7, 19.3));  2972.2
  CHECK(fabs(key_value.ValueAt("Ogden").Volume() - 2560) < .1);
  // Carton(16, 8, 20));  2560
  CHECK(fabs(key_value.ValueAt("Layton").Volume() - 816) < .1);
  // Carton(6, 8.5, 16)); 816
  CHECK(fabs(key_value.ValueAt("Roy").Volume() - 1612.8) < .1);
  // Carton(14, 9.6, 12));  1612.8
  CHECK(fabs(key_value.ValueAt("Taylor").Volume() - 3544.32) < .1);
  // Carton(20.8, 12, 14.2));  3544.32

  // test size
  CHECK(key_value.size() == 5);
}

TEST_CASE(
    "Found method returns true when key found and false when key not found "
    "for keys of type string and values of type Carton ",
    "[found]") {
  KeyValue<string, Carton, kSize> key_value;
  // add key value pairs to container
  key_value.Add("SLC", Carton(22, 7, 19.3));
  key_value.Add("Ogden", Carton(16, 8, 20));
  key_value.Add("Layton", Carton(6, 8.5, 16));
  key_value.Add("Roy", Carton(14, 9.6, 12));
  key_value.Add("Taylor", Carton(20.8, 12, 14.2));

  // test size
  CHECK(key_value.size() == 5);

  CHECK(!key_value.Found("Willard"));

  // test key and value are in the KeyValue container
  CHECK(key_value.Found("SLC"));
  CHECK(key_value.Found("Ogden"));
  CHECK(key_value.Found("Layton"));
  CHECK(key_value.Found("Roy"));
  CHECK(key_value.Found("Taylor"));

  // test size
  CHECK(key_value.size() == 5);
}

TEST_CASE(
    "Empty method returns true when empty and false when not empty "
    "for keys of type string and values of type Carton ",
    "[empty]") {
  KeyValue<string, Carton, kSize> key_value;
  // add key value pairs to container

  CHECK(key_value.Empty());
  // test size
  CHECK(key_value.size() == 0);
  key_value.Add("SLC", Carton(6, 8.5, 16));
  CHECK(!key_value.Empty());
  // test size
  CHECK(key_value.size() == 1);
  key_value.RemoveOne("SLC");
  CHECK(key_value.Empty());
  // test size
  CHECK(key_value.size() == 0);
}

TEST_CASE(
    "Full method returns true when full and false when not full "
    "for keys of type string and values of type Carton "
    "Also, tests size method",
    "[full]") {
  KeyValue<string, Carton, kSize> key_value;

  CHECK(!key_value.Full());
  CHECK(key_value.size() == 0);
  key_value.Add("SLC", Carton(22, 7, 19.3));
  CHECK(!key_value.Full());
  CHECK(key_value.size() == 1);
  key_value.Add("Ogden", Carton(16, 8, 20));
  CHECK(!key_value.Full());
  CHECK(key_value.size() == 2);
  key_value.Add("Layton", Carton(6, 8.5, 16));
  CHECK(!key_value.Full());
  CHECK(key_value.size() == 3);
  key_value.Add("Roy", Carton(14, 9.6, 12));
  CHECK(!key_value.Full());
  CHECK(key_value.size() == 4);
  key_value.Add("Taylor", Carton(20.8, 12, 14.2));
  CHECK(key_value.Full());
  CHECK(key_value.size() == 5);
  key_value.RemoveOne("SLC");
  CHECK(!key_value.Full());
  // test size
  CHECK(key_value.size() == 4);
}

TEST_CASE(
    "The << operator works and outputs key, space, value, carriage return for "
    "all elements in the KeyValue container "
    "for keys of type string and values of type Carton ",
    "[remove_all]") {
  KeyValue<string, Carton, kSize> key_value;
  // add key value pairs to container
  key_value.Add("SLC", Carton(22, 7, 19.3));
  key_value.Add("Ogden", Carton(16, 8, 20));
  key_value.Add("Layton", Carton(6, 8.5, 16));
  key_value.Add("Roy", Carton(14, 9.6, 12));
  key_value.Add("Taylor", Carton(20.8, 12, 14.2));
  // test size
  CHECK(key_value.size() == 5);

  // test <<
  ofstream out("test_output.txt");
  out << key_value;
  out.close();

  ifstream in("test_output.txt");
  string line;
  getline(in, line);
  if (key_value.ValueAt("SLC").width() == 7) {
    CHECK("SLC: Carton 22.0 x 7.0 x 19.3" == line);
  } else {
    CHECK("SLC: Carton 22.0 x 19.3 x 7.0" == line);
  }

  getline(in, line);
  if (key_value.ValueAt("Ogden").width() == 16) {
    CHECK("Ogden: Carton 20.0 x 16.0 x 8.0" == line);
  } else {
    CHECK("Ogden: Carton 20.0 x 8.0 x 16.0" == line);
  }

  getline(in, line);
  if (key_value.ValueAt("Layton").width() == 6) {
    CHECK("Layton: Carton 16.0 x 6.0 x 8.5" == line);
  } else {
    CHECK("Layton: Carton 16.0 x 8.5 x 6.0" == line);
  }

  getline(in, line);
  if (key_value.ValueAt("Roy").width() == 12) {
    CHECK("Roy: Carton 14.0 x 12.0 x 9.6" == line);
  } else {
    CHECK("Roy: Carton 14.0 x 9.6 x 12.0" == line);
  }

  getline(in, line);
  if (key_value.ValueAt("Taylor").width() == 12) {
    CHECK("Taylor: Carton 20.8 x 12.0 x 14.2" == line);
  } else {
    CHECK("Taylor: Carton 20.8 x 14.2 x 12.0" == line);
  }

  getline(in, line);
  CHECK("" == line);

  in.close();
}
