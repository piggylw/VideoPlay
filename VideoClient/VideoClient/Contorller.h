#pragma once
#include "EVlc.h"
#include "VideoClientDlg.h"

enum class CTRL_CMD
{
	EVLC_PALY,
	EVLC_PAUSE,
	EVLC_STOP,
	EVLC_GET_VOLUME,
	EVLC_GET_POS,
	EVLC_GET_LENGTH
};
class Contorller
{
public:

	Contorller();
	~Contorller();
	int Init(CWnd*& pWnd);
	int Invoke();
	int SetMedia(const std::string& strUrl);
	float VideoCtrl(CTRL_CMD cmd);
	void SetPosition(float pos);
	int SetWnd(HWND hWnd);
	int SetVolume(int volume);
	VlcSize GetMediaInfo();

	std::string Unicode2Utf8(const std::wstring& strIn);
protected:
	EVlc m_vlc;
	CVideoClientDlg m_dlg;
};

