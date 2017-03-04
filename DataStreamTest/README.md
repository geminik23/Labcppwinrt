What I need?
=========================

```c++
using namespace winrt;
Windows::Networking::Sockets::DatagramSocket socket;
Windows::Networking::HostName hostname;
Windows::Storage::Streams::IOutputStream outStream;
Windows::Storage::Streams::IInputStream inStream;
Windows::Storage::Streams::DataWriter writer;
winrt::ppl;

```

DatagramSocket Linstener
=========================
[Reference](https://docs.microsoft.com/en-us/uwp/api/windows.networking.sockets.datagramsocket)
```c++
// create DatagramSocket object
Windows::Networking::Sockets::DatagramSocket datagram;

// set Control properties if you need
auto control = datagram.Control();
/* do something with DatagramSocketControl*/

using SocketMSGReceivedHandler = winrt::Windows::Foundation::TypedEventHandler<
			DatagramSocket, DatagramSocketMessageReceivedEventArgs>;

datagram.MessageReceived(SocketMSGReceivedHandler([](DatagramSocket const& sender, DatagramSocketMessageReceivedEventArgs const& arg) {
    /* handle */
}));

bool localHost = true;
std::wstring port = L"3000";
HostName hostname(L"127.0.0.1");

if (localHost)
    winrt::ppl::create_task(datagram.BindServiceNameAsync(port)).then(...);
else
    winrt::ppl::create_task(datagram.BindEndpointAsync(hostname, port)).then(...);


```
If you want to know about DatagramSocketControl Click [Here](https://docs.microsoft.com/en-us/uwp/api/windows.networking.sockets.datagramsocketcontrol)



DatagramSocket sender
==========================

```c++
// only different calling method
winrt::ppl::create_task(socket.ConnectAsync(hostname, port)).then(
    [this](concurrency::task<void> prev) {
    try
    {
        prev.get();
        OutputDebugString(L"Socket connect Succeeded.\n");
    } catch (winrt::hresult_error)
    {
    }
});

```


Temporary storing
--------------------------
```c++
auto props = winrt::Windows::Applcation::Core::CoreApplication::Properties();
if(!props.HasKey(L"key")){
    winrt::Windows::IInspectable value = //init
    props.Insert(L"Key", value);
}




```
