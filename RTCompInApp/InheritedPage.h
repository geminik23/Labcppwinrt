#include "InheritedPage_h.h"

#include <windows.foundation.h>
#include <windows.ui.xaml.controls.h>
#include <wrl.h>
#include "LifespanTracker.h"
#include <memory>


namespace ABI
{
namespace Testing{
using namespace ::ABI::Windows;
using namespace ::ABI::Windows::Foundation;

using namespace ::Microsoft::WRL;
using namespace ::Microsoft::WRL::Wrappers;

using namespace ::ABI::Windows::UI::Xaml;
using namespace ::ABI::Windows::UI::Xaml::Controls;


class IInheritedPageAdapter
{
public:
	virtual ~IInheritedPageAdapter() = default;
	virtual ComPtr<IInspectable> CreatePage(IInspectable* inheritedPage) = 0;

};

class InheritedPageAdapter : public IInheritedPageAdapter,
	private LifespanTracker<InheritedPageAdapter>
{
	ComPtr<IPageFactory> m_pageFactory;

public:
	InheritedPageAdapter();
	virtual ComPtr<IInspectable> CreatePage(IInspectable* inheritedPage) override;
};

class InheritedPage : public RuntimeClass<
	IInheritedPage, ComposableBase<>>, 
	private LifespanTracker<InheritedPage>
{
	InspectableClass(RuntimeClass_Testing_InheritedPage, TrustLevel::BaseTrust);

	std::shared_ptr<IInheritedPageAdapter> m_adapter;


public:
	InheritedPage(std::shared_ptr<IInheritedPageAdapter> adapter);
	~InheritedPage();
/*
private:
	HRESULT OnLoaded(IInspectable *, IRoutedEventArgs *);*/

};


class InheritedFactory : public AgileActivationFactory<>,
	private LifespanTracker<InheritedFactory>
{
	std::weak_ptr<ABI::Testing::InheritedPageAdapter> m_adapter;

public:
	IFACEMETHODIMP ActivateInstance(IInspectable ** obj) override;
};


ActivatableClassWithFactory(InheritedPage, InheritedFactory);

}
}