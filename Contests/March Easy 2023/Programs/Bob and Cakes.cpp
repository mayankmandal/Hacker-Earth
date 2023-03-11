#include <iostream>
#include <vector> 
using namespace std;

long long segments(long long n)
{
	return (n*(n + 1))/2;
}

void solve()
{
	int no_of_elements; 
	cin >> no_of_elements; 

	vector <int> A(no_of_elements + 1);
	for(int i = 1; i <= no_of_elements; i++)
	{
		cin >> A[i];
	}

	long long total_segments = 0;
	int left = 0, right = 0;
	for(int i = 1; i <= no_of_elements; i++)
	{
		if(A[i] <= 0)
		{
			right = i - 1;
			total_segments += segments(right - left);
			left = i;
		}
		else if(i == no_of_elements)
		{
			right = i;
			total_segments += segments(right - left);
		}
	}

	cout << total_segments << "\n";
}

int main() 
{
	int no_of_test_cases; 
	cin >> no_of_test_cases; 

	while(no_of_test_cases--)
		solve();

	return 0;
}
