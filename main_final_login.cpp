#include <iostream>
#include <fstream>
#include <string.h>
#include <cctype>

using namespace std;

class detail
{
public:
    string userId;
    string password;
    string email_Id;
    void getuserId()
    {
        cout << "Enter the userId:";
        cin >> userId;
    }
    void getpassword()
    {
        cout << "Enter the password:";
        cin >> password;
    }
    void getemailId()
    {
        cout << "Enter your Mail Id:";
        cin >> email_Id;
    }
};

void login();
void signup();
void forgot();

int main()
{
    char portal;
    cout << "<----------------------------------------------------------------------------------------->\n";
    cout << "\t\t\t\t\tWELCOME TO AUTO CARS WORLD\n";
    cout << "<----------------------------------------------------------------------------------------->\n\n";
    cout << "ENTER FOR:\n1)CUSTOMER PORTAL(BUYING NEW CAR)\n2)ADMINISTRATION PORTAL\n\n";
    cout << "ENTR HERE:";
    cin >> portal;
    cout << endl;
    switch (portal)
    {
    case '1':
    system("cls");
        char option;
    main:
        cout << "1.Login\n";
        cout << "2.signup\n";
        cout << "3.Forgot Password\n";
        cout << "4.Exit\n\n";

        cout << "Please enter your choice:";
        cin >> option;
        cout << endl;

        switch (option)
        {
        case '1':
            login();
            break;
        case '2':
            signup();
            break;
        case '3':
            forgot();
            break;
        case '4':
            cout << "Thankyou for visiting our showroom!\n\n";
            break;
        default:
            cout << "Wrong input! \n";
            cout << "Please select from the below options\n\n";
            system("cls");
            goto main;
            break;
        }
        break;
    case '2':
        system("cls");
        system("administration1.exe");
        break;
    default:
        system("cls");
        cout << "Wrong input! \n";
        cout << "Please select from the below options\n\n";
        main();
        break;
    }
    return 0;
}

void login()
{
    int count = 0;
    string Id, pass;

    detail details;
    details.getuserId();
    details.getpassword();
    ifstream input("records.txt");
    // while (getline(input, Id) && getline(input, pass))
    while (input >> Id >> pass)
    {
        if (details.userId == Id && details.password == pass)
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
        system("customer_final.exe");
    }
    else
    {
        cout << "\nLogin Error! \n";
        cout << "Check your userId or password. \n";
        cout << "Either you are new Or firstly you have to Signup\n\n";
        main();
    }
}

void signup()
{
    detail details;
    string name;
    string checkId;
    string outputId;
    int i = 0;

    ifstream checked("records.txt");
    cout << "WARNING :- USERID MUST NOT CONTAIN SPACES\n\n";
    details.getuserId();
    while (checked >> checkId)
    {
        if (checkId == details.userId)
        {
            cout << "\nusername Already Exists!Please try different One\n\n";
            signup();
        }
    }
    checked.close();

    ofstream data("records.txt", ios::app);
    fflush(stdin);
    cout << "Enter your's name:";
    getline(cin, name);
    ifstream output("records.txt");
    details.getemailId();
    while (output >> outputId)
    {
        if (outputId == details.email_Id)
        {
            cout << "\nEmail Id already exists!please try different\n\n";
            cout << "Re-enter your Mail Id:";
            cin >> details.email_Id;
        }
    }
    output.close();

    cout << "\n--------------------IMPORTANT---------------------------";
    cout << "\nPassword should have minimum 8 character";
    cout << "\nPassword Should contain atleast ONE CAPITAL LETTER";
    cout << "\nPassword Should contain atleast ONE SMALL LETTER";
    cout << "\nPassword Should contain atleast ONE DIGIT";
    cout << "\nPassword Should contain atleast ONE SPECIAL CHARACTER";
    cout << "\n--------------------------------------------------------\n\n";
here:

    details.getpassword();

    if (details.password.length() < 8)
    {
        cout << "\nPassword Length is insufficient length!";
        cout << "\nplease Re-enter your password!\n\n";
        goto here;
    }
    else
    {
        cout << "\n";
    }

    int uppercase = 0;
    int lowercase = 0;
    int digit = 0;

    for (i = 0; i < details.password.length(); i++)
    {
        if (isupper(details.password[i]))
        {
            uppercase = 1;
        }
        if (islower(details.password[i]))
        {
            lowercase = 1;
        }
        if (isdigit(details.password[i]))
        {
            digit = 1;
        }
    }
    if (uppercase != 1)
    {
        cout << "\nPlease Enter atleast one capital letter! ";
    }
    if (lowercase != 1)
    {
        cout << "\nPlease Enter atleast one small letter!";
    }
    if (digit != 1)
    {
        cout << "\nPlease Enter atleast one digit!";
    }

    if (uppercase == 1 && lowercase == 1 && digit == 1)
    {
        cout << "\n";
    }
    else
    {
        cout << "\nYour password is weak!\n";
        cout << "You have to fulfill above requirements!\n\n";
        goto here;
    }

    data << details.userId << "\n";
    data << details.password << "\n";
    data << details.email_Id << "\n";
    data << details.password << "\n";
    data << name << "\n";

    data.close();
    cout << endl;

    system("cls");
    cout << "\nRegistered Successfully! \n\n";
    main();
}

void forgot()
{
    int flag = 0;
    int temp = 0;
    string userId1;
    string password1;
    string password2;
    string emailId1;

    detail details;

    char choice;
    cout << "Enter '1' to search your password by the userId-> \n";
    cout << "Enter '2' to search your password by the EmailId-> \n";
    cout << "Enter '3' to go back->\n\n";
    cout << "Enter your choice:";
    cin >> choice;
    cout << endl;
    switch (choice)
    {
    case '1':
    {
        details.getuserId();

        ifstream check("records.txt");
        while (check >> userId1 >> password1)
        {
            if (details.userId == userId1)
            {
                flag = 1;
                break;
            }
        }
        check.close();
        system("cls");
        if (flag == 1)
        {
            cout << "\n---------------------------------\n";
            cout << "Your account has been found! \n";
            cout << "Your password is:" << password1 << endl;
            cout << "---------------------------------\n";
            cout << endl;
            main();
        }
        else
        {
            cout << "\nYour account is not found ! \n";
            cout << "Either you not registered or wrong userId input\n";
            cout << "please try again:\n\n";
            forgot();
        }
        break;
    }

    case '2':
    {
        details.getemailId();

        ifstream gmailId("records.txt");
        while (gmailId >> emailId1 >> password2)
        // while( getline(gmailId,password2) && getline(gmailId,emailId1))
        {
            if (details.email_Id == emailId1)
            {
                temp = 1;
                break;
            }
        }
        gmailId.close();
        system("cls");
        if (temp == 1)
        {
            cout << "\n---------------------------------\n";
            cout << "Your account has been found! \n";
            cout << "Your password is:" << password2 << endl;
            cout << "---------------------------------\n";
            cout << endl;
            main();
        }
        else
        {
            cout << "\nYour account is not found ! \n";
            cout << "Either you not registered or wrong Email Id input\n\n";
            forgot();
        }
        break;
    }
    case 3:
    {
        system("cls");
        main();
        break;
    }
    default:
    {
        cout << "Wrong choice!";
        cout << "\nplease select from below options only!\n\n";
        forgot();
        break;
    }
    }
}


