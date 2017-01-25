#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main(){
  cout<<"String 1: ";
  string a;
  cin>>a;
  cout<<"String 2: ";
  string b;
  cin>>b;
  int match,mismatch,gap;
  cout<<"Match: ";
  cin>>match;
  cout<<"Mismatch: ";
  cin>>mismatch;
  cout<<"Gap: ";
  cin>>gap;

  int len1=a.size();
  int len2=b.size();

  int score[len1+1][len2+1];
  int dirx[]={-1,-1,0};
  int diry[]={0,-1,-1};
  int dir[len1+1][len2+1];

  //Scoring Matrix Fill
  score[0][0]=0;
  for(int i=1;i<=len1;i++){
    score[i][0]=score[i-1][0]+gap;
    dir[i][0]=0;
  }
  for(int i=1;i<=len2;i++){
    score[0][i]=score[0][i-1]+gap;
    dir[0][i]=2;
  }
  for(int i=1;i<=len1;i++){
    for(int j=1;j<=len2;j++){
      int pos1=0;
      int pos2=score[i][j-1]+gap;
      int pos3=score[i-1][j]+gap;
      if(a.at(i-1)==b.at(j-1)){
        pos1=score[i-1][j-1]+match;
      }else{
        pos1=score[i-1][j-1]+mismatch;
      }
      if(pos1>=pos2&&pos1>=pos3){
        score[i][j]=pos1;
        dir[i][j]=1;
      }else if(pos2>=pos1&&pos2>=pos3){
        score[i][j]=pos2;
        dir[i][j]=2;
      }else{
        score[i][j]=pos3;
        dir[i][j]=0;
      }
    }
  }
  //Trace back step
  string res1="",res2="";

  while(!(len1==0&&len2==0)){
    switch(dir[len1][len2]){
      case 2:
      res1+='-';
      res2+=b.at(len2-1);
      break;
      case 1:
      res1+=a.at(len1-1);
      res2+=b.at(len2-1);
      break;
      case 0:
      res1+=a.at(len1-1);
      res2+='-';
    }
    int x=len1+dirx[dir[len1][len2]];
    int y=len2+diry[dir[len1][len2]];
    len1=x;
    len2=y;
  }
  reverse(res1.begin(),res1.end());
  reverse(res2.begin(),res2.end());
  cout<<"Final Allignment: "<<endl;
  cout<<res1<<endl;
  cout<<res2<<endl;
  return 0;
}
