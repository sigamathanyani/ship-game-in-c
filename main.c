#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "ESD.h"

#define LEFT_ARROW 75
#define RIGHT_ARROW 77

#define SPECIAL_KEY -32

void drawBox(int posX, int posY, int width, int height);
void aboutClear();

int main()
{
    FILE *fp;
    char buff[50];
    int value,value1;
    int arr1[50];
    int arr2[50];

    int btmBlock[100];

    int block1[200][200];
    int block2[200][200];
    int water[200][200];

    int insideBt[6] = {95,95,95,95,95};
    int btIndex = 0;
    int index=0;

    int i,j=1,r=0;
    int x,y;
    int left_passenger = 0;
    int right_passenger = 0;

    int sail_mode = 1;
    int load_mode = 1;

    int offsetX = 6;
    int offsetY = 4;

    fp = fopen("data.txt","rt");

    char userI;
    int run=1;

    do
    {
        drawBox(10,6,60,9);
        gotoxy(34,7);printf("Boat demo.");
        gotoxy(22,9);printf("Option A - About");
        gotoxy(22,10);printf("Option B - Boat");
        gotoxy(22,11);printf("Option E - Exit");
        gotoxy(22,13);printf("Please type your option : ");

        userI = getche();

        if(userI == 'A' || userI == 'a')
        {
            aboutClear();
            gotoxy(12,9);printf("In the boat demo:");
            gotoxy(12,11);printf("Use the e-, r, d and the f-keys to add remove paxes");
            gotoxy(12,12);printf("from the harbors");
            gotoxy(12,14);printf("Press any key to continue...");
            userI=getch();
            if(userI==SPECIAL_KEY)getch();
            aboutClear();
            gotoxy(12,9);printf("In the boat demo:");
            gotoxy(12,10);printf("The s- and l keys select sail or load mode");
            gotoxy(12,11);printf("In ");setColor(0*16+12); printf("load mode mode ");setColor(0*16+15); printf("the arrow keys load and unload paxes");
            gotoxy(12,12);printf("In ");setColor(0*16+12); printf("sail mode ");setColor(0*16+15); printf("the arrow keys move up/down");
            gotoxy(12,14);printf("Press any key to continue...");
            userI=getch();
            if(userI==SPECIAL_KEY)getch();
        }
        else if(userI == 'B' || userI == 'b')
        {
            clrscr();
            drawBox(0, 0, 78,23);
            drawBox(offsetX-1, offsetY+1, 70,10);
            gotoxy(35,1);printf("Boat Demo");
            for(i=0;i<4;i++)
            {
                fgets(buff,7,fp);

                if(strpbrk(buff," "))
                {
                    int leN=strpbrk(buff," ")-buff;
                    buff[leN]=NULL;
                    value = atoi(buff);
                    value1 = atoi(&buff[leN+1]);

                    arr1[i]=value;
                    arr2[i]=value1;

                }

            }

            setColor(arr1[3]+arr2[3]);

            for(y=0;y<5;y++)
            {
                for(x=0;x<8;x++)
                {
                        fgets(buff,5,fp);
                        value = atoi(buff);
                        block1[x][y] = value;
                        gotoxy(arr1[2]+x+offsetX,arr2[2]+y+offsetY);
                        printf("%c",block1[x][y]);
                }

            }


            fgets(buff,5,fp);

            for(i=4;i<6;i++)
            {

                    fgets(buff,7,fp);
                    if(strpbrk(buff," "))
                    {
                        int leN=strpbrk(buff," ")-buff;
                        buff[leN]=NULL;
                        value = atoi(buff);
                        value1 = atoi(&buff[leN+1]);

                        arr1[i]=value;
                        arr2[i]=value1;

                    }
            }

            for(i=0;i<51;i++)
            {
                fgets(buff,5,fp);
                value = atoi(buff);
                btmBlock[i] = value;
                gotoxy(arr1[4]+i+offsetX,arr2[4]+offsetY);
                printf("%c",btmBlock[i]);
            }


                fgets(buff,5,fp);

            for(i=6;i<8;i++)
            {

                    fgets(buff,7,fp);
                    if(strpbrk(buff," "))
                    {
                        int leN=strpbrk(buff," ")-buff;
                        buff[leN]=NULL;
                        value = atoi(buff);
                        value1 = atoi(&buff[leN+1]);

                        arr1[i]=value;
                        arr2[i]=value1;

                    }
            }

            for(y=0;y<5;y++)
            {
                for(x=0;x<8;x++)
                {
                        fgets(buff,5,fp);
                        value = atoi(buff);
                        block2[x][y] = value;
                        gotoxy(arr1[6]+x+offsetX,arr2[6]+y+offsetY);
                        printf("%c",block2[x][y]);
                }

            }


            fgets(buff,5,fp);

            for(i=8;i<10;i++)
            {

                    fgets(buff,7,fp);
                    if(strpbrk(buff," "))
                    {
                        int leN=strpbrk(buff," ")-buff;
                        buff[leN]=NULL;
                        value = atoi(buff);
                        value1 = atoi(&buff[leN+1]);

                        arr1[i]=value;
                        arr2[i]=value1;

                    }
            }

            setColor(arr1[9]+arr2[9]);
            for(y=0;y<3;y++)
            {
                for(x=0;x<51;x++)
                {
                        fgets(buff,5,fp);
                        value = atoi(buff);
                        water[x][y] = value;
                        gotoxy(arr1[8]+x+offsetX,arr2[8]+y+offsetY);
                        printf("%c",water[x][y]);
                }

            }

            gotoxy(arr1[0]+offsetX,arr2[0]+offsetY);
            printf("|_____/");

            int l_pass=1; int max_l_pass=0; int lft=0;
            int r_pass=1;

                do
                {

                    while(sail_mode)
                    {
                        gotoxy(2,4);
                        printf("Sail Mode");
                        gotoxy(arr1[0]+offsetX,arr2[0]+offsetY);
                        userI = getch();

                        switch(userI)
                        {
                            case SPECIAL_KEY:

                                userI = getch();

                                if(userI == RIGHT_ARROW && arr1[0] < arr2[1])
                                {
                                    for(i=0;i<51;i++)
                                    {
                                        gotoxy(9+i+offsetX,arr2[0]+offsetY);
                                        printf(" ");
                                    }
                                    arr1[0]++;
                                    gotoxy(arr1[0]+offsetX,arr2[0]+offsetY);

                                    if(arr1[0] == arr2[1]) {printf("\\"); for(index=0;index<5;index++){printf("%c",insideBt[index]);} printf("|");}
                                    else {printf("|"); for(index=0;index<5;index++){printf("%c",insideBt[index]);} printf("/");}
                                }
                                else if(userI == LEFT_ARROW && arr1[0] > arr1[1])
                                {
                                    for(i=0;i<51;i++)
                                        {
                                            gotoxy(9+i+offsetX,arr2[0]+offsetY);
                                            printf(" ");
                                        }
                                        arr1[0]--;
                                        gotoxy(arr1[0]+offsetX,arr2[0]+offsetY);

                                        if(arr1[0] == arr1[1]) {printf("|"); for(index=0;index<5;index++){printf("%c",insideBt[index]);} printf("/");}
                                        else {printf("\\"); for(index=0;index<5;index++){printf("%c",insideBt[index]);} printf("|");}
                                    }
                                break;

                        }
                        if(userI == 27 || userI == 'l' || userI == 'L') break;
                    }

                    if(userI == 27) break;

                    while(load_mode)
                    {
                        gotoxy(2,4);
                        printf("Load Mode");
                        if(arr1[0]==arr1[1]){}
                        else if(arr1[0]==arr2[1]){}
                        else break;
                        userI = getch();

                        switch(userI)
                        {
                            case 'e':
                                if(left_passenger < 7 && arr1[0]==arr1[1])
                                {
                                    left_passenger++;
                                    if(l_pass == 0)l_pass=0;
                                    gotoxy(arr1[0]-l_pass+offsetX,arr2[0]-1+offsetY);
                                    printf("%c",219);
                                    l_pass++;
                                    gotoxy(arr1[0]-l_pass+offsetX,arr2[0]-1+offsetY);
                                    max_l_pass = left_passenger;
                                }
                                break;

                            case 'r':
                                if(left_passenger > 0 && arr1[0]==arr1[1])
                                {
                                    l_pass--;
                                    gotoxy(arr1[0]-l_pass+offsetX,arr2[0]-1+offsetY);
                                    printf(" ");
                                    left_passenger--;
                                    gotoxy(arr1[0]-l_pass+offsetX,arr2[0]-1+offsetY);
                                }
                                    break;

                            case 'd':
                                if(right_passenger < 7)
                                {
                                    gotoxy(59+r_pass+offsetX,arr2[0]-1+offsetY);
                                    printf("%c",219);
                                    r_pass++;
                                    right_passenger++;
                                    gotoxy(59+r_pass+offsetX,arr2[0]-1+offsetY);
                                }
                                break;

                            case 'f':
                                if(right_passenger > 0)
                                {
                                    r_pass--;
                                    gotoxy(59+r_pass+offsetX,arr2[0]-1+offsetY);
                                    printf(" ");
                                    right_passenger--;
                                    gotoxy(59+r_pass+offsetX,arr2[0]-1+offsetY);
                                }
                                    break;

                            case SPECIAL_KEY:

                                if(kbhit())
                                {
                                    userI = getch();

                                    //LEFT SIDE OF THE POND START

                                    if(arr1[0] == arr1[1])
                                    {
                                        if(userI == RIGHT_ARROW)
                                        {

                                            if(left_passenger > 0 && btIndex != 5)
                                            {
                                                l_pass--;
                                                gotoxy(arr1[0]-l_pass+offsetX,arr2[0]-1+offsetY);
                                                printf(" ");

                                                insideBt[btIndex] = 219;

                                                for(index=0;index<5;index++)
                                                {
                                                    gotoxy(arr1[0]+btIndex+1+offsetX,arr2[0]+offsetY);
                                                    printf("%c",insideBt[btIndex]);
                                                }

                                                btIndex++;
                                                left_passenger--;
                                            }

                                        }
                                        else if(userI == LEFT_ARROW) //start of left key
                                        {
                                            if(left_passenger < 8 && btIndex != 0)
                                            {
                                                l_pass++;
                                                gotoxy(arr1[0]-l_pass+1+offsetX,arr2[0]-1+offsetY);
                                                printf("%c",219);

                                                if(btIndex==0)btIndex=0;
                                                if(btIndex == 5)insideBt[btIndex] = 95;
                                                insideBt[btIndex-1] = 95;

                                                for(index=0;index<5;index++)
                                                {
                                                    gotoxy(arr1[0]+btIndex+offsetX,arr2[0]+offsetY);
                                                    printf("%c",insideBt[btIndex]);
                                                }

                                                btIndex--;
                                                left_passenger++;
                                            }


                                        } // End of letf key

                                    }
                                    //LEFT SIDE OF THE POND END

                                    //RIGHT SIDE OF THE POND START

                                    if(arr1[0] == arr2[1])
                                    {
                                        if(userI == RIGHT_ARROW)
                                        {

                                            if(right_passenger > 0 && btIndex != 5)
                                            {

                                                r_pass--;
                                                gotoxy(59+r_pass+offsetX,arr2[0]-1+offsetY);
                                                printf(" ");

                                                insideBt[btIndex] = 219;

                                                for(index=0;index<5;index++)
                                                {
                                                    gotoxy(arr1[0]-btIndex+5+offsetX,arr2[0]+offsetY);
                                                    printf("%c",insideBt[btIndex]);
                                                }

                                                btIndex++;
                                                right_passenger--;
                                            }
                                        }
                                        else if(userI == LEFT_ARROW)
                                        {
                                            if(right_passenger < 7 && btIndex != 0)
                                            {

                                                r_pass++;
                                                gotoxy(59+r_pass-1+offsetX,arr2[0]-1+offsetY);
                                                printf("%c",219);

                                                if(btIndex==0)btIndex=0;
                                                if(btIndex == 5)insideBt[btIndex] = 95;
                                                insideBt[btIndex-1] = 95;

                                                for(index=0;index<5;index++)
                                                {
                                                    gotoxy(arr1[0]-btIndex+6+offsetX,arr2[0]+offsetY);
                                                    printf("%c",insideBt[btIndex]);
                                                }

                                                btIndex--;
                                                right_passenger++;
                                            }

                                        }

                                    //RIGHT SIDE OF THE POND END

                                    }

                                break;
                                }
                        }
                        if(userI == 27 || userI == 's' || userI == 'S') break;
                    }

                    if(userI == 27) break;


                }while(userI != 27);
        }
        else if(userI == 'E' || userI == 'e')
        {
            run = 0;
            Sleep(1000);
        }
        clrscr();setColor(0*16+15);
    }while(run);


    return 0;
}

void drawBox(int posX, int posY, int width, int height)
{
    int i;
    gotoxy(posX,posY);
    printf("\xDA");
    gotoxy(posX+width,posY);
    printf("\xBF");
    gotoxy(posX,posY+height);
    printf("\xC0");
    gotoxy(posX+width,posY+height);
    printf("\xD9");
    for(i=1;i<width;i++)
    {
        gotoxy(posX+i,posY);
        printf("\xC4");

        gotoxy(posX+i,posY+height);
        printf("\xC4");
    }

    for(i=1;i<height;i++)
    {
        gotoxy(posX,posY+i);
        printf("\xB3");

        gotoxy(posX+width,posY+i);
        printf("\xB3");
    }
}

void aboutClear()
{
    int i,j;
    for(i=0;i<6;i++)
    {
        for(j=0;j<48;j++)
        {
            gotoxy(22+j,9+i);
            printf(" ");
        }
    }
}
