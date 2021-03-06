// SkyExample.cpp : Definiert den Einstiegspunkt f�r die Konsolenanwendung.
//


#include "stdafx.h"
#include <iostream>
#include "../SkyNet/CSkyNetFactory.h"
#include "../SkyNet/INetwork.h"
#include "../SkyView/CSkyViewFactory.h"
#include <time.h>
#include <cstdlib>
#include <thread>

using namespace std;

void networkViewThread(CRenderWindow* window) {
	window->render();
}

CNetworkManager* createManager2() {
	INetwork* network = CSkyNetFactory::createNetwork();
	CNetworkManager* manager = CSkyNetFactory::createNetworkManager(network);
	CLayer* inputLayer = CSkyNetFactory::createLayer(network);
	CLayer* hiddenLayer = CSkyNetFactory::createLayer(network);
	CLayer* hiddenLayer2 = CSkyNetFactory::createLayer(network);
	CLayer* outputLayer = CSkyNetFactory::createLayer(network);
	INeuron* input1 = CSkyNetFactory::createNeuron();
	INeuron* input2 = CSkyNetFactory::createNeuron();
	INeuron* hidden1 = CSkyNetFactory::createNeuron();
	INeuron* hidden2 = CSkyNetFactory::createNeuron();
	INeuron* hidden3 = CSkyNetFactory::createNeuron();
	INeuron* hidden21 = CSkyNetFactory::createNeuron();
	INeuron* hidden22 = CSkyNetFactory::createNeuron();
	INeuron* hidden23 = CSkyNetFactory::createNeuron();
	INeuron* output = CSkyNetFactory::createNeuron();

	inputLayer->addNeuron(input1);
	inputLayer->addNeuron(input2);

	hiddenLayer->addNeuron(hidden1);
	hiddenLayer->addNeuron(hidden2);
	hiddenLayer->addNeuron(hidden3);

	hiddenLayer2->addNeuron(hidden21);
	hiddenLayer2->addNeuron(hidden22);
	hiddenLayer2->addNeuron(hidden23);

	outputLayer->addNeuron(output);

	manager->setInputLayer(inputLayer);
	manager->addHiddenLayer(hiddenLayer);
	manager->addHiddenLayer(hiddenLayer2);
	manager->setOutputLayer(outputLayer);

	manager->autoConnectLayers();

	return manager;
}

CNetworkManager* createManager1() {
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

	return manager;
}

CNetworkManager* createManager3() {
	INetwork* network = CSkyNetFactory::createNetwork();
	CNetworkManager* manager = CSkyNetFactory::createNetworkManager(network);
	CLayer* inputLayer = CSkyNetFactory::createLayer(network);
	
	CLayer* outputLayer = CSkyNetFactory::createLayer(network);

	for (int i = 0; i < 10; i++) {
		INeuron* input = CSkyNetFactory::createNeuron();
		inputLayer->addNeuron(input);
	}

	for (int i = 0; i < 20; i++) {
		CLayer* hiddenLayer = CSkyNetFactory::createLayer(network);
		for (int y = 0; y < 15; y++) {
			INeuron* hidden = CSkyNetFactory::createTanhNeuron();
			hiddenLayer->addNeuron(hidden);
		}
		manager->addHiddenLayer(hiddenLayer);
	}

	for (int i = 0; i < 5; i++) {
		INeuron* output = CSkyNetFactory::createNeuron();
		outputLayer->addNeuron(output);
	}

	manager->setInputLayer(inputLayer);
	manager->setOutputLayer(outputLayer);

	manager->autoConnectLayers();

	return manager;
}

int main()
{
		srand(time(NULL));
		CNetworkManager* manager1 = createManager1();
		CNetworkManager* manager2 = createManager2();
		CNetworkManager* manager3 = createManager3();

		CRenderWindow* window = CSkyViewFactory::createRenderWindow(1024,768);
		CRenderFrame* frame1 = CSkyViewFactory::createNetworkFrame(manager1,10,10,200,200);
		CRenderFrame* frame2 = CSkyViewFactory::createNetworkFrame(manager2, 210, 10, 200, 200);
		CRenderFrame* frame3 = CSkyViewFactory::createNetworkFrame(manager3, 10, 210, 800, 400);

		window->init();

        window->add(frame1);
		window->add(frame2);
		window->add(frame3);

		//CRenderWindow* window2 = CSkyViewFactory::createNetworkWindow(manager2);
		//window2->init();

		int pos = 0;
		while (1) {
			//window2->render();
			window->render();
			manager1->run();
			manager2->run();
			manager3->run();
//			Sleep(1000);
			pos++;
			if (pos == 4) {
				manager1->getInputLayer()->getNeuron(0)->setValue(1.0);
				manager1->getInputLayer()->getNeuron(1)->setValue(-1.0);

				manager2->getInputLayer()->getNeuron(0)->setValue(1.0);
				manager2->getInputLayer()->getNeuron(1)->setValue(-1.0);

				double v = -2.5;
				for (int i = 0; i < 10; i++) {
					manager3->getInputLayer()->getNeuron(i)->setValue(v);
					v += 0.5;
				}
				pos = 0;
			}
		}
	/*int test;

	INeuron* inputs1[10];
	INeuron* inputs2[10];
	INeuron* outputs[10];

	CSimulationManager* simulationManager = CSkyNetFactory::createSimulationManager();
	CNetworkManager* removeManager;
	std::thread th;
	CRenderWindow* window;
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
			//th = std::thread(networkViewThread, window);
		}

	}
	window = CSkyViewFactory::createNetworkWindow(removeManager);
	window->init();
	window->render();

	for (int i = 0; i < 10; i++) {
	inputs1[i]->setValue(40);
	inputs2[i]->setValue(120);
	}
	window->render();
	simulationManager->run();
	window->render();
	simulationManager->run();
	window->render();
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
	window->render();
	simulationManager->run();
	window->render();
	simulationManager->run();
	window->render();
	for (int i = 0; i < 10; i++) {
	cout << outputs[i]->getValue() << '\n';
	}

	CNetworkManagerFile* file = CSkyNetFactory::createNetworkManagerFile();

	file->saveNetwork(removeManager,"test.txt");
	CNetworkManager* loadNet = file->loadNetwork("test.txt");

	file->saveNetwork(loadNet, "test2.txt");

	cin >> test;

	cout << test;

	cin >> test;

	//th.join();*/

	return 0;
}
