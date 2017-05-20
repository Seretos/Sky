#include "stdafx.h"
#include "CppUnitTest.h"
#include "../SkyNet/CSkyNetFactory.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SkyNetTests
{
	TEST_CLASS(NetworkTests)
	{
	public:
		TEST_METHOD(synapseTest)
		{
			INeuron* input = CSkyNetFactory::createNeuron();
			INeuron* output = CSkyNetFactory::createNeuron();
			ISynapse* synapse = CSkyNetFactory::createSynapse(input, output, 0.5);

			Assert::IsTrue(0==synapse->getValue());

			input->setValue(4);
			Assert::IsTrue(0 == synapse->getValue());
			input->request();
			output->response();
			Assert::IsTrue(0 == synapse->getValue());
			Assert::IsTrue(2 == output->getValue());
		}
	};
}