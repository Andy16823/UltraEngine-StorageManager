#include "UltraEngine.h"
#include "StorageManager.h"


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

void StorageManager::AddEntity(String name, shared_ptr<Entity> entity)
{
	auto var = UltraVariable::CreateVar(entity);
	m_vars.insert(pair<String, shared_ptr<UltraVariable>>(name, var));
}

weak_ptr<Entity> StorageManager::GetEntity(String name) 
{
	auto var = m_vars[name];
	if (var != nullptr) {
		var->Use();
		return var->GetEntitySave();
	}
}