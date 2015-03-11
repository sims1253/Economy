#include "IDGenerator.h"

IDGenerator::IDGenerator(void)
{
	ID = 1;
}

IDGenerator::~IDGenerator(void)
{

}

int IDGenerator::getNewID(void)
{
	return ID++;
}
