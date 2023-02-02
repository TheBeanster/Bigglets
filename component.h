#pragma once



enum class ComponentType
{
	testComponent,
};



class Component
{
public:
	
	ComponentType type;

	virtual void Start();
	virtual void Update();
	virtual void Render();
	virtual void Destroy();
};