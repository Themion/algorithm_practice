#include<iostream>


using namespace std;

int main(int argc, char** argv)
{
	int A, B;
	cin >> A >> B;
	if (A > B) cout << "A";
	else if (A < B) cout << "B";
	else cout << "same";
	cout << '\n';
	return 0;
}