// this tells catch to provide a main()
// only do this in one cpp file
// #define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "fileio.h"

#include <array>
#include <string>

using namespace std;

// valid case
TEST_CASE("main_functions.h has a constant kMaxSize that is greater than 6.",
          "[read_file]") {
  CHECK(kMaxSize > 6);
}

TEST_CASE(
    "ReadProjectsFromFile returns 'Unable to open file.' message when file not "
    "found",
    "[read_file]") {
  array<Project, kMaxSize> projects = {};
  int size = 0;
  string message = "Unable to open file.";
  CHECK(ReadProjectsFromFile("no_file.tst", projects, size) == message);
}

TEST_CASE(
    "ReadProjectsFromFile returns empty string when no errors in file "
    "project_data.txt",
    "[read_file]") {
  array<Project, kMaxSize> projects = {};
  int size = 0;
  string message = "";
  CHECK(ReadProjectsFromFile("../project_data.txt", projects, size) ==
          message);
}

TEST_CASE(
    "ReadProjectsFromFile returns string that starts with 'Unable to add "
    "project named Post final grades' when it reads error in file "
    "project2_data.txt",
    "[read_file]") {
  array<Project, kMaxSize> projects = {};
  int size = 0;
  string message = "Unable to add project named Post final grades";
  string function_message =
      ReadProjectsFromFile("../project2_data.txt", projects, size);
  CHECK(function_message.substr(0, 45) == message);
}

TEST_CASE(
    "ReadProjectsFromFile reads correct projects after it reads error in file "
    "project2_data.txt",
    "[read_file]") {
  array<Project, kMaxSize> projects = {};
  int size = 0;
  ReadProjectsFromFile("../project2_data.txt", projects, size);

  CHECK(projects[0].estimated_time_minutes() == 212);
  CHECK(projects[0].actual_time_minutes() == 180);
  CHECK(projects[0].reported_percent_complete() == 97);
  CHECK(projects[0].name() == "Prep Meeting Agenda");
}

TEST_CASE(
    "ReadProjectsFromFile reads four projects when reading from the "
    "project_data.txt file.",
    "[read_file]") {
  array<Project, kMaxSize> projects = {};
  int size = 0;
  string message = ReadProjectsFromFile("../project_data.txt", projects, size);

  CHECK(message == "");
  CHECK(projects[0].estimated_time_minutes() == 415);
  CHECK(projects[0].actual_time_minutes() == 382);
  CHECK(projects[0].reported_percent_complete() == 85);
  CHECK(projects[0].name() == "Complete data flow project");

  CHECK(projects[1].estimated_time_minutes() == 2172);
  CHECK(projects[1].actual_time_minutes() == 1415);
  CHECK(projects[1].reported_percent_complete() == 57);
  CHECK(projects[1].name() == "Do water meter project");

  CHECK(projects[2].estimated_time_minutes() == 351);
  CHECK(projects[2].actual_time_minutes() == 281);
  CHECK(projects[2].reported_percent_complete() == 72);
  CHECK(projects[2].name() == "Get feedback from stake holders");

  CHECK(projects[3].estimated_time_minutes() == 60);
  CHECK(projects[3].actual_time_minutes() == 0);
  CHECK(projects[3].reported_percent_complete() == 0);
  CHECK(projects[3].name() == "unnamed");
}

TEST_CASE(
    "ReadProjectsFromFile reads first 20 projects when reading from the "
    "project_data_too_many.txt file.",
    "[read_file]") {
  array<Project, kMaxSize> projects = {};
  int size = 0;
  string message =
      ReadProjectsFromFile("../project_data_too_many.txt", projects, size);

  array<int, kMaxSize> estimated_time = {
      1925, 875,  351,  3780, 4290, 1275, 2145, 1832, 945,  3120,
      4020, 1320, 2150, 3240, 2180, 980,  3820, 3292, 5290, 2470};

  array<int, kMaxSize> actual_time = {863,  655, 281,  2154, 3857, 1350, 1822,
                                      958,  822, 1834, 2160, 1152, 1843, 1244,
                                      1430, 870, 2187, 3398, 45,   1244};

  array<int, kMaxSize> percent = {35, 64, 72, 57, 82, 97, 74, 47, 93, 35,
                                  48, 73, 85, 28, 50, 84, 46, 92, 3,  50};

  array<string, kMaxSize> titles = {
      "Complete data entry",
      "Fix accessibility details",
      "Write Static Code Checker",
      "Design hand gesture recognition tool",
      "Code Remote Lab Assistance",
      "Implement Project Approval System",
      "Refactor Online Course Registration",
      "Create Universal Database Viewer",
      "Create Sun Rise Set Time Tracker",
      "Develop Automatic Youtube Playlist Downloader",
      "Design a Health services & Medical outcome monitoring system",
      "Create An Android Messaging App",
      "Design an AI Therapist",
      "Develop Search Tool for Logos",
      "Create Client Master",
      "Make A Game of Anagrams",
      "Develop a Chatbot",
      "Create a Sign Language Translator",
      "Develop a Medical Tracking App",
      "Schedule Green Rides",
  };

  INFO(
      "Possible security breach. Data has been written outside the bounds of "
      "the array!");
  CHECK(size == 20);
  CHECK(message == "");

  // loop through arrays and compare
  for (int i = 0; i < size; i++) {
    CHECK(estimated_time[i] == projects[i].estimated_time_minutes());
    CHECK(actual_time[i] == projects[i].actual_time_minutes());
    CHECK(percent[i] == projects[i].reported_percent_complete());
    CHECK(titles[i] == projects[i].name());
  }
}

TEST_CASE(
    "WriteProjectsToFile writes the projects in an array to an output "
    "file.",
    "[write_file]") {
  array<Project, kMaxSize> projects2 = {Project("one", 36, 24, 8),
                                        Project("two", 82, 12, 25),
                                        Project("three", 12, 13.2, 98)};
  int size = 3;
  array<Project, kMaxSize> projects;
  int valid_size = 0;
  WriteProjectsToFile("../out2_data.txt", projects2, size);

  string message =
      ReadProjectsFromFile("../out2_data.txt", projects, valid_size);

  CHECK(message == "");
  CHECK(projects[0].estimated_time_minutes() == 2160);
  CHECK(projects[0].actual_time_minutes() == 1440);
  CHECK(projects[0].reported_percent_complete() == 8);
  CHECK(projects[0].name() == "one");

  CHECK(projects[1].estimated_time_minutes() == 4920);
  CHECK(projects[1].actual_time_minutes() == 720);
  CHECK(projects[1].reported_percent_complete() == 25);
  CHECK(projects[1].name() == "two");

  CHECK(projects[2].estimated_time_minutes() == 720);
  CHECK(projects[2].actual_time_minutes() == 792);
  CHECK(projects[2].reported_percent_complete() == 98);
  CHECK(projects[2].name() == "three");

  CHECK(projects[3].estimated_time_minutes() == 60);
  CHECK(projects[3].actual_time_minutes() == 0);
  CHECK(projects[3].reported_percent_complete() == 0);
  CHECK(projects[3].name() == "unnamed");
}
