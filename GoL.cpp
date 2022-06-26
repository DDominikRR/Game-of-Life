#include <bits/stdc++.h>
#include <cstdio>
#include <stdlib.h>
#include <iostream>
#include <windows.h>
#define n 50+2
using namespace std;
void tabNULL(int tab[n][n])
{
    for(int i=0;i<=n-1;i++)
    {
        for (int j=0;j<=n-1;j++)
        {
            tab[i][j]=NULL;
        }
    }
}
void tabRAND(int tab[n][n])
{
    for(int i=1;i<=n-2;i++)
    {
        for(int j=1;j<=n-2;j++)
        {
            tab[i][j]=rand()%2;
        }
    }
}
void tabPRINT(int tab[n][n])
{
    for(int i=1;i<=n-2;i++)
    {
        for(int j=1;j<=n-2;j++)
        {
            if(tab[i][j]==0) printf("%c",32);
            else if(tab[i][j]==1) printf("%c",'O');
        }
        cout<<endl;
    }
}
void tabCOPY(int tab[n][n], int tabcopy[n][n])
{
    for(int i=1;i<=n-2;i++)
    {
        for(int j=1;j<=n-2;j++)
        {
            tabcopy[i][j]=tab[i][j];
        }
    }
}
void tabREFRESH(int tab[n][n], int tabcopy[n][n])
{
    int sum;
    for(int i=1;i<=n-2;i++)
    {
        for(int j=1;j<=n-2;j++)
        {
            sum=0;
            for(int k=-1;k<=1;k++)
            {
                for(int o=-1;o<=1;o++)
                {
                    if(k==0 && o==0) continue;
                    sum+=tabcopy[i+k][j+o];
                }
            }
            if      (sum==3 && tabcopy[i][j]==0) {tab[i][j]=1;}
            else if (sum==2 && tabcopy[i][j]==1) {tab[i][j]=1;}
            else if (sum==3 && tabcopy[i][j]==1) {tab[i][j]=1;}
            else    tab[i][j]=0;
        }
    }
}
int main()
{
    int tab[n][n];
    int tabcopy[n][n];
    tabNULL(tab);
    tabNULL(tabcopy);
    srand(time(NULL));
    tabRAND(tab);
    do
    {
    system("cls");
    tabPRINT(tab);
    Sleep(400);
    tabCOPY(tab,tabcopy);
    tabREFRESH(tab,tabcopy);
    }while(1);
    return 0;
}
