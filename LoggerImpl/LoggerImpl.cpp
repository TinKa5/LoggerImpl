#include <iostream>
#include "Logger.h"
#include "Test.h"

using namespace std;

int main()
{
    Logger* logger1 = Logger::getLogger("log3.csv");  //to file
    //Logger* logger1 = Logger::getLogger();  // to console
    
    *logger1 << "LOGGER first line";

    Test test;
    test.testLogger();
   
    *logger1 << "LOGGER second line";

    logger1->~Logger();

}