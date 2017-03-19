#pragma once


#pragma comment(lib,"runtimeobject")
#include <assert.h>
#include <wrl.h>
#include <windows.ui.xaml.data.h>
#include <windows.foundation.h>

using namespace ABI::Windows::UI::Xaml::Data;
using namespace Microsoft::WRL;
using namespace Microsoft::WRL::Wrappers;


namespace RTHelper
{
namespace DataBinding
{

class PropertyChangedEventArg
{
	ComPtr<IPropertyChangedEventArgs> m_valueChangedEventArgs;
public:
	PropertyChangedEventArg(HSTRING name)
	{
		ComPtr<IPropertyChangedEventArgsFactory> pArgs;

		ABI::Windows::Foundation::GetActivationFactory(HStringReference(RuntimeClass_Windows_UI_Xaml_Data_PropertyChangedEventArgs).Get(), pArgs.GetAddressOf());
		pArgs->CreateInstance(name,
							  nullptr,
							  nullptr,
							  m_valueChangedEventArgs.GetAddressOf());
	}

	IPropertyChangedEventArgs* Get() noexcept
	{
		return m_valueChangedEventArgs.Get();
	}


};

}
}