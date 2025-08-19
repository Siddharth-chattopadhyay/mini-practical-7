#include<iostream>
#include<vector>
using namespace std;

class Student{
        string name;
    public:
        int id;
        
        Student(int id, string name){
            this -> id = id;
            this -> name = name;
        }

        void displayData(){
            cout << "Name = " << this -> name << endl;
            cout << "Id = " << this -> id << endl;
        }
};

int main(){
    vector<Student> StudentData;
    int choice = -1, id, indexSelect;
    string name;
    do {
        cout << "### Student Management System ###" << endl;
        cout << "Menu:" << endl;
        cout << "1. Add students to a list" << endl;
        cout << "2. Display all students" << endl;
        cout << "3. Remove student by ID" << endl;
        cout << "4. Find student by ID" << endl;
        cout << "0. Exit" << endl;
        cout << "Your choice: ";
        cin >> choice;
    
        switch (choice){
            case 0:
                cout << "Thank yuu for using Student Management System" << endl;
                break;

            case 1:
            indexSelect = -1;
                cout << "Enter ID: ";
                cin >> id;
                for (int i = 0; i < StudentData.size(); i++){
                    if (StudentData[i].id == id){
                        indexSelect = i;
                    }
                }

                if (indexSelect != -1){
                        cout << "Student with id (" << id << ") already exists" << endl;
                }
                else {
                        cout << "Enter name: ";
                        cin >> name;
                        StudentData.push_back(Student(id, name));
                        cout << "Added student (" << name << ")" << " to vector" << endl;
                    }
                break;

            case 2:
                cout << "Displaying all students:" << endl;
                for (int i = 0; i < StudentData.size(); i++){
                    cout << "--------------------------------" << endl;
                    StudentData[i].displayData();
                }
                cout << "--------------------------------" << endl;
                cout << "Student Data end" << endl;
                break;

            case 3:
                cout << "Enter student ID: ";
                cin >> id;

                for (int i = 0; i < StudentData.size(); i++){
                    if (StudentData[i].id == id) {
                        while(i < StudentData.size() - 1) { // 1
                            StudentData[i] = StudentData[i + 1]; // It might show a warning (not error)
                            i++;
                        }
                        StudentData.pop_back();
                        i = StudentData.size();
                        cout << "Deleted student by id (" << id << ')' << endl;
                    }
                    else if (i+1 >= StudentData.size()){
                        cout << "Unable to find student by id (" << id << ')' << endl;
                    }
                }
                break;

            case 4:
                cout << "Enter student ID: ";
                cin >> id;

                for (int i = 0; i < StudentData.size(); i++){
                    if (StudentData[i].id == id) {
                        cout << "Found student data:" << endl;
                        cout << "--------------------------------" << endl;
                        StudentData[i].displayData();
                        cout << "--------------------------------" << endl;
                        i = StudentData.size();
                    }
                    else if (i+1 >= StudentData.size()){
                        cout << "Unable to find student by id (" << id << ')' << endl;
                    }
                }
                break;
    
            default:
                cout << "Invalid choice ... try again" << endl;
        }
    } while(choice != 0);

    return 0;
}