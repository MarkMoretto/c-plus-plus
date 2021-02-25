
//! Purpose:    Solution for while loop question on Stackoverflow.com
//! url:        https://stackoverflow.com/questions/66361558/c-y-or-n-to-continue
//! Date:       2021-02-24


#include <iostream>

using namespace std;

int main() {

    bool keep_going = true;

    while (keep_going) {
        // keep_going = false;

        // float fahr, cel;
        float fahr;
        float cel;
        char option;
        char answer;

        cout << "Choose from following option 1 or 2:" << endl;
        cout << "1. Celsius to Fahrenheit." << endl;
        cout << "2. Fahrenheit to Celsius." << endl;

        cin >> option;

        //! Evaluates if digit was entered
        if (isdigit(option)) {
          
            //! Evaluates option value
            if (option == '1') {
                cout << "Enter the temperature in Celsius: ";
                cin >> cel;

                fahr = (1.8 * cel) + 32.0;
                cout << "\nTemperature in degree Fahrenheit: " << fahr << " F" << endl;

                // cout << "\n Continue? Y or N";
                // cin >> answer;
                
                // if (answer == 'Y') {
                //     keep_going = true;
                // } else if (answer == 'N') {
                //     keep_going = false;
                // }
            }
        
            //Option for converting Fahrenheit into Celsius
            else if (option == '2') {
                cout << "Enter the temperature in Fahrenheit: ";
                cin >> fahr;

                cel = (fahr - 32) / 1.8; //Temperature conversion formula
                cout << "\nTemperature in degree Celsius: " << cel << " C" << endl;


                // cout << "\n Continue? Y or N";
                // cin >> answer;
                
                // if (answer == 'Y') {
                //     keep_going = true;
                //     break;
                // } else if (answer == 'N') { 
                //     keep_going = false;
                //     break;
                // }
            }


            //! Still in digit mode, asks if user wishes
            //! to continue.

            cout << "\n Continue? Y or N: ";
            cin >> answer;

            //! No need for "Y"; we can just check one side
            if (answer == 'n' || answer == 'N') {
                keep_going = false;
            }  

        } else {
            //! Digit was not entered.
            cout << "Error please input a number" << endl;
            keep_going = true;
        }
    }

    return 0;

}

