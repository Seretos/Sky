#pragma once
#include <vector>

#if defined(_WIN32)
#ifdef INEURON_EXPORTS
#define INEURON_API __declspec(dllexport)
#else
#define INEURON_API __declspec(dllimport)
#endif
#else
#define INEURON_API
#endif

class INeuron;

class ISynapse {
public:
	ISynapse(INeuron* source, INeuron* destination, double weight);

	virtual INEURON_API double getWeight();
	virtual INEURON_API void setWeight(double weight);

	virtual INEURON_API INeuron* getSourceNeuron();
	virtual INEURON_API INeuron* getTargetNeuron();

	virtual INEURON_API void setValue(double value);
	virtual INEURON_API double getValue();

	virtual int getType() = 0;
protected:
	INeuron* source;
	INeuron* destination;
	double weight;
	double value;
};

class INeuron {
public:

	INeuron();
	~INeuron();

	virtual INEURON_API void setValue(double value) = 0;
	virtual INEURON_API double getValue();
	virtual INEURON_API int getType() = 0;

	INEURON_API void request();
	INEURON_API void response();

	INEURON_API void setThreshold(double threshold);
	INEURON_API double getThreshold();

	void addOutputSynapse(ISynapse* synapse);
	void addInputSynapse(ISynapse* synapse);

	void setSaveId(int id);
	int getSaveId();

	INEURON_API int getOutputSynapseSize();
	INEURON_API ISynapse* getOutputSynapse(int index);
protected:
	double threshold;
	double value;
	std::vector<ISynapse*> outputs;
	std::vector<ISynapse*> inputs;
	int saveId;
};
