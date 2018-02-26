#pragma once

#include <iostream>
#include "IPlanet.h"

class Bespin : public IPlanet
{
public:
	Bespin() = default;
	~Bespin() = default;

	void greet() override;
};
