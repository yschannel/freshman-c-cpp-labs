#include<stdio.h>
#include<windows.h>

typedef enum{
    RED,
    GREEN,
    YELLOW
}Traffic_light_color;

void change_traffic_light (Traffic_light_color color, int duration){
    while(1){
        for(int i = 0;i < 3;i++){
            color = i;
            switch(color){
                case RED:{
                    duration = 3000;
                    printf("Traffic Light is RED for 3 seconds.\n");
                    Sleep(duration);
                    break;
                }
                case GREEN:{
                    duration = 5000;
                    printf("Traffic Light is GREEN for 5 seconds.\n");
                    Sleep(duration);
                    break;
                }
                case YELLOW:{
                    duration = 2000;
                    printf("Traffic Light is YELLOW for 2 seconds.\n");
                    Sleep(duration);
                    break;
                }
                default:
                break;
            }
        }
    }
}
int main(){
    Traffic_light_color color;
    int duration;
    change_traffic_light(color,duration);
    return 0;
}