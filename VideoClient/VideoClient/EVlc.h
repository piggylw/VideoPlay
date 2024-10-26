#pragma once
#include "vlc.h"
#include <string>

class VlcSize {
public:
	int width;
	int height;
	VlcSize(int w = 0, int h = 0)
	{
		width = w;
		height = h;
	}
	VlcSize(const VlcSize& size)
	{
		width = size.width;
		height = size.height;
	}

	VlcSize& operator=(const VlcSize& size)
	{
		width = size.width;
		height = size.height;
	}
};
class EVlc
{
public:
	EVlc();
	~EVlc();
	float GetLength();
	int SetMedia(const std::string& strUrl);
	int Play();
	int Pause();
	int Stop();
#ifdef WIN32
	int SetHwnd(HWND hWnd);
#endif // WIN32
	float GetPostion();
	void SetPosion(float pos);
	int GetVolume();
	int SetVolume(int volume);
	VlcSize GetMediaInfo();
	std::string Unicode2Utf8(const std::wstring& strIn);
protected:
	libvlc_instance_t* m_instance;
	libvlc_media_t* m_media;
	libvlc_media_player_t* m_player;
	std::string m_url;
#ifdef WIN32
	HWND m_hwnd;
#endif // WIN32
};

