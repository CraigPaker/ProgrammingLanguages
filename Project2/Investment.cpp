#include "Investment.h"

Investment::Investment()
{
    //constructor
}

        //getters/setters for years
        int Investment::getYears(){

            return m_years;

            };
        void Investment::setYears(int numb){

            m_years = numb;

            };

        //getters/setters for the interest
        float Investment::getInterest(){

            return m_interest;

            };
        void Investment::setInterest(float numb){

            //this converts the given number to a % value
           m_interest = (numb/100.0);

            };

        //getters/setters for the balance
        float Investment::getBalance(){

            return m_balance;

            };
        void Investment::setBalance(float numb){

            m_balance = numb;

            };

        //getters/setters for the initial balance
       float Investment::getInitial(){

            return m_initial;

            };
        void Investment::setInitial(float numb){

            m_initial = numb;

            };

        //getters/setters for the monthly deposits
        float Investment::getMonthly(){

            return m_monthly;

            };
        void Investment::setMonthly(float numb){

            m_monthly = numb;

            };
