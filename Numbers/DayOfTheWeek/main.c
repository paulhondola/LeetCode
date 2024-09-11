#include <stdio.h>
#include <time.h>

const char *dayOfTheWeek(int day, int month, int year) {
  // Array of day names
  const char *day_names[] = {"Sunday",   "Monday", "Tuesday", "Wednesday",
                             "Thursday", "Friday", "Saturday"};

  // Create a tm structure
  struct tm time_in = {
      0,   0,         0,
      day, month - 1, year - 1900}; // month is 0-indexed, year is from 1900

  // Convert tm structure to time_t which represents the number of seconds since
  // epoch
  time_t time_temp = mktime(&time_in);

  // Get the day of the week (0=Sunday, ..., 6=Saturday)
  int day_of_week = localtime(&time_temp)->tm_wday;

  return day_names[day_of_week];
}

int main() {
  int day = 31, month = 8, year = 2019;
  printf("%s\n", dayOfTheWeek(day, month, year)); // Output: Saturday
  return 0;
}
