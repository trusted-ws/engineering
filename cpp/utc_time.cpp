#include <string>
#include <iostream>
#include <time.h>
#include <sstream>

std::string getTime(int timezone) {
    time_t rawtime;
    struct tm *ptm;

    time(&rawtime);

    ptm = gmtime(&rawtime);
    
    char output[10];
    sprintf(output, "%2d:%02d", (ptm->tm_hour + timezone), ptm->tm_min);

    return output;
}

void printWorldTimes(void) {
    printf("GMT:\t\t%s\n", getTime(0).c_str());
    printf("BRAZIL:\t\t%s\n", getTime(-3).c_str());
    printf("BERLIN:\t\t%s\n", getTime(2).c_str());
    printf("NEW YORK:\t%s\n", getTime(-5).c_str());
    printf("MOSCOW:\t\t%s\n", getTime(3).c_str());

}


int main(void) {

    int tz;
    std::cout << "Enter with TIMEZONE: ";
    std::cin >> tz;

    std::cout << "Time: " << getTime(tz) << std::endl;

    std::cout << "\nWorld Wide Time:\n";
    printWorldTimes();

    return 0;
}
