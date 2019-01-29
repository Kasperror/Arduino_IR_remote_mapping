#include "remote.h"
#include <iostream>
#include <string>

using namespace std;


string Remote::get_button_name(){

    string name;
    //it will loop until user enters non-empty input
    do{
    cout << "Enter button name " << endl << endl;
    getline(cin, name);
    }
    while( name.length() == 0 );

        //if the input contains incorrect characters they are replaced with '_'
        string old_name = name;
        bool check = false;
        while(is_input_correct(name) != string::npos ){


            name[is_input_correct(name)] = '_';
            check = true;
        }
        //name for non-global variable cant start with underscore in c++
        if(name[0] == '_'){
            name[0] = '0';
            check = true;
        }

        if(check)
            cout <<"Name you entered was incorrect and changed from \""<<old_name<<"\" to \""<<name<<"\" "<< endl << endl;
        //if name already exists in vector
        check = false;
        for( int i = 0; i < button_names_vec.size() ; ++i ){
            if( button_names_vec[i] == name ){
                check = true;
                break;
            }
        }
            if(check){
                old_name = name;
                name = name + "_0x1";
                cout << "Name already existed and was changed from \""<<old_name<<"\" to \""<<name<<"\" "<< endl << endl;
            }



    button_names_vec.push_back(name);

    cout << "Now press this button until you see some code appear \nin Arduino Serial and press Enter" << endl << endl;
    cin ;
    return name;

}


bool Remote::ask_end(){

    //error handling when user entered a string instead of pressing enter after get_button_name
    cin.ignore( 1000, '\n' );

    while(1){
        char answer;
        cout << "More buttons to map? [y/n] " << endl;
        cin >> answer;
        cin.ignore();
        if( answer == 'y' )
            return false;
        else if( answer == 'n' )
            return true;
        else
            cout << "Wrong input I'll ask you one more time" << endl;
    }
}



vector<string> Remote::get_all_buttons_names(){

            do
                get_button_name();
            while( !ask_end() );

            return button_names_vec;
}


size_t Remote::is_input_correct(string name){

        size_t found = name.find_first_not_of("qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM1234567890_");

        return found;
}






