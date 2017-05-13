#pragma once

/*!***********************************************************************************************************************************************************
 * @file        HRGraphics_Defines.h
 *
 * This file contains the macros for the engine's portability in the next systems (In the following order):
 * - Class exports for the dynamic library efxports.
 *
 * @date        27-10-2016
 * @author      Manuel Aldair Santos Ram�n (ManuSanRam)
 * @copyright   Infernal Coders S.A.
*************************************************************************************************************************************************************/

#include <HRUtility_Prerequisites.h>

/*!***********************************************************************************************************************************************************
 * SECTION #1: DLL EXPORTS.
 * This section contains any specific information for the Microsoft's Windows platform. The information is as follows:
 * - Dynamic Link Library Export macro.
*************************************************************************************************************************************************************/
#if HR_ACTIVE_PLATFORM == HR_PLATFORM_WINDOWS
  #if defined (HR_D3DGRAPHICSAPI_STATIC_LIBRARY)
    #define HR_D3DGRAPHICSAPI_EXPORT
  #else
    #if defined (HR_D3DGRAPHICSAPI_EXPORTS)
      #define HR_D3DGRAPHICSAPI_EXPORT __declspec(dllexport)
    #else
      #if defined (__MINGW32__)
        #define HR_D3DGRAPHICSAPI_EXPORT
      #else
        #define HR_D3DGRAPHICSAPI_EXPORT __declspec(dllimport)
      #endif
    #endif
  #endif
#endif

