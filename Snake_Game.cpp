#include <iostream>
#include <string>
#include <conio.h>
#include <windows.h>

using namespace std;
bool gameover;
const int height=20;
const int width=20;

int x,y,fruitx,fruity,score;
int tailx[100],taily[100],ntail=0;

enum eDierction{STOP=0,UP,DOWN,LEFT,RIGHT};
eDierction dir;

void setup(){
    dir=STOP;
    gameover=false;
    x=width/2;
    y=height/2;
    fruitx=rand()% width;;
    fruity=rand()% height;
}



void Input(){
    if(_kbhit()){
  switch(_getch()){
    case 'w':
       dir=UP;
       break;

       case 'a':
               dir=LEFT;
                break;

          case 'd':
                  dir=RIGHT;
                  break;
           
           case 's':

                  dir=DOWN;
                  break;
 default:
 break;
  }
}



}
void Draw(){
    system("cls");
    for(int i=0;i<width;i++){
        cout<<"#";
    }
    cout<<endl;
    for(int i=0;i<height;i++){
       for(int j=0;j<width;j++){
        cout<<"#";
        }
         if(i==y && j==x){
            cout<<"O";
        }
        else if (i==fruity && j==fruitx)
        {
            cout<<"$";
        }
        else{
            bool print =false;
            for(int k=0;k<ntail;k++){
                if(i==taily[k] && j==tailx[k])
                {
                    cout<<"o";
                    print = true;
                }
                 if(!print)
        {
            cout<<" ";
        }
            }
        }
       
        cout<<endl;

    for(int i=0;i<width;i++){
        cout<<"#";
    }
    cout<<endl;
    cout<<endl;
    cout<<"score :"<<score<<endl;
}
}
void logic(){
 int prevx=tailx[0];
 int prevy=taily[0];

   tailx[0] = x;
   taily[0] = y;
 int prev2x,prev2y;
 for(int i=1;i<ntail;i++){
    prev2x = tailx[i];
    prev2y = taily[i];
    tailx[i] = prevx;
    taily[i] = prevy;
    prevx = prev2x;
    prevy = prev2y;

 }
    switch (dir)
    {
        case UP:
        y--;
        break;

        case RIGHT:
                 x++;
                 break;

        case LEFT:
                  x--;
                 break;
          case DOWN:
         y++;
         break;

    default:
        break;
    }

    if(x<=0 ||x>=width ||y<=0 ||y>=height){
        gameover =true;
    }
    for(int i=0;i<ntail;i++){
        if(x==tailx[i] && y==taily[i]){
            gameover= true;
        }
    }
    if(x==fruitx && y==fruity){
        score+=10;
         fruitx=rand()% width;
          fruity=rand()% height;
          ntail ++;
    }
}  

int main(){
 setup();
 while (!gameover){
    Draw();
    Input();
    logic();
    Sleep(500);
 }
   
  return 0;
}