

#include <iostream>

int main()
{
    using namespace std;
    //Task1

    int seconds = 0;
    cout << "Enter time (3870) ";
    cin >> seconds;
    int hours = seconds / 3600;
    int minutes = (seconds % 3600) / 60;
    int seconds_left = (seconds % 3600) % 60;
    std::cout << hours << " hour, " << minutes << " minutes, " << seconds_left << " seconds" << std::endl;

    //Task2
    int a = 5;
    int b = 6;
    int c = 7;
    cout << a + b + c << endl;
    cout << a *b * c << endl;
    cout << (a + b + c)/3 << endl;
    bool bool1 = a > b;
    bool bool2 = b < c;
    cout << boolalpha<<bool1 << endl;
    cout << boolalpha<<bool2 << endl;

    //Task3
    int x, y;
    cout << "Enter number 1: ";
    cin >> x;
    cout << "Enter number 2: ";
    cin >> y;

    bool lessThan = x < y;
    bool equal = x == y;
    bool moreThan = x > y;
    bool lessOrEqual = x <= y;
    
  
    cout << "lessThan = " <<boolalpha<< lessThan << endl;
    cout << "equal = " << boolalpha << equal << endl;
    cout << "moreThan = " << boolalpha << moreThan << endl;
    cout << "lessOrEqual = " << boolalpha << lessOrEqual << endl;

    //Task4
    int w, h;
    cout << "Enter w: ";
    cin >> w;
    cout << "Enter h: ";
    cin >> h;
    cout << "square: " << w * h << endl;
    cout << "perimetr: " << (w+h)*2 << endl;

    //Task5
    int r;
    double p = 3.14;
    cout << "Enter r: ";
    cin >> r;
    cout << "square circle: " << p*r*r << endl;
    cout << "lenght circle: " << 2*p*r<< endl;




}


