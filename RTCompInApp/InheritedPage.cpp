#include "pch.h"
#include "InheritedPage.h"
#include "ErrorHandling.h"
#include "Utilities.h"

using namespace ABI::Testing;
using namespace ::Microsoft::WRL;
using namespace ::Microsoft::WRL::Wrappers;
using namespace ABI::Windows::UI::Xaml::Controls;


ABI::Testing::InheritedPageAdapter::InheritedPageAdapter()
{
	ThrowIfFailed(
		GetActivationFactory(
			HStringReference(RuntimeClass_Windows_UI_Xaml_Controls_Page).Get(),
			&m_pageFactory)
	);
}

ComPtr<IInspectable> ABI::Testing::InheritedPageAdapter::CreatePage(IInspectable * inheritedPage)
{
	ComPtr<IInspectable> pageInspectable;
	ComPtr<IPage> page;
	ThrowIfFailed(
		m_pageFactory->CreateInstance(inheritedPage, &pageInspectable, &page)
	);

	return pageInspectable;
}

IFACEMETHODIMP::ABI::Testing::InheritedFactory::ActivateInstance(IInspectable ** obj)
{
	return ExceptionBoundary(
		[&]
	{
		CheckAndClearOutPointer(obj);

		auto adapter = m_adapter.lock();

		if(!adapter)
			m_adapter = adapter = std::make_shared<ABI::Testing::InheritedPageAdapter>();

		auto page = Make<ABI::Testing::InheritedPage>(adapter);
		CheckMakeResult(page);

		ThrowIfFailed(page.CopyTo(obj));
	}
	);
}


ABI::Testing::InheritedPage::InheritedPage(std::shared_ptr<IInheritedPageAdapter> adapter)
	:m_adapter{ adapter }
{
	auto base = this->m_adapter->CreatePage(static_cast<ABI::Testing::IInheritedPage *>(this));
	ThrowIfFailed(SetComposableBasePointers(base.Get(), nullptr));


	//auto frameworkElement = As<IFrameworkElement>(this);

	//EventRegistrationToken tokenThatIsThrownAway{};
	//auto callback = Callback<IRoutedEventHandler>(this, &CanvasSwapChainPanel::OnLoaded);
	//CheckMakeResult(callback);

	//ThrowIfFailed(frameworkElement->add_Loaded(callback.Get(), &tokenThatIsThrownAway));

}

ABI::Testing::InheritedPage::~InheritedPage()
{}

//HRESULT ABI::Testing::InheritedPage::OnLoaded(IInspectable *, IRoutedEventArgs *)
//{
//	return E_NOTIMPL;
//}


