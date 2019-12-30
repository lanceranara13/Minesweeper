
// Plans
//
//  User would input the size of board
//  User would input the amount of bombs in the board
//  (check) Create a new board that is Blank that will serve as play area
//
//
//  UPDATES
//  4/22/19 - Creates a solved matrix
//  4/23/19 - User can now input the coordinate of the matrix and get an answer
//          - Created a new blank board that will serve as play area
// 12/31/19 - Replaced string array to vector string
//


#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<string>> vvs;
#define SIZE 10
#define BOMB 30



vector <int> bombPlacement;

void initialize(vvs &square, int r, int c){
    for(int i = 0; i < r; i++){
        vector <string> temp;
        for(int j = 0; j < c; j++){
            temp.push_back("");
        }
        square.push_back(temp);
    }

}

vector <int> randomGen(){
    srand(time(NULL));

    int Initial = 0, number;
    int doubles = SIZE * SIZE;

    for(int i = 0; i < BOMB;){
        number = (rand() % (doubles) + 1);

        bool checker = true;
        for(int j = 0; j < bombPlacement.size(); j++){
            if(number == bombPlacement[j]){
                checker = false;
                number = (rand() % (doubles) + 1);
            }
        }

        if(checker){
            Initial = number;
            bombPlacement.push_back(number);
            i++;
        }
    }
    return bombPlacement;
}


void print(vvs square){
    for(int i = -1; i < SIZE;i++){
        if(i!= -1)
            cout << i+1 << " ";
        for(int j = 0; j < SIZE; j++){
            if(i == -1){
                if(j == 0){
                    cout << "  ";
                    continue;
                }
                else
                    cout << j << " ";

                if(j == SIZE-1)
                    cout << j+1;
            }
            else
                cout << square[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void number(vvs &square){
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            int counter = 0;

            //CORNERS
            if(i == 0 && j == 0){
                if(square[i][j+1] == "B"){
                    counter++;
                }
                if(square[i+1][j] == "B"){
                    counter++;
                }
                if(square[i+1][j+1] == "B"){
                    counter++;
                }
            }
            else if(i == 0 && j == SIZE-1){
                if(square[i][j-1] == "B"){
                    counter++;
                }
                if(square[i+1][j] == "B"){
                    counter++;
                }
                if(square[i+1][j-1] == "B"){
                    counter++;
                }
            }
            else if(i == SIZE-1 && j == 0){
                if(square[i-1][j] == "B"){
                    counter++;
                }
                if(square[i-1][j+1] == "B"){
                    counter++;
                }
                if(square[i][j+1] == "B"){
                    counter++;
                }
            }
            else if(i == SIZE-1 && j == SIZE-1){
                if(square[i][j-1] == "B"){
                    counter++;
                }
                if(square[i-1][j-1] == "B"){
                    counter++;
                }
                if(square[i-1][j] == "B"){
                    counter++;
                }
            }

            //SIDES
            else if(i == 0 && j > 0){
                if(square[i][j-1] == "B"){
                    counter++;
                }
                if(square[i+1][j-1] == "B"){
                    counter++;
                }
                if(square[i+1][j] == "B"){
                    counter++;
                }
                if(square[i+1][j+1] == "B"){
                    counter++;
                }
                if(square[i][j+1] == "B"){
                    counter++;
                }
            }
            else if(i > 0 && j == SIZE-1){
                if(square[i-1][j] == "B"){
                    counter++;
                }
                if(square[i-1][j-1] == "B"){
                    counter++;
                }
                if(square[i][j-1] == "B"){
                    counter++;
                }
                if(square[i+1][j-1] == "B"){
                    counter++;
                }
                if(square[i+1][j] == "B"){
                    counter++;
                }
            }
            else if(i == SIZE-1 && j > 0){
                if(square[i][j-1] == "B"){
                    counter++;
                }
                if(square[i-1][j-1] == "B"){
                    counter++;
                }
                if(square[i-1][j] == "B"){
                    counter++;
                }
                if(square[i-1][j+1] == "B"){
                    counter++;
                }
                if(square[i][j+1] == "B"){
                    counter++;
                }
            }
            else if(i > 0 && j == 0){
                if(square[i-1][j] == "B"){
                    counter++;
                }
                if(square[i-1][j+1] == "B"){
                    counter++;
                }
                if(square[i][j+1] == "B"){
                    counter++;
                }
                if(square[i+1][j+1] == "B"){
                    counter++;
                }
                if(square[i+1][j] == "B"){
                    counter++;
                }
            }

            else if(i > 0 && j > 0 && i < SIZE && j < SIZE){
                if(square[i-1][j] == "B"){
                    counter++;
                }
                if(square[i-1][j-1] == "B"){
                    counter++;
                }
                if(square[i][j-1] == "B"){
                    counter++;
                }
                if(square[i][j+1] == "B"){
                    counter++;
                }
                if(square[i+1][j-1] == "B"){
                    counter++;
                }
                if(square[i+1][j] == "B"){
                    counter++;
                }
                if(square[i+1][j+1] == "B"){
                    counter++;
                }
                if(square[i-1][j+1] == "B"){
                    counter++;
                }
            }
            //cout << counter << endl;

            if(square[i][j] != "B"){
                square[i][j] = char(counter+48);
            }
        }
    }
}

void reveal(vvs &square, vvs &newBoard, int x, int y){
    newBoard[x][y] = square[x][y];
}

bool finish(vvs &newBoard){
    int counter = 0;
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            if(newBoard[i][j] == ".")
                counter++;
        }
    }
    if(counter == BOMB){
        return true;
    }
    else
        return false;
}

void inputs(vvs &square, vvs &newBoard){
    string inputx, inputy;

    if(finish(newBoard)){
        cout << "CONGRATULATION" << endl;
        quick_exit(0);
    }

    cout << "Enter coordinates (x,y): ";
    while(cin >> inputx >> inputy){
        cout << endl;
        int x = stoi(inputx)-1 , y = stoi(inputy)-1;
        if(x >= 0 && x < SIZE && y >= 0 && y < SIZE){
            if(finish(newBoard)){
                cout << "CONGRATULATION" << endl;
                quick_exit(0);
            }

            else if(square[x][y] == "B"){
                cout << endl << "BOOM" << endl << " GAME OVER " << endl;
                //abort();
                quick_exit(0);
            }
            else if(square[x][y] >= "0"){
                cout << "SAFE";
                reveal(square, newBoard, x, y);
            }
            cout << endl << endl;
            print(newBoard);
        }
        else{
            cout << "Invalid Input" << endl;
        }

        cout << "Enter coordinates (x,y): ";
    }

}

void lcopy(vvs &a, vvs &b){
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            b[i][j] = a[i][j];
        }
    }
}

void start(vvs &square){
   for(int i = 0; i < SIZE;i++){
        for(int j = 0; j < SIZE; j++){
            square[i][j] = ".";
        }
   }

   vvs newBoard;
   initialize(newBoard,SIZE,SIZE);
   lcopy(square, newBoard);

   bombPlacement = randomGen();
   sort(bombPlacement.begin(), bombPlacement.end());

//   for(int i = 0; i < bombPlacement.size(); i++){
//       cout << bombPlacement[i] << endl;
//   }
//   cout << endl;


   int bomb = 1, bombCounter = 0;
   for(int i = 0; i < SIZE;i++){
        for(int j = 0; j < SIZE; j++,bomb++){
            if(bomb == bombPlacement[bombCounter]){
                square[i][j] = "B";
                bombCounter++;
            }
        }
   }

   number(square);

   //print(square);
   print(newBoard);

   inputs(square, newBoard);
}








int main(){
    //string square[SIZE][SIZE];
    vvs square;
    initialize(square, SIZE, SIZE);
    start(square);
    return 0;
}

