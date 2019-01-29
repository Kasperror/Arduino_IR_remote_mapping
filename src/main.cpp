//author: Jakub Kasperek - program to create a simple library for any Infra-red remote transmitter for Arduino projects

#include <iostream>
#include "remote.h"
#include "file_management.h"

void hello();

using namespace std;

int main()
{
    hello();
    file_management remote_map;
    Remote remote;
    remote_map.connect_button_to_code( remote.get_all_buttons_names(), remote_map.read_data() );
    cin.ignore(1000, '\n');
    cin;
    return 0;
}

void hello(){

    cout << "Hello fellow Arduino lover before going further read README file \nwhere you can find instructions to use this program properly\n\n";
    cout << "If you're lazy just put attached code into Arduino board and connect it \nas on attached picture\n\n";
    cout << "Names you will give to your buttons should be unique and consist only of \nalphanumeric and '_' characters\nalso underscore can't be the first character of name\n\n";
    cout << "Let's START \n\n";
}
