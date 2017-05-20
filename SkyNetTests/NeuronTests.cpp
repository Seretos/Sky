#include "stdafx.h"
#include "CppUnitTest.h"
#include "../SkyNet/CSkyNetFactory.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SkyNetTests
{
	TEST_CLASS(NeuronTests)
	{
	public:
		TEST_METHOD(linearNeuron)
		{
			INeuron* neuron = CSkyNetFactory::createNeuron();

			Assert::IsTrue(0==neuron->getValue());

			neuron->setValue(0.23);
			Assert::IsTrue(0.23 == neuron->getValue());

			neuron->setValue(-4);
			Assert::IsTrue(-4 == neuron->getValue());

			neuron->setThreshold(0.5);

			neuron->setValue(0.26);
			Assert::IsTrue(0 == neuron->getValue());

			neuron->setValue(-0.6);
			Assert::IsTrue(0 == neuron->getValue());

			neuron->setValue(0.6);
			Assert::IsTrue(0.6 == neuron->getValue());
		}

		TEST_METHOD(binaerNeuron) {
			INeuron* neuron = CSkyNetFactory::createBinaerNeuron();

			Assert::IsTrue(0 == neuron->getValue());

			neuron->setValue(0.23);
			Assert::IsTrue(0 == neuron->getValue());

			neuron->setValue(-2.64);
			Assert::IsTrue(0 == neuron->getValue());

			neuron->setValue(1);
			Assert::IsTrue(1 == neuron->getValue());

			neuron->setValue(2);
			Assert::IsTrue(1 == neuron->getValue());

			neuron->setThreshold(-0.2);

			neuron->setValue(-0.1);
			Assert::IsTrue(-0.2 == neuron->getValue());

			neuron->setValue(-0.3);
			Assert::IsTrue(0 == neuron->getValue());
		}

		TEST_METHOD(biasNeuron) {
			INeuron* neuron = CSkyNetFactory::createBiasNeuron();

			Assert::IsTrue(1 == neuron->getValue());
			neuron->request();
			neuron->response();
			Assert::IsTrue(1 == neuron->getValue());

			neuron->setThreshold(4);

			Assert::IsTrue(4 == neuron->getValue());
			neuron->request();
			neuron->response();
			Assert::IsTrue(4 == neuron->getValue());
		}
	};
}