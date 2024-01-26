#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <algorithm>
using namespace std;



struct Player {
  string team;
  string league;
  string country;
  string name;
  int synergy = 0;
  int index;
  int degree = 0;
};

int calculateSynergy(Player * playa1, Player * playa2) {
  if (playa1->country == playa2->country) {
    if (playa1->team == playa2->team) {
      return 3;
    }
    if (playa1->league == playa2->league) {
      return 2;
    }
    return 1;
  }
  if (playa1->team == playa2->team) {
    return 2;
  }
  if (playa1->league == playa2->league) {
    return 1;
  }
  return 0;
}

bool isPerfectTeam(Player *players[], vector<int> degrees, vector<vector<int> > adjacencyList) {
    vector<bool> visited(10, false);
    queue<int> q;
    int i;
    for (i = 0; i < adjacencyList.size(); i++) {
      if (adjacencyList[i].size() != 0) {
        break;
      }
    }

    q.push(i);
    visited[i] = true;

    while (!q.empty()) {
        int num = q.front();
        q.pop();
        Player* playa = players[num];

        for (int p : adjacencyList[num]) {
            playa->synergy += calculateSynergy(playa, players[p]);
            if (!visited[p]) {
                visited[p] = true;
                q.push(p);
            }
        }
    }

    int count = 0;
    for (int i = 0; i < 10; i++) {
        if (players[i]->synergy >= degrees[i]) {
            count++;
        }
    }

    return (count == 10);
}




int main(int argc, char ** argv) {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);


  int numEdges;

  cin >> numEdges;


  vector<vector<int > > adjacencyList(10);

  Player *players[10];
  for (int i = 0; i < 10; i++) {
    players[i] = new Player;
  }

  vector<int> indices(10, 0);
  for (int i = 0; i < indices.size(); i++) {
    indices[i] = i;
  }


  for (int i = 0; i < numEdges; i++) {
    int first, second;
    cin >> first >> second;

    adjacencyList[first].push_back(second);
    adjacencyList[second].push_back(first);
    players[first]->degree++;
    players[second]->degree++;
  }

  vector<int> degrees(10);
  for (int i =0; i < 10; i++) {
    degrees[i] = players[i]->degree;
  }
  
  

  for (int i = 0; i < 10; i++) {
    cin >> players[i]->name >> players[i]->country >> players[i]->league >> players[i]->team;
    players[i]->index = i;
  }
  bool isPerfect = false;
	
	

  do {
		
		for (int i =0; i < 10; i++) {
			players[i]->synergy = 0;
		}
		
    Player *tempPlayers[10];
    for (int i = 0; i < 10; i++) {
      tempPlayers[i] = players[indices[i]];
    }


    if (isPerfectTeam(tempPlayers, degrees, adjacencyList)) {
			isPerfect = true;
      break;
    }

  } while (next_permutation(indices.begin(), indices.end()));



  if (isPerfect) {
    cout << "yes\n";
  } else {
    cout << "no\n";
  }

  
  return 0;
}





