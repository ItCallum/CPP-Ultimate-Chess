#include "Bishop.h"

//move for the bishop
//distance is how far the peice will move
//direction will determin how rook will move
void Bishop::move(double distance, int direction)
{

	//mod dicertion so that it can repersent 1 of bishops 4 moves 
	direction = (int)direction % 4;

	switch (direction) {

	case 0:
		//std::cout << "NE" << std::endl;
		this->x += distance;
		this->y += distance;
		break;
	case 1:
		//std::cout << "SE" << std::endl;
		this->x += distance;
		this->y -= distance;
		break;
	case 2:
		//std::cout << "SW" << std::endl;
		this->x -= distance;
		this->y -= distance;
		break;
	case 3:
		//std::cout << "NW" << std::endl;
		this->x -= distance;
		this->y += distance;
		break;
	}


}


void Bishop::incScore()
{
	//increase all bishops total score.
	score++;
}
