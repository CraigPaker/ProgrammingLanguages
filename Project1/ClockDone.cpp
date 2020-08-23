// Craig Parker
// 2020-07-13
// CS-210-H6018


#include <iostream>
#include <ios>
#include <iomanip>
#include <String>
using namespace std;

void Clock(){

    //this will stop the loop when the user wants to exit
    int stop = 0;

    //12 hours
    int hour1 = 0;
    //24 hours
    int hour2 = 0;
    //minutes
    int minute = 0;
    //seconds
    int second  = 0;
    //AM/PM signifier
    string day = "AM";


    //do-while loops iterate at least once
    do{
            cout << "";

////////////////////////////////////////////////////////////////////
//Top border code
////////////////////////////////////////////////////////////////////
    cout << setfill('*');
    cout << setw(25) << left << "";
    cout << "\t";
    cout << setfill('*');
    cout << setw(26) << left;


/////////////////////////////////////////////////////////////////////
//the following block of code deals with the time
//it will add time where required, then display the time
/////////////////////////////////////////////////////////////////////


    //this catches when the second rolls into a minute which rolls
    //into an hour
    if(stop == 3 && second == 59 && minute == 59){
            second = 0;
            minute = 0;
            stop = 1;
    }

    //this rolls seconds into minutes
    if(stop == 3 && second == 59){
        second = 0;
        stop = 2;
    }
    //this roles minutes into hours
    else if(stop == 2 && minute == 59){
        minute = 0;
        stop = 1;
    }
    //this keeps within a 12-hour time frame
    else if(stop == 1 && hour1 == 12){
        hour1 = 0;
    }
    //this keeps within a 24-hour time frame
    else if(stop == 1 && hour2 == 23){
        hour2 = -1;
    }


    if(stop == 1){
        //this adds an hour
       hour1 = hour1 + 1;
       hour2 = hour2 + 1;
        //the following if-statements adjust for the right time of day
       if((hour2 <= 11) && (minute <= 59) && (second <= 59)){
            day = "AM";
       }
       else if(hour2 > 11){
            day = "PM";
       }

    }
    else if(stop == 2){
        //this adds a minute
        minute = minute + 1;
    }
    else if(stop == 3){
        //this adds a second
        second = second + 1;
    }
    //this statement runs on the first iteration
    //of the loop and assigns base values to the variables
    else if(stop == 0){
        hour1 = 0;
        hour2 = 0;
        minute = 0;
        second = 0;
    }

//////////////////////////////////////////////////////////////////////
//The following code displays the titles
//////////////////////////////////////////////////////////////////////

    cout << '*';
    cout << setfill(' ') << "\n*";
    cout << setw(18) << right << "12-Hour Clock";
    cout << setw(8);
    cout << "*\t*";

    cout << setw(18) << right << "24-Hour Clock";
    cout << setw(7);
    cout << '*' << endl;

///////////////////////////////////////////////////////////////////////
//The following chunk of code displays both times
///////////////////////////////////////////////////////////////////////

    cout << '*';
    cout << setfill(' ');
    cout << setw(5) << right << "";
    cout << setw(2) << setfill('0') << hour1 <<":";
    cout << setw(2) << minute << ":";
    cout << setw(2) << second << " " << day;
    cout << setfill(' ');
    cout << setw(7) << right << "\t*\t";


    cout << '*';
    cout << setfill(' ');
    cout << setw(5) << right << "";
    cout << setw(2) << setfill('0') << hour2 <<":";
    cout << setw(2) << minute << ":";
    cout << setw(2) << second;
    cout << setfill(' ');
    cout << setw(10) << right << "\t *\n";


////////////////////////////////////////////////////////////////////
//Bottom border code
////////////////////////////////////////////////////////////////////
    cout << setfill('*');
    cout << setw(26);
    cout << "\t";
    cout << setfill('*');
    cout << setw(27);


/////////////////////////////////////////////////////////////////////
//The following chunk of code displays the user's choices
////////////////////////////////////////////////////////////////////

    //border code
    cout << "\n" << setfill('*') << setw(25) << "";

    cout << setfill(' ');
    cout << setw(25) << left << "\n* 1-Add One Hour" << "*\n";
    cout << setw(24) << left << "* 2-Add One Minute" << "*\n";
    cout << setw(24) << left << "* 3-Add One Second" << "*\n";
    cout << setw(24) << left << "* 4-Exit Program" << "*\n";

    //border code
    cout << setfill('*');
    cout << setw(26);

    //prompt for user input
    cout <<"Please enter an option (1-4): \n";
    cin >> stop;

    }while(stop != 4);
//End While Loop
////////////////



}
//end clock function
////////////////////

int main()
{
    //this will call the Clock function
    Clock();

    return 0;

}
//end Main function
