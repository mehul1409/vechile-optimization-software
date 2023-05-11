#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
void login();

struct Car
{
    string make;
    string model;
    int year;
    int mileage;
    bool serviced;
};
void addCar(vector<Car> &cars)
{
    Car car;

    cout << "Enter the make of the car: ";
    getline(cin, car.make);

    cout << "Enter the model of the car: ";
    getline(cin, car.model);

    cout << "Enter the year of the car: ";
    cin >> car.year;

    cout << "Enter the mileage of the car: ";
    cin >> car.mileage;

    car.serviced = false;

    cars.push_back(car);

    cout << "Car added successfully!" << endl;
}
void displayCars(const vector<Car> &cars)
{
    cout << "Cars in the facility:" << endl;

    for (const auto &car : cars)
    {
        cout << car.make << " " << car.model << " (" << car.year << "), " << car.mileage << " miles, ";

        if (car.serviced)
        {
            cout << "serviced" << endl;
        }
        else
        {
            cout << "unserviced" << endl;
        }
    }
}
void serviceCar(vector<Car> &cars)
{
    int index;

    cout << "Enter the index of the car to service: ";
    cin >> index;

    if (index < 0 || index >= cars.size())
    {
        cout << "Invalid index. Please try again." << endl;
        return;
    }

    cars[index].serviced = true;

    cout << "Car serviced successfully!" << endl;
}

void search()
{
    string in, a, b, c, d, e, f, g, h, i, j, k, l, m, n, o;
    int find2 = 0;
WRONG_INVOICE:
    cout << "ENTER INVOICE FOR WHICH YOU WANT TO CHECK INFORMATION:";
    cin >> in;

    ifstream find1("bills.txt");
    while (getline(find1, a) && getline(find1, b) && getline(find1, c) && getline(find1, d) && getline(find1, e) && getline(find1, f) && getline(find1, g) && getline(find1, h) && getline(find1, i) && getline(find1, j) && getline(find1, k) && getline(find1, l) && getline(find1, m) && getline(find1, n) && getline(find1, o))

    // while (find1 >> a >> b >> c >> d >> e >> f >> g >> h >> i >> j >> k >> l >> m)
    {
        if (in == a)
        {
            find2 = 1;
            break;
        }
    }
    find1.close();
    if (find2 == 1)
    {
        cout << "\n\t\t\t\t\tYOUR INVOICE\n";
        cout << "************************************************************************\n";
        cout << "INVOICE NUMBER:" << a << endl;
        cout << "DATE:" << b << "/" << c << "/" << d << endl;
        cout << "CONTACT NUMBER:" << e << endl;
        cout << "MODEL_NAME:" << f << endl;
        cout << "VECHILE COLOUR:" << g << endl;
        cout << "BASE PRICE:" << h << endl;
        cout << "GST:" << i << endl;
        cout << "INSAURANCE:" << j << endl;
        cout << "TOTAL:" << k << endl;
        cout << "DISCOUNT:" << l << endl;
        cout << "NET TOTAL:" << m << endl;
        cout << "NAME:" << n << endl;
        cout << "MAIL ID:" << o << endl;
        cout << "************************************************************************\n";
    }
    else
    {
        cout << "\nYour invoice is not found ! \n";
        cout << "Either you enter wrong invoice number or you not purachase anything\n\n";
        goto WRONG_INVOICE;
    }
}

int main()
{
    vector<Car> cars;
    login();
    char admin;
again_input:
    cout << "1) FOR PURCHASING INFORMATION\n2)SERVICING FACILITY\n\n";
    cout << "ENTER WHICH FACILITY DO YOU WANT:";
    cin >> admin;
    cout << "\n";
    switch (admin)
    {
    wrong:
    case '1':
        search();
        char menu;
        cout << "\nENTER FROM GIVEN OPTIONS->\n1) GO BACK\n2)MAIN MENU\n3)EXIT\n";
        cout << "\nENTER HERE:";
        cin >> menu;
        cout << "\n";

        switch (menu)
        {
        case '1':
            goto again_input;
            break;
        case '2':
            system("cls");
            system("main_final_login.exe");
            break;
        default:
            system("cls");
            cout << "BYE BYE!\n\n";
            break;
        }
        break;
    case '2':

        while (true)
        {
            cout << "Please select an option: " << endl;
            cout << "1. Add a new car" << endl;
            cout << "2. Display all cars" << endl;
            cout << "3. Service a car" << endl;
            cout << "4. Quit" << endl
                 << endl;
            cout << "ENTER HERE:";

            int option;
            cin >> option;

            switch (option)
            {
            case 1:
                cin.ignore();
                addCar(cars);
                break;

            case 2:
                displayCars(cars);
                break;

            case 3:
                serviceCar(cars);
                break;

            case 4:
                cout << "Thank you for using our car servicing facility. Goodbye!" << endl;
                return 0;

            default:
                cout << "Invalid option. Please try again." << endl;
                break;
            }
        }
        break;
    default:
        cout << "Wrong input! \n";
        cout << "Please select from the below options\n\n";
        goto wrong;
        break;
    }
    return 0;
}
void login()
{
    int count = 0;
    string Id3, pass3;
    string id4, pass4;
    cout << "ENTER YOUR USERID:";
    cin >> id4;
    cout << "ENTER YOUR PASSWORD:";
    cin >> pass4;

    ifstream input("admincredentials.txt");
    // while (getline(input, Id) && getline(input, pass))
    while (input >> Id3 >> pass3)
    {
        if (id4 == Id3 && pass4 == pass3)
        {
            count = 1;
            break;
        }
    }
    input.close();
    if (count == 1)
    {
        system("cls");
        cout << "\nLogin successfully! \n\n";
    }
    else
    {
        system("cls");
        cout << "\nLogin Error! \n";
        cout << "Check your userId or password. \n";
        main();
    }
}
