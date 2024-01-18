#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    
    cin.tie(nullptr);

    int num_strings;
    cin >> num_strings;

    vector<string> strings(num_strings);

    for (int i = 0; i < num_strings; i++) {
        cin >> strings[i];
    }
    int first;
    int second;
    int root = 0; 

    vector<vector<int> > matrix(num_strings);
    
    for (int i = 0; i < matrix.size(); i++) {
     matrix[i] = vector<int>();
    }


    for(int i = 0; i < num_strings-1; i++) {
        cin >> first >> second;
        first--, second--;
        matrix[first].push_back(second);
        root = first;
    }

  
    stack<int> s;
    s.push(root);
    while (!s.empty()) {
      int curr = s.top();
      s.pop();

      cout << strings[curr];

      for (int i = matrix[curr].size() - 1; i >= 0; --i) {
        s.push(matrix[curr][i]);
      }
    }
    cout << "\n";
    
    cout << "\n";
    
}



