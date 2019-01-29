#ifndef REMOTE_H
#define REMOTE_H
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Remote
{
    public:
        Remote(){};
        ~Remote(){};

        vector<string> get_all_buttons_names();


    private:
        string get_button_name();
        vector<string> button_names_vec;
        bool ask_end();
        size_t is_input_correct( string name );

};



#endif // REMOTE_H
