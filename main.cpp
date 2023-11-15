/*************************
* Author: Kitov D.A. *
* Date: 01.11.2023 *
* Name: Calendar *
*************************/
#include <iostream>
#include <iomanip>

using namespace std;

int year, startingDayOfWeek = 1, monthsInRow;
int yearlyStartingDayOfWeek;
int curMonth = 1, month = 1;

// Getting month name by number
string nameOfMonth(int numberOfMonth) {
  switch(numberOfMonth) {
    case 1: return "January";
    case 2: return "February";
    case 3: return "March";
    case 4: return "April";
    case 5: return "May";
    case 6: return "June";
    case 7: return "July";
    case 8: return "August";
    case 9: return "September";
    case 10: return "October";
    case 11: return "November";
    case 12: return "December";
  }
}
// Determining if it's a leap year
bool isLeap(int year) {
  return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}
// Determining the number of days in a month
int numberOfDays(int numberOfMonth, int year) {
  switch(numberOfMonth) {
    case 1: return 31;
    case 2:
      if (isLeap(year)) {
        return 29;
      } else {
        return 28;
      }
    case 3: return 31;
    case 4: return 30;
    case 5: return 31;
    case 6: return 30;
    case 7: return 31;
    case 8: return 31;
    case 9: return 30;
    case 10: return 31;
    case 11: return 30;
    case 12: return 31;
  }
}
void yearlyStartingDayOfWeekCalculation() {
  // Calculation of the day of the week on which the year begins
  for (int curYear = 2; curYear <= year; ++curYear) {
    startingDayOfWeek = (startingDayOfWeek + 364) % 7 + 1;
    if ( isLeap(curYear - 1) ) {
      startingDayOfWeek = startingDayOfWeek % 7 + 1;
    }
  }
  yearlyStartingDayOfWeek = startingDayOfWeek;
}

int startingDayOfWeekCalculation(int month, int year, int startingDayOfWeek) {
  if(month >= 2) {
    for(int monthIndex = 2; monthIndex <= month; monthIndex++) {
      startingDayOfWeek = (startingDayOfWeek - 1 + numberOfDays(monthIndex - 1, year)) % 7 + 1;
    }
  }
  return startingDayOfWeek;
}

void horizontalMode() {
  // Output the calendar by months
  while(month <= 12) {
    curMonth = month;
    for(int monthIndex = 0; monthIndex < monthsInRow && curMonth <= 12; ++monthIndex) {
      cout << setw(31) << left << nameOfMonth(curMonth);
      ++curMonth;
    }
    cout << endl;
    curMonth = month;
    for(int monthIndex = 0; monthIndex < monthsInRow && curMonth <= 12; ++monthIndex) {
      cout << "Mon Tue Wed Thu Fri Sat Sun" << setw(4) << " ";
      ++curMonth;
    }
    cout << endl;
    curMonth = month;
    int lastDayInMonthArray[monthsInRow];
    for(int monthIndex = 0; monthIndex < monthsInRow && curMonth <= 12; ++monthIndex) {
      startingDayOfWeek = startingDayOfWeekCalculation(curMonth, year, yearlyStartingDayOfWeek);
      for (int spacingIndex = 0; spacingIndex < startingDayOfWeek - 1; ++spacingIndex) {
        cout << setw(4) << " ";
      }
      for(int day = 1; day < numberOfDays(curMonth, year); ++day) {
        cout << setw(3) << day << " ";
        if ((startingDayOfWeek + day - 1) % 7 == 0) {
          lastDayInMonthArray[monthIndex] = day;
          break;
        }
      }
      cout << setw(3) <<  " ";
      ++curMonth;
    }
    cout << endl;
    curMonth = month;

    bool isAllDaysPrinted = false;
    while(!isAllDaysPrinted) {
      curMonth = month;
      isAllDaysPrinted = true;
      for(int monthIndex = 0; monthIndex < monthsInRow && curMonth <= 12; ++monthIndex) {
        for (int day = lastDayInMonthArray[monthIndex] + 1; day <= lastDayInMonthArray[monthIndex] + 7; ++day) {
          if(day <= numberOfDays(curMonth, year)) {
            cout << setw(3) << day << " ";
            isAllDaysPrinted = false;
          } else {
            cout << setw(4) << setfill(' ') << " ";
          }
        }
        cout << setw(3) << " ";
        lastDayInMonthArray[monthIndex] += 7;
        ++curMonth;
      }
      cout << endl;
    }
    month += monthsInRow;
  }
}

void verticalMode() {
  /*string daysOfWeek[7] = { "Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun" };
  while(month <= 12) {
    curMonth = month;
    for(int monthIndex = 0; monthIndex < monthsInRow && curMonth <= 12; ++monthIndex) {
      cout << setw(31) << left << nameOfMonth(curMonth);
      ++curMonth;
    }
    cout << endl;
    curMonth = month;
    int lastDayInMonthArray[monthsInRow];
    for(int monthIndex = 0; monthIndex < monthsInRow && curMonth <= 12; ++monthIndex) {
      for(int dayOfWeekIndex = 1; dayOfWeekIndex <= 7; ++dayOfWeekIndex) {
        cout << daysOfWeek[dayOfWeekIndex - 1] << " ";

        ++curMonth;
      }

      startingDayOfWeek = startingDayOfWeekCalculation(curMonth, year, yearlyStartingDayOfWeek);
      for (int spacingIndex = 0; spacingIndex < startingDayOfWeek - 1; ++spacingIndex) {
        cout << setw(4) << " ";
      }
      for(int day = 1; day < numberOfDays(curMonth, year); ++day) {
        cout << setw(3) << day << " ";
        if ((startingDayOfWeek + day - 1) % 7 == 0) {
          lastDayInMonthArray[monthIndex] = day;
          break;
        }
      }
      cout << setw(3) <<  " ";
      ++curMonth;
    }
    cout << endl;
    curMonth = month;

    bool isAllDaysPrinted = false;
    while(!isAllDaysPrinted) {
      curMonth = month;
      isAllDaysPrinted = true;
      for(int monthIndex = 0; monthIndex < monthsInRow && curMonth <= 12; ++monthIndex) {
        for (int day = lastDayInMonthArray[monthIndex] + 1; day <= lastDayInMonthArray[monthIndex] + 7; ++day) {
          if(day <= numberOfDays(curMonth, year)) {
            cout << setw(3) << day << " ";
            isAllDaysPrinted = false;
          } else {
            cout << setw(4) << " ";
          }
        }
        cout << setw(3) << " ";
        lastDayInMonthArray[monthIndex] += 7;
        ++curMonth;
      }
      cout << endl;
    }
    month += monthsInRow;
  }*/
}

int main()
{
  // Input year
  setlocale(LC_ALL, "RUS");
  int mode;
  cout << "Введите год: ";
  cin >> year;
  cout << "Введите количество месяцев в строке: ";
  cin >> monthsInRow;
  cout << "Доступно два режима: 1 - горизонтальный, 2 - вертикальный." << endl
  << "В горизонтальном режиме неделя идет горизонтально, в вертикальном - вертикально." << endl;
  do {
    cout << "Выберите режим: ";
    cin >> mode;
  } while (mode != 1 && mode != 2);
  cout << endl << "Календарь для " << year << " года:" << endl << endl;
  yearlyStartingDayOfWeekCalculation();

  if(mode == 1) {
    horizontalMode();
  } else {
    verticalMode();
  }

  return 0;
}
