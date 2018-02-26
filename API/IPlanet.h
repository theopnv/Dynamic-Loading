#pragma once

/*
** This is the base class for all planets (libraries)
*/
class IPlanet
{
	
public:
	virtual ~IPlanet() = default;

	/*
	** Pure method which will be overrided.
	*/
	virtual void greet() = 0;

};