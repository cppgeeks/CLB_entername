#include "Print.h"

int main(int argc, char ** argv){
    Print* print = new Print();

    print->Run();

    print->Quit();

    delete print;

    return 0;
}