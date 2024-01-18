#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

int main(int argc, char ** argv) {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  
  vector<int> v;

  
  int N;
  
  cin >> N;

  v.assign(N, 0);


  for (int i =0; i < N; i++) {
    int curr; 
    cin >> curr;
    
     
    if (v[curr] == 0) { // we haven't seen this num yet, always inc. 
      v[curr-1]++;
    } else { // if we've seen this num, we know to dec. it's index and inc. index-1 because inputs are 1-based indexing
      v[curr-1]++;
      v[curr]--;
    }

  }
  
  int answer = 0;

  for (int i = 0; i < v.size(); ++i) {
    answer += v[i];
  }

  cout << answer;
  


  return 0;
}
