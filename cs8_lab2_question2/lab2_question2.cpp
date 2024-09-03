//Mohammad Shirmohammadi
//10404080
//8/29/24
//lab 2 question 2

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
#include <set>
#include <map>

using namespace std;

class Student {
private:
    string name;
    vector<string> electiveList;
public:
    // Constructor
    Student(const string &studentName, const vector<string> &electives) {
        name = studentName;
        electiveList = electives;
    }

    // Setters
    void setName(const string &studentName) {
        name = studentName;
    }

    void setElectiveList(const vector<string> &electives) {
        electiveList = electives;
    }

    // Getters
    string getName() const {
        return name;
    }

    vector<string> getElectiveList() const {
        return electiveList;
    }

    // Function to print student details
    void printStudentInfo() const {
        cout << left << setw(15) << name;
        for (int i = 0; i < electiveList.size(); ++i) {
            cout << setw(12) << electiveList[i];
        }
        cout << endl;
    }
};

int main() {
    string filename = "student.txt";
    ifstream file(filename);
    if (!file) {
        cerr << "Error opening file: " << filename << endl;
        return 1; // Exit with error code
    }

    string name;
    string class1, class2, class3;
    vector<Student> students;

    // Reading the file and storing student data
    while (file >> name >> class1 >> class2 >> class3) {
        vector<string> electives;
        electives.push_back(class1);
        electives.push_back(class2);
        electives.push_back(class3);
        
        Student student(name, electives);
        students.push_back(student);
    }

    // Print all students' information
    cout << "============= Student List ==============" << endl; 
    cout << "-----------------------------------------" << endl; 
    for (int i = 0; i < students.size(); ++i) {
        students[i].printStudentInfo();
    }

    // Map to store electives and corresponding students
    map<string, set<string> > electiveMap;  // Notice the space between '>>'

    // Populate the map with classes and associated students
    for (int i = 0; i < students.size(); ++i) {
        vector<string> electives = students[i].getElectiveList();
        for (int j = 0; j < electives.size(); ++j) {
            electiveMap[electives[j]].insert(students[i].getName());
        }
    }

    // Print all unique electives and the students enrolled in them
    cout << endl;
    cout << "==================== Elective List =====================" << endl;
    cout << "--------------------------------------------------------" << endl;

    for (map<string, set<string> >::iterator it = electiveMap.begin(); it != electiveMap.end(); ++it) {
        cout << left << "[" << setw(11) << it->first << "] : ";
        set<string> studentSet = it->second;
        int count = 0;
        for (set<string>::iterator sit = studentSet.begin(); sit != studentSet.end(); ++sit) {
            cout << *sit;
            if (++count < studentSet.size()) {
                cout << ", ";
            }
        }
        cout << endl;
    }

    return 0;
}
