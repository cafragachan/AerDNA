
#pragma once

//--------------------------
//---- windows include
//--------------------------
#include<Unknwnbase.h>
#include<commdlg.h>

#include <iomanip>

#if defined(WIN32) 
#undef WIN32
#endif

#include <rhinoSdkStdafxPreamble.h>

#define NOMINMAX
#include <Windows.h>

#define RHINO_V6_READY

#pragma warning (disable: 4251)

#include <rhinoSdk.h>
