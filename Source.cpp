#include<iostream>
#include<string>
#include<iomanip>
#include<vector>
#include<conio.h>
#include<fstream>
#include<map>
using namespace std;
multimap <int, string> savedpatient;

class Person
{
protected:
    string name, family, address, phone;
    int age;


public:
    Person() {}
    Person(string name, string family, string address, string phone, int age) {

        this->name = name;
        (*this).family = family;
        this->address = address;
        this->phone = phone;
        this->age = age;
    }
    void setName(string name) {
        this->name = name;
    }
    void setFamily(string family) {
        this->family = family;
    }
    void setAddress(string address) {
        this->address = address;
    }
    void setPhone(string phone) {
        this->phone = phone;
    }
    void setAge(int age) {
        this->age = age;
    }

    string getName() const {
        return name;
    }
    string getFamily()const {
        return family;
    }
    string getAddress()const {
        return address;
    }
    string getPhone()const {
        return phone;
    }
    int getAge()const {
        return age;
    }

    void report() const {

        cout << name << setw(6) << " " << family << setw(10) << address << setw(10) << phone << setw(11) << age << setw(2) << endl;

    }

};

class Namedisease
{
    int room, diseasenumber;
    string namedisease, doctorname;

public:
    Namedisease() {}
    Namedisease(string namedisease, int diseasenumber, string doctorname, int room)
    {
        this->diseasenumber = diseasenumber;
        this->doctorname = doctorname;
        this->namedisease = namedisease;
        this->room = room;
    }
    void setNamedisease(string namedisease)
    {
        this->namedisease = namedisease;
    }
    void setDiseasenumber(int diseasenumber)
    {
        this->diseasenumber = diseasenumber;
    }
    void setDoctorname(string doctorname)
    {
        this->doctorname = doctorname;
    }
    void setRoom(int room)
    {
        this->room = room;
    }
    string getNamedisease()const
    {
        return namedisease;
    }
    int getDiseasenumber()const
    {
        return diseasenumber;
    }
    string getDoctorname()const
    {
        return doctorname;
    }
    int getRoom()const
    {
        return room;
    }

    void report()
    {
        cout << namedisease << setw(10) << diseasenumber << setw(6) << doctorname << setw(10) << room << setw(3) << endl;
    }
};

class Patient :public Person
{
private:

    int idpatient;


public:
    Patient() {}
    Patient(string name, string family, string address, string phone, int age, int idpatient) :Person(name, family, address, phone, age) {


        this->idpatient = idpatient;

    }
    void registerNamedisease();
    void setIdpatient(int idpatient)
    {
        this->idpatient = idpatient;
    }
    int getIdpatient()const
    {
        return idpatient;
    }
    void report() const {

        cout << name << setw(6) << " " << family << setw(10) << address << setw(10) << phone << setw(11) << age << setw(2) << idpatient << setw(6) << endl;

    }
};

class Doctor :public Person
{
private:
    int codedoctor;
    string expertise;

public:
    Doctor() {}
    Doctor(string name, string family, string address, string phone, int age, int codedoctor, string expertise) :Person(name, family, address, phone, age)
    {

        this->codedoctor = codedoctor;
        this->expertise = expertise;
    }
    void setCodedoctor(int codedoctor)
    {
        this->codedoctor = codedoctor;
    }
    void setExpertise(string expertise)
    {
        this->expertise = expertise;
    }
    int getCodedoctor()const
    {
        return codedoctor;
    }
    string getExpertise()const
    {
        return expertise;
    }

    void report() const {

        cout << name << setw(6) << " " << family << setw(10) << address << setw(10) << phone << setw(11) << age << setw(2) << codedoctor << setw(6) << expertise << setw(10) << endl;

    }
};


//##############################################################
//
//#########################  Namedisease  ###########################


vector<Namedisease> listdi, listdi2;
fstream outputfileDI;

void writDI()
{
    int room, diseasenumber;
    string namedisease, doctorname;
    cout << "Enter Namedisease :" << endl;
    cin >> namedisease;
    cout << "Enter Diseasenumber :" << endl;
    cin >> diseasenumber;
    cout << "Enter Doctorname :" << endl;
    cin >> doctorname;
    cout << "Enter Room :" << endl;
    cin >> room;

    listdi.push_back(Namedisease(namedisease, diseasenumber, doctorname, room));
    outputfileDI.open("Namedisease.csv", ios::app);
    outputfileDI << namedisease + "," + to_string(diseasenumber) + "," + doctorname + "," + to_string(room) << endl;

}
void displayallDI()
{


    system("cls");
    cout << "\n\n\t\tAll Information Namedisease of Namedisease one Result \n\n";
    cout << "==========================================================\n";
    cout << "Namedisease       Diseasenumber       Doctorname       Room " << endl;
    cout << "==========================================================\n";


    for (int i = 0; i < listdi.size(); i++) {

        listdi[i].report();

    }




}
void displayOneDI(int diseasenumber) {


    system("cls");
    cout << "\n\n\t\tAll Information Namedisease of Namedisease one Result \n\n";
    cout << "==========================================================\n";
    cout << "Namedisease       Diseasenumber       Doctorname       Room " << endl;
    cout << "==========================================================\n";


    for (int i = 0; i < listdi.size(); i++) {
        if (listdi[i].getDiseasenumber() == diseasenumber) {
            listdi[i].report();
        }

    }

}
void modifyDI(int diseasenumber) {

    int room, codedoctor;
    string doctorname;

    int a;
    for (int i = 0; i < listdi.size(); i++) {
        if (listdi[i].getDiseasenumber() == diseasenumber) {
            cout << "\n\n\n\tSELECT MENU";
            cout << "\n\n\n\t1. CODE DOCTOR";
            cout << "\n\n\t2. DOCTOR NAME";
            cout << "\n\n\t3. ROOM";
            cout << "\n\n\n\tEnter Choice (1/2/3)? ";
            cin >> a;

            switch (a)
            {
            case 1: cout << "Enter code doctor:"; cin >> codedoctor; listdi[i].setDiseasenumber(codedoctor); break;
            case 2: cout << "Enter doctor name:"; cin >> doctorname; listdi[i].setDoctorname(doctorname); break;
            case 3: cout << "Enter room:"; cin >> room; listdi[i].setRoom(room); break;

            default:
                break;
            }

        }

    }

}
void deleteallDI()
{
    listdi.clear();
}
void deleteOneDI(int diseasenumber) {

    for (int i = 0; i < listdi.size(); i++) {
        if (listdi[i].getDiseasenumber() != diseasenumber) {
            listdi2.push_back(listdi[i]);
        }

    }


    listdi = listdi2;
    vector<Namedisease>().swap(listdi2);
}
vector<Namedisease> getdataregister()
{
    return listdi;
}


//##############################################################
//
//#########################  Patient  ###########################


vector <Patient> listpa, listpa2;
fstream outputfile;

void writest()
{
    string name, family, address, phone;
    int age, idpatient;
    cout << "\n Enter the number of Patient: ";
    cin >> idpatient;
    cout << "\n Enter the name of Patient: ";
    cin >> name;
    cout << "\n Enter the family of Patient: ";
    cin >> family;
    cout << "\n Enter the address of Patient: ";
    cin >> address;
    cout << "\n Enter the phone of Patient: ";
    cin >> phone;
    cout << "\n Enter the age of Patient: ";
    cin >> age;

    listpa.push_back(Patient(name, family, address, phone, age, idpatient));

    outputfile.open("Patient.csv", ios::app);
    outputfile << name + "," + family + "," + address + "," + to_string(age) + phone + ","
        + to_string(idpatient) << endl;
}
void displayallpa()
{

    system("cls");
    cout << "\n\n\t\tAll Patient Result \n\n";
    cout << "==========================================================\n";
    cout << "Name       Family        Address   Phone   age   idPatient" << endl;
    cout << "==========================================================\n";
    for (int i = 0; i < listpa.size(); i++)
    {

        listpa[i].report();
    }

}
void displayonepa(int idpatient) {

    system("cls");
    cout << "\n\n\t\tAll Patient Result \n\n";
    cout << "==========================================================\n";
    cout << "Name       Family        Address   Phone   age   idpatient" << endl;
    cout << "==========================================================\n";

    for (int i = 0; i < listpa.size(); i++)
    {
        if (listpa[i].getIdpatient() == idpatient) {
            listpa[i].report();
        }
    }

}
void modify(int idpatient) {
    string name, family, phone;
    int a;
    for (int i = 0; i < listpa.size(); i++)
    {
        if (listpa[i].getIdpatient() == idpatient) {
            cout << "\n\n\n\tSELECT MENU";
            cout << "\n\n\n\t1. NAME";
            cout << "\n\n\t2. FAMILY";
            cout << "\n\n\t3. PHONE";
            cout << "\n\n\n\tEnter Choice (1/2/3)? ";
            cin >> a;
            switch (a)
            {
            case 1: cout << "Enter a name" << endl; cin >> name; listpa[i].setName(name); break;
            case 2: cout << "Enter a family" << endl; cin >> family; listpa[i].setFamily(family); break;
            case 3: cout << "Enter a phone" << endl; cin >> phone; listpa[i].setPhone(phone); break;

            }

        }
    }

}
void deleteallPatient()
{

    listpa.clear();

}
void deleteOnePatient(int idpatient)
{

    for (int i = 0; i < listpa.size(); i++) {

        if (listpa[i].getIdpatient() != idpatient) {

            listpa2.push_back(listpa[i]);

        }
    }

    listpa = listpa2;
    vector<Patient>().swap(listpa2);

}
void selectNamedisease(int idpatient)
{

    for (int i = 0; i < listpa.size(); i++) {

        if (listpa[i].getIdpatient() == idpatient) {

            listpa[i].registerNamedisease();
        }
    }
}
void Patient::registerNamedisease() {
    displayallDI();
    int code;
    char ch;
    do {
        cout << "Enter the code of Name Disease for register" << endl;
        cin >> code;
        vector<Namedisease> listdi = getdataregister();
        for (int i = 0; i < listdi.size(); i++) {

            if (listdi[i].getDiseasenumber() == code) {

                listdi.push_back(listdi[i]);
                savedpatient.insert(pair<int, string>(code, name + " " + family));

            }

        }
        cout << "Are you continue? (Y|y)" << endl;
        cin >> ch;

    } while (ch == 'y' || ch == 'Y');
}
multimap <int, string> getsavedstudent()
{
    return savedpatient;
}


//##############################################################
//
//#########################  Doctor  ###########################


vector <Doctor> listDO, listDO2;
fstream outputfileDO;

void writeDO()
{
    int codedoctor, age;
    string name, family, address, phone, expertise;
    cout << "\n Enter the number of Doctor: ";
    cin >> codedoctor;
    cout << "\n Enter the name of Doctor: ";
    cin >> name;
    cout << "\n Enter the family of Doctor: ";
    cin >> family;
    cout << "\n Enter the address of Doctor: ";
    cin >> address;
    cout << "\n Enter the phone of Doctor: ";
    cin >> phone;
    cout << "\n Enter the expertise of Doctor: ";
    cin >> expertise;
    cout << "\n Enter the age of Doctor: ";
    cin >> age;


    listDO.push_back(Doctor(name, family, address, phone, age, codedoctor, expertise));
    outputfileDO.open("teacher.csv", ios::app);
    outputfileDO << name + "," + family + "," + address + "," + to_string(age) + phone + ","
        + to_string(codedoctor) + "," + expertise << endl;
}
void displayallDO() {

    system("cls");
    cout << "\n\n\t\tAll Doctor Result \n\n";
    cout << "==========================================================\n";
    cout << "Name       Family        Address   Phone   Age   Code     Expertise " << endl;
    cout << "==========================================================\n";
    for (int i = 0; i < listDO.size(); i++)
    {

        listDO[i].report();
    }

}
void displayoneDO(int iddisease) {

    system("cls");
    cout << "\n\n\t\tAll Doctor Result \n\n";
    cout << "==========================================================\n";
    cout << "Name       Family        Address   Phone   Age   Code    Expertise" << endl;
    cout << "==========================================================\n";

    for (int i = 0; i < listDO.size(); i++)
    {
        if (listDO[i].getCodedoctor() == iddisease) {
            listDO[i].report();
        }
    }

}
void modifyDO(int iddisease) {
    string name, family, phone;
    int a;
    for (int i = 0; i < listDO.size(); i++)
    {
        if (listDO[i].getCodedoctor() == iddisease) {
            cout << "\n\n\n\tSELECT MENU";
            cout << "\n\n\n\t1. NAME";
            cout << "\n\n\t2. FAMILY";
            cout << "\n\n\t3. PHONE";
            cout << "\n\n\n\tEnter Choice (1/2/3)? ";
            cin >> a;
            switch (a)
            {
            case 1: cout << "Enter a name" << endl; cin >> name; listDO[i].setName(name); break;
            case 2: cout << "Enter a family" << endl; cin >> family; listDO[i].setFamily(family); break;
            case 3: cout << "Enter a phone" << endl; cin >> phone; listDO[i].setPhone(phone); break;

            }

        }
    }

}
void deleteallDO()
{

    listDO.clear();

}
void delete_DO(int codedoctor) {


    for (int i = 0; i < listDO.size(); i++) {

        if (listDO[i].getCodedoctor() != codedoctor) {

            listDO2.push_back(listDO[i]);


        }
    }

    listDO = listDO2;
    vector<Doctor>().swap(listDO2);


}
void printsavedpatient(int diseasenumber) {

    multimap<int, string> list = getsavedstudent();
    for (multimap<int, string> ::iterator it = list.begin(); it != list.end(); it++) {

        if (diseasenumber == it->first) {
            cout << it->second;
        }

    }

}


//##############################################################################
//
//###################################  MENU ####################################



void intro()
{
    system("cls");
    cout << "\n\n\n\t\t  SYSTEM HOSPITAL";
    cout << "\n\n\t\t  ADVANCED C++ PROJECT";
    cout << "\n\n\n\tMADE BY : FATEMEH SADAT FARAJI";
    cout << "\n\tSCHOOL : QOM UNIVERSITY";
    cin.get();
}
void report_men() {

    int a, e, f, iddisease;
    system("cls");
    cout << "\n\n\n\tREPORT MENU";
    cout << "\n\n\n\t1. REPORTS";
    cout << "\n\n\t2. Back to Main Menu";
    cout << "\n\n\n\tEnter Choice (1/2/3)? ";
    cin >> a;
    switch (a)
    {
    case 1:
    {	system("cls");
    cout << "\n\n\n\tREPORTs MENU";
    cout << "\n\n\t1. Paitent Reports";
    cout << "\n\n\t2. Doctor Reports";
    cout << "\n\n\t3. Disease Reports";
    cout << "\n\n\n\tEnter Choice (1/2/3)? ";
    cin >> e;
    switch (e)
    {
    case 1:
    {	system("cls");
    cout << "\n\n\n\tSELECT";
    cout << "\n\n\t1. All Patient Report";
    cout << "\n\n\t2. Patient Report";
    cout << "\n\n\n\tEnter Choice (1/2)? ";
    cin >> f;
    switch (f)
    {
    case 1:  displayallpa(); break;
    case 2: cout << "\n Enter the number of patient: "; cin >> iddisease;
        displayonepa(iddisease); break;
    default:
        break;
    }

    break; }
    case 2:
    {	system("cls");
    cout << "\n\n\n\tSELECT";
    cout << "\n\n\t1. All Doctor Report";
    cout << "\n\n\t2. Doctor Report";
    cout << "\n\n\t3. Disease Report";
    cout << "\n\n\n\tEnter Choice (1/3)? ";
    cin >> f;
    switch (f)
    {
    case 1:  displayallDO(); break;
    case 2: cout << "\n Enter the number of teacher: "; cin >> iddisease;
        displayoneDO(iddisease); break;
    case 3: cout << "\n Enter the code of course for report: "; cin >> iddisease;
        printsavedpatient(iddisease); _getch(); break;
    default:
        break;
    }

    break; }

    case 3:
    {	system("cls");
    cout << "\n\n\n\tSELECT";
    cout << "\n\n\t1. All Disease Report";
    cout << "\n\n\t2. Disease Report";
    cout << "\n\n\n\tEnter Choice (1/2)? ";
    cin >> f;
    switch (f)
    {
    case 1:  displayallDI(); break;
    case 2: cout << "\n Enter the number of Course: "; cin >> iddisease;
        displayOneDI(iddisease); break;
    default:
        break;
    }

    break; }


    default:
        break;
    }


    break;

    }
    case 2:break;
    }

}
void entry_men() {
    int a, num;
    char choice;
    system("cls");
    cout << "\n\n\n\tENTRY MENU";
    cout << "\n\n\t1.ENTRY MENU PATIENT";
    cout << "\n\n\t2.ENTRY MENU DOCTOR";
    cout << "\n\n\t3.ENTRY MENU DISEASE";
    cout << "\n\n\t4.BACK TO MAIN MENU";
    cout << "\n\n\tPlease Enter Your Choice (1-4) ";

    cin >> a;
    switch (a)
    {
    case 1:
    {    system("cls");
    cout << "\n\n\n\tENTRY MENU PATIENT";
    cout << "\n\n\t1.CREATE PATIENT RECORD";
    cout << "\n\n\t2.MODIFY PATIENT RECORD";
    cout << "\n\n\t3.DELETE PATIENT RECORD";
    cout << "\n\n\t4.DELETE PATIENT RECORDS";
    cout << "\n\n\t5.SELECT DISEASE";
    cout << "\n\n\t6.BACK TO MAIN MENU";
    cout << "\n\n\tPlease Enter Your Choice (1-6) ";
    cin >> a;
    switch (a) {
    case 1:
        do {
            writest();
            cout << "\n Patient record has been created";

            system("cls");
            cout << "Do you want to insert new record of Patient? Y|N";
            cin >> choice;
            system("cls");
        } while (choice == 'Y' || choice == 'y');
        break;
    case 2: cout << "\nEnter the number of Patient " << endl;
        cin >> num; modify(num); break;
        break;
    case 3: cout << "\nEnter the number of Patient " << endl;
        cin >> num; deleteOnePatient(num); break;
        break;
    case 4:  deleteallPatient(); break;
    case 5: cout << "\nEnter the number of Patient " << endl;
        cin >> num; selectNamedisease(num); break;
    case 6: break;
    }
    break;
    }
    case 2:
    {   system("cls");
    cout << "\n\n\n\tENTRY MENU DOCTOR";
    cout << "\n\n\t1.CREATE DOCTOR RECORD";
    cout << "\n\n\t2.MODIFY DOCTOR RECORD";
    cout << "\n\n\t3.DELETE DOCTOR RECORD";
    cout << "\n\n\t4.DELETE DOCTOR RECORDS";
    cout << "\n\n\t5.BACK TO MAIN MENU";
    cout << "\n\n\tPlease Enter Your Choice (1-5) ";
    cin >> a;
    switch (a) {
    case 1:
        do {
            writeDO();
            cout << "\n Doctor record has been created";

            system("cls");
            cout << "Do you want to insert new record of Doctor? Y|N";
            cin >> choice;
            system("cls");
        } while (choice == 'Y' || choice == 'y');
        break;
    case 2: cout << "\nEnter the number of Doctor " << endl;
        cin >> num; modifyDO(num); break;
        break;
    case 3: cout << "\nEnter the number of Doctor " << endl;
        cin >> num; delete_DO(num); break;
        break;
    case 4:  deleteallDO(); break;
    case 5: break;
    }
    break;
    }

    case 3:
    {   system("cls");
    cout << "\n\n\n\tENTRY MENU DISEASE";
    cout << "\n\n\t1.CREATE DISEASE RECORD";
    cout << "\n\n\t2.MODIFY DISEASE RECORD";
    cout << "\n\n\t3.DELETE DISEASE RECORD";
    cout << "\n\n\t4.DELETE DISEASE RECORDS";
    cout << "\n\n\t5.BACK TO MAIN MENU";
    cout << "\n\n\tPlease Enter Your Choice (1-5) ";
    cin >> a;
    switch (a) {
    case 1:
        do {
            writDI();
            cout << "\n Disease record has been created";

            system("cls");
            cout << "Do you want to insert new record of Disease? Y|N";
            cin >> choice;
            system("cls");
        } while (choice == 'Y' || choice == 'y');
        break;
    case 2: cout << "\nEnter the number of Disease " << endl;
        cin >> num; modifyDI(num); break;
        break;
    case 3: cout << "\nEnter the number of Disease " << endl;
        cin >> num; deleteOneDI(num); break;
        break;
    case 4:  deleteallDI(); break;
    case 5: break;
    }
    break;
    }

    case 4:break;

    }

}


int main()
{
    int a;
    do {
        system("cls");
        cout << "\n\n\n\tMAIN MENU";
        cout << "\n\n\t01. REPORT MENU";
        cout << "\n\n\t02. ENTRY/EDIT MENU";
        cout << "\n\n\t03. EXIT";
        cout << "\n\n\tPlease Select Your Option (1-3) ";

        cin >> a;
        system("cls");
        switch (a)
        {
        case 1:report_men(); break;
        case 2:entry_men();
        case 3:break;
        }
    } while (a != 3);


    _getch();
    return 0;
}




