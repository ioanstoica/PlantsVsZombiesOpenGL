#pragma once
#include "GenericNPC.h"
#include "glm/glm.hpp"		
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtx/transform.hpp"
#include "glm/gtc/type_ptr.hpp"
#include "Colors.h"
#include <GL/glew.h>  

class Plant: public	GenericNPC
{
	// Numarul de puncte ale obiectului
	static GLuint nrPoints;

	// Offset-ul obiectului in array-ul de vertices
	static GLuint offset;
public:
	static void setOffset(int offset);
	// xCenter, yCenter, zCenter - coordonatele centrului obiectului
	Plant(int color, float xCenter, float yCenter, float zCenter = 0.f);
	void draw() override;
	~Plant();
};

