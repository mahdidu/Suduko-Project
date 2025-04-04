#include <iostream>
#include <conio.h>
#include "clui.h"
#include <ctime>
#include <algorithm>
//First change
using namespace std;
time_t start = time(0),endd;
int pnum=0;
struct game{
    char name[100];
    int point=0;
    int dorost=0;
    int ghalat=0;
    int time=0;
    int winrate=0;
    int loserate=0;
    int level=0;
};
struct player{
    char name[100];
    int point=0;
    int dorost=0;
    int ghalat=0;
    int time=0;
    int winrate=0;
    int loserate=0;
};
player players[100];
int level,num=0;
game pl[100];

int eror=0;
int defualt_sudoko[9][9]={
    {5,3,0, 0,7,0, 0,0,0},
    {6,0,0, 1,9,5, 0,0,0},
    {0,9,8, 0,0,0, 0,6,0},

    {8,0,0, 0,6,0, 0,0,3},
    {4,0,0, 8,0,3, 0,0,1},
    {7,0,0, 0,2,0, 0,0,6},

    {0,6,0, 0,0,0, 2,8,0},
    {0,0,0, 4,1,9, 0,0,5},
    {0,0,0, 0,8,0, 0,7,9}
};
int defualt_copy[9][9]={
    {5,3,0, 0,7,0, 0,0,0},
    {6,0,0, 1,9,5, 0,0,0},
    {0,9,8, 0,0,0, 0,6,0},

    {8,0,0, 0,6,0, 0,0,3},
    {4,0,0, 8,0,3, 0,0,1},
    {7,0,0, 0,2,0, 0,0,6},

    {0,6,0, 0,0,0, 2,8,0},
    {0,0,0, 4,1,9, 0,0,5},
    {0,0,0, 0,8,0, 0,7,9}
};
int tr_sudoko[9][9]={
    {5,3,4, 6,7,8, 9,1,2},
    {6,7,2, 1,9,5, 3,4,8},
    {1,9,8, 3,4,2, 5,6,7},

    {8,5,9, 7,6,1, 4,2,3},
    {4,2,6, 8,5,3, 7,9,1},
    {7,1,3, 9,2,4, 8,5,6},

    {9,6,1, 5,3,7, 2,8,4},
    {2,8,7, 4,1,9, 6,3,5},
    {3,4,5, 2,8,6, 1,7,9}
};

struct saved{
    char player_name[100];
    char name[100];
    int draft[9][9];
    int dorost=0;
    int ghalat=0;
    int time=0;
    int point=0;
    int level=0;
};
int num2=0;
saved s[100];

int saving(){
    system("cls");
    int row = get_window_rows();
    int column = get_window_cols();
    change_color_rgb(237, 237, 14);
    cursor_to_pos(row / 2 , column / 2 -5);
    cout<<"chose name for your draft";
    cursor_to_pos(row / 2+1 , column / 2 -5);
    cin>>s[num2].name;
    for (int i=0;i<100;i++)
        s[num2].player_name[i]=pl[num].name[i];
    s[num2].dorost=pl[num].dorost;
    s[num2].ghalat=pl[num].ghalat;
    s[num2].time=pl[num].time;
    s[num2].point=pl[num].point;
    s[num2].level=pl[num].level;
    for (int i=0;i<9;i++){
        for (int j=0;j<9;j++){
            s[num2].draft[i][j]=defualt_sudoko[i][j];
        }
    }
    num2++;
    return 0;
}

int cursorRow = 0, cursorCol = 0;
int chart(int row, int column) {
    system("cls");
    int t=0;
    int copy;
    for (int i = 0; i < 9; i++) {
        /*endd=time(0);
        double pl[num].time = difftime(endd, start);
        change_color_rgb(237, 237, 14);
        cursor_to_pos(row / 2 - 10, column / 2 );
        cout<<"time = "<< pl[num].time;*/
        cursor_to_pos(row / 2 + i + t, column / 2 );
        cout<<"---------------------------------------------";
        for (int j = 0; j < 9; j++) {
            cursor_to_pos(row / 2 + i+1+t, column / 2 + j * 5);
            if (i == cursorRow && j == cursorCol) {
                change_color_rgb(237, 237, 14);
                cout<<"| ";
                change_color_rgb(237, 237, 14);
                cout<<defualt_sudoko[i][j];
                copy=defualt_sudoko[i][j];
            } 
            else {
                change_color_rgb(237, 237, 14);
                cout<<"| "<<defualt_sudoko[i][j];
                
            }
        }
        change_color_rgb(237, 237, 14);
        cout<<" |";
        t++;
    }
    cursor_to_pos(row / 2 + cursorRow * 2 + 1, column / 2 + cursorCol * 5 + 2);
    return copy;
}

int show(int sit){
    system("cls");
    int row = get_window_rows();
    int column = get_window_cols();
    change_color_rgb(237, 237, 14);
    cursor_to_pos(row / 2 , column / 2 -5);
    if (sit==1){
        cout<<"you won!";
    }
    else {
        cout<<"you lose!";
    }
    cursor_to_pos(row / 2 +1, column / 2 -5);
    cout<<"point: "<<pl[num].point;
    
    cursor_to_pos(row / 2 +2, column / 2 -5);
    cout<<"correct: "<<pl[num].dorost;
    cursor_to_pos(row / 2 +3, column / 2 -5);
    cout<<"incorrect: "<<pl[num].ghalat;
    cursor_to_pos(row / 2 +4, column / 2 -5);
    cout<<"time: "<<pl[num].time;
    cursor_to_pos(row / 2 +5, column / 2 -5);
    cout<<"winrate: "<<pl[num].winrate;
    cursor_to_pos(row / 2 +6, column / 2 -5);
    cout<<"loserate: "<<pl[num].loserate;
    cursor_to_pos(row / 2 +8, column / 2 );
    cout<<"enter m to leave";
    for (int i=0;i<pnum;i++){
        if (strcmp(players[i].name,pl[num].name)==0){
            players[i].point+=pl[num].point;
            players[i].dorost+=pl[num].dorost;
            players[i].ghalat+=pl[num].ghalat;
            players[i].time+=pl[num].time;
            players[i].winrate+=pl[num].winrate;
            players[i].loserate+=pl[num].loserate;
            
        }
    }
    
    char ch;
    while (true){
        ch=getch();
        if (ch=='m'){
            return 0;
        }
    }

}
int numbers=0;


int moveCursor(int fgh) {
    system("cls");
    int row = get_window_rows();
    int column = get_window_cols();
    char ch;
    level=pl[num].level
    if (fgh!=3){
        change_color_rgb(237, 237, 14);
        cursor_to_pos(row / 2 , column / 2 -5);
        cout<<"chose your level :";
        cursor_to_pos(row / 2 +1, column / 2 -5);
        cout<<"1: easy";
        cursor_to_pos(row / 2 +2, column / 2 -5);
        cout<<"2: medium";
        cursor_to_pos(row / 2 +3, column / 2 -5);
        cout<<"3: hard";
        cursor_to_pos(row / 2 + 4, column / 2 -5);
        cin>>level;
        for (int i=0;i<9;i++){
            for (int j=0;j<9;j++){
                if (defualt_copy[i][j]==0)
                    defualt_sudoko[i][j]=0;
            }
        }
    }
    int d=0;
    int now = chart(row, column);
    start = time(0);
    while (true) {
        endd=time(0);
        pl[num].time = difftime(endd, start);
        if (level==3){
            if (pl[num].time==120){
                system("cls");
                cursor_to_pos(row / 2, column / 2 );
                cout<<"ha ha ha you lose";
                delay(1000);
                show(0);
                return 0;
            }
        }
        if (level==2){
            if (pl[num].time==180){
                system("cls");
                cursor_to_pos(row / 2, column / 2 );
                cout<<"ha ha ha you lose";
                delay(1000);
                show(0);
                return 0;
            }
        }
        if (level==1){
            if (pl[num].time==300){
                system("cls");
                cursor_to_pos(row / 2, column / 2 );
                cout<<"ha ha ha you lose";
                delay(1000);
                show(0);
                return 0;
            }
        }
        change_color_rgb(237, 237, 14);
        cursor_to_pos(row / 2 - 10, column / 2 );
        
        cout<<"time = "<< pl[num].time;
        cursor_to_pos(row / 2 + cursorRow * 2 + 1, column / 2 + cursorCol * 5 + 2);

        if (_kbhit()) {
            int now = chart
        (row, column);
            ch = getch();
            
            /*system("cls");
            cout<<(int)ch;
            delay(1000);*/
            if (ch == 27) break;
            else if (ch==72){
                if (cursorRow>0)
                    cursorRow--;
            }
            else if (ch==80){
                if (cursorRow<8)
                    cursorRow++;
            }
            else if (ch==75){
                if (cursorCol>0)
                    cursorCol--;
            }
            else if (ch==77){
                if (cursorCol<8)
                    cursorCol++;
            }
            else if (ch=='q'){
                system("cls");
                cursor_to_pos(row / 2, column / 2 );
                cout<<"ha ha ha you lose";
                pl[num].loserate+=1;
                delay(1000);
                show(0);
                return 0;
            }
            else if (ch=='s'){
                saving();
                return 0;
            }
            
            else if ( ch>'9' && ch!=-32 && ch!=77 && ch!=80 && ch!=75 && ch!=77 ){
                system("cls");
                cursor_to_pos(row / 2, column / 2 );
                cout<<"wrong input!";
                delay(500);
                int now = chart
            (row, column);
            }
            
            
            if (ch >= '1' && ch <= '9'){
                if (defualt_copy[cursorRow][cursorCol] == 0){
                    if (tr_sudoko[cursorRow][cursorCol] == ch - '0'){
                        defualt_sudoko[cursorRow][cursorCol]=ch - '0';
                        int now = chart(row, column);
                        pl[num].point+=1;
                        pl[num].dorost+=1;
                        d+=1;
                        if (d==51){
                            system("cls");
                            cursor_to_pos(row / 2, column / 2 );
                            cout<<"goodjob you win!";
                            pl[num].winrate+=1;
                            delay(1000);
                            show(1);
                            return 0;
                        }
                    }
                    else{
                        
                        eror++;
                        pl[num].point-=1;
                        pl[num].ghalat+=1;
                        if (eror==3){
                            system("cls");
                            cursor_to_pos(row / 2, column / 2 );
                            cout<<"ha ha ha you lose";
                            pl[num].loserate+=1;
                            delay(1000);
                            show(0);
                            return 0;
                        }
                        system("cls");
                        cursor_to_pos(row / 2, column / 2 );
                        cout<<"wrong choice be careful!";
                        delay(1000);
                        int now = chart(row, column);
                    }
                
            }
        }
    }
    }
}
int stttart(){
    int row = get_window_rows();
    int column = get_window_cols();
    char m[100];
    system("cls");
    cursor_to_pos(row / 2, column / 2);
    change_color_rgb(237, 237, 14);
    cout<<"chose username:";
    delay(1000);
    cursor_to_pos(row / 2+1, column / 2);
    cin>>pl[num].name;
    int t=0;
    if (num!=0){
        while (t!=1){
            for (int i=0;i<num;i++){
                if (strcmp(pl[i].name,pl[num].name)==0){
                    system("cls");
                    cursor_to_pos(row / 2, column / 2);
                    change_color_rgb(237, 237, 14);
                    cout<<"already taken chose another one:";
                    cursor_to_pos(row / 2+1, column / 2);
                    cin>>pl[num].name;
                    break;
                }
                if (i==num-1)
                    t=1;
            }
        }
    }
    for (int i=0;i<100;i++)
        players[pnum].name[i]=pl[num].name[i];
    pnum++;

    
    
    return 0;

}
int show_saved(){
    int t=0;
    int row = get_window_rows();
    int column = get_window_cols();
    system("cls");
    for (int i=0;i<num2;i++){
        if (strcmp(s[i].player_name,pl[num].name)==0){
            cursor_to_pos(row / 2+t, column / 2);
            change_color_rgb(237, 237, 14);
            cout<<s[i].name<<endl;
        }
        t++;
    }
    char m[100];
    cursor_to_pos(row / 2+t, column / 2);
    change_color_rgb(237, 237, 14);
    cin>>m;
    for (int i=0;i<num2;i++){
        if (strcmp(m,s[i].name)==0){
            for (int k=0;k<9;k++){
                for (int j=0;j<9;j++){
                    defualt_sudoko[k][j]=s[i].draft[k][j];
                }
            }
            for (int j=0;j<100;j++)
                s[num2].player_name[j]=pl[num].name[j];
            pl[num].point=s[i].point;
            pl[num].dorost=s[i].dorost;
            pl[num].ghalat=s[i].ghalat;
            pl[num].time=s[i].time;
            pl[num].level=s[i].level;

        }
    }
    moveCursor(3);
}



    
bool comparePlayers(const player &a, const player &b) {
    return a.point > b.point;
}

int grades() {
    int row = get_window_rows();
    int column = get_window_cols();
    
    system("cls");
    cursor_to_pos(row / 2, column / 2-20);
    change_color_rgb(237, 237, 14);

    

    sort(players, players + pnum, comparePlayers);

    cout << "Rank\tName\tPoints\tCorrect\tWrong\tTime\tWinrate\tLoserate\n";
    cursor_to_pos(row / 2+1, column / 2-20);
    change_color_rgb(237, 237, 14);
    cout << "--------------------------------------------------------------\n";
    for (int i = 0; i < pnum+1; i++) {
        cursor_to_pos(row / 2+2+i, column / 2-20);
        cout << i + 1 << "\t" << players[i].name << "\t"
             << players[i].point << "\t" << players[i].dorost << "\t"
             << players[i].ghalat << "\t" << players[i].time << "\t"
             << players[i].winrate << "\t" << players[i].loserate << endl;
    }
    getch();
    return 0;
}
int main() {
    int a=0;
    stttart();
    int row = get_window_rows();
    int column = get_window_cols();
    eror = 0;
    while (true){
        system("cls");
        cursor_to_pos(row / 2, column / 2);
        change_color_rgb(237, 237, 14);
        cout<<"1: Start a new game!"<<endl;
        cursor_to_pos(row / 2+1, column / 2);
        cout<<"2: Play a saved game!"<<endl;
        cursor_to_pos(row / 2+2, column / 2);
        cout<<"3: LeaderBoard"<<endl;
        cursor_to_pos(row / 2+3, column / 2);
        cout<<"4: Exit"<<endl;
        cursor_to_pos(row / 2 + 4, column / 2);
        change_color_rgb(237, 237, 14);
        cin>>a;
        if (a==1){   
            moveCursor(1);
        }
        if (a==2){
            show_saved();
        }
        if (a==3){
            grades();
        }
        if (a==4){ 
            num++;
            stttart();
        }
    }
    return 0;
}
