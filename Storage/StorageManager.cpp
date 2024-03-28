#include "UltraEngine.h"
#include "StorageManager.h"


bool StorageManager::Contains(String name)
{
	auto it = m_vars.find(name);
	if (it != m_vars.end())
		return true;
	return false;
}

bool StorageManager::Contains(shared_ptr<Entity> entity) 
{
	for (auto i : m_vars) {
		auto ref = i.second->GetEntity();
		if (ref == entity)
			return true;
	}
	return false;
}

int StorageManager::CountEntitys() {
	return m_vars.size();
}

void StorageManager::ClearEntitys() {
	m_vars.clear();
}

void StorageManager::RemoveEntity(String name)
{
	auto it = m_vars.find(name); 
	if (it != m_vars.end()) { 
		m_vars.erase(it);
	}
}

void StorageManager::AddEntity(String name, shared_ptr<Entity> entity, bool checkForExistingVar)
{
	if (checkForExistingVar) {
		if (!this->Contains(entity)) {
			auto var = UltraVariable::CreateVar(entity);
			m_vars.insert(pair<String, shared_ptr<UltraVariable>>(name, var));
		}
	}
	else {
		auto var = UltraVariable::CreateVar(entity);
		m_vars.insert(pair<String, shared_ptr<UltraVariable>>(name, var));
	}
}

weak_ptr<Entity> StorageManager::GetEntity(String name) 
{
	auto var = m_vars[name];
	if (var != nullptr) {
		var->Use();
		return var->GetEntitySave();
	}
}