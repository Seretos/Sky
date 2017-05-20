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

	INeuron* inputs1[10];
	INeuron* inputs2[10];
	INeuron* outputs[10];

	CSimulationManager* simulationManager = CSkyNetFactory::createSimulationManager();
	CNetworkManager* removeManager;

	for (int i = 0; i < 10; i++) {
		INetwork* network = CSkyNetFactory::createNetwork();
		CNetworkManager* manager = CSkyNetFactory::createNetworkManager(network);
		CLayer* inputLayer = CSkyNetFactory::createLayer(network);
		CLayer* hiddenLayer = CSkyNetFactory::createLayer(network);
		CLayer* outputLayer = CSkyNetFactory::createLayer(network);
		INeuron* input1 = CSkyNetFactory::createNeuron();
		INeuron* input2 = CSkyNetFactory::createNeuron();
		INeuron* hidden1 = CSkyNetFactory::createNeuron();
		INeuron* hidden2 = CSkyNetFactory::createNeuron();
		INeuron* hidden3 = CSkyNetFactory::createNeuron();
		INeuron* output = CSkyNetFactory::createNeuron();

		inputLayer->addNeuron(input1);
		inputLayer->addNeuron(input2);

		hiddenLayer->addNeuron(hidden1);
		hiddenLayer->addNeuron(hidden2);
		hiddenLayer->addNeuron(hidden3);

		outputLayer->addNeuron(output);

		manager->setInputLayer(inputLayer);
		manager->addHiddenLayer(hiddenLayer);
		manager->setOutputLayer(outputLayer);

		manager->autoConnectLayers();

		inputs1[i] = input1;
		inputs2[i] = input2;
		outputs[i] = output;

		simulationManager->addNetwork(manager);
		if (i == 9) {
			removeManager = manager;
		}
	}

	for (int i = 0; i < 10; i++) {
		inputs1[i]->setValue(40);
		inputs2[i]->setValue(120);
	}
	simulationManager->run();
	simulationManager->run();
	for (int i = 0; i < 10; i++) {
		cout << outputs[i]->getValue() << '\n';
	}
	cout << '\n';

	simulationManager->removeNetwork(removeManager);
	outputs[9]->setValue(0);
	
	for (int i = 0; i < 10; i++) {
		inputs1[i]->setValue(40);
		inputs2[i]->setValue(120);
	}
	simulationManager->run();
	simulationManager->run();
	for (int i = 0; i < 10; i++) {
		cout << outputs[i]->getValue() << '\n';
	}

	CNetworkManagerFile* file = CSkyNetFactory::createNetworkManagerFile();

	file->saveNetwork(removeManager,"test.txt");
	CNetworkManager* loadNet = file->loadNetwork("test.txt");

	file->saveNetwork(loadNet, "test2.txt");

	cin >> test;

    return 0;
}
