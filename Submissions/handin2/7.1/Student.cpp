#include "Student.hpp"
#include <cmath>



Student::Student(){};
Student::Student(std::string name, double fines, double fees){
    this->name = name;
    this->library_fines = fines;
    this->tuition_fees = fees;

};

	
double Student::MoneyOwed() const{
    return this->library_fines + this->tuition_fees;
};

void Student::SetLibraryFines(double amount){
    this->library_fines += std::abs(amount);
};

double Student::GetLibraryFines() const{
    return this->library_fines;
};

