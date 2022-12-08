#include <bits/stdc++.h>
using namespace std;

int indexx=-1,indexy=-1;

bool is_full(char arr[3][3]){
    for (int i=0;i<3;i++){
        for (int j=0;j<3;j++){
            if (arr[i][j]=='#') return 0;
        }
    }
    return 1;
}

int check(char arr[3][3]){
    for (int i=0;i<3;i++){
        if (arr[i][0]=='X' and arr[i][1]=='X' and arr[i][2]=='X') return 10;
    }
    for (int i=0;i<3;i++){
        if (arr[0][i]=='X' and arr[1][i]=='X' and arr[2][i]=='X') return 10;
    }
    if (arr[0][0]=='X' and arr[1][1]=='X' and arr[2][2]=='X') return 1;
    if (arr[0][2]=='X' and arr[1][1]=='X' and arr[2][0]=='X') return 10;

    for (int i=0;i<3;i++){
        if (arr[i][0]=='O' and arr[i][1]=='O' and arr[i][2]=='O') return -10;
    }
    for (int i=0;i<3;i++){
        if (arr[0][i]=='O' and arr[1][i]=='O' and arr[2][i]=='O') return -10;
    }
    if (arr[0][0]=='O' and arr[1][1]=='O' and arr[2][2]=='O') return -10;
    if (arr[0][2]=='O' and arr[1][1]=='O' and arr[2][0]=='O') return -10;
    return 0;
}

void print_arr(char arr[3][3]){
    cout<<arr[0][0]<<"||"<<arr[0][1]<<"||"<<arr[0][2]<<endl;
    cout<<"======="<<endl;
    cout<<arr[1][0]<<"||"<<arr[1][1]<<"||"<<arr[1][2]<<endl;
    cout<<"======="<<endl;
    cout<<arr[2][0]<<"||"<<arr[2][1]<<"||"<<arr[2][2]<<endl;
}

int minimax(int depth, char arr[3][3], bool flag){
    int score=check(arr);
    if (score==10) return score;
    else if (score==-10) return score;
    else if (is_full(arr)==1) return 0;

    if (flag){
        int maxx=-1000;
        for (int i=0;i<3;i++){
            for (int j=0;j<3;j++){
                if (arr[i][j]=='#'){
                    arr[i][j]='X';
                    maxx=max(maxx,minimax(depth+1,arr,!flag));
                    arr[i][j]='#';
                }
            }
        }
        return maxx;
    } else {
        int minn=1000;
        for (int i=0;i<3;i++){
            for (int j=0;j<3;j++){
                if (arr[i][j]=='#'){
                    arr[i][j]='O';
                    minn=min(minn,minimax(depth+1,arr,!flag));
                    arr[i][j]='#';
                }
            }
        }
        return minn;
    }
}

void bestmove(char arr[3][3]){
    int best=-1000;
    
    for (int i=0;i<3;i++){
        for (int j=0;j<3;j++){
            if (arr[i][j]=='#'){
                arr[i][j]='X';
                int move_val=minimax(0,arr,false);
                arr[i][j]='#';

                if (move_val>best){
                    indexx=i;
                    indexy=j;
                    best=move_val;
                }
            }
        }
    }
}
void move(bool who, char arr[3][3]){
    int x,y,valid=0;
    if (who==0){
        while(valid==0){
            cout<<"it is X's turn"<<endl;
            cin>>x>>y;
            if (arr[x][y]=='#'){
                arr[x][y]='X';
                valid=1;
            } else {
                cout<<"position is filled please try again"<<endl;
            }
        }
        who=1;
    }
    else {
        while(valid==0){
            cout<<"it is O's turn"<<endl;
            cin>>x>>y;
            if (arr[x][y]=='#'){
                arr[x][y]='O';
                valid=1;
            } else {
                cout<<"position is filled please try again"<<endl;
            }
        }
        who=1;
    }
}
void two_player(char arr[3][3]){
    print_arr(arr);
    bool who=0;
    int num_of_moves=0;
    while (!check(arr) and num_of_moves<9){
        move(who,arr);
        print_arr(arr);
        num_of_moves+=1;
        who=(!who);
        system("CLS"); 
        print_arr(arr);
    }
    if (check(arr)==0){
        cout<<"draw";
    } else if (check(arr)==1){
        cout<<"X won";
    } else {
        cout<<"O won";
    }
}

void one_player(char arr[3][3]){
    print_arr(arr);
    bool who=0;
    int num_of_moves=0;
    while(!check(arr) and num_of_moves<9){
        if (who==0){
            bestmove(arr);
            arr[indexx][indexy]='X';
            print_arr(arr);
            num_of_moves+=1;
            who=(!who);
            system("CLS");
            print_arr(arr);
        } else{
            move(who,arr);
            print_arr(arr);
            num_of_moves+=1;
            who=(!who);
            system("CLS"); 
            print_arr(arr);
        }
        
    }
    if (check(arr)==0 ){
            cout<<"draw";
        } else if (check(arr)==10){
            cout<<"X won";
        } else {
            cout<<"O won";
        }
}

// the second case
int check2(char arr[3][3]){
    for (int i=0;i<3;i++){
        if (arr[i][0]=='O' and arr[i][1]=='O' and arr[i][2]=='O') return 10;
    }
    for (int i=0;i<3;i++){
        if (arr[0][i]=='X' and arr[1][i]=='X' and arr[2][i]=='O') return 10;
    }
    if (arr[0][0]=='O' and arr[1][1]=='O' and arr[2][2]=='O') return 1;
    if (arr[0][2]=='O' and arr[1][1]=='O' and arr[2][0]=='O') return 10;

    for (int i=0;i<3;i++){
        if (arr[i][0]=='X' and arr[i][1]=='X' and arr[i][2]=='X') return -10;
    }
    for (int i=0;i<3;i++){
        if (arr[0][i]=='X' and arr[1][i]=='X' and arr[2][i]=='X') return -10;
    }
    if (arr[0][0]=='X' and arr[1][1]=='X' and arr[2][2]=='X') return -10;
    if (arr[0][2]=='X' and arr[1][1]=='X' and arr[2][0]=='X') return -10;
    return 0;
}

int minimax2(int depth, char arr[3][3], bool flag){
    int score=check2(arr);
    if (score==10) return score;
    else if (score==-10) return score;
    else if (is_full(arr)==1) return 0;

    if (flag){
        int maxx=-1000;
        for (int i=0;i<3;i++){
            for (int j=0;j<3;j++){
                if (arr[i][j]=='#'){
                    arr[i][j]='O';
                    maxx=max(maxx,minimax2(depth+1,arr,!flag));
                    arr[i][j]='#';
                }
            }
        }
        return maxx;
    } else {
        int minn=1000;
        for (int i=0;i<3;i++){
            for (int j=0;j<3;j++){
                if (arr[i][j]=='#'){
                    arr[i][j]='X';
                    minn=min(minn,minimax2(depth+1,arr,!flag));
                    arr[i][j]='#';
                }
            }
        }
        return minn;
    }
}

void bestmove2(char arr[3][3]){
    int best=-1000;
    
    for (int i=0;i<3;i++){
        for (int j=0;j<3;j++){
            if (arr[i][j]=='#'){
                arr[i][j]='O';
                int move_val=minimax2(0,arr,false);
                arr[i][j]='#';

                if (move_val>best){
                    indexx=i;
                    indexy=j;
                    best=move_val;
                }
            }
        }
    }
}

void one_player2(char arr[3][3]){
    print_arr(arr);
    bool who=0;
    int num_of_moves=0;
    while(!check(arr) and num_of_moves<9){
        if (who==0){
            move(who,arr);
            print_arr(arr);
            num_of_moves+=1;
            who=(!who);
            system("CLS"); 
            print_arr(arr);
        } else{
            bestmove2(arr);
            arr[indexx][indexy]='O';
            print_arr(arr);
            num_of_moves+=1;
            who=(!who);
            system("CLS");
            print_arr(arr);
        }
        
    }
    if (check(arr)==0){
            cout<<"draw";
        } else if (check(arr)==10){
            cout<<"X won";
        } else {
            cout<<"O won";
        }
}
int main(){
    char arr[3][3];
    for (int i=0;i<3;i++){
        for (int j=0;j<3;j++){
            arr[i][j]='#';
        }
    }

    int which;
    cout<<"select the mode, 0 for one player mode and 1 for two player mode:"<<endl;
    cin>>which;
    int player_or_comp;
    cout<<"enter 0 if you want computer going first else enter 1"<<endl;
    cin>> player_or_comp;

    if (which==0){
        if (!player_or_comp){
            one_player(arr);
        } else one_player2(arr);
    } else {
        two_player(arr);
    }
}