#include "Zombie.h"
#include "Shared.h"

Zombie::Zombie(int color, float xCenter, float yCenter, float zCenter): 
	GenericNPC(color, xCenter, yCenter, zCenter) {
	currentXPosition = xCenter;
}

GLuint Zombie::nrPoints = 12;

GLuint Zombie::offset = 0;

int Zombie::interiorColor = DARK_GREEN;

float Zombie::step = 0.1f;

void Zombie::draw() {
	glm::mat4 translateMatrix = glm::translate(this->getPosition());
	glm::mat4 myMatrix = Shared::resizeMatrix * translateMatrix;
	glUniformMatrix4fv(Shared::myMatrixLocation, 1, GL_FALSE, &myMatrix[0][0]);
	glUniform1i(Shared::codColLocation, this->getColor());
	glDrawArrays(GL_POLYGON, offset, nrPoints / 2);
	glUniform1i(Shared::codColLocation, interiorColor);
	glDrawArrays(GL_POLYGON, offset + nrPoints / 2, nrPoints / 2);
}

void Zombie::move() {
	this->currentXPosition -= step;
	glm::vec3 newPosition = glm::vec3(this->currentXPosition, this->getPosition().y, this->getPosition().z);
	this->setPosition(newPosition);
}

void Zombie::setOffset(int offset) {
	Zombie::offset = offset;
}

bool Zombie::isActive() const {
	return this->getPosition().x > 50.f;
}

Zombie::~Zombie() {}