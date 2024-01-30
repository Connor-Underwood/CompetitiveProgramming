#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
typedef long long ll;

int main(int argc, char ** argv) {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);


  ll days;

  
  cin >> days;

  vector<ll> stocks(days);

  for (int i = 0; i < days; i++) {
    cin >> stocks[i];
  }

  ll price = stocks[0];

  ll MAX_SHARES = 100000;
  ll money = 100;



  for (int i = 1; i < stocks.size(); i++) {
    ll nextPrice = stocks[i];
    if (nextPrice > price) {
      ll boughtShares = min(money / price, MAX_SHARES);
      ll change = nextPrice - price;
      money += boughtShares * change;
    }
    price = nextPrice;
  }


  cout << money << "\n";


  return 0;
}
