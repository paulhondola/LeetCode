int checkBisectYear(const int year) {
  if (year % 400 == 0)
    return 1;
  if (year % 100 == 0)
    return 0;
  if (year % 4 == 0)
    return 1;
  return 0;
}

int extractYearFromDate(const char *date) {
  int year = 0;
  for (int i = 0; i <= 3; i++)
    year = year * 10 + (date[i] - '0');
  return year;
}

int extractMonthFromDate(const char *date) {
  int month = 0;
  for (int i = 5; i <= 6; i++)
    month = month * 10 + (date[i] - '0');
  return month;
}

int extractDayFromDate(const char *date) {
  int day = 0;
  for (int i = 8; i <= 9; i++)
    day = day * 10 + (date[i] - '0');
  return day;
}

int dayOfYear(char *date) {
  int dayCount[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  const int year = extractYearFromDate(date);
  const int month = extractMonthFromDate(date);
  const int day = extractDayFromDate(date);

  if (checkBisectYear(year))
    dayCount[2] = 29;

  int resultDay = 0;

  for (int i = 1; i < month; i++)
    resultDay += dayCount[i];

  resultDay += day;

  return resultDay;
}
