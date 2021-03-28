#pragma once

#include "Piece.h"


//Callum Simpson -- b6030326
//my rook class that implerments piece 
class Bishop : public Piece {

public:

	//bishop constutor - adds upon peice const 
	Bishop(double x = 0.0, double y = 0.0) : Piece(x, y) {
		this->shape = Piece::circle;
		this->name = Piece::ABishop;
		//this->diamater = 2;
	};

	//move
	void move(double distance, int direction);

	//increas score
	void incScore();
	//unqine score for piece
		static int score;
};