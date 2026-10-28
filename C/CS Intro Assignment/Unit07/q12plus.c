#include<stdio.h>
#include<windows.h>

typedef enum{
    RED,
    GREEN,
    YELLOW
}TrafficLightColor;

void changeTrafficLight(TrafficLightColor color, int duration){
    switch(color){
        case RED:
            printf("Traffic Light is RED for %d seconds.\n", duration/1000);
            Sleep(duration);
            break;
        case GREEN:
            printf("Traffic Light is GREEN for %d seconds.\n", duration/1000);
            Sleep(duration);
            break;
        case YELLOW:
            printf("Traffic Light is YELLOW for %d seconds.\n", duration/1000);
            Sleep(duration);
            break;
    }
}

int main(){
    // 模拟完整的交通灯周期
    while(1){
        changeTrafficLight(RED, 3000);     // 红灯3秒
        changeTrafficLight(GREEN, 5000);   // 绿灯5秒
        changeTrafficLight(YELLOW, 2000);  // 黄灯2秒
    }
    return 0;
}