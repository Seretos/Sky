#include "stdafx.h"
#include "CSimulationManager.h"
#include <thread>

void networkSimulationThreadMethod(CNetworkManager* manager) {
	manager->run();
}

CSimulationManager::CSimulationManager() {
	this->networks = std::vector<CNetworkManager*>();
}

CSimulationManager::~CSimulationManager() {
	this->networks.clear();
}

int CSimulationManager::addNetwork(CNetworkManager* network) {
	this->networks.push_back(network);
	return this->networks.size() - 1;
}

void CSimulationManager::removeNetwork(CNetworkManager* network) {
	for (int i = 0; i < this->networks.size(); i++) {
		if (this->networks.at(i) == network) {
			this->networks.erase(this->networks.begin()+i);
		}
	}
}

void CSimulationManager::run() {
	std::vector<std::thread> threads = std::vector<std::thread>();

	for (int i = 0; i < this->networks.size(); i++) {
		threads.push_back(std::thread(networkSimulationThreadMethod,this->networks.at(i)));
	}

	for (int i = 0; i < threads.size(); i++) {
		threads.at(i).join();
	}

	threads.clear();
}