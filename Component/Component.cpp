#include "pch.h"

#include "Component.h"

using namespace Microsoft::WRL;
using namespace Microsoft::WRL::Wrappers;


namespace ABI
{
namespace Component
{

	
class Component : public RuntimeClass<IComponent>
{
	InspectableClass(RuntimeClass_Component_Component, TrustLevel::BaseTrust);
public:
	STDMETHOD(SayHello)(HSTRING Hello)
	{
		OutputDebugString(L"Hello");
		return S_OK;
	}

};

ActivatableClass(Component)

}
}