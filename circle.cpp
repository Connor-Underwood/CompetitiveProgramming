#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

int main(int argc, char** argv) {


	const double PI = 3.14159265358979323846;
	double radius; 
	double total_points;
	double points_in_circle;

	vector<double> res;

	cin >> radius;

	cin >> total_points;

	cin >> points_in_circle;



	while(radius != 0 && total_points != 0 && points_in_circle != 0) {

		double squarea = (2*radius) * (2*radius);


		double proportion = points_in_circle / total_points;


		double true_area = PI * (radius * radius);

		double estimated_area = proportion * squarea;


		

		res.push_back(true_area);
		res.push_back(estimated_area);


		cin >> radius;

		cin >> total_points;

		cin >> points_in_circle;
	}

	cout << fixed << setprecision(6);

	for (int i=0; i < res.size(); i+=2) {
		cout <<	res[i] << " " << res[i+1]; 
		cout << "\n";
	}




	return 0;
}
