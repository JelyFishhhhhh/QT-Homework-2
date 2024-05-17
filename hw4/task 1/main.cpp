#include <iostream>
#include <iomanip>      // setw(), setfill(), right     
#include <cstring>      // string
#include <cmath>        // abs
using namespace std;

class Time{

    private:
        
        int second;
        int minute;
        int hour;
    public:

        Time()
        :   second(int()),
            minute(int()),
            hour(int())
        {

        }
        Time(int hour, int minute, int second)
        :   second(second),
            minute(minute),
            hour(hour)        
        {
            // carry
            if(this->second> 60){

                minute+= second/ 60;
                second%= 60;
            }
            if(this->minute> 60){

                hour+= minute/ 60;
                minute%= 60;
            }
            if(this->hour> 24){

                hour%= 24;
            }
        }


        int getSecond(){

            return this->second;
        }
        int getMinute(){

            return this->minute;
        }
        int getHour(){

            return this->hour;
        }

        void setSecond(int second){

            this->second= second;
        }
        void setMinute(int minute){

            this->minute= minute;
        }
        void setHour(int hour){

            this->hour= hour;
        }

        void add(int amount, string unit){

            if(unit== "second"){

                this->second+= amount;
            }
            else if(unit== "minute"){

                this->minute+= amount;
            }
            else if(unit== "hour"){

                this->hour+= amount;
            }
            else{

                cout<< "UNIT ERROR!!\n";
            }

            // carry
            while(this->second>= 60){

                minute++;
                second-= 60;
            }
            while(this->minute>= 60){

                hour++;
                minute-= 60;
            }
            while(this->hour>= 24){

                hour-= 24;
            }
            while(this->second< 0){

                minute--;
                second+= 60;
            }
            while(this->minute< 0){

                hour--;
                minute+= 60;
            }
            while(this->hour< 0){

                hour+= 24;
            }
        }
        int duration(Time& T2){

            int second_T1= this->second+ (this->minute* 60)+ (this->hour* 3600);
            int second_T2= T2.getSecond()+ (T2.getMinute()* 60)+ (T2.getHour()* 3600);
            return abs(second_T1- second_T2);
        }

        bool operator<(Time& T2){

            // hour
            if(this->hour> T2.getHour()){

                return false;
            }
            else if(this->hour< T2.getHour()){

                return true;
            }
            // minute
            if(this->minute> T2.getMinute()){

                return false;
            }
            else if(this->minute< T2.getMinute()){

                return true;
            }
            // second
            if(this->second> T2.getSecond()){

                return false;
            }
            else if(this->second< T2.getSecond()){

                return true;
            }

            // if equal
            return false;
        }
        
        bool operator>(Time& T2){

            // hour
            if(this->hour< T2.getHour()){

                return false;
            }
            else if(this->hour> T2.getHour()){

                return true;
            }
            // minute
            if(this->minute< T2.getMinute()){

                return false;
            }
            else if(this->minute> T2.getMinute()){

                return true;
            }
            // second
            if(this->second< T2.getSecond()){

                return false;
            }
            else if(this->second> T2.getSecond()){

                return true;
            }

            // if equal
            return false;
        }
        bool operator==(Time& T2){

            if(this->hour!= T2.getHour()){

                return false;
            }
            else if(this->minute!= T2.getMinute()){

                return false;
            }
            else if(this->second!= T2.getSecond()){

                return false;
            }

            // if equal
            return true;
        }

        bool operator<=(Time& T2){

            return (*this< T2) || (*this== T2);
        }
        
        bool operator>=(Time& T2){

            return (*this> T2) || (*this== T2);
        }
        bool operator!=(Time& T2){

            return !(*this== T2);
        }
        Time& operator++(){

            ++this->second;
            // carry
            if(this->second>= 60){

                this->minute+= this->second/ 60;
                this->second%= 60;
            }
            if(this->minute>= 60){

                this->hour+= this->minute/ 60;
                this->minute%= 60;
            }
            if(this->hour>= 24){

                this->hour%= 24;
            }

            return *this;
        }
        Time& operator--(){

            this->second--;
            // carry
            if(this->second< 0){

                this->minute--;
                this->second+= 60;
            }
            if(this->minute< 0){

                this->hour--;
                this->minute+= 60;
            }
            if(this->hour< 0){

                this->hour+= 24;
            }
            return *this;
        }
        Time operator+=(int amount){

            this->second+= amount;
            // carry
            if(this->second>= 60){

                minute+= second/ 60;
                second%= 60;
            }
            if(this->minute>= 60){

                hour+= minute/ 60;
                minute%= 60;
            }
            if(this->hour>= 24){

                hour%= 24;
            } 
            return *this;
        }
        Time operator-=(int amount){

            this->second-= amount;
            // carry
            while(this->second< 0){

                minute--;
                second+= 60;
            }
            while(this->minute< 0){

                hour--;
                minute+= 60;
            }
            while(this->hour< 0){

                hour+= 24;
            }
            return *this;
        }
        int operator-(Time& T2){

            int second_T1= this->second+ (this->minute* 60)+ (this->hour* 3600);
            int second_T2= T2.getSecond()+ (T2.getMinute()* 60)+ (T2.getHour()* 3600);
            return (second_T1- second_T2);
        }

        friend ostream &operator<<(ostream& output, Time& T){

            output  << setfill('0')<< right
                    << setw(2)<< T.hour<< ":"
                    << setw(2)<< T.minute<< ":"
                    << setw(2)<< T.second<< '\n';

            return output;
        }
        
        friend istream &operator>>(istream& input, Time& T){

            input>> T.hour>> T.minute>> T.second;

            // carry
            if(T.second>= 60){

                T.minute+= T.second/ 60;
                T.second%= 60;
            }
            if(T.minute>= 60){

                T.hour+= T.minute/ 60;
                T.minute%= 60;
            }
            if(T.hour>= 24){

                T.hour%= 24;
            } 

            return input;
        }

};

int main(){

    cout<< "Constructors:\n";
    Time T, T1(23, 59, 59);
    cout<< "T: "<< T<< "T1: "<< T1<< '\n';
    
    cout<< "Increment/ Decrement:\n";
    ++T1;
    --T;
    cout<< "T: "<< T<< "T1: "<< T1<< '\n';
    
    
    cout<< "Adding/ Subtracting:\n";
    T+= 5;
    T1-= 8;
    cout<< "T: "<< T<< "T1: "<< T1<< '\n';

    cout<< "Member Function:\n";
    cout<< "T: "<< T<< '\n';
    T.add(5, "second");
    T.add(2, "minute");
    T.add(1, "hour"); 
    cout<< "T: "<< T<< '\n';
    T.add(-12, "second");
    T.add(-3, "minute");
    T.add(-2, "hour");
    cout<< "T: "<< T<< '\n';
    cout<< "T: "<< T<< "T1: "<< T1<< '\n';
    cout<< "Duration: "<< T.duration(T1)<< "\n\n";
    
    cout<< "Logic:\n";
    cout<< "T: "<< T<< "T1: "<< T1<< '\n';
    cout<< "T< T1?: "<< ((T< T1)? "True": "False")<< '\n';
    cout<< "T> T1?: "<< ((T> T1)? "True": "False")<< '\n';
    cout<< "T<= T1?: "<< ((T<= T1)? "True": "False")<< '\n';
    cout<< "T>= T1?: "<< ((T>= T1)? "True": "False")<< '\n';
    cout<< "T== T1?: "<< ((T== T1)? "True": "False")<< '\n';
    cout<< "T!= T1?: "<< ((T!= T1)? "True": "False")<< '\n';

    cout<< "Minus:\n";
    int a= T- T1, b= T1- T;
    cout<< "T- T1= "<< a<< '\n';
    cout<< "T1- T= "<< b<< '\n';
}