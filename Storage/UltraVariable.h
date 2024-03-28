#pragma once

using namespace UltraEngine;
using namespace std;

class UltraVariable
{
private:
	shared_ptr<Entity> m_entity;
	uint16_t m_lastUsage;
public:

	~UltraVariable() {
		m_entity.reset();
	}

	virtual void SetEntity(shared_ptr<Entity> entity) {
		m_entity = entity;
	}

	virtual weak_ptr<Entity> GetEntitySave() {
		return m_entity;
	}

	virtual shared_ptr<Entity> GetEntity() {
		return m_entity;
	}

	virtual int GetUsages() {
		return m_entity.use_count();
	}

	virtual void Reset() {
		m_entity.reset();
	}

	virtual bool IsAllive() {
		if (m_entity != nullptr)
			return true;
		return false;
	}

	void Use();
	static shared_ptr<UltraVariable> CreateVar(shared_ptr<Entity> entity);
};

