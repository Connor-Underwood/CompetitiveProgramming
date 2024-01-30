#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

int calculateRightDelivery(vector<pair<int, int> >& deliveries, int capacity) {
    int furthest = deliveries[deliveries.size() - 1].first * 2;
    int i; 
    int tripCap = capacity;
    for (i=deliveries.size() - 1; i >= 0; i--) {
      if (tripCap >= deliveries[i].second) {
        tripCap -= deliveries[i].second;
        deliveries.pop_back();
      } else {
        deliveries[i].second -= tripCap;
        break;
      }
    } 
    return furthest;
}


// int calculateLeftDelivery(vector<pair<int, int> >& deliveries, int capacity) {
//     int furthest = -deliveries[0].first * 2;
//     int i;
//     int tripCap = capacity;
// 		for (i = 0; i < deliveries.size(); i++) {
//       if (tripCap >= deliveries[i].second) {
//         tripCap -= deliveries[i].second;
//         deliveries.erase(deliveries.begin());
//       } else {
//         deliveries[i].second -= tripCap;
//         break;
//       }
// 		}
//     return furthest;
// }

int calculateLeftDelivery(vector<pair<int, int>>& deliveries, int capacity) {
    if (deliveries.empty()) {
        return 0;
    }

    int furthest = -deliveries.front().first * 2;
    int tripCap = capacity;

    for (int i = 0; i < deliveries.size();) {
        if (tripCap >= deliveries[i].second) {
            tripCap -= deliveries[i].second;
            deliveries.erase(deliveries.begin()); 
        } else {
            deliveries[i].second -= tripCap;
            break;
        }
    }

    return furthest;
}


int main(int argc, char ** argv) {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int addresses;
  int capacity;

  cin >> addresses >> capacity;

  vector<pair<int, int> > leftDeliveries;
  vector<pair<int, int> > rightDeliveries;

  for (int i = 0;i < addresses; i++) {
    int pos, amt;

    cin >> pos >> amt;

    if (pos < 0) {
      leftDeliveries.push_back(make_pair(pos, amt));
    } else {
      rightDeliveries.push_back(make_pair(pos, amt));
    }
  }
	
  sort(rightDeliveries.begin(), rightDeliveries.end());

//  int total_distance = calculateLeftDelivery(leftDeliveries, capacity) + calculateRightDelivery(rightDeliveries, capacity);
	int right = 0;
	int left = 0;
	//cout << "Left distance = " << left << "\n";
	//cout << "Right distance = " << right << "\n";

  while (leftDeliveries.size() > 0) {
    left += calculateLeftDelivery(leftDeliveries, capacity);
  }

  while (rightDeliveries.size() > 0) {
    right += calculateRightDelivery(rightDeliveries, capacity);
  }
  int total = left + right;

	cout << total << "\n";

	


  return 0;
}
