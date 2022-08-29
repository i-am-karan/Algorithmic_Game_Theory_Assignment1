#include<bits/stdc++.h>
using namespace std;
/********** code from here *******************/
struct Game{
   int no_of_player; //stores the number of players
   vector<string>names; //stores the name of the players
   vector<vector<double>>utility; // stores the utitity corresepondint to a startegy profile (tot_strategy * no_of_player dimension)
   vector<vector<string>>strategy; // stores the names of the strategy of each player 

   Game(vector<string>str){
      int n=str.size();
      no_of_player=0;
      int i=0;
      int count=0;
      int row=1;
      while(i<n){
        if(str[i].size()<=1) {
            i++;
            continue;
        }
        int j=0;
        int sz=str[i].size();

        if(!i){
        //parsing the name of the players in names 
        bool ch=false;
        string name;
        while(j<sz){
           if(str[i][j]==' ') {
            j++;
            continue;
           } 
           if(str[i][j]=='"'){
              if(ch){
                ch=false;
                names.push_back(name);
              }
              else{
                 no_of_player++;
                 ch=true;
                 name.clear();
              }
           }
           else name+=str[i][j];
           j++;
         }
        }
        else{
            if(sz==2){
                count++;
                i++;
                continue;
            }
            else if(count==1){
               while(i<n && (int)str[i].size()!=2){
               bool ch=false;
               string name;
               vector<string>op;
               while(j<sz){
                  if(str[i][j]==' ' || str[i][j]=='{'){
                    j++;
                    continue;
                  }
                 if(str[i][j]=='"'){
                 if(ch){
                    ch=false;
                    op.push_back(name);
                  }
                  else{
                    ch=true;
                    name.clear();
                  }
                }
                else name+=str[i][j];
                j++;
               }
               if(!op.empty()) {
                strategy.push_back(op);
                row*=(op.size());
               } 
               name.clear();
               i++;
               sz=str[i].size();
               j=0;
            }
            }
            else if(count==2){
                while(i<n && (int)str[i].size()!=2){
                    string val;
                    vector<double>op;
                    while(j<sz){
                        if(str[i][j]==' ' || str[i][j]=='{'){
                            if(!val.empty()){
                                op.push_back(stod(val));
                                val.clear();
                            }
                            j++;
                            continue;
                        }
                        if(str[i][j]=='"'){
                            j+=2;
                            continue; 
                        }
                        if(str[i][j]==','){
                             op.push_back(stod(val));
                             val.clear();
                             j++;
                             continue;
                        }
                        val+=str[i][j];
                        j++;
                    }
                    if(!op.empty()) utility.push_back(op);
                    i++;
                    sz=str[i].size();
                    j=0;

                }
            }
        }
        i++;
      }
   }
};
void solve(int tc){
    ifstream g("Trial3_3player_2strat.nfg");
    vector<string>str;
    string s;
    while(getline(g,s)){
         str.push_back(s);
    }
    Game gamma(str);
}
/**********code ends here ********************/
signed main( ){
int t=1;
// cin>>t;
for(int i=1;i<=t;i++){
  solve(i);
}
return 0;
}