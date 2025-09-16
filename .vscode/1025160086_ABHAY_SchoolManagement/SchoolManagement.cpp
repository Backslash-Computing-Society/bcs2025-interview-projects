#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;
// ----------------- student.h code -----------------
class Student {
private:
string name;
int age;
int roll;
public:
void input();
void display();
void saveToFile();
Student() {}
Student(string n, int a, int r) : name(n), age(a), roll(r) {}
};
// ----------------- student.cpp code -----------------
void Student::input() {
cout << "Enter name: ";
cin >> name;
cout << "Enter age: ";
cin >> age;
cout << "Enter roll number: ";
cin >> roll;
}
void Student::display() {
cout << "Name: " << name << endl;
cout << "Age: " << age << endl;
cout << "Roll No: " << roll << endl;
}
void Student::saveToFile() {
ofstream fout("students.txt", ios::app);
if (fout.is_open()) {
fout << name << "," << age << "," << roll << "\n";
fout.close();
} else {
cout << "Error: Cannot open file to save student.\n";
}
}
// ----------------- main.cpp code -----------------
int main() {
vector<Student> students;
int choice;
// Load from file
ifstream fin("students.txt");
if (fin.is_open()) {
string line;
while (getline(fin, line)) {
stringstream ss(line);
string name;

int age, roll;
getline(ss, name, ',');
ss >> age;
ss.ignore(1);
ss >> roll;
Student s(name, age, roll);
students.push_back(s);
}
fin.close();
}
do {
cout << "\n--- Menu ---\n";
cout << "1. Add Student\n";
cout << "2. Display Students\n";
cout << "3. Exit\n";
cout << "Enter choice: ";
cin >> choice;
switch (choice) {
case 1: {
Student s;
s.input();
students.push_back(s);
s.saveToFile();
break;
}
case 2: {
for (auto &s : students) {
s.display();
cout << "--------------\n";
}
break;
}
case 3:
cout << "Exiting...\n";
break;
default:
cout << "Invalid choice.\n";
}
} while (choice != 3);
return 0;
}