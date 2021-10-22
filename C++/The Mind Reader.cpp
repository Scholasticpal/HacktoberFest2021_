The Mind Reader

#include<conio.h>
#include<stdio.h>
#include<dos.h>
#include<stdlib.h>

void First_Card(void);void Second_Card(void);
void Third_Card(void);void Fourth_Card(void);
void Fifth_Card(void);void Sixth_Card(void);
void Analyze(void); Check(void);
void main(void)
{  int ans=0,in=0;
   clrscr();
   _setcursortype(_NOCURSOR);
   First_Card();
     in=Check(); if (in==0) ans+=1;
   Second_Card();
     in=Check(); if (in==0) ans+=2;
   Third_Card();
     in=Check(); if (in==0) ans+=4;
   Fourth_Card();
     in=Check(); if (in==0) ans+=8;
   Fifth_Card();
     in=Check(); if (in==0) ans+=16;
   Sixth_Card();
     in=Check(); if (in==0) ans+=32;
     textcolor(WHITE);textbackground(BLACK);
     clrscr(); Analyze();     clrscr();
   if(ans>60) {gotoxy(20,12);printf("You Entered Incorrect Information.");}
   else
   {gotoxy(28,13);printf("Your No Is : "%d"",ans);}

}

void First_Card(void)
{