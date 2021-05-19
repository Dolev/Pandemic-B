#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"

#include "Researcher.hpp"
#include "Scientist.hpp"
#include "FieldDoctor.hpp"
#include "GeneSplicer.hpp"
#include "OperationsExpert.hpp"
#include "Dispatcher.hpp"
#include "Medic.hpp"
#include "Virologist.hpp"
#include "doctest.h"
#include <string>
#include <iostream>

using namespace std;
using namespace pandemic;


Board Test;

TEST_CASE(" Test my board: ") {//5
CHECK(Test.is_clean() == true);
Test[City::HoChiMinhCity] = 1;
Test[City::HoChiMinhCity] = 0;
CHECK(Test.is_clean() == true);
Test[City::HoChiMinhCity] = 2;
CHECK(Test.is_clean() == false);// false
Test.remove_cures();
//CHECK(Test.is_clean() == true);
Test[City::HoChiMinhCity] = 2;
Test[City::Essen] = 2;
CHECK(Test[City::Essen] ==  2 );//5
//CHECK(Test[City::HoChiMinhCity] == Test[City::Essen]);

}

Board Test1;
Board Test2;
Board Test3;

TEST_CASE(" Test my Players: ") {
Test1[City::Essen] = 2;
Test1[City::Bogota] = 2;
OperationsExpert OE {Test1, City::Bogota};//CHECK OperationsExpert
CHECK_NOTHROW(OE.discover_cure(Color::Red));
CHECK_NOTHROW(OE.build());
CHECK_NOTHROW(OE.take_card(City::Bogota));
CHECK(OE.role()=="OperationsExpert");//10
//std::cout<< OE.role() << endl;

Researcher R {Test1, City::Essen};
CHECK_NOTHROW(R.discover_cure(Color::Black));//CHECK Researcher 
CHECK(R.role()=="Researcher");

Virologist V {Test1, City::Essen};
CHECK_NOTHROW(V.treat(City::Essen));//CHECK Virologist
CHECK(V.role()=="Virologist");//14

Dispatcher D {Test1, City::HoChiMinhCity};
CHECK_NOTHROW(D.treat(City::HoChiMinhCity));//CHECK Virologist
CHECK(D.role()=="Dispatcher");//16

GeneSplicer g {Test1, City::Atlanta};
CHECK_NOTHROW(g.discover_cure(Color::Blue));//CHECK GeneSplicer 
CHECK(g.role() == "GeneSplicer");//18
CHECK_NOTHROW(g.take_card(City::Bogota));
CHECK(Test1.is_clean() == false);


Test2[City::Essen] = 5;
Test2[City::Bogota] = 3;
OperationsExpert OE2 {Test1, City::Essen};//CHECK OperationsExpert
CHECK_NOTHROW(OE2.take_card(City::Essen));
CHECK_NOTHROW(OE2.fly_shuttle(City::Essen));
}

TEST_CASE(" Test Exeptions: ") {
    Test3[City::Bogota] = 2;
    Test3[City::Atlanta] = 2;
    GeneSplicer g {Test3, City::Atlanta};
}
