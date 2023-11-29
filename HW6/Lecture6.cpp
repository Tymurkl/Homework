
#include <iostream>
#include <cctype>
using namespace std;
int main()
{
	//Task 1
	cout << "Task I" << endl;
	int a1;
	int d;
	int an;
	cout << "Enter initial number: ";
	cin >> a1;
	cout << "Enter step of progression: ";
	cin >> d;
	cout << "Enter last number: ";
	cin >> an;
	for (int i = a1; i <= an; i = i + d)
	{
		cout << i << endl;
	}

	//Task 2
	
	int term1 = 0;
	int term2 = 1;
	int num = 0;
	int nextTerm = 0;
	cout << "Number of terms: ";
	cin >> num;
	if (num <= 2) {
		cout << "Number of terms must be >=3" << endl;
		return 1;
		
	}
	cout << term1 << ", " << term2 << ", ";
	for (int i = 3; i <= num; i++) {
		nextTerm = term1 + term2;
		cout << nextTerm;
		if (i != num) cout << ", ";
		term1 = term2;
		term2 = nextTerm;
	}
	cout << endl;

	//Task 3
	cout << "Task III" << endl;
	unsigned int sumi = 1;
	unsigned int i = 1;
	int p = 0;
	std::cout << "Enter factorial number: ";
	std::cin >> p;
	while (i <= p)
	{
		sumi = sumi * i;
		i++;
	}
	std::cout << sumi;
	cout << endl;
	//Task 4
	cout << "Task IV (a)" << endl;
	int w1 = 0;
	int h1 = 0;
	cout << "Enter height: ";
	cin >> h1;
	cout << "Enter width: ";
	cin >> w1;
	for (i = 1; i <= h1; i++)
	{
		for (int j = i; j <= w1; j++)
		{
			std::cout << '*';
		}
		std::cout << std::endl;
	}
	cout << "Task IV (b)" << endl;
	int h3 = 0;
	cout << "Enter height: ";
	cin >> h3;
	for (i = 1; i <= h3; i++)
	{
		for (int j = 0; j < i; j++)
		{
			std::cout << '*';
		}
		std::cout << std::endl;
	}

	cout << "Task IV (c)" << endl;
	int w2 = 0;
	int h2 = 0;
	cout << "Enter height: ";
	cin >> h2;
	cout << "Enter width: ";
	cin >> w2;
	for (i = 1; i <= h2; i++)
	{
		for (int j = 1; j <= w2; j++)
		{
			std::cout << '*';
		}
		std::cout << std::endl;

	}
	cout << "Task IV (d)" << endl;
	int rows; // Number of rows
	cout << "Enter number of rows: ";
	cin >> rows;
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < i; ++j) {
			std::cout << " ";
		}
		for (int i = 0; i < rows; ++i) {
			std::cout << "*";
		}
		std::cout << std::endl;
	}


	cout << "Task IV (e)" << endl;
	int h4 = 0;
	cout << "Enter height: ";
	cin >> h4;
	for (i = 1; i <= h4; i++)
	{
		for (int j = 0; j < i; j++)
		{
			std::cout << i<<j<<" ";
		}
		std::cout << std::endl;
	}

	//Task 5
	cout << "Task V" << endl;
char symbol;
int suma = 0;

while (true) {
	cout << "Enter symbol: ";
	cin >> symbol;

	if (symbol == '.') {
		cout << "End program" << endl;
		break;
	}
	else if (islower(symbol)) {
		symbol = toupper(symbol);
		cout << "Letter in uppercase: " << symbol << endl;
	}
	else if (isdigit(symbol)) {
		int digit = symbol - '0';
		suma += digit;
		cout << "Current sum of numbers: " << suma << endl;
	}
	else {
		cout << "This symbol is invalid." << endl;
	}
}
}

