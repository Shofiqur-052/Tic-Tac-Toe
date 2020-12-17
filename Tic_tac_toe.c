#include <bits/stdc++.h>
#include <math.h>
#include <string.h>

using namespace std;

int f=0;

void tic_show(int a[][3], char s[][18])
{
    int i, k, x, y;
    for(i=0; i<9; i++)
    {
        for(k=0; k<17; k++)
        {
            if(i==1 || i==4 || i==7)
            {
                if(k==2 || k==8 || k==14)
                {
                    if(i!=1) x=abs(i-5);
                    else x=0;

                    if(k==2) y=0;
                    else if(k==8) y=1;
                    else y=2;

                    if(f==0) cout << a[x][y];
                    else
                    {
                        if(a[x][y]==0) cout << "O";
                        else if(a[x][y]==1) cout << "X";
                        else cout << s[i][k];
                    }
                }
                else cout << s[i][k];
            }
            else cout << s[i][k];
        }
        cout << endl;
    }
    cout << endl;
    f++;
}
int self_check(int a[][3])
{
    int i, k, sum;

    for(i=0; i<3; i++)
    {
        sum=0;
        for(k=0; k<3; k++) sum+=a[i][k];

        if(sum==9)
        {
            a[i][0]=0;
            a[i][1]=0;
            a[i][2]=0;
            return 1;
        }
    }
    for(k=0; k<3; k++)
    {
        sum=0;
        for(i=0; i<3; i++) sum+=a[i][k];

        if(sum==9)
        {
            a[0][k]=0;
            a[1][k]=0;
            a[2][k]=0;
            return 1;
        }
    }
    if(a[0][0]+a[1][1]+a[2][2]==9)
    {
        a[0][0]=0;
        a[1][1]=0;
        a[2][2]=0;
        return 1;
    }
    if(a[0][2]+a[1][1]+a[2][0]==9)
    {
        a[0][2]=0;
        a[1][1]=0;
        a[2][0]=0;
        return 1;
    }
    return 0;
}
int opp_check(int a[][3])
{
    int i, k, sum;

    for(i=0; i<3; i++)
    {
        sum=0;
        for(k=0; k<3; k++) sum+=a[i][k];

        if(sum==11)
        {
            if(a[i][0]==9) a[i][0]=0;
            else if(a[i][1]==9) a[i][1]=0;
            else a[i][2]=0;
            return 1;
        }
    }
    for(k=0; k<3; k++)
    {
        sum=0;
        for(i=0; i<3; i++) sum+=a[i][k];

        if(sum==11)
        {
            if(a[0][k]==9) a[0][k]=0;
            else if(a[1][k]==9) a[1][k]=0;
            else a[2][k]=0;
            return 1;
        }
    }
    if(a[0][0]+a[1][1]+a[2][2]==11)
    {
        if(a[0][0]==9) a[0][0]=0;
        else if(a[1][1]==9) a[1][1]=0;
        else a[2][2]=0;
        return 1;
    }
    if(a[0][2]+a[1][1]+a[2][0]==11)
    {
        if(a[0][2]==9) a[0][2]=0;
        else if(a[1][1]==9) a[1][1]=0;
        else a[2][0]=0;
        return 1;
    }
    return 0;
}
int corner(int a[][3])
{
    if(a[0][0]==9)
    {
        a[0][0]=0;
        return 1;
    }
    if(a[0][2]==9)
    {
        a[0][2]=0;
        return 1;
    }
    if(a[2][0]==9)
    {
        a[2][0]=0;
        return 1;
    }
    if(a[2][2]==9)
    {
        a[2][2]=0;
        return 1;
    }
    return 0;
}
int mid_side(int a[][3])
{
    if(a[0][1]==9)
    {
        a[0][1]=0;
        return 1;
    }
    if(a[1][0]==9)
    {
        a[1][0]=0;
        return 1;
    }
    if(a[1][2]==9)
    {
        a[1][2]=0;
        return 1;
    }
    if(a[2][1]==9)
    {
        a[2][1]=0;
        return 1;
    }
    return 0;
}
int double_side(int a[][3])
{
    if(a[0][1]==9 && a[2][1]==9)
    {
        a[0][1]=0;
        return 1;
    }
    if(a[1][0]==9 && a[1][2]==9)
    {
        a[1][0]=0;
        return 1;
    }
    return 0;
}
int angel_side(int a[][3])
{
    if(a[0][1]==1)
    {
        if(a[1][0]==1)
        {
            a[0][2]=0;
            return 1;
        }
        if(a[1][2]==1)
        {
            a[0][0]=0;
            return 1;
        }
    }
    if(a[2][1]==1)
    {
        if(a[1][2]==1)
        {
            a[0][2]=0;
            return 1;
        }
        if(a[1][0]==1)
        {
            a[0][0]=0;
            return 1;
        }
    }
    return 0;
}
int can_u(int a[][3])
{
    int i, k, sum;

    for(i=0; i<3; i++)
    {
        sum=0;
        for(k=0; k<3; k++) sum+=a[i][k];

        if(sum==3) return 1;
    }
    for(k=0; k<3; k++)
    {
        sum=0;
        for(i=0; i<3; i++) sum+=a[i][k];

        if(sum==3) return 1;
    }
    if(a[0][0]+a[1][1]+a[2][2]==3) return 1;
    if(a[0][2]+a[1][1]+a[2][0]==9) return 1;

    return 0;
}
int pos_check(int a[][3], int p)
{
    int x, y;

    if(p!=1) x=abs(p-5);
    else x=0;

    if(p<=3)
    {
        y=p-1;
        x=x=0;
    }
    else if(p<=6)
    {
        y=p-4;
        x=1;
    }
    else
    {
        y=p-7;
        x=2;
    }
    if(a[x][y]!=9) return 1;
    return 0;
}

int main()
{
    char s[10][18];
    strcpy(s[0], "     |     |     ");
    strcpy(s[1], "     |     |     ");
    strcpy(s[3], "     |     |     ");
    strcpy(s[4], "     |     |     ");
    strcpy(s[6], "     |     |     ");
    strcpy(s[7], "     |     |     ");
    strcpy(s[8], "     |     |     ");
    strcpy(s[2], "_____|_____|_____");
    strcpy(s[5], "_____|_____|_____");
    
    int b[3][3]={1, 2, 3, 4, 5, 6, 7, 8, 9}, n=1;
    
    cout << "***************************" << endl;
    cout << "*****~> TIC TAC TOE <~*****" << endl;
    cout << "***************************\n" << endl;
    cout << "How to play :-" << endl;
    cout << "1. In your every turn, You need to select a cell number from 1 to 9 given in the picture bellow." << endl;
    cout << "2. In your turn, the cell will be marked as cross 'X' sign, and 'O' for computer's turn" << endl;
    cout << "3. First is your turn. ---- Let's play.\n" << endl;
    tic_show(b, s);
    cout << "Winning rules :-" << endl;
    cout << "1. If u can make a straight line with lining three contiguous 'X' sign, you will win.\n   ";
    cout << "Otherwise computer for 'O' or match would be drawn.\n" << endl;
    cout << ">> Games started !!\n" << endl;

    while(n==1){
    
    int a[3][3]={9, 9, 9, 9, 9, 9, 9, 9, 9}, x, h, r;

    cout << "Enter first point : ";
    char ch[100];
    cin >> ch;
    x=ch[0]-48;
    cout << endl;
    
    while(x<1 || x>9 || pos_check(a, x)==1)
    {
        cout << "Choose another valid number : " << endl;
        char ch[100];
        cin >> ch;
        x=ch[0]-48;
        cout << endl;
    }
    if(x<=3) a[0][x-1]=1;
    else if(x<=6) a[1][x-4]=1;
    else a[2][x-7]=1;

    for(h=1, r=0; h<=4; h++)
    {
        if(self_check(a)==1)
        {
            tic_show(a, s);
            printf("**>>______________You lost :(_____________<<**\n\n");
            r=1;
            break;
        }
        else if(opp_check(a)==1)
        {
            tic_show(a, s);
        }
        else
        {
            if(a[1][1]==1)
            {
                if(corner(a)==0)
                {
                    if(double_side(a)==0)
                    {
                        mid_side(a);
                    }
                }
                tic_show(a, s);
            }
            else
            {
                if(h==1)
                {
                    a[1][1]=0;
                    tic_show(a, s);
                }
                else if(h==2 && ((a[0][1]==1 && a[2][1]==1) || (a[1][0]==1 && a[1][2]==1)))
                {
                    corner(a);
                    tic_show(a, s);
                }
                else if(h==2 && angel_side(a)==1) tic_show(a, s);
                else
                {
                    if(double_side(a)==0)
                    {
                        if(mid_side(a)==0)
                        {
                            corner(a);
                        }
                    }
                    tic_show(a, s);
                }
            }
        }
        cout << "Enter next point : ";
        char ch[100];
        cin >> ch;
        x=ch[0]-48;
        cout << endl;

        while(x<1 || x>9 || pos_check(a, x)==1)
        {
            cout << "Choose another valid number : ";
            char ch[100];
            cin >> ch;
            x=ch[0]-48;
            cout << endl;
        }
        if(x<=3) a[0][x-1]=1;
        else if(x<=6) a[1][x-4]=1;
        else a[2][x-7]=1;  
    }
    if(r==0){
        tic_show(a, s);

        if(can_u(a)==1) cout << "\n**>>___________You Win !! :) :) :)___________<<**\n\n";
        else cout << "\n**>>___________Match draw :)___________<<**\n\n";
    }
    cout << "1. Once more !!\n2. Exit\n\nChoose an option : ";
    cin >> n;
    cout << endl;
    }
    cout << "\n**>>______________The End_______________<<**\n" << endl;

    return 0;
}