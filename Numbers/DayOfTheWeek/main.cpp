#include <ctime>
#include <iostream>

std::string dayOfTheWeek(int day, int month, int year) {
  // Array of day names
  const std::string day_names[] = {"Sunday",   "Monday", "Tuesday", "Wednesday",
                                   "Thursday", "Friday", "Saturday"};

  // Create a tm structure
  std::tm time_in = {
      0,   0,         0,
      day, month - 1, year - 1900}; // month is 0-indexed, year is from 1900

  // Convert tm structure to time_t which represents the number of seconds since
  // epoch
  std::time_t time_temp = std::mktime(&time_in);

  // Get the day of the week (0=Sunday, ..., 6=Saturday)
  int day_of_week = std::localtime(&time_temp)->tm_wday;

  return day_names[day_of_week];
}

int main() {
  int day = 31, month = 8, year = 2019;
  std::cout << dayOfTheWeek(day, month, year) << std::endl; // Output: Saturday
  return 0;
}
