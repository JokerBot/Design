#include<bits/stdc++.h>
using namespace std;


class Player
{
  private:    
  string name;
  
  public:
  void set_name(string);
  string get_name();  
};

void Player::set_name(string s)
{
    this->name=s;
}

string Player::get_name()
{
    return this->name;
}

class Board
{
    private:
    char matrix[3][3];
    
    
    
    public:
    void init();
    int moves=0;
    int  possible_move(int x,int y,char a);
    void display();
    int check_horizontal(char a);
    int check_vertical(char a);
    int check_diagonal(char a);
};

void  Board::init()
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {this->matrix[i][j]='*';}
    }
}

int Board::possible_move(int x,int y,char a)
{
    if(x<0 || x>2 || y<0 || y>2 || this->matrix[x][y]=='X' || this->matrix[x][y]=='O')
    {return -1;}
    this->matrix[x][y]=a;
    this->moves+=1;
    return 0;
}

void Board::display()
{
    for(int i=0;i<3;i++)
    {for(int j=0;j<3;j++)
     {cout<<this->matrix[i][j]<<" ";}
     cout<<endl;    
    }
    cout<<"-------------------------------------------------------------";
}

int Board::check_horizontal(char a)
{
   for(int i=0;i<3;i++)
   {
       if(this->matrix[i][0]==this->matrix[i][1] && this->matrix[i][1]==this->matrix[i][2] && this->matrix[i][0]==a)
       {return 1;}
   }
    return 0;
}

int Board::check_vertical(char a)
{
   for(int j=0;j<3;j++)
   {
       if(this->matrix[0][j]==this->matrix[1][j] && this->matrix[1][j]==this->matrix[2][j]  && this->matrix[0][j]==a)
       {return 1;}
   }
    return 0;
}

int Board::check_diagonal(char a)
{
   
       if(this->matrix[0][0]==this->matrix[1][1] && this->matrix[1][1]==this->matrix[2][2]  && this->matrix[0][0]==a)
       {return 1;}
       if(this->matrix[2][0]==this->matrix[1][1] && this->matrix[1][1]==this->matrix[0][2] && this->matrix[2][0]==a)
       {return 1;}
    return 0;
}

int main()
{
    cout<<"\t\t\t\t\t\t____________________TIC TAC TOE_____________________"<<endl;
    Player p1;
    Player p2;
    Board B;
    B.init();
    int x,y;
    B.display();
    while(1)
    { 
       
       cout<<endl<<"player1 enter x y: ";
       cin>>x>>y;
       while(B.possible_move(x,y,'X')==-1)
       { cout<<endl<<"invalid, pleade enter again: ";
         cin>>x>>y;  
       }
       B.display();
       
       if(B.check_horizontal('X')||B.check_vertical('X')||B.check_diagonal('X'))
       {B.display();cout<<endl<<"Player1 wins the match";break;}
       
       if(B.moves==9){cout<<endl<<"draw";break;}
       
       
              
       cout<<endl<<"player2 enter x y: ";
       cin>>x>>y;
       while(B.possible_move(x,y,'O')==-1)
       { cout<<endl<<"invalid, pleade enter again: ";
         cin>>x>>y;  
       } 
       B.display();
       
       if(B.check_horizontal('O')||B.check_vertical('O')||B.check_diagonal('O'))
       {cout<<endl<<"Player2 wins the match";break;}
       
       if(B.moves==9){cout<<endl<<"draw";break;}
       
       
    }
   
    
}
