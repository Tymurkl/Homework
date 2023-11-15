

#include <iostream>
#include <iomanip>
enum class WeekDay
{
    Monday = 1,
    Tuesday = 2,
    Wednesday = 3,
    Thursday = 4,
    Friday = 5,
    Saturday = 6,
    Sunday = 7
};

int main()
{
    using namespace std;
    int Num1;
    int Num2;
    //Task1
    cout << "Enter number 1: ";
    cin >> Num1;
    cout << "Enter number 2: ";
    cin >> Num2;
    auto temp = Num1;
    Num1 = Num2;
    Num2 = temp;
    cout << "Result number 1: " << Num1 << endl;
    cout << "Result number 2: " << Num2 << endl;
    //Task2
    double Num3 = 25.456;
    cout << Num3 << endl;
    int Num4 = (int)Num3;
    cout << Num4 << endl;
    double Num5 = 2345.6575884930383635;
    cout << setw(20) << right <<setfill('$') << Num3 << endl;
    double Num6 = 23.56789;
    //Task3
        cout << setprecision(2) << Num6 << endl;
        cout << setprecision(5) << Num6 << endl;
        cout << scientific << Num6 << endl;

        //Task4
        WeekDay day1 = WeekDay::Monday;
        WeekDay day2 = WeekDay::Tuesday;
        WeekDay day3 = WeekDay::Wednesday;
        WeekDay day4 = WeekDay::Thursday;
        WeekDay day5 = WeekDay::Friday;
        WeekDay day6 = WeekDay::Saturday;
        WeekDay day7 = WeekDay::Sunday;
        cout << int(day1) << endl;
        cout << int(day2) << endl;
        cout << int(day3) << endl;
        cout << int(day4) << endl;
        cout << int(day5) << endl;
        cout << int(day6) << endl;
        cout << int(day7) << endl;

        //Task 5
        int Num7 = 0;
        cout << "Enter number again: ";
        cin >> Num7;
        cout << (bool)Num7<<endl;
        cout <<boolalpha << (bool)Num7 <<endl;
        
       

}

