#include "pch.h"
#include "Contorller.h"

Contorller::Contorller()
{
	m_dlg.m_controller = this;
}

Contorller::~Contorller()
{
}

int Contorller::Init(CWnd*& pWnd)
{
	pWnd = &m_dlg;
	return 0;
}

int Contorller::Invoke()
{
	INT_PTR nResponse = m_dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: �ڴ˷��ô����ʱ��
		//  ��ȷ�������رնԻ���Ĵ���
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: �ڴ˷��ô����ʱ��
		//  ��ȡ�������رնԻ���Ĵ���
	}
	else if (nResponse == -1)
	{
		TRACE(traceAppMsg, 0, "����: �Ի��򴴽�ʧ�ܣ�Ӧ�ó���������ֹ��\n");
		TRACE(traceAppMsg, 0, "����: ������ڶԻ�����ʹ�� MFC �ؼ������޷� #define _AFX_NO_MFC_CONTROLS_IN_DIALOGS��\n");
	}
	return nResponse;
}

int Contorller::SetMedia(const std::string& strUrl)
{
	
	return m_vlc.SetMedia(strUrl);
}

float Contorller::VideoCtrl(CTRL_CMD cmd)
{
	switch (cmd)
	{
	case CTRL_CMD::EVLC_PALY:
		return (float)m_vlc.Play();
		break;
	case CTRL_CMD::EVLC_PAUSE:
		return (float)m_vlc.Pause();
		break;
	case CTRL_CMD::EVLC_STOP:
		return (float)m_vlc.Stop();
		break;
	case CTRL_CMD::EVLC_GET_VOLUME:
		return (float)m_vlc.GetVolume();
		break;
	case CTRL_CMD::EVLC_GET_POS:
		return m_vlc.GetPostion();
		break;
	case CTRL_CMD::EVLC_GET_LENGTH:
		return m_vlc.GetLength();
		break;
	default:
		break;
	}
	return -1.0f;
}

void Contorller::SetPosition(float pos)
{
	m_vlc.SetPosion(pos);
}

int Contorller::SetWnd(HWND hWnd)
{
	return m_vlc.SetHwnd(hWnd);
}

int Contorller::SetVolume(int volume)
{
	return m_vlc.SetVolume(volume);
}

VlcSize Contorller::GetMediaInfo()
{
	return m_vlc.GetMediaInfo();
}

std::string Contorller::Unicode2Utf8(const std::wstring& strIn)
{
	return m_vlc.Unicode2Utf8(strIn);
}
