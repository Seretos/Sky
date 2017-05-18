#pragma once

#include "INetwork.h"
#include <vector>

class CNetwork: public INetwork {
public:
	CNetwork();
	~CNetwork();

	int addNeuron(INeuron* neuron);
	INeuron* getNeuron(int index);

	void request();
	void response();
private:
	std::vector<INeuron*> neurons;
};