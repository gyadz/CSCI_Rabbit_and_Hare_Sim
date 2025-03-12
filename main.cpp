#include <iostream>
#include <cstdlib>
#include <ctime>

#include <thread>
#include <chrono>

void theGame(int&, int&);

void moveHare(int& harePos){
    switch(rand()%10+1){
        case 1:
        // big slip, 10%
            harePos-=12;
            break;
        case 2:case 3:
        // nap, 20%
            break;
        case 4:case 5:
        // big hop, 20%
            harePos+=9;
            break;
        case 6:case 7:
        // small slip, 20%
            harePos-=2;
            break;
        default:
        // small hop, 30%
            harePos++;
    }

    if(harePos<1){
        harePos=1;
    }
}
void moveTurtle(int& turtPos){
    switch(rand()%10+1){
        case 1:case 2:
        // slip, 20%
            turtPos-=6;
            break;
        case 3:case 4:case 5:
        // slow plod, 30%
            turtPos+=1;
            break;
        default:
        // fast plod, 50%
            turtPos+=3;
    }

    if(turtPos<1){
        turtPos=1;
    }
}

void printBoardv2(int& harePos, int& turtPos, int x){
    for(int i{0+x}; i<35+x; i++){
        std::cout<<"|";
        if(i==harePos || i==turtPos){

            if(harePos==turtPos){
                std::cout<<"X"; // using X instead of OUCH!! because printing that would mess up my board
            }else if(i==harePos){
                std::cout<<"H";
            }else{
                std::cout<<"T";
            }
        }else{
            std::cout<<"_";
        }
    }
    std::cout<<"|";
}
void printBoard(int& harePos, int& turtPos){

    for(int i{0}; i<35; i++){
        std::cout<<" _";
    }
    std::cout<<std::endl;
    printBoardv2(harePos, turtPos, 0);
    std::cout<<std::endl;
    printBoardv2(harePos, turtPos, 35);

    std::this_thread::sleep_for(std::chrono::seconds(1));
    theGame(harePos, turtPos);
}

void theGame(int& harePos, int& turtPos){
    moveHare(harePos);
    moveTurtle(turtPos);

    std::cout<<std::endl;
    if(harePos>70 || turtPos>70){
        if(harePos>70 && turtPos>70){
            std::cout<<"It's a tie";
        }else if(harePos>70){
            std::cout<<"The hare wins";
        }else{
            std::cout<<"Mr Turt wins";
        }
        std::exit(0);
    }

    printBoard(harePos, turtPos);
}

int main(){
    srand(time(0));
    int turtPos{1}, harePos{1};

    std::cout<<"BANG!\nAND THEY'RE OFF!\n";

    theGame(turtPos, harePos);
}
