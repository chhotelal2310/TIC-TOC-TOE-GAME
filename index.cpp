#include<bits/stdc++.h>
using namespace std;
char arr[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
char turn='X';
int row,col;
bool draw=false;
void dispalyTICTACTOE(){
  system("cls");
    cout<<endl;
    cout<<endl;
    cout<<"************************ TIC-TAC-TOE GAME **********************"<<endl;
    cout<<"Player1[x]     "<<endl;
    cout<<"Player2[0]     "<<endl;
    cout<<endl;
    cout<<"     \t       |       |       "<<endl;
    cout<<"     \t   "<<arr[0][0]<<"   |   "<<arr[0][1]<<"   |   "<<arr[0][2]<<"   "<<endl;
    cout<<"     \t_______|_______|_______"<<endl;
    cout<<"     \t       |       |       "<<endl;
    cout<<"     \t   "<<arr[1][0]<<"   |   "<<arr[1][1]<<"   |   "<<arr[1][2]<<"   "<<endl;
    cout<<"     \t_______|_______|_______"<<endl;
    cout<<"     \t       |       |       "<<endl;
    cout<<"     \t   "<<arr[2][0]<<"   |   "<<arr[2][1]<<"   |   "<<arr[2][2]<<"   "<<endl;
    cout<<"     \t       |       |       "<<endl;
    cout<<endl;
}
void player_turn(){
  int choicenumber;
  if(turn=='X')
  cout<<"Player1 [x] turn : ";
  if(turn=='O')
   cout<<"Player2 [O] turn : ";
cin>>choicenumber;
switch(choicenumber){
  case 1:row=0;col=0;break;
  case 2:row=0;col=1;break;
  case 3:row=0;col=2;break;
  case 4:row=1;col=0;break;
  case 5:row=1;col=1;break;
  case 6:row=1;col=2;break;
  case 7:row=2;col=0;break;
  case 8:row=2;col=1;break;
  case 9:row=2;col=2;break;
  default:
  cout<<"Invalid choice"<<endl;
  break;
}
if(turn=='X'&& arr[row][col]!='X' && arr[row][col]!='O'){
  arr[row][col]='X';
  turn='O';
}
else if(turn=='O' && arr[row][col]!='X' && arr[row][col]!='O'){
  arr[row][col]='O';
  turn='X';
}
else{
  cout<<"Box Aleady Filled ! "<<endl;
  cout<<"Please Try Again ! "<<endl;
  player_turn();
}
dispalyTICTACTOE();
}
bool gameover(){
  //chek win
  for(int i=0;i<3;i++)
    if((arr[i][0]==arr[i][1]&& arr[i][0]==arr[i][2])||(arr[0][i]==arr[1][i]&& arr[0][i]==arr[2][i]))
    return false;
  if((arr[0][0]==arr[1][1] && arr[0][0]==arr[2][2])||(arr[0][2]==arr[1][1]&&arr[0][2]==arr[2][0]))
  return false;

    //if there is any obx are not filled
    for(int i=0;i<3;i++){
      for(int j=0;j<3;j++){
        if(arr[i][j]!='X'&&arr[i][j]!='O'){
          return true;
        }
      }
    }
  //draw
  draw=true;
  return false;
}
int main(){
  while(gameover()){
dispalyTICTACTOE();
player_turn();
gameover();
  }
  if(turn=='X'&& draw==false)
  cout<<"Player2 [O] Wins! Cogratulations "<<endl;
  else if(turn=='O' && draw==false)
  cout<<"Player1 [X] Wins! Cogratulations "<<endl;
  else
  cout<<"GAME DRAW!!"<<endl;
return 0;
}