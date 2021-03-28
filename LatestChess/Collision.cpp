#include "Piece.h"


//Callum Simpson -- b6030326
//see if a sqaure and circle over lap 
//1st value should be a circle 
//2nd should be a square

//source used to help create https://stackoverflow.com/questions/401847/circle-rectangle-collision-detection-intersection/1879223#1879223
static bool squareCircle(const Piece& circle, const Piece& square) {

	//get the absoule values of x and y
	double circleDistanceX = abs(circle.getX() - square.getX());
	double circleDistanceY = abs(circle.getY() - square.getY());

	//is there a no possiable way for an intersection 
	if (circleDistanceX > ((square.getDiamater() / 2 ) + (circle.getDiamater() / 2))) { return false; }
	if (circleDistanceY > ((square.getDiamater() / 2 ) + (circle.getDiamater() / 2))) { return false; }

	//is it guarneted there is an overlap 
	if (circleDistanceX <= (square.getDiamater() / 2)) { return true; }
	if (circleDistanceY <= (square.getDiamater() / 2)) { return true; }


	double cornerDistance = pow((circleDistanceX - (square.getDiamater() / 2)), 2) +
		pow((circleDistanceY - (square.getDiamater() / 2)), 2);

	return (cornerDistance <= pow((circle.getDiamater() / 2), 2));


}

//A collision to see if a square has collided with another square
static bool squareSquare(const Piece& one, const Piece& two) {

	//square - square collisison
	return ((one.getX() - (one.getDiamater() / 2)) < (two.getX() + (one.getDiamater() / 2)) && (one.getX() + (one.getDiamater() / 2)) > (two.getX() - (two.getDiamater() / 2)) && (one.getY() + (one.getDiamater() / 2)) > (two.getY() - (two.getDiamater() / 2)) && (one.getY() - (one.getDiamater() / 2)) < (two.getY() + (two.getDiamater() / 2)));

}

//A collision to see if a queen has collided with another queen
static bool circleCircle(const Piece& one, const Piece& two) {

	bool isCollison = false;

	double radius1 = one.getDiamater() / 2;

	double radius2 = two.getDiamater() / 2;

	double test = pow(one.getX() - two.getX(), 2) + pow((one.getY() - two.getY()), 2);


	if (test <= pow(radius1 + radius2, 2)) {

		isCollison = true;
	}

	return isCollison;
		
}

//A method to check what the shape of two pieces are then decide what collision check should be prefomed
//if there has been collision return true
//else return false
static bool checkCollision(const Piece& one, const Piece& two) {

	bool check = false;

	//if piece 1 is a circle  && if piece 2 is a circle 
	if (one.getShape() == 1 && two.getShape() == 1) {
		check = circleCircle(one, two);
	}
	//if piece 2 is a square and p2 is a square
	else if (one.getShape() == 0 && two.getShape() == 0) {
		check = squareSquare(one, two);
	}
	else if (one.getShape() == 0 && two.getShape() == 1) {
		check = squareCircle(two, one);
	}
	else if (one.getShape() == 1 && two.getShape() == 0) {
		check = squareCircle(one, two);
	}

	return check;
}


// a check to see if a wall has been hit
static bool wallHit(const Piece& one, int maxX, int maxY) {

	double storeLength = one.getDiamater() / 2;

	if ((one.getX() + storeLength >= maxX) || (one.getX() - storeLength) <= 0 || (one.getY() + storeLength) >= maxY || (one.getY() - storeLength) <= 0) {
		//std::cout << "A wall has been hit" << std::endl;
		return true;
	}

	else {
		return false;
	}

}