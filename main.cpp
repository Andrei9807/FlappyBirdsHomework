#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <unistd.h>
#include <fstream>
using namespace std;
bool gameOver;
const int width = 50;
const int height = 20;
int x, y, powerUPx,powerUPy, score=0,wallY,temporalCreativ=width/2+10,temporalDistructiv=-5,time=0,nimic=0;
int wallYhole=rand()%height+1;
int inPillar1=rand()%height+1;
int inPillar2=rand()%height+1;
enum birdDirection { STOP = 0 , UP , DOWN };
birdDirection dir;
void Setup()
{
    gameOver = false;
    dir = DOWN;
    x = width/2-5;
    y = height/2-5;
    powerUPx= width/2-5;
    powerUPy=rand()%height+1;
    score = 0;
    time=0;
    wallYhole=rand()%height+1;
    inPillar1=rand()%height+1;
    inPillar2=rand()%height+1;
    temporalCreativ=width/2+10;
    temporalDistructiv=-5;
}
void Tempo()
{  time++;
    if(time==width/4+width/2+5)
    {
        temporalCreativ=width/2+10;
        temporalDistructiv=-5;
        time=0;
        wallYhole=rand()%height+1;
        inPillar1=rand()%height+1;
        inPillar2=rand()%height+1;

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


           if(j==temporalCreativ-temporalDistructiv+width-height)
               {
                if(inPillar1==i ||inPillar1==i+1 ||inPillar1==i-1)
                  cout<<" ";

                else
                    cout<<"#";

                goto jump;

               }


            if(j==temporalCreativ-temporalDistructiv+width+10)
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
    if((y==inPillar1 && x==temporalCreativ-temporalDistructiv+width-height)||(y==inPillar1-1 && x==temporalCreativ-temporalDistructiv+width-height)||(y==inPillar1+1 && x==temporalCreativ-temporalDistructiv+width-height))
        score++;
    if((y!=inPillar1 && x==temporalCreativ-temporalDistructiv+width-height)&&(y!=inPillar1-1 && x==temporalCreativ-temporalDistructiv+width-height)&&(y!=inPillar1+1 && x==temporalCreativ-temporalDistructiv+width-height))
       gameOver=true;
    if((y==inPillar2 && x==temporalCreativ-temporalDistructiv+width+10)||(y==inPillar2-1 && x==temporalCreativ-temporalDistructiv+width+10)||(y==inPillar2+1 &&x==temporalCreativ-temporalDistructiv+width+10))
        score++;
    if((y!=inPillar2 && x==temporalCreativ-temporalDistructiv+width+10)&&(y!=inPillar2-1 && x==temporalCreativ-temporalDistructiv+width+10)&&(y!=inPillar2+1 &&x==temporalCreativ-temporalDistructiv+width+10))
        gameOver=true;

    if(x == powerUPx && y == powerUPy)
    {
        score++;
    powerUPx= width/2-5;
    powerUPy=rand()%height+1;
    }
}
void Menu();
void CheckScore()
{   int scorMaxim;
    ifstream f("scorMaxim.txt");
    f>>scorMaxim;
    f.close();
    ofstream g("scorMaxim.txt");
    if(score>scorMaxim)
       {
           scorMaxim=score;
          g<<scorMaxim;
       }
       else
       {
           g<<scorMaxim;
       }
    g.close();
    cout<<"Your highest score is: ";
    cout<<scorMaxim;
    cout<<endl;
    cout<<"Going back to menu?[y/n]";
    char caracter;
    cin>>caracter;
    if(caracter=='y')
        Menu();

    else
        return;

}
void Menu()
{   int tasta;
    system("cls");
    cout<<endl;
    cout<<"Welcome"<<endl;
    cout<<" M E N U:"<<endl<<endl;
    cout<<"1.Start Game"<<endl<<endl;
    cout<<"2.Check the HighScore"<<endl<<endl;
    cout<<"3.How to play"<<endl<<endl;
    cout<<"4.Exit"<<endl<<endl;
    cout<<"TIP: Please choose one option from above and hit ENTER"<<endl<<endl;
    cout<<"Your choice: ";
    cin>>tasta;
    if(tasta==1)
    {
        Setup();
        while(!gameOver)
       {

        Draw();
        Input();
        Logic();
        usleep(100000);
       }
       cout<<endl;
       cout<<"Well played!"<<endl;
       CheckScore();
    }
    if(tasta==2)
    {

      CheckScore();

    }
    if(tasta==3)
    {
      cout<<"Press 'z' to fly , press 'x' to end the game"<<endl;
      cout<<"If you get the Power-Up , your score is increased by 1"<<endl;
      cout<<"Don't hit the pillars, the ground, or the sky, this will kill you";
      cout<<endl;
      cout<<"Going back to menu?[y/n]";
      char caracter;
      cin>>caracter;
      if(caracter=='y')
        Menu();

    else
        return;
    }
    if(tasta==4)
    {
        return;
    }

}
int main()
{
    Menu();
    return 0;
}
