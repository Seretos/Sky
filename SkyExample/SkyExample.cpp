// SkyExample.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include <iostream>
#include "../SkyNet/CSkyNetFactory.h"
#include "../SkyNet/INetwork.h"
#include <time.h>

using namespace std;

int main()
{
	srand(time(NULL));
	int test;

	CSimpleNetworkBuilder* builder = CSkyNetFactory::createSimpleNetworkBuilder();

	builder->build(2, 1);

	double inputs[2] = {1.0f,0.2f};
	builder->input(inputs);
	builder->run();

	double* arr = builder->output();

	cout << arr[0]<< '\n';

	INetwork* net = CSkyNetFactory::createNetwork();
	INeuron* input1 = CSkyNetFactory::createNeuron();
	INeuron* input2 = CSkyNetFactory::createNeuron();
	INeuron* output1 = CSkyNetFactory::createNeuron();

	net->addNeuron(input1);
	net->addNeuron(input2);
	net->addNeuron(output1);

	CSkyNetFactory::createSynapse(input1, output1,0.1);
	CSkyNetFactory::createSynapse(input2, output1,0.1);

	input1->setValue(1.0f);
	input2->setValue(1.0f);

	net->request();
	net->response();

	cout << input1->getValue();
	cout << input2->getValue();
	cout << output1->getValue();

	cin >> test;

    return 0;
}

