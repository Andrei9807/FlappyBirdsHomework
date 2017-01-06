#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <unistd.h>
using namespace std;
bool gameOver;
const int width = 50;
const int height = 20;
int x, y, powerUPx,powerUPy, score=0,wallY,temporalCreativ=width/2+10,temporalDistructiv=-5,time=0,nimic=0;
int wallYhole=2+rand()%((height-1-2)+1);
int inPillar1=2+rand()%((height-1-2)+1);
int inPillar2=2+rand()%((height-1-2)+1);
enum birdDirection { STOP = 0 , UP , DOWN };
birdDirection dir;
void Setup()
{
    gameOver = false;
    dir = DOWN;
    x = width/2-5;
    y = height/2-5;
    powerUPx= width/2-5;
    powerUPy= 2+rand()%((height-1-2)+1);
    score = 0;
}
void Tempo()
{  time++;
    if(time==width/4+width/2+1)
    {
        temporalCreativ=width/2+10;
        temporalDistructiv=-5;
        time=0;
        wallYhole=2+rand()%((height-1-2)+1);
        inPillar1=2+rand()%((height-1-2)+1);
        inPillar2=2+rand()%((height-1-2)+1);

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
                if(i==y && j==x)
                {cout<< "O";
                goto jump;
                }
                 if(i==powerUPy && j==powerUPx)
                {cout<<"*";
                goto jump;}


            if(j==temporalCreativ-temporalDistructiv)
            {
                if(wallYhole==wallY || wallYhole==wallY+1 || wallYhole==wallY-1)
                cout<<" ";
                else
                cout<<"#";
               goto jump;
            }


            if(j==temporalCreativ-temporalDistructiv+width-width/2)
               {
                if(inPillar1==i ||inPillar1==i+1 ||inPillar1==i-1)
                  cout<<" ";

                else
                    cout<<"#";

                goto jump;

               }


            if(j==temporalCreativ-temporalDistructiv+width)
                {
                    if(inPillar2==i || inPillar2==i+1 || inPillar2==i-1)
                        cout<<" ";
                    else
                       cout<<"#";
                    goto jump;

                }

                cout<<" ";
         jump:
             nimic++;
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
    if((y==wallYhole && x==temporalCreativ-temporalDistructiv) || (y==wallYhole+1 && x==temporalCreativ-temporalDistructiv)||(y==wallYhole-1 && x==temporalCreativ-temporalDistructiv))
        score++;
    if((y!=wallYhole && x==temporalCreativ-temporalDistructiv)&&(y!=wallYhole+1 && x==temporalCreativ-temporalDistructiv)&&(y!=wallYhole-1 && x==temporalCreativ-temporalDistructiv))
        gameOver=true;
    if((y==inPillar1 && x==temporalCreativ-temporalDistructiv+width/2)||(y==inPillar1 && x==temporalCreativ-temporalDistructiv+width/2)||(y==inPillar1 && x==temporalCreativ-temporalDistructiv+width/2))
        score++;
    if((y!=inPillar1 && x==temporalCreativ-temporalDistructiv+width/2)&&(y!=inPillar1 && x==temporalCreativ-temporalDistructiv+width/2)&&(y!=inPillar1 && x==temporalCreativ-temporalDistructiv+width/2))
       gameOver=true;
    if((y==inPillar2 && x==temporalCreativ-temporalDistructiv+width)||(y==inPillar2-1 && x==temporalCreativ-temporalDistructiv+width)||(y==inPillar2+1 &&x==temporalCreativ-temporalDistructiv+width))
        score++;
    if((y!=inPillar2 && x==temporalCreativ-temporalDistructiv+width)&&(y!=inPillar2-1 && x==temporalCreativ-temporalDistructiv+width)&&(y!=inPillar2+1 &&x==temporalCreativ-temporalDistructiv+width))
        gameOver=true;

    if(x == powerUPx && y == powerUPy)
    {
    powerUPx= width/2-5;
    powerUPy= 2+rand()%((height-1-2)+1);
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
