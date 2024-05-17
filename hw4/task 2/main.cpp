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
            // if(this->hour> 24){

            //     hour%= 24;
            // }
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
            // carry
            if(this->second> 60){

                minute+= second/ 60;
                second%= 60;
            }
            if(this->minute> 60){

                hour+= minute/ 60;
                minute%= 60;
            }
        }
        void setMinute(int minute){

            this->minute= minute;
            // carry
            if(this->second> 60){

                minute+= second/ 60;
                second%= 60;
            }
            if(this->minute> 60){

                hour+= minute/ 60;
                minute%= 60;
            }
        }
        void setHour(int hour){

            this->hour= hour;
            // carry
            if(this->second> 60){

                minute+= second/ 60;
                second%= 60;
            }
            if(this->minute> 60){

                hour+= minute/ 60;
                minute%= 60;
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

int monthDate[13]= {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool isLeapYear(int year);

int MonthDate(int year, int month);

int toDays(DateTime& dttm);

class DateTime{


    private: 
        int date;
        int month;
        int year;
        Time time;
    
    public:

        DateTime()
        :   year(int()),
            month(int()),
            date(int()),
            time(Time())
        {

        }
        DateTime(int year, int month, int date)
        :   year(year> 0? year: 0),
            month(month> 0? month: 0),
            date(date> 0? date: 0),
            time(Time())
        {
            if(this->date> MonthDate(this->year, this->month)){

                int origialMonth= this->month;
                this->month+= this->date/ MonthDate(this->year, this->month);
                this->date%= MonthDate(this->year, origialMonth);
            }
            if(this->month> 12){

                this->year+= this->month/ 12;
                this->month%= 12;
            }
        }
        DateTime(int year, int moth, int date, Time time)
        :   year(year> 0? year: 0),
            month(month> 0? month: 0),
            date(date> 0? date: 0),
            time(time)
        {
            while(this->time.getHour()> 24){

                this->date++;
                this->time.setHour(time.getHour()- 24);
            }
            while(this->date> MonthDate(this->year, this->month)){

                int origialMonth= this->month;
                this->month++;
                this->date-= MonthDate(this->year, origialMonth);
            }
            while(this->month> 12){

                this->year++;
                this->month-= 12;
            }
        }
        DateTime(int year, int month, int date, int hour, int min, int second)
        :   year(year> 0? year: 0),
            month(month> 0? month: 0),
            date(date> 0? date: 0),
            time(Time())
        {
            Time buf(hour, min, second);
            this->time= buf;

            while(this->time.getHour()> 24){

                this->date++;
                this->time.setHour(time.getHour()- 24);
            }
            while(this->date> MonthDate(this->year, this->month)){

                int origialMonth= this->month;
                this->month++;
                this->date-= MonthDate(this->year, origialMonth);
            }
            while(this->month> 12){

                this->year++;
                this->month-= 12;
            }
        }       

        int getDate(){

            return this->date;
        }
        int getMonth(){

            return this->month;
        }
        int getYear(){

            return this->year;
        }
        int getSecond(){

            return this->time.getSecond();
        }
        int getMinute(){

            return this->time.getMinute();
        }
        int getHour(){

            return this->time.getHour();
        }

        void setDate(int date){

            this->date= date;
            if(this->date< 0 || this->date> MonthDate(this->year, this->month)){

                this->date= 0;
            }
        }
        void setMonth(int month){

            this->month= month;
            if(this->month< 0 || this->month> 12){

                this->month= 0;
            }
        }
        void setYear(int year){

            this->year= year;
        }
        void setSecond(int second){

            this->time.setSecond(second);
        }
        void setMinute(int minute){

            this->time.setMinute(minute);
        }
        void setHour(int hour){

            this->time.setHour(hour);
        }

                void add(int amount, string unit){

            if(unit== "second"){

                this->time.setSecond(time.getSecond()+ amount);
            }
            else if(unit== "minute"){

                this->time.setMinute(time.getMinute()+ amount);
            }
            else if(unit== "hour"){

                this->time.setHour(time.getHour()+ amount);
            }
            else if(unit== "date"){

                this->date+= amount;
            }
            else if(unit== "week"){

                this->date+= 7* amount;
            }
            else if(unit== "month"){

                this->date+= amount;
            }
            else if(unit== "year"){

                this->year+= amount;
            }
            else{

                cout<< "UNIT ERROR!!\n";
            }

            // carry
            while(this->getSecond()>= 60){

                this->setMinute(getMinute()+ 1);
                this->setSecond(this->getSecond()- 60);
            }
            while(this->getMinute()>= 60){

                this->setHour(this->getMinute()+ 1);
                this->setMinute(this->getMinute()- 60);
            }
            while(this->getHour()>= 24){

                this->date++;
                this->setHour(this->time.getHour()- 24);
            }
            while(this->date> MonthDate(this->year, this->month)){

                this->month++;
                this->date-= MonthDate(this->year, this->month- 1);
            }
            while(this->month> 12){

                this->year++;
                this->month--;
            }
            while(this->getSecond()< 0){

                this->setMinute(getMinute()- 1);
                this->setSecond(this->getSecond()+ 60);
            }
            while(this->getMinute()< 0){

                this->setHour(this->getHour()- 1);
                this->setMinute(this->getMinute()+ 60);
            }
            while(this->getHour()< 0){

                this->date--;
                this->setHour(this->getHour()+ 24);
            }
            while(this->date< 0){

                this->month--;
                this->date+= MonthDate(this->year, this->month+ 1);
            }
            while(this->month< 0){

                this->year--;
                this->month+= 12;
            }
        }

        int dayOfMonth(){

            return MonthDate(this->year, this->month);
        }
        int dayOfYear(){

            int sum= 0;
            for(int i= 1; i< this->month; i++){

                sum+= MonthDate(this->year, i);
            }
            sum+= this->date;
            return sum;
        }
        string dayOfWeek(){

            int day= this->date, month= this->month, year= this->year;
            if (month == 1 || month == 2) {
                month += 12;
                year -= 1;
            }
            
            // Apply the formula
            int j = year / 100;
            int k = year % 100;
            int h = (day + 13 * (month + 1) / 5 + k + k / 4 + j / 4 + 5 * j) % 7;

            switch (h) {
                case 0:
                    return "Saturday";
                    break;
                case 1:
                    return "Sunday";
                    break;
                case 2:
                    return "Monday";
                    break;
                case 3:
                    return "Tuesday";
                    break;
                case 4:
                    return "Wednesday";
                    break;
                case 5:
                    return "Thursday";
                    break;
                case 6:
                    return "Friday";
                    break;
                default:
                    return "Invalid";
            }
        }
        int weekOfYear(){

            int a = (14 - this->month) / 12;
            int y = this->year - a;
            int m = this->month + 12 * a - 2;
            int d = (this->date + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12) % 7;

            return (this->date + (m * 2 + (d >= 5 ? 1 : 0)) / 7);
        }
        int quarterOfYear() {
            
            return (this->month - 1) / 3 + 1;
        }

        bool operator<(DateTime dttm2){

            if(this->year< dttm2.year){

                return true;
            }
            if(this->year> dttm2.year){

                return false;
            }
            if(this->month< dttm2.month){

                return true;
            }
            if(this->month> dttm2.month){

                return false;
            }
            if(this->date< dttm2.date){

                return true;
            }
            if(this->date> dttm2.date){

                return false;
            }

            return this->time< dttm2.time;
        }
        bool operator>(DateTime dttm2){

            if(this->year> dttm2.year){

                return true;
            }
            if(this->year< dttm2.year){

                return false;
            }
            if(this->month> dttm2.month){

                return true;
            }
            if(this->month< dttm2.month){

                return false;
            }
            if(this->date> dttm2.date){

                return true;
            }
            if(this->date< dttm2.date){

                return false;
            }

            return this->time> dttm2.time;
        }
        bool operator==(DateTime dttm2){

            if(this->year!= dttm2.year){

                return false;
            }
            if(this->month!= dttm2.month){

                return false;
            }
            if(this->date!= dttm2.date){

                return false;
            }

            return (this->time!= dttm2.time);
        }
        bool operator<=(DateTime dttm2){

            return *this< dttm2 || *this== dttm2;
        }
        bool operator>=(DateTime dttm2){

            return *this> dttm2 || *this== dttm2;
        }
        bool operator!=(DateTime dttm2){

            return !(*this== dttm2);
        }

        DateTime& operator++(){

            this->date++;
            // carry
            while(this->getSecond()>= 60){

                this->setMinute(getMinute()+ 1);
                this->setSecond(this->getSecond()- 60);
            }
            while(this->getMinute()>= 60){

                this->setHour(this->getMinute()+ 1);
                this->setMinute(this->getMinute()- 60);
            }
            while(this->getHour()>= 24){

                this->date++;
                this->setHour(this->time.getHour()- 24);
            }
            while(this->date> MonthDate(this->year, this->month)){

                this->month++;
                this->date-= MonthDate(this->year, this->month- 1);
            }
            while(this->month> 12){

                this->year++;
                this->month--;
            }
            while(this->getSecond()< 0){

                this->setMinute(getMinute()- 1);
                this->setSecond(this->getSecond()+ 60);
            }
            while(this->getMinute()< 0){

                this->setHour(this->getHour()- 1);
                this->setMinute(this->getMinute()+ 60);
            }
            while(this->getHour()< 0){

                this->date--;
                this->setHour(this->getHour()+ 24);
            }
            while(this->date< 0){

                this->month--;
                this->date+= MonthDate(this->year, this->month+ 1);
            }
            while(this->month< 0){

                this->year--;
                this->month+= 12;
            }
            return *this;
        }
        DateTime& operator--(){

            this->date--;
            // carry
            while(this->getSecond()>= 60){

                this->setMinute(getMinute()+ 1);
                this->setSecond(this->getSecond()- 60);
            }
            while(this->getMinute()>= 60){

                this->setHour(this->getMinute()+ 1);
                this->setMinute(this->getMinute()- 60);
            }
            while(this->getHour()>= 24){

                this->date++;
                this->setHour(this->time.getHour()- 24);
            }
            while(this->date> MonthDate(this->year, this->month)){

                this->month++;
                this->date-= MonthDate(this->year, this->month- 1);
            }
            while(this->month> 12){

                this->year++;
                this->month--;
            }
            while(this->getSecond()< 0){

                this->setMinute(getMinute()- 1);
                this->setSecond(this->getSecond()+ 60);
            }
            while(this->getMinute()< 0){

                this->setHour(this->getHour()- 1);
                this->setMinute(this->getMinute()+ 60);
            }
            while(this->getHour()< 0){

                this->date--;
                this->setHour(this->getHour()+ 24);
            }
            while(this->date<= 0){

                this->month--;
                this->date+= MonthDate(this->year, this->month+ 1);
            }
            while(this->month<= 0){

                this->year--;
                this->month+= 12;
            }
            return *this;
        }
        double operator-(DateTime dttm2){

            int diffInDate= abs(toDays(*this)- toDays(dttm2));
            double diffInSec= this->time- dttm2.time;
            
            return diffInDate+ diffInSec/ 86400;
        }

        double duration(DateTime dttm2){

            int diffInDate= abs(toDays(*this)- toDays(dttm2));
            double diffInSec= this->time.duration(dttm2.time);

            return diffInDate+ diffInSec/ 86400;
        }
};

bool isLeapYear(int year){

    return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}

int MonthDate(int year, int month){

    if(month!= 2){

        return monthDate[month];
    }
    return monthDate[2]+ isLeapYear(year);
}

int toDays(DateTime& dttm) {

        // Calculate the number of days from the reference year (e.g., 1970) to the given year
        int days = 0;
        for (int y = 1970; y < dttm.getYear(); ++y) {
            days += (isLeapYear(y) ? 366 : 365);
        }

        // Add the days in the current year up to the given month
        for (int m = 0; m < dttm.getMonth() - 1; ++m) {
            days += monthDate[m];
        }

        // Add one more day if the current year is a leap year and the month is after February
        if (isLeapYear(dttm.getYear()) && dttm.getMonth() > 2) {
            days += 1;
        }

        // Add the days in the current month
        days += dttm.getDate() - 1;

        return days;
}

int main(){

}
