#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char **argv) {
    
    int rectangle;

    cin >> rectangle;

    vector<int> answers;
    int index = 0;
    while (rectangle != 0) {
      
      int squares = 0;

      vector<vector<int> > grid(501, vector<int>(501));

      while (rectangle-- != 0) {
        int a, b, c, d;

        cin >> a >> b >> c >> d;

        for (int i = a; i < c; ++i) {
          for (int j = b; j < d; ++j) {
            grid[i][j]++;
          }
        }

        
      }

      for (int i = 0; i <= 500; ++i) {
        for (int j = 0; j <= 500; ++j) {
          if (grid[i][j] > 0) {
            squares++;
          }
        }
      }
      
      answers.push_back(squares);


      cin >> rectangle;
      
    }
    for (int i = 0; i < answers.size(); ++i) {
      if (answers[i] != 0) {
        cout << answers[i] << "\n";
      }
    }
    return 0;
}
