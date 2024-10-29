# include "iGraphics.h"
#include<time.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<mmsystem.h>

int pic_x, pic_y;
int scoreindex=0;
bool Music_On=TRUE;
char hall_of_fame[100][20];
#define Timesec 20

typedef struct
{
    int x;
    int y;
    int w;
    int h;
    char filepath[30];
    char text[30];
    char score1[150][10];

} Button;
char scored[2];

char* correctWord();
char** wrongWords();
FILE *fp;

/// NORMAL CODE ===================
int window = 0;

int isPointInRectangle(int px, int py, int rx, int ry, int rw, int rh)
{
    if(px >= rx && px <= (rx+rw) && py >= ry && py <= (ry+rh))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

//////////////////////////////////////////
/// HOME WINDOW (id 0) ===================
//////////////////////////////////////////

#define HOME_WINDOW_BUTON_COUNT 4
Button homeWindowButtons[HOME_WINDOW_BUTON_COUNT];

void initialiseHomeWindow()
{
    homeWindowButtons[0].x = 140;
    homeWindowButtons[0].y = 300;
    homeWindowButtons[0].w = 230;
    homeWindowButtons[0].h = 50;
    strcpy(homeWindowButtons[0].filepath, "large_button.bmp");
    strcpy(homeWindowButtons[0].text, "START");

    homeWindowButtons[1].x = 140;
    homeWindowButtons[1].y = 250;
    homeWindowButtons[1].w = 230;
    homeWindowButtons[1].h = 50;
    strcpy(homeWindowButtons[1].filepath, "large_button.bmp");
    strcpy(homeWindowButtons[1].text, "RULES");

    homeWindowButtons[3].x = 140;
    homeWindowButtons[3].y = 200;
    homeWindowButtons[3].w = 230;
    homeWindowButtons[3].h = 50;
    strcpy(homeWindowButtons[3].filepath, "large_button.bmp");
   strcpy(homeWindowButtons[3].text, "Hall of Fame");

    homeWindowButtons[2].x = 140;
    homeWindowButtons[2].y = 150;
    homeWindowButtons[2].w = 230;
    homeWindowButtons[2].h = 50;
    strcpy(homeWindowButtons[2].filepath, "large_button.bmp");
    strcpy(homeWindowButtons[2].text, "EXIT");
}

/// check mouse click on home window
void handleHomeWindowClicks(int mx, int my)
{
    for(int i = 0; i < HOME_WINDOW_BUTON_COUNT; i++)
    {
        if(isPointInRectangle(mx, my, homeWindowButtons[i].x, homeWindowButtons[i].y, homeWindowButtons[i].w, homeWindowButtons[i].h))
        {
            printf("Button clicked : %d\n", i);
            if(i == 0)
            {
                window = 1; /// any
            }
            else if (i==1){
                window=4;
            }
            else if(i == 2)
            {
                exit(0);
            }
            else if(i==3){
                window=6;
           }
        }
    }
}


void drawHomeWindow()
{
    for(int i = 0; i < HOME_WINDOW_BUTON_COUNT; i++)
    {
        iSetColor(0,0,0);
        ///iFilledRectangle(homeWindowButtons[i].x, homeWindowButtons[i].y, homeWindowButtons[i].w, homeWindowButtons[i].h);
        iShowBMP(homeWindowButtons[i].x, homeWindowButtons[i].y, homeWindowButtons[i].filepath);
        iText(homeWindowButtons[i].x + 20, homeWindowButtons[i].y + 15, homeWindowButtons[i].text, GLUT_BITMAP_TIMES_ROMAN_24);
    }
}

//////////////////////////////////////////
/// WIndow 4(RULES)//////////////////////
////////////////////////////////////////

#define WINDOW_BUTON_COUNT 1
Button WindowButtons4[WINDOW_BUTON_COUNT];

void Window4()
{
    WindowButtons4[0].x = 390;
    WindowButtons4[0].y = 420;
    WindowButtons4[0].w = 230;
    WindowButtons4[0].h = 50;
    strcpy(WindowButtons4[0].filepath, "large_button.bmp");
    strcpy(WindowButtons4[0].text, "BACK");


}


/// check mouse click on home window4
void WindowClicks4(int mx, int my)
{
    for(int i = 0; i < WINDOW_BUTON_COUNT; i++)
    {
        if(isPointInRectangle(mx, my, WindowButtons4[i].x, WindowButtons4[i].y, WindowButtons4[i].w, WindowButtons4[i].h))
        {
            printf("Button clicked : %d\n", i);
            if(i == 0)
            {
                window = 0; /// any
            }

        }
    }
}


void drawWindow4()
{
    for(int i = 0; i < WINDOW_BUTON_COUNT; i++)
    {
        iShowBMP(0,0,"rules.bmp");
        iSetColor(0,0,0);
        ///iFilledRectangle(homeWindowButtons[i].x, homeWindowButtons[i].y, homeWindowButtons[i].w, homeWindowButtons[i].h);
        iShowBMP(WindowButtons4[i].x, WindowButtons4[i].y, WindowButtons4[i].filepath);
        iText(WindowButtons4[i].x + 20, WindowButtons4[i].y + 15, WindowButtons4[i].text, GLUT_BITMAP_TIMES_ROMAN_24);
    }
}


///////////////////////////////////////////
/// START WINDOW  (id 1) ==================
///////////////////////////////////////////

time_t start, curr, deadline, total = 60;

#define WINDOW_BUTON_COUNT_1 2
Button windowButtons1[WINDOW_BUTON_COUNT_1];

void initialiseWindow1()
{
    windowButtons1[0].x = 140;
    windowButtons1[0].y = 300;
    windowButtons1[0].w = 230;
    windowButtons1[0].h = 50;
    strcpy(windowButtons1[0].filepath, "large_button.bmp");
    strcpy(windowButtons1[0].text, "Find The Correct");

    windowButtons1[1].x = 140;
    windowButtons1[1].y = 250;
    windowButtons1[1].w = 230;
    windowButtons1[1].h = 50;
    strcpy(windowButtons1[1].filepath, "large_button.bmp");
    strcpy(windowButtons1[1].text, "BACK");
}
/// check mouse click on home window1
void handleWindowClicks1(int mx, int my)
{
    for(int i = 0; i < WINDOW_BUTON_COUNT_1; i++)
    {
        if(isPointInRectangle(mx, my, windowButtons1[i].x, windowButtons1[i].y, windowButtons1[i].w, windowButtons1[i].h))
        {
            printf("Button clicked : %d\n", i);
            if(i == 0)
            {
                start = time(0);
                window = 2;
            }
            else if(i==1)
            {
                window=0;
            }
        }
    }
}
void drawWindow1()
{
    for(int i = 0; i < WINDOW_BUTON_COUNT_1; i++)
    {
        iSetColor(0,0,0);
        ///iFilledRectangle(windowButtons1[i].x, windowButtons1[i].y, windowButtons1[i].w, windowButtons1[i].h);
        iShowBMP(windowButtons1[i].x, windowButtons1[i].y, windowButtons1[i].filepath);
        iText(windowButtons1[i].x + 20, windowButtons1[i].y + 15, windowButtons1[i].text,GLUT_BITMAP_TIMES_ROMAN_24 );
    }
}


///////////////////////////////////////////
/// OPTION WINDOW  (id 2) ==================
///////////////////////////////////////////

#define WINDOW_BUTON_COUNT_2 6
Button windowButtons2[WINDOW_BUTON_COUNT_2];

char* correctWordList;
char** wrongWordsList;

char options[4][20];

int correctWordIndex;

int isCorrect = 0;
int score = 0;
int optionClicked = 0;

int lifeCounter = 5;

void initialiseWindow2()
{
    iPauseTimer(0);

    isCorrect = -1;

    correctWordList = correctWord();
    wrongWordsList = wrongWords();

    srand(time(NULL));


    correctWordIndex = rand()%4;

    strcpy(options[correctWordIndex], correctWordList);


    int j=0;
    for(int i = 0; i < 4; i++)
    {
        if(i != correctWordIndex)
        {
            strcpy(options[i], wrongWordsList[j]);
            j++;
        }
    }


    /// BUTTON
     //iText(140, 380, " Chose Option :",GLUT_BITMAP_TIMES_ROMAN_24);
      windowButtons2[4].x = 140;
    windowButtons2[4].y = 380;
    windowButtons2[4].w = 230;
    windowButtons2[4].h = 50;
    strcpy(windowButtons2[4].filepath, "large_button.bmp");
    strcpy(windowButtons2[4].text, " Chose Option :");

    windowButtons2[0].x = 140;
    windowButtons2[0].y = 300;
    windowButtons2[0].w = 230;
    windowButtons2[0].h = 50;
    strcpy(windowButtons2[0].filepath, "large_button.bmp");
    strcpy(windowButtons2[0].text, options[0]);

    windowButtons2[1].x = 140;
    windowButtons2[1].y = 250;
    windowButtons2[1].w = 230;
    windowButtons2[1].h = 50;
    strcpy(windowButtons2[1].filepath, "large_button.bmp");
    strcpy(windowButtons2[1].text, options[1]);

    windowButtons2[2].x = 140;
    windowButtons2[2].y = 200;
    windowButtons2[2].w = 230;
    windowButtons2[2].h = 50;
    strcpy(windowButtons2[2].filepath, "large_button.bmp");
    strcpy(windowButtons2[2].text, options[2]);

    windowButtons2[3].x = 140;
    windowButtons2[3].y = 150;
    windowButtons2[3].w = 230;
    windowButtons2[3].h = 50;
    strcpy(windowButtons2[3].filepath, "large_button.bmp");
    strcpy(windowButtons2[3].text, options[3]);

     windowButtons2[5].x = 140;
    windowButtons2[5].y = 10;
    windowButtons2[5].w = 230;
    windowButtons2[5].h = 50;
    strcpy(windowButtons2[5].filepath, "large_button.bmp");
    strcpy(windowButtons2[5].text,"QUIT GAME");
}

/// check mouse click on home window2
void handleWindowClicks2(int mx, int my)
{
    for(int i = 0; i < WINDOW_BUTON_COUNT_2; i++)
    {
        if(isPointInRectangle(mx, my, windowButtons2[i].x, windowButtons2[i].y, windowButtons2[i].w, windowButtons2[i].h))
        {
            printf("Button clicked : %d\n", i);

            if(i == correctWordIndex)
            {
                isCorrect = 1;
                optionClicked = i;
                iResumeTimer(0);
                score += 10;
                sprintf(scored,"%d",score);
                break;
            }
            else if(i==5){
                window=0;
            }

            else if(isCorrect != 1)
            {
                isCorrect = 0;
                optionClicked = i;
            }

        }
        iResumeTimer(0);
    }
}

void drawWindow2()
{
    curr = time(0);
    //iShowBMP(0,0,"window3.bmp");


    /// WORD CORRECT OR INCORRECT
    if(isCorrect == 1)
    {
        iSetColor(0, 255, 0);
        iText(100, 100, "CORRECT", GLUT_BITMAP_TIMES_ROMAN_24);
        //iText(140 + 200, 150 + 50*optionClicked, "TICK IMAGE", GLUT_BITMAP_TIMES_ROMAN_24);
    }
    else if(isCorrect == 0)
    {
        iSetColor(255, 0, 0);
        iText(100, 100, "INCORRECT", GLUT_BITMAP_TIMES_ROMAN_24);
        //iText(140, 100, "WRONG IMAGE", GLUT_BITMAP_TIMES_ROMAN_24);
    }



    iSetColor(0,0,0);

    //iShowBMP(0,0,"option.bmp");


    for(int i = 0; i < WINDOW_BUTON_COUNT_2; i++)
    {
        iSetColor(0,0,0);
        ///iFilledRectangle(windowButtons1[i].x, windowButtons1[i].y, windowButtons1[i].w, windowButtons1[i].h);
        iShowBMP(windowButtons2[i].x, windowButtons2[i].y, windowButtons2[i].filepath);
        iText(windowButtons2[i].x + 20, windowButtons2[i].y + 15, windowButtons2[i].text, GLUT_BITMAP_TIMES_ROMAN_24);
    }

    if((Timesec-curr + start) ==0 )
    {
        window = 3;
        int y=score;
                score=0;
                sprintf(scored,"%d",y);
                FILE *fp=fopen("HallOfFame.txt","a+");
                fprintf(fp, "%d\n", y);
               // fgets(scored,12,fp);

    }

    char time[100];
    sprintf(time, "%d", (Timesec-curr + start));
    //sprintf(scored,"%d",score);





    iText(420,490,"Time:",GLUT_BITMAP_TIMES_ROMAN_24);
    iText(490, 490, time, GLUT_BITMAP_TIMES_ROMAN_24);
    if(score==0){
            iText(10,480,"0",GLUT_BITMAP_TIMES_ROMAN_24);

    }
    else{
    iText(10,480,scored,GLUT_BITMAP_TIMES_ROMAN_24);
    }
}

///WINDOW3//////////////////
////////////////////////////
#define WINDOW_BUTON_COUNT_3 2
Button windowButtons3[WINDOW_BUTON_COUNT_3];

void initialiseWindow3()
{

    windowButtons3[0].x = 140;
    windowButtons3[0].y = 300;
    windowButtons3[0].w = 230;
    windowButtons3[0].h = 50;
    strcpy(windowButtons3[0].filepath, "large_button.bmp");
    strcpy(windowButtons3[0].text, "YOUR SCORE:");

    windowButtons3[1].x = 140;
    windowButtons3[1].y = 250;
    windowButtons3[1].w = 230;
    windowButtons3[1].h = 50;
    strcpy(windowButtons3[1].filepath, "large_button.bmp");
    strcpy(windowButtons3[1].text, "BACK");


}
/// check mouse click on home window3
void handleWindowClicks3(int mx, int my)
{
    for(int i = 0; i < WINDOW_BUTON_COUNT_3; i++)
    {
        if(isPointInRectangle(mx, my, windowButtons3[i].x, windowButtons3[i].y, windowButtons3[i].w, windowButtons3[i].h))
        {
            printf("Button clicked : %d\n", i);

             if(i==1)
            {
                window=1;
            }
        }
    }
}
void drawWindow3()
{
    iShowBMP(0,0,"score.bmp");
    for(int i = 0; i < WINDOW_BUTON_COUNT_3; i++)
    {
        iSetColor(230,153,0);
        ///iFilledRectangle(windowButtons1[i].x, windowButtons1[i].y, windowButtons1[i].w, windowButtons1[i].h);
        //iShowBMP(windowButtons3[i].x, windowButtons3[i].y, windowButtons3[i].filepath);
        if(i==0){
//iSetColor(255,255,255);

                iText(windowButtons3[0].x + 190, windowButtons3[0].y+15 , scored,GLUT_BITMAP_TIMES_ROMAN_24) ;
        }
       // iSetColor(255,255,255);
        iText(windowButtons3[0].x + 20, windowButtons3[0].y + 15, windowButtons3[0].text,GLUT_BITMAP_TIMES_ROMAN_24 );
        iText(windowButtons3[1].x + 60, windowButtons3[1].y + 15, windowButtons3[1].text,GLUT_BITMAP_TIMES_ROMAN_24 );


    }
}
/////////////////////////////////////////
///  WINDOW 6   (HALL OF FAME)///////////
/////////////////////////////////////////
#define WINDOW_BUTON_COUNT_6 1
Button windowButtons6[WINDOW_BUTON_COUNT_6];

void Window6()
{
    windowButtons6[0].x = 150;
    windowButtons6[0].y = 20;
    windowButtons6[0].w = 230;
    windowButtons6[0].h = 50;
    strcpy(windowButtons6[0].filepath, "large_button.bmp");
    strcpy(windowButtons6[0].text, "BACK");


}

void WindowClicks6(int mx, int my)
{
    for(int i = 0; i < WINDOW_BUTON_COUNT_6; i++)
    {
        if(isPointInRectangle(mx, my, windowButtons6[i].x, windowButtons6[i].y, windowButtons6[i].w, windowButtons6[i].h))
        {
            printf("Button clicked : %d\n", i);

             if(i==0)
            {
                window=0;
            }
        }
    }
}
void drawWindow6()
{
    iShowBMP(0,0,"leaderboard.bmp");
    for(int i = 0; i < WINDOW_BUTON_COUNT_6; i++)
    {
        iSetColor(230,153,0);
        iFilledRectangle(windowButtons6[i].x, windowButtons6[i].y, windowButtons6[i].w, windowButtons6[i].h);
        iShowBMP(windowButtons6[i].x, windowButtons6[i].y, windowButtons6[i].filepath);

        iSetColor(255,255,255);
        iText(150,480,"Hall of Fame List:",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(windowButtons6[0].x + 20, windowButtons6[0].y + 15, windowButtons6[0].text,GLUT_BITMAP_TIMES_ROMAN_24 );

    }
    for(int i=0,y=0;i<5;i++){
            iText(240,420-y,*(hall_of_fame+i),GLUT_BITMAP_TIMES_ROMAN_24 );
    y+=50;

    }
}

//////////////////////////////////////
/// MAIN CODE ============================
//////////////////////////////////////////

int index=0;
char photo[12]={"m1.bmp"};
//char hofswap(char **p)
//{
//    int i=*p[0]
//}
//

char **wrongWords()
{
    FILE *out;
    out=fopen("WrongWord.txt","r");
    srand(time(NULL));
    int count2;
    char wrong[3][20];


    char ch;
    count2=200;
    int countx=0;
    int y1=rand()%count2;
    int y2=rand()%count2;
    int y3=rand()%count2;

    while(!feof(out))
    {
        ch=fgetc(out);
        if(ch=='\n')
         {
            countx++;

        }
        if(countx==y1-1)
        {
            break;
        }
    }
    fscanf(out,"%s",wrong);
    rewind(out);

    countx=0;

    while(!feof(out))
    {
        ch=fgetc(out);
        if(ch=='\n')
        {
            countx++;

        }
        if(countx==y2)
        {
            break;
        }
    }
    fscanf(out,"%s",wrong+1);
    rewind(out);

    countx=0;

    while(!feof(out))
    {
        ch=fgetc(out);
        if(ch=='\n')
        {
            countx++;
        }
        if(countx==y3)
        {
            break;
        }
    }
    fscanf(out,"%s",wrong+2);
    //printf("%s %s %s\n",wrong,wrong+1,wrong+2);
    char **p=(char**)malloc(3*sizeof(char*));
    for(int i=0; i<3; i++)
    {
        p[i]=(char *)malloc(20*sizeof(char));
        strcpy(p[i],wrong[i]);
    }

    for(int i=0; i<3; i++)
    {
        printf("%s\n", p[i]);
    }

    return p;  ///return wrong words pointer
    fclose(out);

}

char * correctWord()
{
    FILE *inp;
    inp=fopen("CorrectWord.txt","r");
    srand(time(NULL));
    int count1;
    char right[20];
    char ch;
    count1=260;
    int x1,countx=0;
    x1=rand()%count1;

    while(!feof(inp))
    {
        ch=fgetc(inp);
        if(ch=='\n')
        {
            countx++;
        }
        if(countx==x1-1)
        {
            break;
        }
    }

    fscanf(inp,"%s",right);
    char *rightpr=(char *)malloc(20*sizeof(char));
    strcpy(rightpr,right);

    fclose(inp);
    return rightpr;

}
void randOption()
{
    int i;
    srand(time(NULL));
    //correct=rand()%4;

}


void iDraw()
{


    iClear();

    iShowBMP(pic_x, pic_y, photo);
    //iShowBMP2(0,0,"rectangle.bmp",0);
    iSetColor(244,164,96);

    //iText(160, 170, "Press Enter To Start",GLUT_BITMAP_TIMES_ROMAN_24);

    if(window == 0)
    {
        drawHomeWindow();
    }
    else if(window == 1)
    {
        drawWindow1();
    }
    else if(window==2)
    {
        drawWindow2();
    }
    else if(window ==3){
        drawWindow3();
    }
    else if(window==4){
        drawWindow4();
    }
    else if(window==6){
        drawWindow6();
    }
}


void iMouseMove(int mx, int my)
{
    //place your codes here
}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        //place your codes here
        if(window == 0)
        {
            handleHomeWindowClicks(mx, my);
        }
        else if(window == 1)
        {
            handleWindowClicks1(mx, my);
        }
        else if(window == 2)
        {
            handleWindowClicks2(mx,my);
        }
        else if(window==3){
            handleWindowClicks3(mx, my);
        }
        else if(window==4){
            WindowClicks4(mx,my);
        }
        else if(window==6){
            WindowClicks6(mx,my);
        }

    }
    if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {
        //place your codes here
    }
}

void iKeyboard(unsigned char key)
{
    if(key == 'x')
    {
        //do something with 'x'
        exit(0);
    }
    //place your codes for other keys here
}


void iSpecialKeyboard(unsigned char key)
{

    if(key == GLUT_KEY_END)
    {
        exit(0);
    }
    if(key == GLUT_KEY_LEFT)
    {
        pic_x--;
    }
    if(key == GLUT_KEY_RIGHT)
    {
        pic_x++;
    }
    if(key == GLUT_KEY_UP)
    {
        pic_y++;
    }
    if(key == GLUT_KEY_DOWN)
    {
        pic_y--;
    }
    //place your codes for other keys here
}

void reloadOptions()
{
    initialiseWindow2();
}

int main()
{
    //PlaySound("music.wav",NULL,SND_LOOP|SND_ASYNC);
    iSetTimer(1000, reloadOptions);
    iPauseTimer(0);
    char c;

    //place your own initialization codes here.
    pic_x = 0;
    pic_y = 0;

    //fp=fopen("HallOfFame.txt","a+");

    initialiseHomeWindow();
    initialiseWindow1();
    initialiseWindow2();
    initialiseWindow3();
    Window4();
    Window6();
    //if(Music_On){
   PlaySound("music.wav",NULL,SND_LOOP|SND_ASYNC);
    //}
   FILE *qp=fopen("HallOfFame.Txt","r");
   index = 0;
   while(fscanf(qp, "%s", hall_of_fame[index])!=EOF){
        fgetc(qp);
        index++;

  }
    iInitialize(512, 512, "PictureDemo");
    return 0;

}

