#ifndef INVESTMENT_H
#define INVESTMENT_H

class Investment
{
    public:
        Investment();

        //declaring getters/setters for years
        int getYears();
        void setYears(int numb);

        //declaring getters/setters for the interest
        float getInterest();
        void setInterest(float numb);

        //declaring getters/setters for the balance
        float getBalance();
        void setBalance(float numb);

        //declaring getters/setters for the initial balance
        float getInitial();
        void setInitial(float numb);

        //declaring getters/setters for the monthly deposits
        float getMonthly();
        void setMonthly(float numb);

    private:
        int m_years = 0;
        float m_interest = 0.0; //Annual interest
        float m_initial = 0.0; //initial investment
        float m_balance = 0.0; //current balance
        float m_monthly = 0.0; //the monthly deposit for this investment
};

#endif // INVESTMENT_H
