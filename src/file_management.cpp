#include "file_management.h"

using namespace std;


vector<string> file_management::read_data(){

        //vector to store IR codes of buttons
        vector<string> codes_vec;
        ifstream arduino_codes("codes.txt");

            if(arduino_codes.fail()){
                cerr << "Error opening codes.txt file check if it exists in same folder " << endl;
		cin.ignore(1000, '\n');
		cin;
                exit(1);
            }

        //getting every line separately and pushing into vector
        string code_line;
        while( getline(arduino_codes, code_line) && code_line.length() != 0 )
            codes_vec.push_back(code_line);

        return codes_vec;
}

void file_management::connect_button_to_code(std::vector<std::string> button_names, std::vector<std::string> IR_codes){

        remove("remote_map.txt");
        remove("remote_map.h");
        cout << "!!! Now copy the Arduino Serial output into \"codes.txt\" file!!!\n\n";
        cout << "Double-press Enter when you're done\n\n";
        cin.ignore(1000, '\n');
        cin;
        cin.ignore();
        cin;

        //error handling if sizes of vectors are different
        if( button_names.size() != IR_codes.size()){

            cerr << "Sorry number of collected names is different from numbers of IR codes \ncheck if codes copied to codes.txt file are correct and restart program\n";
	    cin.ignore(1000, '\n');
	    cin;
            exit(1);

        }
        ofstream remote_map("remote_map.txt");

        remote_map << comment_part1 << comment_part2 << comment_part3 << comment_part4;
        remote_map << "class Remote{ \n" << "   public: \n";

        for( int i = 0; i < button_names.size(); ++i ){
        remote_map << "const unsigned long var_"<< button_names[ i ] <<" = " << IR_codes[ i ] << ";" << '\n';
        remote_map << "constexpr unsigned long b_" << button_names[ i ] <<"() const{ return var_" << button_names[ i ] << ";}" << '\n';
        }

        remote_map << "};";
        remote_map.close();
        rename("remote_map.txt", "remote_map.h");
        cout << "Okay-dokey your remote map is waiting in \"remote_map.h\" file have fun " << endl;
}





