#include "stdafx.h"
#include "CppUnitTest.h"
#include "../SkyNet/CSkyNetFactory.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SkyNetTests
{		
	TEST_CLASS(NetworkTests)
	{
	public:
		TEST_METHOD(xorNetwork)
		{
			INetwork* network = CSkyNetFactory::createNetwork();

			INeuron* input1 = CSkyNetFactory::createNeuron();
			INeuron* input2 = CSkyNetFactory::createNeuron();
			INeuron* hidden1 = CSkyNetFactory::createNeuron();
			INeuron* hidden2 = CSkyNetFactory::createNeuron();
			INeuron* hidden3 = CSkyNetFactory::createNeuron();
			INeuron* output = CSkyNetFactory::createNeuron();

			hidden2->setThreshold(2.0);

			ISynapse* synapse1 = CSkyNetFactory::createSynapse(input1, hidden1, 1.0);
			ISynapse* synapse2 = CSkyNetFactory::createSynapse(input1, hidden2, 1.0);
			ISynapse* synapse3 = CSkyNetFactory::createSynapse(input2, hidden2, 1.0);
			ISynapse* synapse4 = CSkyNetFactory::createSynapse(input2, hidden3, 1.0);
			ISynapse* synapse5 = CSkyNetFactory::createSynapse(hidden1, output, 1.0);
			ISynapse* synapse6 = CSkyNetFactory::createSynapse(hidden2, output, -1.0);
			ISynapse* synapse7 = CSkyNetFactory::createSynapse(hidden3, output, 1.0);

			network->addNeuron(input1);
			network->addNeuron(input2);
			network->addNeuron(hidden1);
			network->addNeuron(hidden2);
			network->addNeuron(hidden3);
			network->addNeuron(output);

			input1->setValue(0);
			input2->setValue(0);

			network->request();
			network->response();
			network->request();
			network->response();

			Assert::IsTrue(0 == output->getValue());

			input1->setValue(1);
			input2->setValue(0);

			network->request();
			network->response();
			network->request();
			network->response();

			Assert::IsTrue(1 == output->getValue());

			input1->setValue(0);
			input2->setValue(1);

			network->request();
			network->response();
			network->request();
			network->response();

			Assert::IsTrue(1 == output->getValue());

			input1->setValue(1);
			input2->setValue(1);

			network->request();
			network->response();
			network->request();
			network->response();

			Assert::IsTrue(0 == output->getValue());
		}

		TEST_METHOD(orNetwork) 
		{
			INetwork* network = CSkyNetFactory::createNetwork();

			INeuron* input1 = CSkyNetFactory::createNeuron();
			INeuron* input2 = CSkyNetFactory::createNeuron();
			INeuron* output = CSkyNetFactory::createBinaerNeuron();

			ISynapse* synapse1 = CSkyNetFactory::createSynapse(input1, output, 1.0);
			ISynapse* synapse2 = CSkyNetFactory::createSynapse(input2, output, 1.0);

			network->addNeuron(input1);
			network->addNeuron(input2);
			network->addNeuron(output);

			input1->setValue(0);
			input2->setValue(0);

			network->request();
			network->response();

			Assert::IsTrue(0 == output->getValue());

			input1->setValue(1);
			input2->setValue(0);

			network->request();
			network->response();

			Assert::IsTrue(1 == output->getValue());

			input1->setValue(0);
			input2->setValue(1);

			network->request();
			network->response();

			Assert::IsTrue(1 == output->getValue());

			input1->setValue(1);
			input2->setValue(1);

			network->request();
			network->response();

			Assert::IsTrue(1 == output->getValue());
		}

		TEST_METHOD(andNetwork)
		{
			INetwork* network = CSkyNetFactory::createNetwork();

			INeuron* input1 = CSkyNetFactory::createNeuron();
			INeuron* input2 = CSkyNetFactory::createNeuron();
			INeuron* output = CSkyNetFactory::createNeuron();
			output->setThreshold(1);

			ISynapse* synapse1 = CSkyNetFactory::createSynapse(input1, output, 0.5);
			ISynapse* synapse2 = CSkyNetFactory::createSynapse(input2, output, 0.5);

			network->addNeuron(input1);
			network->addNeuron(input2);
			network->addNeuron(output);

			input1->setValue(0);
			input2->setValue(0);

			network->request();
			network->response();

			Assert::IsTrue(0 == output->getValue());

			input1->setValue(1);
			input2->setValue(0);

			network->request();
			network->response();

			Assert::IsTrue(0 == output->getValue());

			input1->setValue(0);
			input2->setValue(1);

			network->request();
			network->response();

			Assert::IsTrue(0 == output->getValue());

			input1->setValue(1);
			input2->setValue(1);

			network->request();
			network->response();

			Assert::IsTrue(1 == output->getValue());
		}

		TEST_METHOD(simpleNetwork)
		{
			INetwork* network = CSkyNetFactory::createNetwork();

			INeuron* input1 = CSkyNetFactory::createNeuron();
			INeuron* input2 = CSkyNetFactory::createNeuron();
			INeuron* output = CSkyNetFactory::createNeuron();

			ISynapse* synapse1 = CSkyNetFactory::createSynapse(input1, output, 0.1);
			ISynapse* synapse2 = CSkyNetFactory::createSynapse(input2, output, 0.2);

			network->addNeuron(input1);
			network->addNeuron(input2);
			network->addNeuron(output);

			Assert::IsTrue(0 == input1->getValue());
			Assert::IsTrue(0 == input2->getValue());
			Assert::IsTrue(0 == output->getValue());

			input1->setValue(1.0);
			input2->setValue(2.5);

			Assert::IsTrue(1.0 == input1->getValue());
			Assert::IsTrue(2.5 == input2->getValue());
			Assert::IsTrue(0 == output->getValue());

			network->request();
			
			Assert::IsTrue(0 == input1->getValue());
			Assert::IsTrue(0 == input2->getValue());
			Assert::IsTrue(0 == output->getValue());
			
			network->response();

			Assert::IsTrue(0 == input1->getValue());
			Assert::IsTrue(0 == input2->getValue());
			Assert::IsTrue(0.6 == output->getValue());

			synapse1->setWeight(0.6);
			synapse2->setWeight(-0.5);

			input1->setValue(3.0);
			input2->setValue(-1.5);

			Assert::IsTrue(3.0 == input1->getValue());
			Assert::IsTrue(-1.5 == input2->getValue());
			Assert::IsTrue(0.6 == output->getValue());
			
			network->request();

			Assert::IsTrue(0 == input1->getValue());
			Assert::IsTrue(0 == input2->getValue());
			Assert::IsTrue(0 == output->getValue());

			network->response();

			Assert::IsTrue(0 == input1->getValue());
			Assert::IsTrue(0 == input2->getValue());
			Assert::IsTrue(2.55 == output->getValue());
		}

	};
}