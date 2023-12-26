/*************************
* Author: Kitov D.A. *
* Date: 10.10.2023 *
* Name: Roman and arabian numbers *
*************************/

#include <iostream>
#include <map>

using namespace std;

void toArabian() {
  map<char, int> numbers = {
    {'I', 1},
    {'V', 5},
    {'X', 10},
    {'L', 50},
    {'C', 100},
    {'D', 500},
    {'M', 1000}
  };
  string romanNumber;
  cout << "Введите римское число: ";
  cin >> romanNumber;

  int result = 0;
  for (int characterIndex = 0; characterIndex < romanNumber.size(); ++characterIndex) {
    if (characterIndex < romanNumber.size() - 1 &&
        numbers[ romanNumber[characterIndex] ] < numbers[ romanNumber[characterIndex + 1] ]) {
      result -= numbers[ romanNumber[characterIndex] ];
    } else {
      result += numbers[ romanNumber[characterIndex] ];
    }
  }

  cout << "Результат: " << result << endl;
}

void toRoman() {
  map<int, string> numbers {
    {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
    {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
    {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
  };
  int arabianNumber;
  cout << "Введите арабское число: ";
  cin >> arabianNumber;

  string result = "";
  for (auto numbersIterator = numbers.rbegin(); numbersIterator != numbers.rend(); numbersIterator++) {
    while (arabianNumber >= numbersIterator->first) {
      result += numbersIterator->second;
      arabianNumber -= numbersIterator->first;
    }
  }

  cout << "Результат: " << result << endl;
}

int main() {
  setlocale(LC_ALL, "RUS");
  int mode;
  while(true) {
    cout << "Введите 1, чтобы перевести из арабских чисел в римские, 2, чтобы наоборот, и 0, чтобы выйти: ";
    cin >> mode;
    if(mode == 0) {
      break;
    } else if(mode == 1) {
      toRoman();
    } else if(mode == 2) {
      toArabian();
    }
  }
  return 0;
}
