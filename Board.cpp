/****************
* Author: Noy Osi
****************/

#include "Board.hpp"
#include <iostream>

using namespace std;

namespace ariel {

/**
 * @brief - resize the message board
 * 
 * @param row - the row number
 * @param col - the column number
 */
void Board::resizeMB(uint row, uint col){

    this->maxC=max(this->maxC, col);
    this->maxR=max(this->maxR, row);
    this->minC=min(this->minC, col);
    this->minR=min(this->minR, row);

    this->messageBoard.vector::resize(maxR);
    for (uint i = 0; i < maxR; i++)
    {
        this->messageBoard.at(i).vector::resize(maxC, '_');
    }
}

/**
 * @brief - post a message on the board, in the given location
 * 
 * @param row - the row number where the message begins
 * @param col - the column number where the message begins
 * @param direction - the direction of the message, wheather horizontal or vertical
 * @param msg - represent the message we post
 */
void Board::post(uint row, uint col, Direction direction, std::string msg){

    if (msg.length()==0) {
        return;
    }
    
    (direction==Direction::Horizontal) ? resizeMB(row+1, col+msg.length()) : resizeMB(row+msg.length(), col+1);
    for (uint i = 0; i < msg.length(); i++)
    {
        messageBoard.at(row).at(col)=msg.at(i);
        (direction==Direction::Horizontal) ? col++ : row++;
    }
}

/**
 * @brief - read a message from the board, in the given location & length
 * 
 * @param row - the row number where the message begins
 * @param col - the column number where the message begins
 * @param direction - the direction of the message, wheather horizontal or vertical
 * @param len - the message length
 * @return string - the message
 */
string Board::read(uint row, uint col, Direction direction, uint len){

    if(len==0){
        return ""; 
    }

    string msg;
    for (uint i = 0; i < len; i++)
    {
        try {
        msg+=this->messageBoard.at(row).at(col);
        (direction==Direction::Horizontal) ? col++ : row++;
        }
        catch (exception ex){
        msg+="_";
        }
    }
    return msg;
}

/**
 * @brief - shows the message board
 */
void Board::show(){

    for (uint i = 0; i < this->maxR; i++)
    {
        for (uint j = 0; j < this->maxC; j++)
        {
            cout << messageBoard.at(i).at(j);
        }
        cout << endl;
    }     
}

}