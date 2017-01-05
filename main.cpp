#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <unistd.h>
using namespace std;
bool gameOver;
const int width = 35;
const int height = 20;
int x, y, powerUPx,powerUPy, score=0,wallY,temporalCreativ=width/2+10,temporalDistructiv=-5,time=0;
int wallYhole=2+rand()%((height-1-2)+1);
enum birdDirection { STOP = 0 , UP , DOWN };
birdDirection dir;
void Setup()
{
    gameOver = false;
    dir = DOWN;
    x = width/2-5;
    y = height/2-5;
    powerUPx= rand()%width;
    powerUPy= rand()%height;
    score = 0;
}
void Tempo()
{  time++;
    if(time==width/2+11)
    {
        temporalCreativ=width/2+10;
        temporalDistructiv=-5;
        time=0;
        wallYhole=2+rand()%((height-1-2)+1);

    }
    temporalCreativ--;
    temporalDistructiv++;
}
void Draw()
{
    system("cls");
    for (int i=0; i < width; i++)
        cout<< "#";
    cout<<endl;

    for(int i=0; i < height ;i++)
    {
       wallY=i;
        for(int j=0 ; j <width ; j++)
        {

            if(j==0)
                cout<<" ";
            if(wallYhole==wallY || wallYhole==wallY+1 || wallYhole==wallY-1)
                goto jump;
            if(j==temporalCreativ-temporalDistructiv)
                cout<<"#";
             jump:

            if(j==temporalCreativ-temporalDistructiv+14)
                cout<<"#";

            if(j==temporalCreativ-temporalDistructiv+28)
                cout<<"#";

            if(i==y && j==x)
                cout<< "O";

            //if(i==powerUPy && j==powerUPx)
                //cout<<"*";
           // else
                cout<<" ";

        }
        cout<<endl;
    }

    for (int i=0; i< width ; i++)
        cout<<"#";
    cout<<endl;
    cout<<"Score:"<<score<<endl;
    Tempo();
}

void Input()
{
   if(_kbhit())
   {
       switch(_getch())
       {
       case 'z':
         dir = UP;
         break;
       case 'x':
         gameOver=true;
         break;
       }
   }
   else
    dir=DOWN;
}
void Logic()
{
    switch(dir)
    {
    case UP:
        y--;
        break;
    case DOWN:
        y++;
        break;
    default:
        break;
    }
    if(y>height || y<0)
        gameOver=true;

    if(x == powerUPx && y == powerUPy)
    {
    powerUPx= rand()%width;
    powerUPy= rand()%height;
    }
}
int main()
{
    Setup();
    while(!gameOver)
    {

        Draw();
        Input();
        Logic();
        usleep(100000);
    }
    return 0;
}
