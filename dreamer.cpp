#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
bool is_leap_year(int year) {
    if (year % 4 != 0) {
        return false;
    }
    if (year % 100 != 0) {
        return true;
    }
    return year % 400 == 0;
}

bool is_valid_date(int day, int month, int year) {
    if (year < 2000) {
        return false;
    }
    if (1 > month || month > 12) {
        return false;
    }
    vector<int> days {0, 31, (is_leap_year(year) ? 29 : 28), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (day < 1 || day > days[month]) {
        return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    int input;
    cin >> input;
    cin.ignore(); 







    for (int i = 0; i < input; i++) {
        string digits;
        getline(cin, digits); 

        digits.erase(remove(digits.begin(), digits.end(), ' '), digits.end());


        int x = 1;

        x  = x << 20;

        int y = 1;

        y = y << 10;


        sort(digits.begin(), digits.end());
        int MAX_YEAR = x;
        int MAX_MONTH = y;
        int MAX_DAY = y;
        int n = 0;
        int day = stoi(digits.substr(0,2));
        int month = stoi(digits.substr(2,2));
        int year = stoi(digits.substr(4,4));

        if (is_valid_date(day, month, year)) {
            n++;
            if (year < MAX_YEAR || (year == MAX_YEAR && (month < MAX_MONTH || (month == MAX_MONTH && day < MAX_DAY)))) {
                MAX_YEAR = year;
                MAX_MONTH = month;
                MAX_DAY = day;
            }
        }
        while (next_permutation(digits.begin(), digits.end())) {

            int day = stoi(digits.substr(0,2));
            int month = stoi(digits.substr(2,2));
            int year = stoi(digits.substr(4,4));

            if (is_valid_date(day, month, year)) {
                n++;
                if (year < MAX_YEAR || (year == MAX_YEAR && (month < MAX_MONTH || (month == MAX_MONTH && day < MAX_DAY)))) {
                    MAX_DAY = day;
                    MAX_MONTH = month;
                    MAX_YEAR = year;
                }
            }
        }
        if (n == 0) {
            cout << n << "\n";
        } else {
            cout << n << " ";
            cout << (MAX_DAY < 10 ? "0" : "") << MAX_DAY;
            cout << " ";
            cout    << (MAX_MONTH < 10 ? "0" : "") << MAX_MONTH;
            cout << " " << MAX_YEAR << "\n";
        }
    }
    return 0;
}

