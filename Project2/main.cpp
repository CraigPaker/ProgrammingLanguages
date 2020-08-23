// Craig Parker
// 2020-07-28
// CS-210-H6018

#include <iostream>
#include <ios>
#include <iomanip>
#include <windows.h>
#include <stdexcept>
using namespace std;

//this includes the class I wrote
#include <Investment.h>

//this function prints the border and title for the user
void InputTitle(){

       //Top border code
////////////////////////////////////////////////////////////////////
    cout << setfill('*');
    cout << setw(52) << left << "" << endl;
////////////////////////////////////////////////////////////////////

    //title code
////////////////////////////////////////////////////////////////////
    cout << setw(31) << right << " Data Input ";
    cout << setw(21) << left << "" << endl;
////////////////////////////////////////////////////////////////////

}//end InputTitle

//this outputs the portfolio expectations
// w_o = with\without deposits
void OutPutTitle(int w_o){

    if(w_o == 0){

        //title code without deposits
    ////////////////////////////////////////////////////////////////
    cout << endl;
    cout << setfill(' ');
    cout << setw(49) << right << " Balance & Interest Without Monthly Deposits ";
    cout << setw(3) << left << "" << endl;
    ////////////////////////////////////////////////////////////////

    }
    else if(w_o == 1){

        //title code with deposits
    ////////////////////////////////////////////////////////////////
    cout << endl;
    cout << setfill(' ');
    cout << setw(47) << right << " Balance & Interest With Monthly Deposits ";
    cout << setw(5) << left << "" << endl;
    ////////////////////////////////////////////////////////////////

    }

        //Title layout (standard for both w_o options)
    /////////////////////////////////////////////////////////////////
    cout << setfill('=');
    cout << setw(52) << left << "" << endl;
    cout << setfill(' ');
    cout << setw(43) << left << "   Year |:| Year End Balance |:| Year End Interest";
    cout << setw(8) << left << "" << endl;
    cout << setfill('~');
    cout << setw(52) << left << "" << endl;
    ///////////////////////////////////////////////////////////////////

}//end OutPutTitle

//this function calculates the investments and prints out the formatted output
void Calculate(float t_initial, float t_deposit, float t_rate, int t_years){
    float balance = t_initial;
    float interest = t_initial * t_rate;
    float compound = 0.0;

    //this prints the title without deposits
    //by calling the correct function and passing the correct value
    OutPutTitle(0);

    //this loop calculates and prints the yearly values
    //without monthly payments
    for(int i = 1; i <= t_years; i++){

            //the loop shows projected growth
            //i.e. one year from now
            balance = balance + interest;

            //This prints out the calculated values
            cout << setfill(' ');
            cout << setw(4) << right << i;
            cout << setw(19) << right << '$' << balance;
            cout << setw(19) << right << '$' << interest;
            cout << endl;

            //this calculates the given values
            interest = balance * t_rate;

    }

    //this prints the title including monthly deposits
    //by calling the correct function
    OutPutTitle(1);

    balance = t_initial;

    //this loop calculates and prints the yearly values
    //with monthly payments
    for(int i = 1; i <= t_years; i++){

            //this resets annual compound interest
            compound = 0;

            //the loop shows projected growth in 12 months
            //i.e. one year from now
            for(int j = 1; j <= 12; j++){
                interest = (balance + t_deposit) * (t_rate / 12);
                balance = balance + t_deposit + interest;

                compound = compound + interest;

            }

            //This prints out the calculated values
            cout << setfill(' ');
            cout << setw(4) << right << i;

            cout << setw(14) << right << '$' << balance;

            /*
            I could not find a way to
            dynamically format the output
            to handle the changing variable size


            the first two columns were not an issue.
            the differing size of the account balances made the subsequent
            spaces irregular, and there for the following column was
            irregular too too
            */

            if(balance < 10){

                cout << setw(21) << right << '$' << compound;
            }
             else if(balance < 100){

                cout << setw(20) << right << '$' << compound;
            }
            else if(balance < 1000){

                cout << setw(20) << right << '$' << compound;
            }
            else if(balance < 10000){

            cout << setw(19) << right << '$' << compound;

            }
            else if(balance < 100000){

            cout << setw(18) << right << '$' << compound;

            }
            else if(balance < 1000000){

            cout << setw(17) << right << '$' << compound;

            }

            cout << endl;
    }//end for loop
}//end Calculate function

//this is a callable function which can
//calculate investments over years using flexible variables
void InvestmentCalculator(){

//////////////////////////////////////////////////////////////////
//Console color code
///////////////////////////////////////////////////////////////////

    //from what I read this my be OS-specific to Windows
    //OS = Operating System
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 11);

    //This creates an account-object
    Investment account;

    //this prints the title
    InputTitle();

    //DataInput code
///////////////////////////////////////////////////////////////////

    //this is a temp-value holder for  input
    int number = 0;

    //this is a temp-value holder for input
    float floats = 0.0;

    //this will allow the user to leave the program
    //by breaking the loop
    bool stop = false;

    //this line of code and the following "try" statement will
    //prevent invalid input from causing an infinite loop
    std::cin.exceptions(std::ios_base::failbit);

    try{
        while(stop == false){

            //offering the user an escape from the program/app
            //Ihe check needs to be within the loop for it to
            //break the loop using "break;"
            cout << endl << "Enter a negative number to exit" << endl;

            //this prompts the user for the initial investment amount
            cout << "Please enter the initial investment: $";
            cin >> floats;

            if(floats <= -1){
                    break;
                }

            //this sets the initial investment
            account.setInitial(floats);

            //this prompts the user for the deposit amount
            cout << "Please enter the monthly deposit amount: $";
            cin >> floats;

            if(floats <= -1){
                    break ;
                }

            //this sets the monthly deposit
            account.setMonthly(floats);

            //this prompts the user for the interest rate
            cout << "Please enter the % interest rate: ";
            cin >> floats;

            if(floats <= -1){
                   break;
                }

            //this sets the interest
            account.setInterest(floats);

            //this prompts the user for the number of years to invest
            cout << "Please enter the number of years: ";
            cin >> number;

            floats = number;
            if(floats <= -1){
                    break;
                }

            //this sets the number of years to invest
            account.setYears(number);
            cout << endl;

/////////////////////////////////////////////////////////////////////
            //end DataInput code

            //this re-prints the title
            InputTitle();

            //DataOutPut code
/////////////////////////////////////////////////////////////////////

            //this shows the user the initial investment amount
            cout << fixed << setprecision(2);
            cout << "Initial investment: $" << account.getInitial() << endl;

            //this shows the user the deposit amount
            cout << "Monthly deposit amount: $" << account.getMonthly() << endl;

            //this calculates, then shows the user the interest rate
            floats = account.getInterest() * 100.0;
            cout << "Interest rate: " << floats << "%" << endl;

            //this shows the user the number of years to invest
            cout << "Number of years: " << account.getYears() << endl;

//////////////////////////////////////////////////////////////////////
            //end DataOutPut code

            Calculate(account.getInitial(), account.getMonthly(), account.getInterest(), account.getYears());

        }//end while loop
    }//end try

    //this catch "catches" the error and stops the program
    catch(float floats){

    }//end catch

    cout << endl << "Thank you for using the Airgead Banking App!" << endl;

}//end InvestmentCalculator  function

//MAIN function
int main()
{
    InvestmentCalculator();
    return 0;
}//end Main

//end of program
