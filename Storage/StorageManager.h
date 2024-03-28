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
	void RemoveEntity(String name);
	void ClearEntitys();
	void AddEntity(String name, shared_ptr<Entity> entity);
	weak_ptr<Entity> GetEntity(String name);
};

