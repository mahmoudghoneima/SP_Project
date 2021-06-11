#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// CLASSES /



// FUNCTION DECLARATION /
char logIN(string, string);
void reg(string, string);
void addDisease(string);
void removeDisease();
void addSymptom(string);
void showSymptoms();
void findDisease(string);
void display();
void viewHistory(string);
void viewPatients();
void removeHistory(string);


// MAIN /
int main()
{
	string username, password;
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
			cout << "what is ur username: ";
			cin >> username;
			cout << "what is ur password: ";
			cin >> password;
			proffesion = logIN(username, password);
			done = true;
			break;
		case '2':
			cout << "what is ur username: ";
			cin >> username;
			cout << "what is ur password: ";
			cin >> password;
			reg(username, password);
			break;
		case '3':
			done = true;
			break;
		}
	} while (!done);

	if (proffesion == 'd') {
		do {
			system("cls");
			cout << "\n\n\n\tDOCTOR MENU";
			cout << "\n\n\n01. EXIT";
			cout << "\n\n\n02. ADD DISEASE";
			cout << "\n\n\n03. REMOVE DISEASE";
			cout << "\n\n\n04. ADD SYMPTOM";
			cout << "\n\n\n05. DISPLAY ALL DISEASES";
			cout << "\n\n\n06. VIEW PATIENTS WITH A CERTAIN DISEASE";
			cout << "\n\n\nSelect your option (1-6) ";

			cin >> choice;
			switch (choice) {
			case '2':
				addDisease(username);
				break;
			case '3':
				removeDisease();
				break;
			case '4':
				addSymptom(username);
				break;
			case '5':
				display();
				break;
			case'6':
				viewPatients();
				break;
			}
		} while (choice != '1');
	}
	if (proffesion == 'p') {
		do {
			system("cls");
			cout << "\n\n\n\tPATIENT MENU";
			cout << "\n\n\n01. EXIT";
			cout << "\n\n\n02. VIEW SYMPTOMS OF DISEASE";
			cout << "\n\n\n03. FIND YOUR DISEASE";
			cout << "\n\n\n04. VIEW DIAGNOSIS HISTORY";
			cout << "\n\n\n05. REMOVE DIAGNOSIS HISTORY";
			cout << "\n\n\nSelect your option (1-5) ";
			cin >> choice;
			switch (choice) {
			case '2':
				showSymptoms();
				break;
			case '3':
				findDisease(username);
				break;
			case '4':
				viewHistory(username);
				break;
			case '5':
				removeHistory(username);
				break;
			}
		} while (choice != '1');
	}
	/*patient struct */
	string temporary;
	struct patient {
		string patientNameStruct;
		string patientPasswordStruct;

	}patientStruct[10];

	
	ifstream patientFile("patientAccounts.txt");
	for (int i = 0; i < 10; i++) {
		patientFile >> patientStruct[i].patientNameStruct >> patientStruct[i].patientPasswordStruct;
	}
	int patientCounter = 0;

	patientFile.clear();
	patientFile.seekg(0);
	while (getline(patientFile,temporary)) {

		patientCounter++;
	}
	
	patientFile.close();
	
	cout << "\n\n\t\tPATIENT STRUCT\n\n";
	cout << "====================================================\n";
	cout << "ID\tUsername\tPassword\n";
	cout << "====================================================\n";
	for (int i = 0; i < patientCounter; i++) {
		cout << i<<"\t";
		cout << patientStruct[i].patientNameStruct << "\t\t";
		cout << patientStruct[i].patientPasswordStruct << "\n";
		
		
	}

	/*doctor struct*/
	struct doctor {
		string doctorNameStruct;
		string doctorPasswordStruct;

	}doctorStruct[10];


	ifstream doctorFile("doctorAccounts.txt");
	for (int i = 0; i < 10; i++)
		doctorFile >> doctorStruct[i].doctorNameStruct >> doctorStruct[i].doctorPasswordStruct;
	int doctorCounter = 0;

	doctorFile.clear();
	doctorFile.seekg(0);
	while (getline(doctorFile, temporary)) {

		doctorCounter++;
	}

	doctorFile.close();

	cout << "\n\n\t\tDOCTOR STRUCT\n\n";
	cout << "====================================================\n";
	cout << "ID\tUsername\tPassword\n";
	cout << "====================================================\n";
	for (int i = 0; i < doctorCounter; i++) {
		cout << i << "\t";
		cout << doctorStruct[i].doctorNameStruct << "\t\t";
		cout << doctorStruct[i].doctorPasswordStruct << "\n";

	}

	/*disease struct*/
	struct disease {
		string diseaseNameStruct;
		string doctorAddedStruct;

	}diseaseStruct[10];


	ifstream diseaseFile("Diseases.txt");
	for (int i = 0; i < 10; i++)
		diseaseFile >> diseaseStruct[i].diseaseNameStruct >> diseaseStruct[i].doctorAddedStruct;
	int diseaseCounter = 0;

	diseaseFile.clear();
	diseaseFile.seekg(0);
	while (getline(diseaseFile, temporary)) {

		diseaseCounter++;
	}

	diseaseFile.close();

	cout << "\n\n\t\tDISEASE STRUCT\n\n";
	cout << "====================================================\n";
	cout << "ID\tDisease Name\tDoctor Added\n";
	cout << "====================================================\n";
	for (int i = 0; i < diseaseCounter; i++) {
		cout << i << ".0\t";
		cout << diseaseStruct[i].diseaseNameStruct << "\t\t";
		cout << diseaseStruct[i].doctorAddedStruct << " \n";

	}


	return 0;

}

//Log IN /
char logIN(string username, string password) {
	string name;
	char proffesion;
	bool nameCorrect = false;
	cout << "what is ur proffesion (d/p): ";
	cin >> proffesion;
	if (proffesion == 'd') {
		ifstream doctorAccountsFile("doctorAccounts.txt");
		while (doctorAccountsFile >> name) {
			if (nameCorrect == true && name == password)
				return proffesion;

			if (name == username)
				nameCorrect = true;
		}
		doctorAccountsFile.close();

	}
	else if (proffesion == 'p') {
		ifstream patientAccountsFile("patientAccounts.txt");
		while (patientAccountsFile >> name) {
			if (nameCorrect == true && name == password)
				return proffesion;
			if (name == username)
				nameCorrect = true;
		}
		patientAccountsFile.close();
	}
}
// Register /
void reg(string username, string password) {
	char proffesion;
	cout << "what is ur proffesion (d/p): ";
	cin >> proffesion;
	if (proffesion == 'd') {
		ofstream doctorAccountsFile("doctorAccounts.txt", ios::app);
		doctorAccountsFile << endl << username << " " << password;
		doctorAccountsFile.close();
	}
	if (proffesion == 'p') {
		ofstream patientAccountsFile("patientAccounts.txt", ios::app);
		patientAccountsFile << endl << username << " " << password;
	}
}
// Add Disease /
void addDisease(string username) {

	string disease, generalinfo;
	cout << "enter the disease u want to add: ";
	cin >> disease;
	cout << "enter the disease general info: ";
	cin >> generalinfo;
	ofstream diseasesFile("Diseases.txt", ios::app);
	diseasesFile << endl << disease << " " << username;
	diseasesFile.close();
	disease += ".txt";
	ofstream diseaseFile(disease);
	diseaseFile << generalinfo << endl;
	diseaseFile.close();
	cout << "disease added\n";
	cout << "\n\n";
	system("pause");
}
// Remove Disease /
void removeDisease() {
	string diseaseNameInput, diseaseNameFile, lineFile;

	cout << "enter the disease u want deleted: ";
	cin >> diseaseNameInput;
	ifstream diseasesFile("Diseases.txt");
	ofstream newFile("Temp.txt", ios::app);
	while (diseasesFile >> diseaseNameFile) {
		getline(diseasesFile, lineFile);
		if (diseaseNameInput != diseaseNameFile) {
			newFile << diseaseNameFile << lineFile << endl;
		}
	}
	diseasesFile.close();
	newFile.close();
	remove("Diseases.txt");
	rename("Temp.txt", "Diseases.txt");

}
// Add Symptom /
void addSymptom(string username) {
	string diseaseNameInput, diseaseNameFile, diseaseURL, symptomName;
	int symptomAmount, counter = 0, userNo = 0, diseaseNo = 0;
	bool nameCorrect = false, access = false;
	cout << "enter the disease: ";
	cin >> diseaseNameInput;
	ifstream diseasesFile("Diseases.txt");

	while (diseasesFile >> diseaseNameFile) {
		if (nameCorrect == true && diseaseNameFile == username) {
			userNo = counter;
			if ((userNo - diseaseNo) == 1) {
				access = true;
				break;
			}
		}
		if (diseaseNameInput == diseaseNameFile) {
			nameCorrect = true;
			diseaseNo = counter;;
		}
		counter++;
	}
	diseasesFile.close();
	if (access == true) {
		cout << "how many symptoms are u adding? ";
		cin >> symptomAmount;
		diseaseURL = diseaseNameInput + ".txt";
		ofstream diseaseFile(diseaseURL, ios::app);
		cout << "enter symptoms: \n";
		for (int i = 0; i < symptomAmount; i++) {
			cin >> symptomName;
			diseaseFile << symptomName << " ";
		}
		diseaseFile.close();
		cout << "symptoms added...";
		cout << "\n\n";
		system("pause");
	}
	else {
		cout << "wrong doctor ";
		system("pause");
	}
}
// Show Symptoms of Disease /
void showSymptoms() {
	string diseaseName, diseaseURL, symptomNameFile, temp;
	cout << "enter the disease: ";
	cin >> diseaseName;
	diseaseURL = diseaseName + ".txt";
	ifstream diseaseFile(diseaseURL);
	getline(diseaseFile, temp);
	cout << "\n\n\t\tSYMPTOMS OF: " << diseaseName << "\n\n";
	cout << "====================================================\n";
	cout << "Symptoms\n";
	cout << "====================================================\n";
	while (diseaseFile >> symptomNameFile) {
		cout << symptomNameFile << endl;
	}
	cout << "\n\n";
	system("pause");
}
//Find your Disease /
void findDisease(string username) {
	string diseaseName, diseaseURL, generalInfo, symptomName, patientURL, patientName;
	int symptomsAmount, diseaseFileCounter = 0, counterSymptomsFile = 0, counterSymptomsPatient = 0, counterSymptomsFileDivider = 0, patientCounter = 0, patientSickCounter = 0;
	bool found = false;
	cout << "enter the number of symptoms u will enter: ";
	cin >> symptomsAmount;
	string* symptomsList = new string[symptomsAmount];
	cout << "Enter " << symptomsAmount << " elements" << endl;
	for (int i = 0; i < symptomsAmount; i++)
		cin >> symptomsList[i];
	ifstream diseasesFile("Diseases.txt");
	while (diseasesFile >> diseaseName) {
		counterSymptomsFile = 0;
		counterSymptomsPatient = 0;
		counterSymptomsFileDivider = 0;
		if (diseaseFileCounter % 2 == 0) {
			diseaseURL = diseaseName + ".txt";


			for (int i = 0; i < symptomsAmount; i++) {
				ifstream diseaseFile(diseaseURL);
				getline(diseaseFile, generalInfo);


				counterSymptomsFileDivider++;
				while (diseaseFile >> symptomName) {
					counterSymptomsFile++;


					if (symptomName == symptomsList[i]) {
						counterSymptomsPatient++;

					}
				}


				diseaseFile.close();
			}
			if ((counterSymptomsPatient * 100.0) / (counterSymptomsFile / counterSymptomsFileDivider) >= 80) {
				patientURL = diseaseName + "Patients.txt";
				ofstream patientFile(patientURL, ios::app);
				patientFile << endl << username;
				patientFile.close();
				ifstream patientFileNew(patientURL);
				while (getline(patientFileNew, patientName))
					patientSickCounter++;
				patientFileNew.close();
				ifstream patientsFile("patientAccounts.txt");
				while (getline(patientsFile, patientName))
					patientCounter++;
				patientsFile.close();
				found = true;
				cout << "u have " << diseaseName << " info: " << generalInfo << "\npercentage of patients sick with " << diseaseName << " " << (patientSickCounter * 100.0) / (patientCounter) << "%" << endl;
				cout << "\n\n";
				system("pause");

			}
		}
		diseaseFileCounter++;
	}
	if (found == false)
		cout << "no exact match ";
	system("pause");
	diseasesFile.close();
	delete[] symptomsList;
}

//display diseases

void display()
{

	ifstream diseasesFile("Diseases.txt");
	string diseaseName;
	int counter = 0;
	cout << "\n\n\t\tDISEASES LIST\n\n";
	cout << "====================================================\n";
	cout << "NAME\n";
	cout << "====================================================\n";
	while (diseasesFile >> diseaseName)
	{
		if (counter % 2 == 0)
			cout << diseaseName << endl;
		counter++;
	}
	diseasesFile.close();
	cout << "\n\n";
	system("pause");
}
/*View Diagnosis History*/
void viewHistory(string username) {
	ifstream diseasesFile("Diseases.txt");
	string diseaseName, diseaseURL, patientName;
	int counter = 0;

	while (diseasesFile >> diseaseName)
	{
		if (counter % 2 == 0) {
			diseaseURL = diseaseName + "Patients.txt";

			ifstream diseaseFile(diseaseURL);
			if (!diseaseFile)
				cout << "no patients have been dignosed with this disease yet\n";
			while (diseaseFile >> patientName) {

				if (patientName == username) {
					cout << "u had been diagnosed with " << diseaseName << "before\n";
				}
			}
			diseaseFile.close();
		}

		counter++;
	}
	system("pause");
	diseasesFile.close();
}

////view patients with a certain disease 
void viewPatients() {
	string diseaseNameInput, diseaseURL, patientNameFile;
	int counter = 0;
	cout << "Enter the disease name: ";
	cin >> diseaseNameInput;
	diseaseURL = diseaseNameInput + "Patients.txt";
	ifstream patientFile(diseaseURL);
	if (!patientFile)
		cout << "Invalid disease\n";
	cout << "\n\n\t\tPATIENTS OF: " << diseaseNameInput << "\n\n";
	cout << "====================================================\n";
	cout << "Patients\n";
	cout << "====================================================\n";
	while (patientFile >> patientNameFile) {

		cout << patientNameFile << endl;
	}
	patientFile.close();
	cout << "\n\n";
	system("pause");
}
//clear diagnosis history
void removeHistory(string username) {
	string diseaseNameFile, diseaseURL, patientNameFile;
	int counter = 0;
	ifstream diseasesFile("Diseases.txt");

	while (diseasesFile >> diseaseNameFile) {
		if (counter % 2 == 0) {
			ofstream tempFile("Temp.txt", ios::app);
			diseaseURL = diseaseNameFile + "Patients.txt";
			ifstream patientFile(diseaseURL);
			while (patientFile >> patientNameFile) {
				if (patientNameFile != username)
					tempFile << patientNameFile << endl;
			}
			tempFile.close();
			remove(diseaseURL.c_str());
			rename("Temp.txt", diseaseURL.c_str());
		}
		counter++;
	}
	diseasesFile.close();
}
