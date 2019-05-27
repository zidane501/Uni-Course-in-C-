#include "Student.hpp"
#include "GraduateStudent.hpp"
#include "PhdStudent.hpp"

void student(){
    //"distance" finds elements between indices in iterator 
    //lowerbound
/*
    Student s( "Jens", 35, 100);

    std::cout << "s.name " << s.name << std::endl;
    std::cout << "s.GetLibraryFines " << s.GetLibraryFines() << std::endl;
    std::cout << "s.tuition_fees " << s.tuition_fees << std::endl;
    std::cout << "s.MoneyOwed " << s.MoneyOwed() << std::endl;
    s.SetLibraryFines(10);
    std::cout << "s.GetLibraryFines " << s.GetLibraryFines() << std::endl;
*/
/*
    GraduateStudent Gs( "Per", 20, 40, true);

    std::cout << "Gs.name " << Gs.name << std::endl;
    std::cout << "Gs.fullTime " << Gs.fullTime << std::endl;
    std::cout << "Gs.GetLibraryFines " << Gs.GetLibraryFines() << std::endl;
    std::cout << "Gs.tuition_fees " << Gs.tuition_fees << std::endl;
    std::cout << "Gs.MoneyOwed " << Gs.MoneyOwed() << std::endl;
    Gs.SetLibraryFines(10);
    std::cout << "Gs.GetLibraryFines " << Gs.GetLibraryFines() << std::endl;
*/
    PhdStudent phdS( "Per", 20, 40, true);

    std::cout << "phdS.name " << phdS.name << std::endl;
    std::cout << "phdS.fullTime " << phdS.fullTime << std::endl;
    std::cout << "phdS.GetLibraryFines " << phdS.GetLibraryFines() << std::endl;
    std::cout << "phdS.tuition_fees " << phdS.tuition_fees << std::endl;
    std::cout << "phdS.MoneyOwed " << phdS.MoneyOwed() << std::endl;
    phdS.SetLibraryFines(10);
    std::cout << "phdS.GetLibraryFines " << phdS.GetLibraryFines() << std::endl;

}


int main(int argc, const char** argv) {

    student();


    return 0;
}