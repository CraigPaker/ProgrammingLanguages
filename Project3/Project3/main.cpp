// Craig Parker
// 2020-08-15
// CS-210-H6018


//standard library
#include <iostream>

//used to handle strings
#include <string>

//used in formating console output
#include <ios>
#include <iomanip>
#include <windows.h>

//used to allow for try/catch
#include <stdexcept>

//used to convert int-values into string-values
#include <sstream>

//used to read and write i/o of files
#include <fstream>

//allowed vectors to read-in and allow the removal of lines within files
#include <vector>

//used to search for elements within a vector
#include <algorithm>
#include <iterator>


using namespace std;

//this was skeleton code for this project
//I did not feel the need to implement this function;
//This program writes to a .txt file every time data is changed
//the only temporary data is stored within a vector before
//the old data is overwritten
/*
void SaveDataToFile()
{
     /
            TODO: Write proper code to store vector/array to file.
     /

     //My program reads and writes data to the file and saves that data
     //whenever I close the file; to "add animals" I append the file so that
     //the data is saved and previous data is not overwritten
}
*/

//this function creates and adds data to a file
void GenerateData()
{

                int entermore = 1;

	           //this block of code takes in user input
	           //and adds it to an array
	           //once the array has been filled it is
	           //written into a file for later use

	           //these are the declarations of arrays
	           //that will be used
	           //these are set up to only hold 81 animals

	           int TrackNumber[80]; //needs length of 6
	           string AnimalName[80]; //needs length of 15
	           string AnimalType[80]; //needs length of 15
	           string SubType[80]; //needs length of 15
	           int Eggs[80]; //needs length of 1
	           int Nurse [80]; //needs length of 1

	           //placeholder variable
	           int i = 0;

	           //the following loop charges the arrays
	           for(int y = 0; y < 80; y++){
                    TrackNumber[y] = 0;
                    AnimalName[y] = "";
                    AnimalType[y] = "";
                    SubType[y] = "";
                    Eggs[y] = 0;
                    Nurse[y] = 0;
                    }
            try{

	           do
	           {

                    //this requests and reads-in the tracking number
                    cout << "Enter Tracking Number: " << endl;
                    cin >> TrackNumber[i];

                    //this statement catches invalid input and re-iterates
                    //the loop
                    if(cin.fail()){

                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                        cin.clear();

                        cout << "Please enter a valid input-type" << endl;

                        continue;
                    }

                    //the following pieces of code store values within their
                    //respective arrays

                    cout << "Enter Animal Name: " << endl;
                    cin >> AnimalName[i];

                    cout << "Enter Animal Type: " << endl;
                    cin >> AnimalType[i];

                    cout << "Enter Animal Sub-type: " << endl;
                    cin >> SubType[i];

                    cout << "Enter Number of Eggs: " << endl;
                    cin >> Eggs[i];

                    //this statement catches invalid input and re-iterates
                    //the loop
                    if(cin.fail()){

                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                        cin.clear();

                        cout << "Please enter a valid input-type" << endl;

                        continue;
                    }

                    cout << "Enter 1 if Nursing, 0 if not: " << endl;
                    cin >> Nurse[i];

                    //this statement catches invalid input and re-iterates
                    //the loop
                    if(cin.fail()){

                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                        cin.clear();

                        cout << "Please enter a valid input-type" << endl;
                        continue;
                    }

                    cout << "Enter more data? (1 for yes)" << endl;
                    cin >> entermore;

                    //this statement catches invalid input and re-iterates
                    //the loop
                    if(cin.fail()){

                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                        cin.clear();

                        cout << "Please enter a valid input-type" << endl;
                        continue;
                    }

                    i++;

                }while (entermore == 1);

                //The following code opens a file then writes the data to that file
                ofstream ZooData;
                ZooData.open("ZooData.txt");

                //this alerts us of any error in generating the file
                if(!ZooData){

                    cout << " an error occurred during file generation";
                }

                //this statement breaks the loop and
                //prevents the file from being filled with
                //data that was used to charge the arrays
                for(int t = 0; t < sizeof(TrackNumber); t++){
                    if(TrackNumber[t] == 0){
                        break;
                    }

                    //this chunk of code converts the int and writes
                    //a string to the file using the following format:
                    //[000001], [000123], [123456]

                    string temp;
                    std::ostringstream ss;
                    ss << TrackNumber[t];
                    temp = ss.str();
                    if( temp.size() < 6){
                        for(int g = temp.size(); g < 6; g++){
                        ZooData << '0';
                        }//end for '0' number padding
                    }//end size check statement
                    ZooData << TrackNumber[t];

                    //this writes the formatted animal name to the file
                    temp = AnimalName[t];
                    if( temp.size() < 15){
                        for(int g = temp.size(); g < 15; g++){
                        ZooData << ' ';
                        }//end for ' ' space-padding
                    }//end size check statement
                    ZooData << AnimalName[t];

                    //this writes the formatted animal type to the file
                    temp = AnimalType[t];
                    if( temp.size() < 15){
                        for(int g = temp.size(); g < 15; g++){
                        ZooData << ' ';
                        }//end for ' ' space-padding
                    }//end size check statement
                    ZooData << AnimalType[t];

                    //this writes the formatted sub-type to the file
                    temp = SubType[t];
                    if( temp.size() < 15){
                        for(int g = temp.size(); g < 15; g++){
                        ZooData << ' ';
                        }//end for ' ' space-padding
                    }//end size check statement
                    ZooData << SubType[t];

                    //this writes the formatted egg number
                    std::ostringstream zz;
                    zz << Eggs[t];
                    temp = zz.str();
                    if( temp.size() < 15){
                        for(int g = temp.size(); g < 15; g++){
                        ZooData << ' ';
                        }//end for ' ' space-padding
                    }//end size check statement
                    ZooData << Eggs[t];

                     //this writes the formatted Nursing number
                    std::ostringstream gg;
                    gg << Nurse[t];
                    temp = gg.str();
                    if( temp.size() < 15){
                        for(int g = temp.size(); g < 15; g++){
                        ZooData << ' ';
                        }//end for ' ' space-padding
                    }//end size check statement
                    ZooData << Nurse[t];
                    ZooData << endl;
                }

                //this closes the ZooData.txt File
                ZooData.close();

                cout << endl << "The file has been successfully created..." << endl;

	          }catch(invalid_argument e){

	          }//end try-catch
}//end GenerateData

void AddAnimal()
{
     /*
            TODO: Write proper code to add an animal to your vector (or array)
     */

     int trackNumber;
     string animalName;
     string animalType;
     string subType;
     int eggs;
     int nurse;

     int stop = 1;

     do
	           {

                    //this requests and reads-in the tracking number
                    cout << "Enter Tracking Number: " << endl;
                    cin >> trackNumber;

                    //this statement catches invalid input and re-iterates
                    //the loop
                    if(cin.fail()){

                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                        cin.clear();

                        cout << "Please enter a valid input-type" << endl;

                        continue;
                    }

                    //the following pieces of code store values within their
                    //respective arrays

                    cout << "Enter Animal Name: " << endl;
                    cin >> animalName;

                    cout << "Enter Animal Type: " << endl;
                    cin >> animalType;

                    cout << "Enter Animal Sub-type: " << endl;
                    cin >> subType;

                    cout << "Enter Number of Eggs: " << endl;
                    cin >> eggs;

                    //this statement catches invalid input and re-iterates
                    //the loop
                    if(cin.fail()){

                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                        cin.clear();

                        cout << "Please enter a valid input-type" << endl;

                        continue;
                    }

                    cout << "Enter 1 if Nursing, 0 if not: " << endl;
                    cin >> nurse;

                    //this statement catches invalid input and re-iterates
                    //the loop
                    if(cin.fail()){

                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                        cin.clear();

                        cout << "Please enter a valid input-type" << endl;

                        continue;
                    }

                    //this statement catches invalid input and re-iterates
                    //the loop
                    if(cin.fail()){

                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                        cin.clear();

                        cout << "Please enter a valid input-type" << endl;

                        continue;
                    }

                    stop = 0;
                }while(stop != 0);

                //The following code opens a file then writes the data to that file
                ofstream ZooData;
                ZooData.open("ZooData.txt", ios::app);

                //this alerts us of any error in generating the file
                if(!ZooData){

                    cout << " an error occurred during file generation";
                }

                //declaration for the int to string converters
                string temp;
                std::ostringstream ss;
                ss << trackNumber;
                temp = ss.str();

                if( temp.size() < 6){
                    for(int g = temp.size(); g < 6; g++){
                        ZooData << '0';
                        }//end for '0' number padding
                }//end size check statement
                    ZooData << trackNumber;

                    //this writes the formatted animal name to the file
                    if( animalName.size() < 15){
                        for(int g = animalName.size(); g < 15; g++){
                        ZooData << ' ';
                        }//end for ' ' space-padding
                    }//end size check statement
                    ZooData << animalName;

                    //this writes the formatted animal type to the file
                    if( animalType.size() < 15){
                        for(int g = animalType.size(); g < 15; g++){
                        ZooData << ' ';
                        }//end for ' ' space-padding
                    }//end size check statement
                    ZooData << animalType;

                    //this writes the formatted sub-type to the file
                    if( subType.size() < 15){
                        for(int g = subType.size(); g < 15; g++){
                        ZooData << ' ';
                        }//end for ' ' space-padding
                    }//end size check statement
                    ZooData << subType;

                    //this writes the formatted egg number
                    std::ostringstream zz;
                    zz << eggs;
                    temp = zz.str();
                    if( temp.size() < 15){
                        for(int g = 0 + temp.size(); g < 15; g++){
                        ZooData << ' ';
                        }//end for ' ' space-padding
                    }//end size check statement
                    ZooData << eggs;

                    //this writes the formatted Nursing number
                    std::ostringstream gg;
                    gg << nurse;
                    temp = gg.str();
                    if( temp.size() < 15){
                        for(int g = 0 + temp.size(); g < 15; g++){
                        ZooData << ' ';
                        }//end for ' ' space-padding
                    }//end size check statement
                    ZooData << nurse;
                    ZooData << endl;

                    ZooData.close();

                    cout << endl << "Animal added!!" << endl;

}//end add animal


void RemoveAnimal()
{
     /*
            TODO: Write proper code to remove an animal from your vector (or array. Remmber to re-allocate proper size if using array)
    */

    //declaration of a vector and transfer string-variable
    std::vector<std::string> AnimalVector;
    string transfer;
    AnimalVector.clear();

    //this reads the file into a vector
    ifstream ZooData("ZooData.txt", ios_base::in);
    while(getline(ZooData, transfer)){
          AnimalVector.push_back(transfer);
          }

    //sentinel control for the do/while loop
    int stop = 1;

    //id-number for animal index
    int number;

    //this will hold the index value after
    //the integer is converted and formatted
    string toDelete = "";

     try{
	           do
	           {
                    //this requests and reads-in the tracking number
                    cout << "Enter Tracking Number For Animal To Be Removed: " << endl;
                    cin >> number;

                    //this statement catches invalid input and re-iterates
                    //the loop
                    if(cin.fail()){

                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                        cin.clear();

                        cout << "Please enter a valid input-type" << endl;

                        continue;
                    }
                    stop = 0;
                }while(stop != 0);
        }catch(invalid_argument e){
	          }//end try-catch

    //this converts the int to string
    string temp;
    std::ostringstream ss;
    ss << number;
    temp = ss.str();

    //this pads the string to match the data format in the .txt
    if( temp.size() < 6){
        for(int g = temp.size(); g < 6; g++){
            toDelete.append("0");
            }//end for '0' number padding
    }//end size check statement
    toDelete.append(temp);

    //this searches the vector index and deletes the line the
    //animal's ID is found on
    for(int i = 0; i < AnimalVector.size(); i++){
        if(toDelete == AnimalVector.at(i).substr(0,6)){
            AnimalVector.erase(AnimalVector.begin() + i);
        }// end delete if
    }//end vector search loop

    //the following code will overwrite the previous list;
    //saving the list in the process
    ofstream NewZooData("ZooData.txt");
    for(int i = 0; i < AnimalVector.size(); i++){

        NewZooData << AnimalVector[i] << endl;
    }//end overwrite loop

}//end remove animal function


///////////////////////////////////////////////////////////////////////
//I did not use this function,
//I was unable to get the JNI environment to function properly
//I used C++ to open/close the files
// <fstream>
/*
void LoadDataFromFile()
{
     /
            TODO: Write proper code to load data from input file (generated using JNI) into vector/array.
     /
}
*/
////////////////////////////////////////////////////////////////////////////

//this function will display the data of the animals
void DisplayData(){

    //declaration of a vector and transfer string-variable
    std::vector<std::string> DisplayVector;
    string transfer;
    DisplayVector.clear();

    //this reads the file into a vector
    ifstream DisplayData("ZooData.txt", ios_base::in);
    while(getline(DisplayData, transfer)){
          DisplayVector.push_back(transfer);
          }

        //this creates the top border for the chart
        cout << setfill('_');
        cout << setw(87) << left << "" << endl << endl;

        //these declarations will fill the chart's title
        string id = "| ID :";
        string name = "| Name :";
        string type = "| Type :";
        string subType = "| Sub :";
        string eggs = "| Eggs :";
        string nurse = "| Nurse :";
        string temp = "";


        for(int i = 0; i <= 5; i++){

            if(i == 0){
                temp = id;
            }else if(i == 1){
                temp = name;
            }else if(i == 2){
                temp = type;
            }else if(i == 3){
                temp = subType;
            }else if(i == 4){
                temp = eggs;
            }else if(i == 5){
                temp = nurse;
            }

            //this writes the formatted animal name to the file

            if( i != 0){
                for(int g = temp.size(); g < 14; g++){
                    cout << ' ';
                }

            }else{
                for(int g = temp.size(); g < 5; g++){
                        cout << ' ';
                    }//end space padding

            }
                cout << temp;
                cout << " |";

        }//end column titles
    cout << endl;
    for(int i = 0; i < DisplayVector.size(); i++){
        cout << setfill('_');
        cout << setw(87) << left << "" << endl;
        cout << endl << DisplayVector[i] << endl;

    }//end loop

    //this created the bottom border for the chart
    cout << setfill('_');
    cout << setw(87) << left << "" << endl;

}//end display function

//this function is to demonstrate my ability to create classes
//However, they are unimplemented.
//
void GenerateAnimals()
{


    //Base class
    class Animal{


    public:
            void setID(string number){

                id = number;
            }
            void setName(string _name){

                name = _name;
            }
            void setType(string _type){

                type = _type;
            }
            void setSubType(string _sub){

                sub = _sub;
            }

    private:

        string id;
        string name;
        string type;
        string sub;

    };//end animal class


    class Oviparous: public Animal{

        public:
            void setEggs(string _eggs){
                eggs = _eggs;
            }

        private:
            string eggs;
    };//end egg class


    class Mammal: public Animal{

        public:
            void setNurse(string _nurse){
                nurse = _nurse;
            }

        private:
            string nurse;
    };//end mammal class

}//end animal generation function

//This function displays the menu
//I could have made this a recursive function, but
//the data-catch I implemented would have made
//recursion redundant
void DisplayMenu()
{
     /*
            TODO: write proper code to display menu to user to select from
     */

    //////////////////////////////////////////////////////////////////
    //Console color code
    ///////////////////////////////////////////////////////////////////

    //from what I read this my be OS-specific to Windows
    //OS = Operating System
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 10);

    int choice = 0;

    do{
        //Top border code
////////////////////////////////////////////////////////////////////
        cout << setfill('_');
        cout << setw(52) << left << "" << endl;
////////////////////////////////////////////////////////////////////

        //title code
////////////////////////////////////////////////////////////////////
        cout << setw(31) << right << " Options ";
        cout << setw(21) << left << "" << endl;
////////////////////////////////////////////////////////////////////

        cout << endl << "Enter a 1 to generate animal data. ";
        cout << endl << "Enter a 2 display animal data: ";
        cout << endl << "Enter a 3 add an animal record. ";
        cout << endl << "Enter a 4 delete an animal record. ";
        cout << endl << "Enter a 5 to generate animal objects. ";
        cout << endl << "Enter a 0 to EXIT" << endl;

         //Bottom border code
////////////////////////////////////////////////////////////////////
        cout << setfill('_');
        cout << setw(52) << left << "" << endl;
////////////////////////////////////////////////////////////////////

        //title code
////////////////////////////////////////////////////////////////////
        cout << setw(31) << right << "_________";
        cout << setw(21) << left << "" << endl;
////////////////////////////////////////////////////////////////////

        cout << endl << "User Choice: ";
        cin >> choice;

        //the following if/else statements will catch invalid user input
        //and will reiterate the menu loop
        if(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cin.clear();

            cout << "Please enter a valid number" << endl;
            choice = 1;
            continue;

        }else if(choice > 5 || choice < 0){

            cout << "Please enter a valid number" << endl;
            continue;
        }

        //an extra line for aesthetics
        cout << endl;

        if(choice == 1){
            GenerateData();

        }else if(choice == 2){
            DisplayData();

        }else if(choice == 3){
            AddAnimal();

        }else if(choice == 4){
            RemoveAnimal();

        }else if(choice == 5){
            GenerateAnimals();
        }
    }while(choice != 0);

    cout << endl << "Thanks For Using This Program!!" << endl;
}//end Menu Function


int main()
{

    DisplayMenu();

    return 0;
}//end main
