#pragma once
#include "UltraVariable.h"

using namespace UltraEngine;
using namespace std;

class StorageManager
{
private:
	std::map<String, shared_ptr<UltraVariable>> m_vars;
public:

	virtual uint64_t MillisFromSeconds(int seconds) {
		return seconds * 1000;
	}

	virtual uint64_t MillisFromMinutes(int minutes) {
		return minutes * 60000;
	}

	int CountEntitys();
	bool Contains(String name);
	bool Contains(shared_ptr<Entity> entity);
	String GetEntityKey(shared_ptr<Entity> entity);
	void RemoveEntity(String name);
	void ClearEntitys();
	void ClearGarbage(uint64_t duration);
	String AddEntity(String name, shared_ptr<Entity> entity, bool checkForExistingVar = true);
	String AddEntity(shared_ptr<Entity> entity);
	weak_ptr<Entity> GetEntity(String name);
};

