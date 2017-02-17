#include<iostream>
#include<string>
#include<cstring>
#include<vector>
using namespace std;
class hangman
{
public:
    string input;
    string guess;
    int length;
    int flag;
    int result;
    int wrong;
    hangman(string str,string str2){input=str;guess=str2;}
    void work();
};
void hangman::work()
{
    int f=0;
    wrong =0;
    length = guess.length();
    int l2=input.length();
    flag=input.length();
    for(int i=0;i<length;i++){
            f=0;
        for(int j=0;j<l2 ;j++){
            if(guess[i]==input[j]){
                input[j]=0;
                f=1;
                flag--;
            }
        }
        if(!f){
            wrong++;
        }
        if(wrong==7 || flag==0) break;
    }
}
int main()
{

    string str,str2;
    int n;
    while(cin>>n && n!=-1){
        cout<<"Round "<<n<<endl;
    cin>>str>>str2;
            hangman ob(str,str2);
        ;

        ob.work();
        if(ob.flag==0) cout<<"You win."<<endl;
       else if(ob.wrong==7) cout<<"You lose."<<endl;

        else cout<<"You chickened out."<<endl;

    }
return 0;

}
