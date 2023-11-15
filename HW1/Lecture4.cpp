

#include <iostream>
enum class Months {
    Jan=1,
    Feb,
    Mar,
    Apr,
    May,
    Jun,
    Jul,
    Aug,
    Sep,
    Oct,
    Nov,
    Dec,
}; 

   



int main()
{
    using namespace std;
    //Task 1
    int Num1 = 0;
    int Num2 = 0;
    int Num3 = 0;
    cout << "Enter number 1: ";
    cin >> Num1;
    cout << "Enter number 2: ";
    cin >> Num2;
    cout << "Enter number 3: ";
    cin >> Num3;
    if (Num1 > Num2 && Num1 > Num3)
    {
        cout << Num1 << endl;
    }
    else if (Num2 > Num1 && Num2 > Num3)
    {
        cout << Num2 << endl;
    }
    else
    {
        cout << Num3 << endl;
    }

    //Task 2
    int Num4 = 0;
    int Num5 = 0;
    cout << "Enter first number: ";
    cin >> Num4;
    cout << "Enter second number: ";
    cin >> Num5;
    int Result= (Num4 > Num5) ? Num5 : Num4;
    cout << Result << endl;

    //Task 3

    int Num6 = 0;
    cout << "Enter number for calculation:";
    cin >> Num6;
    if (Num6 % 6 ==0 && Num6 % 11== 0) {
        cout << "All right" << endl;
    }
    else
    {
        cout << "Warning not div!" << endl;
    }
    //Task 4
    int ang1 = 0;
    int ang2 = 0;
    int ang3 = 0;
    cout << "Enter degree for angle 1: ";
    cin >> ang1;
    cout << "Enter degree for angle 2: ";
    cin >> ang2;
    cout << "Enter degree for angle 3: ";
    cin >> ang3;
    if ((ang1 + ang2 + ang3) == 180) {
        cout << "You can create triangle!" << endl;
    }
    else if ((ang1 + ang2 + ang3) < 180) {
        cout << "Angle degree is not enought to create triangle" << endl;
    }
    else
    {
        cout << "Sum of degree is too big" << endl;
    }
    //Task 5
    int month_number;
    cout << "Enter number 1-12: ";
    cin >> month_number;
    Months month = static_cast<Months>(month_number);
    switch (month)
    {
    case Months::Jan:
        cout << "Jan"<<endl;
        break;
    case Months::Feb:
        cout << "Feb" << endl;
        break;
    case Months::Mar:
        cout << "Mar" << endl;
        break;
    case Months::Apr:
        cout << "Apr" << endl;
        break;
    case Months::May:
        cout << "May" << endl;
        break;
    case Months::Jun:
        cout << "Jun" << endl;
        break;
    case Months::Jul:
        cout << "Jul" << endl;
        break;
    case Months::Aug:
        cout << "Aug" << endl;
        break;
    case Months::Sep:
        cout << "Sep" << endl;
        break;
    case Months::Oct:
        cout << "Oct" << endl;
        break;
    case Months::Nov:
        cout << "Nov" << endl;
        break;
    case Months::Dec:
        cout << "Dec" << endl;
        break;
    default:
        cout << "Write number from 1 to 12"<<endl;
        break;
    }
    //Task 6
    int mes = 0;
    cout << "enter number of month: ";
    cin >> mes;
    if (mes >= 9 && mes <= 11)
        cout << "Autumn";
    else if (mes>=3 && mes<=5)
        cout << "Spring";
    else if (mes >= 6 && mes <= 8)
        cout << "Summer";
    else
        cout << "Winter";

    }

    
    

    
    

