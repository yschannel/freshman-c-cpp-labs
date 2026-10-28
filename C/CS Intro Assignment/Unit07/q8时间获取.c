/*8.Based on Quiz7, define a date structure 
that contains four member variables: year, month, day 
and weekday, with data types of integer, integer, integer,
 WeekDay respectively. Store the current date in 
 a date structure variable and then output the date.*/
#include<stdio.h>
#include<time.h>

typedef enum{
    SUNDAY,
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY    
}Weekday;

typedef struct {
    int year;
    int month;
    int day;
    Weekday weekday;
}Date;

const char* weekday_output(Weekday day){
    switch (day){
        case SUNDAY: return "SUNDAY";
        case MONDAY: return "MONDAY";
        case TUESDAY: return "TUESDAY";
        case WEDNESDAY: return "TEDNESDAY";
        case THURSDAY: return "THURSDAY";
        case FRIDAY: return "FRIDAY";
        case SATURDAY: return "SATURDAY";
        default: return "UNKNOWN";
    }
}

int main(){
    time_t current_time;
    struct tm *time_info;
    time(&current_time);
    time_info = localtime(&current_time);

    Date current_date ={
        time_info->tm_year + 1900,
        time_info->tm_mon + 1,
        time_info->tm_mday,
        time_info->tm_wday
    };

    printf("Year:%d\n",current_date.year);
    printf("Month:%d\n",current_date.month);
    printf("Day:%d\n",current_date.day);
    printf("Weekday:");
    printf(weekday_output(current_date.weekday));
    return 0;
}
