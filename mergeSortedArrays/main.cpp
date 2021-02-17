#include <iostream>
#include <vector>
using namespace std;

vector<int> mergeSorted(vector<int> array1, vector<int> array2);

int main() {
	vector<int> vector1 = { 0, 3, 4, 31 };
	vector<int> vector2 = { 4, 6, 30};

	vector<int> answer = mergeSorted(vector1, vector2);
		
	for (auto element : answer) {
		cout << element << " ";
	}

	vector1.clear();
	vector2.clear();

	return 0;
}

vector<int> mergeSorted(vector<int> vector1, vector<int> vector2) {
	//module 1, get sizes
	int n1 = vector1.size();
	int n2 = vector2.size();
	
	vector<int> mergedArray;
	int temp = 2147483646;

	int i = 0; //vector1 counter
	int j = 0; //vector2 counter
	cout << "n1 =" << n1 << " n2 = " << n2 << endl;

	cout << "i = " << i << "  ";
	cout << "j = " << j << endl;

	//module 2, populate merged array until shortest vector runs out
	while (i < n1 && j < n2) {
		if (vector1[i] < vector2[j]) {
			mergedArray.push_back(vector1[i]);
			i++;
		}

		else if (vector1[i] > vector2[j]) { 
			mergedArray.push_back(vector2[j]);
			j++;
		}

		else if (vector1[i] == vector2[j]) {
			mergedArray.push_back(vector1[i]);
			i++;
		}

		else if (i == n1) { 
			mergedArray.push_back(vector2[j]);
			j++;
			
		}

		else if (j == n2) { 
				mergedArray.push_back(vector1[i]);
		}

		cout << "i = " << i << "  ";
		cout << "j = " << j << endl;

	}

	// module 3, put the rest of longest (sorted) vector into the merged vector
	if (j == n2) {
		for (int remaining = i; remaining < n1; remaining++) {
			mergedArray.push_back(vector1[remaining]);
		}
	}

	if (i == n1) {
		for (int remaining = j; remaining < n2; remaining++) {
			mergedArray.push_back(vector2[remaining]);
		}
	}
	
	return mergedArray;
}