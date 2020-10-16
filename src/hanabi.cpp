#include "hanabi.h"


Hanabi::Hanabi()
{

}

void Hanabi::update()
{
	velocity = velocity + acceleration;
	position = position + velocity;

	age++;
}

void Hanabi::draw()
{
	ofPushMatrix();
	//ofTranslate(position);
	ofScale(scale);

	ofFill();
	ofSetColor(255, 198, 84);
	
	ofSetRectMode(OF_RECTMODE_CENTER);
	ofDrawRectangle(position, 4, 4);
	ofSetRectMode(OF_RECTMODE_CORNER);

	ofSetColor(255, 198, 84, 10);

	ofDrawEllipse(position, 40, 40);
	ofSetColor(255, 198, 84, 40);
	ofDrawEllipse(position, 10, 10);

	ofPopMatrix();
}


bool Hanabi::isDead()
{
	return age > maxAge;
}
