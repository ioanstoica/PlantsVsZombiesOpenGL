﻿#include <GL/glew.h>      
#include "glm/gtc/matrix_transform.hpp"
#include <list>
#include "Plant.h"
#include "Zombie.h"
#include "Bullet.h"
#pragma once


class Shared
{
public:
	static GLfloat winWidth;
	static GLfloat winHeight;
	static const float PI;
	static int lives;
	static GLuint myMatrixLocation;
	static GLuint codColLocation;
	static glm::mat4 resizeMatrix;
	static std::list<Plant*> plants;
	static std::list<Zombie*> zombies;
	static std::list<Bullet*> bullets;
};

