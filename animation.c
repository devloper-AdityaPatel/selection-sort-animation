/* assignment - 1
 * data structure and algorithms
 * coded  by : aditya patel
 * roll no : 2k22/co/31
 *  */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

/* date time and version macros */
# define DTV    printf("%s\n",__DATE__);\
                printf("%s\n",__TIME__);\
                printf("version - 1.0.0\n");

               
# define CODER  printf("coded by :");\
                printf(CYAN);\
                printf(" Aditya Patel");\
                printf(DEFAULT_COLOR);
/* color macros */

#define DEFAULT_COLOR "\033[1;0m"
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define VIOLET "\033[1;35m"
#define CYAN "\033[1;36m"

/* clear screen macros */
#define CLR_SCRN system("cls");
#define CURSR cursor
#define BLK blank
#define NEWLINE printf("\n");
#define DSPLYFORMT(a) printf("%4c",a);

/* global decalration */

char cursor = '^';
char blank = ' ';

void delay(int number_of_seconds)
{
    // Converting time into milli_seconds
    int milli_seconds = 250 * number_of_seconds;

    // Storing start time
    clock_t start_time = clock();

    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds)
        ;
}

void display_credit(void){
    DTV
    CODER
    delay(10);
}


void animation(int arr[], int size)
{
    display_credit();
    printf(RED);
    printf("\nSelection sort Animation will start in next 3 sec...\n\n");
    printf(DEFAULT_COLOR);
    delay(40);

    int min = 0; // initial assumed minimu element is at zero index


    int j = 0; //   outer while loop iterator
    while (j < size)
    {

        int k = j;  // inner while loop iterator(while loop no - 2)

        int min = j;

        while (k < size)    //while loop no - 2
        {
            CLR_SCRN

            /* checking,is Kth index element  mininimum? */
            if (arr[min] > arr[k])
            {
                min = k;
            }
            
            NEWLINE

            /* printing array*/
            for (int i = 0; i < size; i++)
            {
                if (i < j)
                {
                    printf(VIOLET);
                    printf("%4d", arr[i]);
                    printf(DEFAULT_COLOR);
                }
                else if (min == i)
                {
                    printf(GREEN);
                    printf("%4d", arr[i]);
                    printf(DEFAULT_COLOR);
                }
                else
                {
                    printf("%4d", arr[i]);
                }
            }

            NEWLINE

            /* loop for cursor movement */
            for (int i = 0; i < k; i++)
            {
                DSPLYFORMT(BLK)
            }
            DSPLYFORMT(CURSR) //displaying cursor here

            delay(1);
            k++;
        }

        if (j != min)
        {

            CLR_SCRN

            int a = 1; //iterator for while loop no - 3

            int d = min - j; //giving the difference b/w min index to intiaial smallest element index

            while (a < d) //while loop no - 3
            {
                CLR_SCRN

                for (int i = 0; i < j + a; i++)
                {
                    DSPLYFORMT(BLK)
                }
                printf(VIOLET);
                printf("%4d\n", arr[j]);
                printf(DEFAULT_COLOR);

                for (int i = 0; i < size; i++)
                {

                    if (i < j)
                    {
                        printf(VIOLET);
                        printf("%4d", arr[i]);
                        printf(DEFAULT_COLOR);
                    }
                    else if (min == i || j == i)
                    {

                        printf(GREEN);
                        printf("%4c", blank);
                        printf(DEFAULT_COLOR);
                    }
                    else
                    {
                        printf("%4d", arr[i]);
                    }
                }
                
                NEWLINE


                for (int i = 0; i < min - a; i++)
                {
                   DSPLYFORMT(BLK)
                }

                printf(VIOLET);
                printf("%4d", arr[min]);
                printf(DEFAULT_COLOR);
                delay(1);

                a++;
            }

            int temp = arr[j];
            arr[j] = arr[min];
            arr[min] = temp;
        }

        j++;
    }

    printf(GREEN);
    printf("\n\n\t\tThank You...");
    printf(DEFAULT_COLOR);
}

int main()
{

    // int arr[14] = {78,45,12,39,1,89,-5,-3,-78,33,100,112,5-100};
    // int size = 14;

    int arr[15] = {45,12,-5,16,75,42,11,9,-105,11,1,0,45,8,-6};
    int size = 15;
    animation(arr, size);
}