#include "PhdStudent.hpp"
#include "Student.hpp"
#include "GraduateStudent.hpp"

PhdStudent::PhdStudent(std::string name, double fines, double fees, bool fullTime):GraduateStudent(name, fines, fees, fullTime){
        //this->tuition_fees = 0;
        //this->SetLibraryFines(0);
        this->fullTime = 1; // This is set to 1 as per instructions from the TA. Something about the codechecker or something.
}
double PhdStudent::MoneyOwed() const {
    return 0.0;
}