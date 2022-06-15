#ifndef _READERDLL_H
#define _READERDLL_H

#ifdef WIN32

#ifdef DLL_EXPORTS
#define DLL_API  extern "C" __declspec(dllexport)
#else//DLL_EXPORTS

#ifdef __cplusplus
#define DLL_API extern "C" __declspec(dllimport)
#else//__cplusplus
#define DLL_API
#endif//__cplusplus

#endif//DLL_EXPORTS

#else//WIN32

#ifdef __cplusplus
#define DLL_API extern "C"  
#else
#define DLL_API	
#endif //__cplusplus

#endif//WIN32
typedef struct IDCARDINFO
{
	char name[24];
	char gender[24];
	char folk[24];
	char birth[24];
	char address[128];
	char id[24];
	char issue[128];
	char startDate[24];
	char endDate[24];
}IDCardInfo;


DLL_API int OpenReader(char const* port, int baud);
DLL_API int FindCard(char const* port);
DLL_API int SelectCard(char const* port);
DLL_API int ReadBaseFPMsg(const char* port, unsigned char* WZbuffer, int WZ_length,
	unsigned char* ZPbuffer, int ZP_length, unsigned char* FPbuffer, int FP_length);
DLL_API int DecodeWZu8(IDCardInfo* id_info, unsigned char* data, int length);
DLL_API void CloseReader(char const* port);

#endif//_READERDLL_H