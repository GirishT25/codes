#include <iostream>
#include <string>

#define MAX 10

using namespace std;

// Define structure for patient data
struct Patient {
    int patientID;
    string name,disease,histroy;

    // Add more fields as needed: age, medical history, etc.
};

void insert(Patient b[][2]) {
    int s, t;
    do {
        Patient newPatient;
        cout << "\nEnter Patient ID: ";
        cin >> newPatient.patientID;
        cout << "Enter Patient Name: ";
        cin >> newPatient.name;
        cout<<"Enter the patient disease :";
        cin>>newPatient.disease;
        cout<<"Enter the medical history of patient :";
        cin>>newPatient.histroy;
        s = newPatient.patientID % MAX;
        if (b[s][0].patientID == -1)
            b[s][0] = newPatient;
        else {
            do {
                cout << "True Collision Occurs";
                if (b[s][1].patientID == -1 || s == b[s][1].patientID) {
                    t = s;
                    while (b[s][0].patientID != -1) {
                        s = (s + 1) % MAX;
                        if (s == t) {
                            cout << "Overflow";
                            break;
                        }
                    }
                    if (s != t && b[s][0].patientID == -1) {
                        b[s][0] = newPatient;
                        b[t][1].patientID = s;
                    }
                    break;
                } else
                    s = b[s][1].patientID;
            } while (true);
        }
        char choice;
        cout << "\nDo you want to insert another patient? (y/n): ";
        cin >> choice;
        if (choice != 'y' && choice != 'Y')
            break;
    } while (true);
}

void display(Patient b[][2]) {
    cout << "\nINDEX\tPATIENT ID\tPATIENT NAME\tHISTORY \t DISEASE \tCHAIN";
    for (int i = 0; i < MAX; i++) {
        cout << "\n" << i;
        if (b[i][0].patientID != -1) {
            cout << "\t" << b[i][0].patientID;
            cout << "\t" << b[i][0].name;
            cout<<"\t "<<b[i][0].histroy;
            cout<<"\t "<<b[i][0].disease;
            if (b[i][1].patientID != -1)
                cout << "\t" << b[i][1].patientID;
        } else {
            cout << "\tNULL";
        }
    }
    cout<<endl;
}

void deletePatient(Patient b[][2], int patientID) {
    int s = patientID % MAX;
    if (b[s][0].patientID == patientID) {
        b[s][0].patientID = -1;
        b[s][0].name = "";
    } else if (b[s][1].patientID == patientID) {
        b[s][1].patientID = -1;
    } else {
        int prev = s;
        s = b[s][1].patientID;
        while (s != -1 && b[s][0].patientID != patientID) {
            prev = s;
            s = b[s][1].patientID;
        }
        if (s != -1) {
            b[prev][1].patientID = b[s][1].patientID;
            b[s][0].patientID = -1;
            b[s][0].name = "";
            b[s][1].patientID = -1;
        }
    }
}

void searchPatient(Patient b[][2], int patientID) {
    int s = patientID % MAX;
    if (b[s][0].patientID == patientID) {
        cout << "Patient Found:\n";
        cout << "Patient ID: " << b[s][0].patientID << "\n";
        cout << "Patient Name: " << b[s][0].name << "\n";
    } else if (b[s][1].patientID == patientID) {
        cout << "Patient Found:\n";
        cout << "Patient ID: " << b[s][1].patientID << "\n";
        cout << "Patient Name: " << b[s][1].name << "\n";
    } else {
        int temp = b[s][1].patientID;
        while (temp != -1 && b[temp][0].patientID != patientID) {
            temp = b[temp][1].patientID;
        }
        if (temp != -1) {
            cout << "Patient Found:\n";
            cout << "Patient ID: " << b[temp][0].patientID << "\n";
            cout << "Patient Name: " << b[temp][0].name << "\n";
        } else {
            cout << "Patient with ID " << patientID << " not found.\n";
        }
    }
}

void updatePatient(Patient b[][2], int patientID) {
    int s = patientID % MAX;
    if (b[s][0].patientID == patientID) {
        cout << "Enter new Patient Name: ";
        cin >> b[s][0].name;
        cout << "Enter new Patient Disease: ";
        cin >> b[s][0].disease;
        cout << "Enter new Medical History: ";
        cin >> b[s][0].histroy;
        cout << "Patient information updated successfully.\n";
    } else if (b[s][1].patientID == patientID) {
        cout << "Enter new Patient Name: ";
        cin >> b[s][1].name;
        cout << "Enter new Patient Disease: ";
        cin >> b[s][1].disease;
        cout << "Enter new Medical History: ";
        cin >> b[s][1].histroy;
        cout << "Patient information updated successfully.\n";
    } else {
        int temp = b[s][1].patientID;
        while (temp != -1 && b[temp][0].patientID != patientID) {
            temp = b[temp][1].patientID;
        }
        if (temp != -1) {
            cout << "Enter new Patient Name: ";
            cin >> b[temp][0].name;
            cout << "Enter new Patient Disease: ";
            cin >> b[temp][0].disease;
            cout << "Enter new Medical History: ";
            cin >> b[temp][0].histroy;
            cout << "Patient information updated successfully.\n";
        } else {
            cout << "Patient with ID " << patientID << " not found.\n";
        }
    }
}

int main() {
    // Your main function remains the same, with the addition of the update option in the menu
    Patient hashTable[MAX][2];
    for (int i = 0; i < MAX; i++) {
        hashTable[i][0].patientID = -1;
        hashTable[i][1].patientID = -1;
    }

    char option;
    do {
        cout << "\nMedical Record Management System\n";
        cout << "1. Insert Patient\n";
        cout << "2. Display Patient Records\n";
        cout << "3. Search Patient\n";
        cout << "4. Update Patient Information\n"; // New option
        cout << "5. Delete Patient\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> option;

        switch (option) {
            case '1':
                insert(hashTable);
                break;
            case '2':
                cout << "\nPatient Records:\n";
                display(hashTable);
                break;
            case '3': {
                int patientIDToSearch;
                cout << "\nEnter the Patient ID to search: ";
                cin >> patientIDToSearch;
                searchPatient(hashTable, patientIDToSearch);
                break;
            }
            case '4': {
                int patientIDToUpdate;
                cout << "\nEnter the Patient ID to update: ";
                cin >> patientIDToUpdate;
                updatePatient(hashTable, patientIDToUpdate);
                break;
            }
            case '5': {
                int patientIDToDelete;
                cout << "\nEnter the Patient ID to delete: ";
                cin >> patientIDToDelete;
                deletePatient(hashTable, patientIDToDelete);
                break;
            }
            case '6':
                cout << "\nExiting...\n";
                break;
            default:
                cout << "\nInvalid choice. Please try again.\n";
        }
    } while (option != '6');

    return 0;
}