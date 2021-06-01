#include <iostream>
#include <fstream>
using namespace std;

/****************************
           classes
****************************/
//account
struct account {
    void createAccount();
    char retproffesion();
    string retUsername();
    string retPassword();
    int retID();
protected:
    char username[50];
    char password[50];
    int accountID;
    char proffesion;
};


void account::createAccount() {
    account ac;
    cout << "enter ur username: ";
    cin >> username;
    cout << "enter ur password: ";
    cin >> password;
    cout << "enter ur unique ID: ";
    cin >> accountID;
    cout << "enter the type of account (d/p): ";
    cin >> proffesion;
    cout << "ur account ID is: " << accountID <<endl;
}

char account::retproffesion() {
    return proffesion;
}

string account::retUsername() {
    return username;
}
string account::retPassword() {
    return password;
}

int account::retID() {
    return accountID;
}


//doctor
struct doctor: public account {
    void getName();
    ifstream inFile;
private:
    char name[50];
    int diseasesAdded[20];
};

void doctor::getName() {
    cout << "enter your name: ";
    cin >> name;
}

//patient
struct patient : public account {
    void getInfo();
private:
    char name[50];
    int age;
    char gender;
    int diseaseHistory[20];
};

void patient::getInfo() {
    cout << "enter your name: ";
    cin >> name;
    cout << "enter ur age: ";
    cin >> age;
    cout << "are u a male or female (m/f) :";
    cin >> gender;
}
//disease
struct disease : public doctor{
    void createDisease();
    void getDoctorAdded(int);
private:
    char name[50];
    int doctorID;
    int diseaseID;
    char generalInfo[50];
    string symptoms[20];
};

void disease::getDoctorAdded(int ID) {
    doctorID = ID;
}

void disease::createDisease() {
    cout << "enter disease name: ";
    cin >> name;
    cout << "enter unique disease ID: ";
    cin >> diseaseID;
    cout << "enter general info: ";
    cin >> generalInfo;
}

/************************
 function declaration
*************************/
void reg();
char logIn();
void addDisease();

int main()
{
    char proffesion = 'q';
    char choice;
    bool done = false;
    do {
        system("cls");
        cout << "\n\n\n\tMAIN MENU";
        cout << "\n\n\n01. LOG IN";
        cout << "\n\n\n02. REGISTER";
        cout << "\n\n\n03. EXIT";
        cout << "\n\n\nSelect your option (1-3) ";
        cin >> choice;
        switch (choice) {
        case '1':
            proffesion=logIn();
            done = true;
            break;
        case '2':
            reg();
            break;
        case '3':
            done = true;
            break;
        }
    } while (!done);
    choice = 0;
    account ac;
    if (proffesion == 'd') {
        do {
            system("cls");
            cout << "\n\n\n\tDOCTOR MENU";
            cout << "\n\n\n01. EXIT";
            cout << "\n\n\n02. ADD DISEASE";
            cout << "\n\n\nSelect your option (1-3) ";
            cin >> choice;
            switch (choice) {
            case '2':
                addDisease();
                break;
            }
        } while (choice!='1');
    }

    return 0;
}

void reg() {
    account ac;
    doctor doc;
    patient pat;
    ofstream outFile;
    outFile.open("account.txt", ios::binary | ios::app);
    ac.createAccount();
    outFile.write(reinterpret_cast<char*> (&ac), sizeof(account));
    outFile.close();
    if (ac.retproffesion() == 'd') {
        doc.getName();
    }
    else if (ac.retproffesion() == 'p') {
        pat.getInfo();
    }
}

char logIn() {
    ifstream inFile;
    account ac;
    char username[50], password[50];
    bool found = false;
    cout << "enter ur username: ";
    cin >> username;
    cout << "enter ur password: ";
    cin >> password;
    inFile.open("account.txt", ios::binary);
    while (!inFile.eof() && found == false) {
        inFile.read(reinterpret_cast<char*> (&ac), sizeof(account));
        if (password == ac.retPassword() && username == ac.retUsername()) {
            found = true;
            cout << "log in done";
        }
    }
    return ac.retproffesion();
}
void addDisease() {
    ofstream outFile;
    disease dis;
    outFile.open("diseases.txt", ios::binary | ios::app);
    dis.createDisease();
    dis.getDoctorAdded(dis.retID());
    outFile.write(reinterpret_cast<char*> (&dis), sizeof(disease));
    outFile.close();
    
}
