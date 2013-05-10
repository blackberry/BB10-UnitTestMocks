/*
   Copyright 2013 Research In Motion Limited

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/
#ifndef BB_CASCADES_MULTIMEDIA_CAMERATYPES_HPP
#define BB_CASCADES_MULTIMEDIA_CAMERATYPES_HPP
#include "gtest/gtest.h"
#include <bb/Global>
#include <QtDeclarative>
namespace bb
{
namespace cascades
{
namespace multimedia
{
class QT_CASCADES_EXPORT BB_DLL_PUBLIC CameraUnit
{
public:
    enum Type
    {
        None  = 0,    
        Front = 1,    
        Rear  = 2,    
    };
class QT_CASCADES_EXPORT BB_DLL_PUBLIC CameraMode
public:
    enum Type
    {
        Photo         = 0,    
        Video         = 1,    
    };
class QT_CASCADES_EXPORT BB_DLL_PUBLIC CameraFocusMode
public:
    enum Type
    {
        Off             = 0,    
        Manual          = 1,
        Auto            = 2,
        Macro           = 3,
        ContinuousAuto  = 4,
        ContinuousMacro = 5
    };
class QT_CASCADES_EXPORT BB_DLL_PUBLIC CameraFlashMode
public:
    enum Type
    {
        Off   = 0,    
        On    = 1,    
        Auto  = 2,    
        Light = 3     
    };
class QT_CASCADES_EXPORT BB_DLL_PUBLIC CameraSceneMode
public:
    enum Type
    {
        Auto         = 0,
        Action       = 1,
        Whiteboard   = 2,
        Night        = 3,
        BeachAndSnow = 4
    };
class QT_CASCADES_EXPORT BB_DLL_PUBLIC CameraShootingMode
public:
    enum Type
    {
        Normal          = 0,    
        Stabilization   = 1,    
    };
class QT_CASCADES_EXPORT BB_DLL_PUBLIC CameraFocusState
public:
    enum Type
    {
        None      = 0,
        Waiting   = 1,
        Searching = 2,
        Failed    = 3,
        Locked    = 4
    };
class QT_CASCADES_EXPORT BB_DLL_PUBLIC CameraError
public:
    enum Type
    {
        General            = 0,    
        BadPointer         = 1,    
        APIFailure         = 2,    
        InvalidArgument    = 3,    
        InvalidState       = 4,    
        RecordingSpaceFull = 5,    
        CameraInUse        = 6,    
        MicInUse           = 7     
    };
};
}
}
}
#endif 
