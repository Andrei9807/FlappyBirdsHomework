#include <iostream>
#include <cstdlib>
using namespace std;
bool gameOver;
const int width = 20;
const int height = 20;
int x, y, powerUPx,powerUPy, score;
enum birdDirection { STOP = 0 , UP , DOWN };
birdDirection dir;
void Setup()
{
    gameOver = false;
    dir = DOWN;
    x = width/2;
    y = height/2;
    powerUPx= rand()%width;
    powerUPy= rand()%height;
    score = 0;
}
void Draw()
{
    system("cls");
    for (int i=0; i < width ; i++)
        cout<< "#";
    cout<<endl;


    for(int i=0; i < height ;i++)
    {
        for(int j=0 ; j <width ; j++)
        {
            if(j==0)
                cout<<" ";
        }
        cout<<endl;
    }

    for (int i=0; i< width ; i++)
        cout<<"#";
    cout<<endl;

}
void Input()
{

}
void Logic()
{

}
int main()
{
    Setup();
    while(!gameOver)
    {
        Draw();
        Input();
        Logic();
    }
    return 0;
}
