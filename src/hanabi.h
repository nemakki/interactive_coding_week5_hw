#pragma once


#include "ofMain.h"


class Hanabi {
public:

	//constructor
	Hanabi();

	void update();
	void draw();

	bool isDead();

	glm::vec2 position;
	glm::vec2 velocity;
	glm::vec2 acceleration;

	int age = 0;
	int maxAge = 40;


	ofTexture tex;

	float scale = 1.;

	//int brightness = 20;



};
