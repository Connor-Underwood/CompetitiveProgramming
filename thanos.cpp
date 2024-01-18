#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char **argv) {

  long long num_planets;

  cin >> num_planets;

  vector<long long> answers;

  while (num_planets-- != 0) {
    long long population;
    long long rate; 
    long long food_production;

    cin >> population >> rate >> food_production;

    long long years = 0;

    while (population <= food_production) {
      population *= rate;
      years++;
    }
    
    answers.push_back(years);

  }

  for (long long answer : answers) {
    cout << answer << "\n";
  }
  
  return 0;
}
