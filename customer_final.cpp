#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;
void billing();
void find1();
void getFeedback();

static int BASE_PRICE;
static string model_name;
static string model_colour;
static int a;
static int gst;
static int insaurance;
static int total;
static int discount;
static int net_total;

class CARS
{
public:
    int brand, dd, mm, yy;
    string buyer_name;
    long long contact_no;
    string buyer_mail;

    void contactdetail()
    {
        fflush(stdin);
        cout << "ENTER BUYER'S NAME:";
        getline(cin, buyer_name);
        cout << "ENTER CONTACT NUMBER :";
        cin >> contact_no;
        cout << "ENTER BUYER'S MAIL :";
        cin >> buyer_mail;
        cout << "ENTER PURCHASING DATE:\n";
    dd:
        cout << "ENTER DAY(DD FORMAT):";
        cin >> dd;
        if (dd < 1 || dd > 30)
        {
            cout << "\nWRONG INPUT!\nPLEASE INPUT CORRECT DAY\n";
            goto dd;
        }
    mm:
        cout << "ENTER MONTH(MM FORMAT):";
        cin >> mm;
        if (mm < 1 || mm > 12)
        {
            cout << "\nWRONG INPUT!\nPLEASE INPUT CORRECT MONTH\n";
            goto mm;
        }
    yy:
        cout << "ENTER YEAR(YYYY FORMAT):";
        cin >> yy;
        if (yy != 2023)
        {
            cout << "\nWRONG INPUT!\nPLEASE INPUT CORRECT YEAR\n";
            goto yy;
        }
    }

    void getdetails()
    {
        cout << "Select the brand from below which you want to see:\n\n";
        cout << "currently avaliable brands:-\n\n";
        cout << "1: MARUTI SUZUKI\n"
             << "2: TATA\n"
             << "3: MAHINDRA\n"
             << "4: RANGE ROVER\n\n";
        cout << "SELECT OPTION:";
        cin >> brand;
        cout << endl;
    }
};

class MODEL
{
public:
    int maruti800_price = 250000;
    int alto_price = 300000;
    int wagonr_price = 450000;
    int brezza_price = 750000;
    int tiago_price = 500000;
    int harrier_price = 1400000;
    int altroz_price = 550000;
    int safari_price = 1700000;
    int bolero_price = 850000;
    int thar_price = 1200000;
    int scorpion_price = 1250000;
    int xuv300_price = 1000000;
    int velar_price = 9000000;
    int defender_price = 10000000;
    int sport_price = 15000000;
    int discovery_price = 8000000;

    void MARUTI_SUZUKI()
    {
        cout << "Currently avalaible models for selected brands is:-\n\n";
        cout << "******************************************************************************\n";
        cout << "S.No\t\t\t\tMODEL_NAME\t\t\tPRICE/-\n";
        cout << "1)\t\t\t\tMARUTI 800\t\t\t" << maruti800_price << "/-" << endl;
        cout << "2)\t\t\t\tALTO\t\t\t\t" << alto_price << "/-" << endl;
        cout << "3)\t\t\t\tWAGONR\t\t\t\t" << wagonr_price << "/-" << endl;
        cout << "4)\t\t\t\tBREZZA\t\t\t\t" << brezza_price << "/-" << endl;
        cout << "******************************************************************************\n\n";
    }
    void TATA()
    {
        cout << "Currently avalaible models for selected brands is:-\n\n";

        cout << "******************************************************************************\n";
        cout << "S.No\t\t\t\tMODEL_NAME\t\t\tPRICE/-\n";
        cout << "1)\t\t\t\tTIAGO\t\t\t\t" << tiago_price << "/-" << endl;
        cout << "2)\t\t\t\tHARRIER\t\t\t\t" << harrier_price << "/-" << endl;
        cout << "3)\t\t\t\tALTROZ\t\t\t\t" << altroz_price << "/-" << endl;
        cout << "4)\t\t\t\tSAFARI\t\t\t\t" << safari_price << "/-" << endl;
        cout << "******************************************************************************\n\n";
    }
    void MAHINDRA()
    {
        cout << "Currently avalaible models for selected brands is:-\n\n";
        cout << "******************************************************************************\n";
        cout << "S.No\t\t\t\tMODEL_NAME\t\t\tPRICE/-\n";
        cout << "1)\t\t\t\tBOLERO\t\t\t\t" << bolero_price << "/-" << endl;
        cout << "2)\t\t\t\tTHAR\t\t\t\t" << thar_price << "/-" << endl;
        cout << "3)\t\t\t\tSCORPIO-N\t\t\t" << scorpion_price << "/-" << endl;
        cout << "4)\t\t\t\tXUV300\t\t\t\t" << xuv300_price << "/-" << endl;
        cout << "******************************************************************************\n\n";
    }
    void RANGE_ROVER()
    {
        cout << "Currently avalaible models for selected brands is:-\n\n";
        cout << "******************************************************************************\n";
        cout << "S.No\t\t\t\tMODEL_NAME\t\t\tPRICE/-\n";
        cout << "1)\t\t\t\tVELAR\t\t\t\t" << velar_price << "/-" << endl;
        cout << "2)\t\t\t\tDEFENDER\t\t\t" << defender_price << "/-" << endl;
        cout << "3)\t\t\t\tSPORT\t\t\t\t" << sport_price << "/-" << endl;
        cout << "4)\t\t\t\tDISCOVERY\t\t\t" << discovery_price << "/-" << endl;
        cout << "******************************************************************************\n\n";
    }
};

class DETAILS : public MODEL
{
public:
    string maruti1;
    string cc;
    string mileage;
    string colour;
    string airbags;
    string power;
    string car_name;
    string carname;
    string price;
    string price1;

    void specifications()
    {
        ifstream specs("features.txt");
        if (!specs.is_open())
        {
            cout << "Failed to open file\n";
            return;
        }
        while (getline(specs, carname) && getline(specs, cc) && getline(specs, mileage) && getline(specs, colour) && getline(specs, airbags) && getline(specs, power) && getline(specs, price) && getline(specs, price1))
        {
            if (carname == car_name)
            {
                cout << "-------------------------------------------------------\n";
                cout << "car:" << carname << endl;
                cout << "cc:" << cc << endl;
                cout << "mileage:" << mileage << endl;
                cout << "colour:" << colour << endl;
                cout << "airbags:" << airbags << endl;
                cout << "power:" << power << endl;
                cout << "price:" << price << endl;
                cout << "-------------------------------------------------------\n";
                BASE_PRICE = stoi(price1);
                model_name = string(carname);
                model_colour = string(colour);
            }
            else
            {
                cout << "";
            }
        }
        specs.close();
    }
};

int main()
{
    CARS cars;
    MODEL model;
    DETAILS detail;
    char choice;
getagain:
    cars.getdetails();
    switch (cars.brand)
    {
    case 1:
        model.MARUTI_SUZUKI();
        break;
    case 2:
        model.TATA();
        break;
    case 3:
        model.MAHINDRA();
        break;
    case 4:
        model.RANGE_ROVER();
        break;
    default:
        system("cls");
        cout << "WRONG INPUT\nPLEASE SELECT AGAIN !!!\n\n";
        goto getagain;
        break;
    }
optionagain:
    char mo;
    cout << "Select which model do you want to purchase:";
    cin >> mo;
    cout << endl;
    switch (mo)
    {
    case '1':
        switch (cars.brand)
        {
        case 1:
            detail.car_name = "maruti800";
            break;
        case 2:
            detail.car_name = "tiago";
            break;
        case 3:
            detail.car_name = "bolero";
            break;
        case 4:
            detail.car_name = "velar";
            break;
        }
        cout << "SPECIFICATIONS OF SELECTED MODEL ARE AS FOLLOWS:-\n\n";
        detail.specifications();
        break;
    case '2':
        switch (cars.brand)
        {
        case 1:
            detail.car_name = "alto";
            break;
        case 2:
            detail.car_name = "harrier";
            break;
        case 3:
            detail.car_name = "thar";
            break;
        case 4:
            detail.car_name = "defender";
            break;
        }
        cout << "SPECIFICATIONS OF SELECTED MODEL ARE AS FOLLOWS:-\n\n";
        detail.specifications();
        break;
    case '3':
        switch (cars.brand)
        {
        case 1:
            detail.car_name = "wagonr";
            break;
        case 2:
            detail.car_name = "altroz";
            break;
        case 3:
            detail.car_name = "scorpion";
            break;
        case 4:
            detail.car_name = "sport";
            break;
        }
        cout << "SPECIFICATIONS OF SELECTED MODEL ARE AS FOLLOWS:-\n\n";
        detail.specifications();
        break;
    case '4':
        switch (cars.brand)
        {
        case 1:
            detail.car_name = "brezza";
            break;
        case 2:
            detail.car_name = "safari";
            break;
        case 3:
            detail.car_name = "xuv300";
            break;
        case 4:
            detail.car_name = "discovery";
            break;
        }
        cout << "SPECIFICATIONS OF SELECTED MODEL ARE AS FOLLOWS:-\n\n";
        detail.specifications();
        break;
    default:
        cout << "WRONG INPUT\nPLEASE SELECT FROM ABOVE OPTIONS !!!\n\n";
        goto optionagain;
        break;
    }
menu:
    cout << "\nIf you want to go back Press '#'\n";
    cout << "If you want to go in main Press '*'\n";
    cout << "Press 'y' to buy a car\n\n";
    cout << "ENTER YOUR CHOICE:";
    cin >> choice;
    switch (choice)
    {
    case '#':
        goto optionagain;
        break;
    case '*':
        goto getagain;
        break;
    case 'y':
        cout << "\n";
        billing();
        break;
    case 'Y':
        cout << "\n";
        billing();
        break;
    default:
        cout << "\nWRONG INPUT\nPLEASE SELECT FROM ABOVE OPTIONS !!!\n\n";
        goto menu;
        break;
    }
    getFeedback();
    return 0;
}
void getFeedback()
{
    string feedback;

    cout << "Please select an option for feedback: " << endl;
    cout << "1. Excellent" << endl;
    cout << "2. Good" << endl;
    cout << "3. Very Good" << endl;
    cout << "4. Poor" << endl;
    cout << "5. Quit" << endl;
    cout << "\nENTER HERE:";

    int option;
    cin >> option;

    if (option == 1)
    {
        feedback = "Excellent";
    }
    else if (option == 2)
    {
        feedback = "Good";
    }
    else if (option == 3)
    {
        feedback = "Very Good";
    }
    else if (option == 4)
    {
        feedback = "Poor";
    }
    else if (option == 5)
    {
        cout << "Thank you for using our service. Goodbye!" << endl;
        return;
    }
    else
    {
        cout << "\nInvalid option. Please try again." << endl;
        getFeedback();
        return;
    }

    cout << "Thank you for your feedback! Here's what you said: " << feedback << endl;
}
void billing()
{
    MODEL model;
    CARS car;
    srand(time(0));

    gst = BASE_PRICE * (0.18);
    insaurance = BASE_PRICE * (0.05);
    total = gst + BASE_PRICE + insaurance;
    if (total < 1000000)
    {
        discount = total * (0.04);
    }
    else if (total >= 1000000 && total < 5000000)
    {
        discount = total * (0.07);
    }
    else if (total >= 5000000 && total < 10000000)
    {
        discount = total * (0.10);
    }
    else
    {
        discount = total * (0.13);
    }

    net_total = total - discount;

    car.contactdetail();
    system("cls");

    a = rand() + rand() + rand();
    cout << "\n\t\t\t\t\t\tINVOICE\n";
    cout << "*******************************************************************************************************\n";
    cout << "AUTO CARS WORLD\n";
    cout << "JIIT,NOIDA,SECTOR-62\n";
    cout << "UTTAR PRADESH\n\n";

    cout << "->INVOICE:\n";
    cout << "INVOICE NUMBER:#" << a << endl;
    cout << "DATE:" << car.dd << "/" << car.mm << "/" << car.yy << endl
         << endl;

    cout << "->SOLD TO:\n";
    cout << "NAME:" << car.buyer_name << endl;
    cout << "CONTACT NUMBER:" << car.contact_no << endl;
    cout << "EMAIL:" << car.buyer_mail << endl
         << endl;

    cout << "->VECHILE INFORMATION:\n";
    cout << "MODEL NAME:" << model_name << endl;
    cout << "MODEL COLOUR:" << model_colour << endl
         << endl;

    cout << "->PRICE BREAKDOWN(IN RUPEES):\n";
    cout << "BASE PRICE:" << BASE_PRICE << "/-" << endl;
    cout << "GST:" << gst << "/-" << endl;
    cout << "INSAURANE CHARGE:" << insaurance << "/-" << endl;
    cout << "TOTAL:" << total << "/-" << endl;
    cout << "DISCOUNT:" << discount << "/-" << endl;
    cout << "NET TOTAL:" << net_total << "/-" << endl
         << endl;

    cout << "Thank you for your deal! If you have any question or concerns,please do not hesitate to contact us.\n";
    cout << "*******************************************************************************************************\n\n";

    cout << "BILL SAVED SUCCESSFULLY!\n\n";

    ofstream save("bills.txt", ios::app);
    save << a << "\n";
    save << car.dd << "\n";
    save << car.mm << "\n";
    save << car.yy << "\n";
    save << car.contact_no << "\n";
    save << model_name << "\n";
    save << model_colour << "\n";
    save << BASE_PRICE << "\n";
    save << discount << "\n";
    save << net_total << "\n";
    save << gst << "\n";
    save << insaurance << "\n";
    save << total << "\n";
    save << car.buyer_name << "\n";
    save << car.buyer_mail << "\n";
    save.close();
}

void find1()
{
    string in;
    string a;
    string b;
    string c;
    string d;
    string e;
    string f;
    string g;
    string h;
    string dis;
    string nt;
    string i;
    string j;
    string k;
    string l;
    string m;
    int find2 = 0;

    cout << "ENTER INVOICE:";
    cin >> in;

    ifstream find1("bills.txt");
    while (getline(find1, a) && getline(find1, b) && getline(find1, c) && getline(find1, d) && getline(find1, e) && getline(find1, f) && getline(find1, g) && getline(find1, h) && getline(find1, dis) && getline(find1, nt) && getline(find1, i) && getline(find1, j) && getline(find1, k) && getline(find1, l) && getline(find1, m))
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
        cout << "INVOICE NUMBER: " << a << endl;
        cout << "DATE: " << b << "/" << c << "/" << d << endl;
        cout << "NAME: " << l << endl;
        cout << "MAIL ID: " << m << endl;
        cout << "CONTACT NUMBER: " << e << endl;
        cout << "MODEL_NAME: " << f << endl;
        cout << "VECHILE COLOUR: " << g << endl;
        cout << "BASE PRICE: " << h << "/-" << endl;
        cout << "GST: " << i << "/-" << endl;
        cout << "INSAURANCE: " << j << "/-" << endl;
        cout << "TOTAL: " << k << "/-" << endl;
        cout << "DISCOUNT: " << dis << "/-" << endl;
        cout << "NET TOTAL: " << nt << "/-" << endl;
        cout << "************************************************************************\n";
    }
    else
    {
        cout << "\nYour invoice is not found ! \n";
        cout << "Either you enter wrong invoice number or you not purachase anything\n\n";
    }
}
