
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
	cout << "Task II" << endl;
	int a = 0;
	int b = 1;
	int c = 0;
	int n = 0;
	cout << "Enter number: ";
	cin >> n;
	while (a < n)
	{
		a = b;
		b = c;
		c = a + b;
		cout << c << " ";
		a++;

	}
	cout << endl;

	//Task 3
	cout << "Task III" << endl;
	unsigned int sum = 1;
	unsigned int i = 1;
	int p = 0;
	std::cout << "Enter factorial number: ";
	std::cin >> p;
	while (i <= p)
	{
		sum = sum * i;
		i++;
	}
	std::cout << sum;
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

	cout << "Task IV (c,d)" << endl;
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
		break;
	}
	else {
		cout << "This symbol is invalid." << endl;
	}
}
}

