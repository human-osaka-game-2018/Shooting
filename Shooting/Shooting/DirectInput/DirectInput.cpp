#include"DirectInput.h"



HRESULT DirectInput::Initialize(HWND hWnd)
{
	HRESULT hr;
	//オブジェクトの作成
	if (FAILED(hr = DirectInput8Create(GetModuleHandle(NULL),
		DIRECTINPUT_VERSION, IID_IDirectInput8, (VOID**)&m_pDinput, NULL)))
	{
		return hr;
	}

	//デバイスの作成
	if (FAILED(hr = m_pDinput->CreateDevice(GUID_SysKeyboard, &m_pKeyDevice, NULL)))
	{
		return hr;
	}

	//デバイスをキーボードに設定
	if (FAILED(hr = m_pKeyDevice->SetDataFormat(&c_dfDIKeyboard)))
	{
		return hr;
	}

	//協調レベルの設定
	if (FAILED(hr = m_pKeyDevice->SetCooperativeLevel(hWnd, DISCL_NONEXCLUSIVE | DISCL_BACKGROUND)))
	{
		return hr;
	}

	//デバイスを取得する
	m_pKeyDevice->Acquire();
	return S_OK;
}

void DirectInput::CaptureKeyState()
{
	//入力を調べる
	HRESULT hr = m_pKeyDevice->Acquire();
	if ((hr == DI_OK) || (hr == S_FALSE))
	{
		m_pKeyDevice->GetDeviceState(sizeof(m_diks), m_diks);
	}
}

bool DirectInput::IsKeyPressed(int key)
{
	return (0 != (m_diks[key] & 0x80));
}

DirectInput::~DirectInput()
{
	m_pKeyDevice->Unacquire();
	m_pKeyDevice->Release();
	m_pDinput->Release();
}
