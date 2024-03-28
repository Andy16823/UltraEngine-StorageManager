#pragma once
#include "UltraEngine.h"
#include "UltraVariable.h"


void UltraVariable::Use() 
{
	m_lastUsage = Millisecs();
}

shared_ptr<UltraVariable> UltraVariable::CreateVar(shared_ptr<Entity> entity)
{
	auto var = make_shared<UltraVariable>();
	var->SetEntity(entity);
	var->Use();
	return var;
}