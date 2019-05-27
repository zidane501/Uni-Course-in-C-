#include "PhdStudent.hpp"
#include "Student.hpp"
#include "GraduateStudent.hpp"

PhdStudent::PhdStudent(std::string name, double fines, double fees, bool fullTime):GraduateStudent(name, fines, fees, fullTime){
        //this->tuition_fees = 0;
        //this->SetLibraryFines(0);
        this->fullTime = 1;
}
double PhdStudent::MoneyOwed() const {
    return 0.0;
}