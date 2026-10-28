#include "graphics.h"      // 引用ege图形库
int main() {
    initgraph(640, 480);   // 初始化，显示一个窗口，大小为640*480
    int n1, n2, total;
    rectangle(10,10,300,200); // 画矩形，左上(10,10)，右下(300,200)
    //在坐标(20,20)处和(20,40)处显示信息
    xyprintf(20,20,"Add two numbers.\n"); 
    xyprintf(20,40,"1st number? ");
    //调用EGE库中的getInteger()。注意此处使用的不是ASC库中的getInteger()
    n1 = getInteger("请输入第一个加数");
    xyprintf(20,60,"2nd number? ");
    n2 = getInteger("请输入第二个加数");
    total = n1 + n2;
    xyprintf(20,80,"The total is %d.\n", total);
    getch();               // 暂停一下等待用户按键
    closegraph();          // 关闭图形界面
    return 0;
}
