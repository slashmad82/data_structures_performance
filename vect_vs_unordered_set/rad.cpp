#include <vector>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <iostream>
#include <chrono>
#include <algorithm>

using namespace std;

 //TEST CODE
int main()
{
	cout << "CONTAINERS FIND SPEED TEST" << endl;
	cout << "|-------------------------------------|"<<endl;
	vector<uint64_t> numbers = {10,100,1000,10*1000, 100*1000, 500*1000};
	int to_find = 6*100*1000;
	typedef chrono::duration<float> ms;
	/* containers to compare: */
	unordered_set<uint64_t> hm;
	vector<uint64_t> vec;

	/* test for different numbers in data structure */
	for(auto n : numbers) {
		cout <<endl<< "°°°°number of elements: "<< n <<endl;

		/*insert element in both vector and set structures */
		auto start = chrono::high_resolution_clock::now();
		for (int i = 0; i<n; i++) {
			hm.insert(i);
			vec.push_back(i);
		}
		auto end = chrono::high_resolution_clock::now();
		auto elapsed = end-start;

		/* search in unordered_set */
		start = chrono::high_resolution_clock::now();
		cout << "Search in unordered set:" << endl;
		auto it = hm.find(to_find);
		if (it != hm.end())
			cout << *it << endl;
		else 
			cout <<" non trovato"<< endl; 
		end = chrono::high_resolution_clock::now();
		elapsed = end-start;
		cout << "time nedeed unsorted set[ticks]: " << elapsed.count() << endl;

		/* search in vector */
		start = chrono::high_resolution_clock::now();
		cout << "Search in vector:" << endl;
		auto xxit = find(vec.begin(), vec.end(), to_find);
		if (xxit != vec.end())
			cout << *xxit << endl;
		else 
			cout <<" non trovato"<< endl; 
		end = chrono::high_resolution_clock::now();
		elapsed = end-start;
		cout << "time nedeed vector[ticks]: " << elapsed.count() << endl;
	}

	cout << "|-------------------------------------|"<<endl;

	return 0;
}
