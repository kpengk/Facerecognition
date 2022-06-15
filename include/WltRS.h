#ifndef _WltRS_H_
#define _WltRS_H_

#ifdef WIN32

#ifdef DLL_EXPORTS
#define DLL_API  extern "C" __declspec(dllexport)
#else//DLL_EXPORTS
#define DLL_API extern "C" __declspec(dllimport)
#endif//DLL_EXPORTS

#else//WIN32
#define DLL_API
#endif//WIN32


DLL_API int GetBmp(char *Wlt_File, int intf);
DLL_API int WltRS(const char *Infile, const char *Outfile);

#endif
