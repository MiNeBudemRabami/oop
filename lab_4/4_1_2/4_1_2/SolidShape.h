#pragma once

#include "ISolidShape.h"

class SolidShape : public ISolidShape
{
public:
	virtual std::string ToString() const;
};
