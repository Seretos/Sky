#include "stdafx.h"
#include "CSynapse.h"

int CSynapse::getType() {
	return 1;
}

CSynapse::CSynapse(INeuron* source, INeuron* destination, double weight) : ISynapse(source, destination, weight) {

}