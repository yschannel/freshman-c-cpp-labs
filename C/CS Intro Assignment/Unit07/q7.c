/*
Define an enumeration type WeekDay representing the day
 of the week, with seven enumeration elements: Monday,
  Tuesday, Wednesday, Thursday, Friday, Saturday, 
  and Sunday. Test WeekDay in main()
*/
#include<stdio.h>
typedef enum {
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY,
    SUNDAY
} Week_day;

int main(){
    Week_day day = MONDAY;
    switch (day){
        case MONDAY:{
            printf("MONDAY");
            break;
        }
        case TUESDAY:{
            printf("TUESDAY");
            break;
        }
        case WEDNESDAY:{
            printf("WEDNESDAY");
            break;
        }
        case THURSDAY:{
            printf("THURSDAY");
            break;
        }
        case FRIDAY:{
            printf("FRIDAY");
            break;
        }
        case SATURDAY:{
            printf("SATURDAY");
            break;
        }
        case SUNDAY:{
            printf("SUNDAY");
            break;
        }
        default:break;
    }    
    return 0;
}