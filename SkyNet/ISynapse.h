#pragma once

#ifdef ISYNAPSE_EXPORTS
#define ISYNAPSE_API __declspec(dllexport) 
#else
#define ISYNAPSE_API __declspec(dllimport) 
#endif

class ISynapse {
public:
	virtual ISYNAPSE_API double getWeight() = 0;
	virtual ISYNAPSE_API void setWeight(double weight) = 0;

	virtual void setValue(double value) = 0;
	virtual double getValue() = 0;
};