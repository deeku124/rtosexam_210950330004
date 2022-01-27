#include<stdio.h>
#include<freertos/FreeRTOS.h>
#include<freertos/task.h>
#include<freertos/timers.h>

TimerHandle_t timer1;



void TCALLBACK(TimerHandle_t xTimer)
{
printf("timer callback function\n");
}
void task1(void *pvParameters)
{
    while(1)
    {
    printf("this is task1\n");
    vTaskDelay( 1000 / portTICK_PERIOD_MS);
    }
}
void task2(void *pvParameters)
{
    while(1)
    {
    printf("this is task2\n");
    vTaskDelay( 2000 / portTICK_PERIOD_MS);
    }
}
void task3(void *pv)
{
    printf("this is task3\n");
    timer1=xTimerCreate("s/wtimer",pdMS_TO_TICKS(10000),pdTRUE,NULL,TCALLBACK);
    xTimerStart(timer1,0);
    vTaskDelay( 5000 / portTICK_PERIOD_MS);
    vTaskDelete(NULL);
}

void app_main()
{
xTaskCreate(task1,"TIMER",2048,NULL,5,NULL);
xTaskCreate(task2,"TIMER",2048,NULL,6,NULL);
xTaskCreate(task3,"TIMER",2048,NULL,7,NULL);
while(1)
{
printf("main function\n");
vTaskDelay(pdMS_TO_TICKS(1000));
}
}