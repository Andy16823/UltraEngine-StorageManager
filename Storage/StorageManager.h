#pragma once
#include "UltraVariable.h"

using namespace UltraEngine;
using namespace std;

class StorageManager
{
private:
	std::map<String, shared_ptr<UltraVariable>> m_vars;
public:
	int CountEntitys();
	bool Contains(String name);
	bool Contains(shared_ptr<Entity> entity);
	String GetEntityKey(shared_ptr<Entity> entity);
	void RemoveEntity(String name);
	void ClearEntitys();
	String AddEntity(String name, shared_ptr<Entity> entity, bool checkForExistingVar = true);
	weak_ptr<Entity> GetEntity(String name);
};

