#pragma once
#include "Ishape.h"

class ISolidShape : public IShape
{
public:

	virtual uint32_t GetFillColor() const = 0;

};