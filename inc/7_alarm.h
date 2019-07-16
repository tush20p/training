#include<stdio.h>
#include<string.h>
#include<time.h>
#include<unistd.h>
#define MAX_SIZE 100
#define MAX_TIME 10
typedef struct alarm
{
        char notification[MAX_SIZE];
        char time[MAX_TIME];
}al;

