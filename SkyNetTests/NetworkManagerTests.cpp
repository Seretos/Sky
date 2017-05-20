#include "stdafx.h"
#include "CppUnitTest.h"
#include "../SkyNet/CSkyNetFactory.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SkyNetTests
{
	TEST_CLASS(NetworkManagerTests)
	{
	public:
		TEST_METHOD(simpleNetworkManager)
		{
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

			input1->setValue(40);
			input2->setValue(100);

			manager->run();
			manager->run();

			Assert::IsFalse(0 == output->getValue());
		}
	};
}