#include <iostream>
#include <fstream>
#include <cstdio>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
using namespace std;
bool directoryExists(const char* dirName) {
    struct stat info;
    return (stat(dirName, &info) == 0 && (info.st_mode & S_IFDIR));
}
bool fileExists(const char* fileName) {
    struct stat info;
    return (stat(fileName, &info) == 0 && !(info.st_mode & S_IFDIR));
}
void createDirectory(const char* dirName) {
    if (!directoryExists(dirName)) {
        mkdir(dirName, 0777);
    }
}
int main() {
    int q = 0;
    int choice;
    int subChoice;  

    const char* dirName = "statuspr";
    const char* projectFileName = "statuspr/projetstatus.txt";
    const char* activitiesFileName = "statuspr/activitiesstatus.txt";
    const char* notesFileName = "statuspr/notes.txt";

    createDirectory(dirName);

    ofstream projectOutFile(projectFileName);
    ofstream activitiesOutFile(activitiesFileName);
    ofstream notesOutFile(notesFileName);
    system("clear");
    cout << "+++++++++++++ Welcome +++++++++++++" << endl;
    sleep(3);
    system("clear");
    do {
        cout << "++Choose an option: \n" << endl;
        cout << "+ Project_status (1)\n+ Activities_status (2)\n+ Notes (3)\n+ Quit (4)" << endl;
        cin >> choice;
        FILE *ptr = nullptr;
        string input;
        char buffer[1000];
        switch (choice) {
            case 1:
                system("clear");
                cout << "++ Project status\n(1) READ\n(2)EDIT\n" << endl;
                cin >> subChoice;
                    if (subChoice == 1){
                            ptr = fopen(projectFileName, "r");
                        if (ptr == NULL) {
                            cout << "no file exists" << endl;
                        } else {
                            system("clear");
                            while (fgets(buffer, sizeof(buffer), ptr) != NULL) {
                                cout << buffer;
                                cout << endl;
                            }
                            fclose(ptr);
                        }
                        } else {
                            ptr = fopen(projectFileName, "a");
                            if (ptr == NULL) {
                                cout << "no file exists" << endl;
                            } else {
                                system("clear");
                                cout << "Enter text to write to the file (type 'exit' to finish):" << endl;
                                while (true) {
                                    getline(cin, input);
                                    if (input == "exit") {
                                        break;
                                    }
                                    fprintf(ptr, "%s\n", input.c_str());
                                }
                                fclose(ptr);
                                cout << "Data written to " << projectFileName << " successfully." << endl;
                            }
                        }
                break;
            case 2:
            system("clear");
            cout << "++ Activities_Status\n(1) READ\n(2)EDIT\n" << endl;
            cin >> subChoice;
                if (subChoice == 1){
                    ptr = fopen(activitiesFileName, "r");
                    if (ptr == NULL) {
                        cout << "no file exists" << endl;
                    } else {
                        system("clear");
                        while (fgets(buffer, sizeof(buffer), ptr) != NULL) {
                            cout << buffer;
                            cout << endl;
                        }
                        fclose(ptr);
                    }
                    } else {
                        
                        ptr = fopen(projectFileName, "a");
                        if (ptr == NULL) {
                            cout << "no file exists" << endl;
                        } else {
                            system("clear");
                            cout << "Enter text to write to the file (type 'exit' to finish):" << endl;
                            while (true) {
                                getline(cin, input);
                                if (input == "exit") {
                                    break;
                                }
                                fprintf(ptr, "%s\n", input.c_str());
                            }
                            fclose(ptr);
                            cout << "Data written to " << projectFileName << " successfully." << endl;
                        }
                    }
                break;
            case 3:
                system("clear");
                cout << "++ Notes\n(1) READ\n(2)EDIT\n" << endl;
                cin >> subChoice;
                    if (subChoice == 1){
                    ptr = fopen(notesFileName, "r");
                    if (ptr == NULL) {
                        cout << "no file exists" << endl;
                    } else {
                        system("clear");
                        while (fgets(buffer, sizeof(buffer), ptr) != NULL) {
                            cout << buffer;
                            cout << endl;
                        }
                        fclose(ptr);
                    }
                    } else {
                        ptr = fopen(notesFileName, "a");
                        if (ptr == NULL) {
                            cout << "no file exists" << endl;
                        } else {
                            system("clear");
                            cout << "Enter text to write to the file (type 'exit' to finish):" << endl;
                            while (true) {
                                getline(cin, input);
                                if (input == "exit") {
                                    break;
                                }
                                fprintf(ptr, "%s\n", input.c_str());
                            }
                            fclose(ptr);
                            cout << "Data written to " << notesFileName << " successfully." << endl;
                        }
                    }
                break;
            case 4:
                system("clear");
                cout << "Goodbye!" << endl;
                sleep(3);
                q = 1;
                system("clear");
                break;
            default:
                system("clear");
                cout << "Invalid option! \n" << endl;
                system("clear");
                break;
        }
    } while (q != 1);
    return 0;
}
