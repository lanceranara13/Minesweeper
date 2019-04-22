#include <bits/stdc++.h>
using namespace std;

//Plans
//
//  User would input the size of board
//  User would input the amount of bombs in the board
//  Create a new board that is Blank that will serve as play area
//
//
//
//

#define SIZE 10
#define BOMB 30



vector <int> bombPlacement;

vector <int> randomGen(){
    srand(time(NULL));
    
    int initial = 0, number;
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
            initial = number;
            bombPlacement.push_back(number);
            i++;
        }
    }
    return bombPlacement;
}


void print(string square[][SIZE]){
    for(int i = 0; i < SIZE;i++){
        for(int j = 0; j < SIZE; j++){
            cout << square[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void number(string square[][SIZE]){
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
            
            if(square[i][j] != "B" && counter != 0){
                square[i][j] = char(counter+48); 
            }
        }
    }
}

void start(string square[][SIZE]){
   for(int i = 0; i < SIZE;i++){
        for(int j = 0; j < SIZE; j++){
            square[i][j] = ".";
        }
   }
   
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
   
   print(square);
}







int main(){
    string square[SIZE][SIZE];
    start(square);
    return 0;
}
