#include "Dot.h"

Dot::Dot()
{

}

Dot::Dot(Vec2 position, type dotType)
{
	this->pos = position;
	this->dType = dotType;
}