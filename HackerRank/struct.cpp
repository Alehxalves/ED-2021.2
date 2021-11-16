#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct student{
    int age;
    string first_name;
    string last_name;
    int standard_student;
};


int main() {
    student student1;
    cin >> student1.age >> student1.first_name >> student1.last_name >> student1.standard_student;
    cout << student1.age << " " << student1.first_name << " " << student1.last_name << " " << student1.standard_student << endl;
    return 0;
}