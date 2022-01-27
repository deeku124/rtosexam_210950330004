#include<stdio.h>
#include<freertos/FreeRTOS.h>
#include<freertos/task.h>
#include<freertos/queue.h>

QueueHandle_t queue;

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
void task3(void *pvParameters)
{
    while(1)
    {
    printf("this is task3\n");
    vTaskDelay( 5000 / portTICK_PERIOD_MS);
    }
}
void task4(void *pvParameters)
{
    int count=25;
    while(1)
    {
    printf("this is task4\n");
    xQueueSend(queue,&count,portMAX_DELAY);
    printf("data being sent is %d\n",count);
    vTaskDelay( 500 / portTICK_PERIOD_MS);
    }
}
void task5(void *pvParameters)
{
    int buffer;
    while(1)
    {
    printf("this is task5\n");
    xQueueReceive(queue,&buffer,portMAX_DELAY);
    printf("data being received is %d\n",buffer);
    vTaskDelay( 500 / portTICK_PERIOD_MS);
    }
}

void app_main()
{
printf("in main function\n");
queue=xQueueCreate(10,sizeof(int));
if(queue!=NULL)
{
    printf("queue is created\n");
}
xTaskCreate(task1,"Task1",2048,NULL,5,NULL);
xTaskCreate(task2,"Task2",2048,NULL,6,NULL);
xTaskCreate(task3,"Task3",2048,NULL,7,NULL);
xTaskCreate(task4,"Task4",2048,NULL,8,NULL);
xTaskCreate(task5,"Task5",2048,NULL,9,NULL);
}