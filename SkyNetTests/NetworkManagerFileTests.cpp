#include "stdafx.h"
#include "CppUnitTest.h"
#include "../SkyNet/CSkyNetFactory.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SkyNetTests
{
	TEST_CLASS(NetworkManagerFileTests)
	{
	public:
		TEST_METHOD(NetworkManagerFile)
		{
			INetwork* network = CSkyNetFactory::createNetwork();
			CNetworkManager* manager = CSkyNetFactory::createNetworkManager(network);

			INeuron* input1 = CSkyNetFactory::createNeuron();
			INeuron* input2 = CSkyNetFactory::createNeuron();
			INeuron* hidden11 = CSkyNetFactory::createTanhNeuron();
			INeuron* hidden12 = CSkyNetFactory::createLogisticNeuron();
			INeuron* hidden13 = CSkyNetFactory::createBinaerNeuron();
			INeuron* hidden21 = CSkyNetFactory::createBiasNeuron();
			INeuron* hidden22 = CSkyNetFactory::createTanhNeuron();
			INeuron* hidden23 = CSkyNetFactory::createTanhNeuron();
			INeuron* output1 = CSkyNetFactory::createNeuron();
			INeuron* output2 = CSkyNetFactory::createNeuron();

			CLayer* inputLayer = CSkyNetFactory::createLayer(network);
			CLayer* hiddenLayer1 = CSkyNetFactory::createLayer(network);
			CLayer* hiddenLayer2 = CSkyNetFactory::createLayer(network);
			CLayer* outputLayer = CSkyNetFactory::createLayer(network);

			inputLayer->addNeuron(input1);
			inputLayer->addNeuron(input2);

			hiddenLayer1->addNeuron(hidden11);
			hiddenLayer1->addNeuron(hidden12);
			hiddenLayer1->addNeuron(hidden13);

			hiddenLayer2->addNeuron(hidden21);
			hiddenLayer2->addNeuron(hidden22);
			hiddenLayer2->addNeuron(hidden23);

			outputLayer->addNeuron(output1);
			outputLayer->addNeuron(output2);

			manager->setInputLayer(inputLayer);
			manager->addHiddenLayer(hiddenLayer1);
			manager->addHiddenLayer(hiddenLayer2);
			manager->setOutputLayer(outputLayer);

			manager->autoConnectLayers();

			input1->setValue(-20);
			input2->setValue(4000);

			manager->run();
			manager->run();
			manager->run();

			Assert::IsFalse(0 == output1->getValue());
			Assert::IsFalse(0 == output2->getValue());

			CNetworkManagerFile* file = CSkyNetFactory::createNetworkManagerFile();
			file->saveNetwork(manager, "net1.txt");
			CNetworkManager* manager2 = file->loadNetwork("net1.txt");

			manager2->getInputLayer()->getNeuron(0)->setValue(-20);
			manager2->getInputLayer()->getNeuron(0)->setValue(4000);

			manager2->run();
			manager2->run();
			manager2->run();

			Assert::IsFalse(0 == manager2->getOutputLayer()->getNeuron(0)->getValue());
			Assert::IsFalse(0 == manager2->getOutputLayer()->getNeuron(1)->getValue());

			Assert::IsTrue(((output1->getValue() - manager2->getOutputLayer()->getNeuron(0)->getValue())<0.1)||
				((output1->getValue() - manager2->getOutputLayer()->getNeuron(0)->getValue())>-0.1)
			);
			Assert::IsTrue(((output2->getValue() - manager2->getOutputLayer()->getNeuron(1)->getValue())<0.1) ||
				((output2->getValue() - manager2->getOutputLayer()->getNeuron(1)->getValue())>-0.1)
			);
		}
	};
}