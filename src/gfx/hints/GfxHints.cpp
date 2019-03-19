		/*
 Giotto
 Copyright (C) 2019 George Oros
 
 This software is provided 'as-is', without any express or implied
 warranty.  In no event will the authors be held liable for any damages
 arising from the use of this software.
 
 Permission is granted to anyone to use this software for any purpose,
 including commercial applications, and to alter it and redistribute it
 freely, subject to the following restrictions:
 
 1. The origin of this software must not be misrepresented; you must not
 claim that you wrote the original software. If you use this software
 in a product, an acknowledgment in the product documentation would be
 appreciated but is not required.
 2. Altered source versions must be plainly marked as such, and must not be
 misrepresented as being the original software.
 3. This notice may not be removed or altered from any source distribution.
 
 See copyright notice at http://lidsdl.org/license.php
*/

#include <cassert>
#include <string>
#include <map>
#include <utility>
#include <vector>

#include "GfxHints.hpp"
#include "GfxBasicLogger.hpp"

LOG_TRACE_MODULE_NAME("gfxhints::hints::gfx");

namespace gfx
{

namespace hints
{

const char GfxHints::ClassName[] = "GfxHints";

const std::vector<std::pair<GfxHints::ValueType, const char *>> GfxHints::hintsMap_ =
{
    { /*  1 */ GfxHints::ValueType::hintFramebufferAcceleration, SDL_HINT_FRAMEBUFFER_ACCELERATION },
    { /*  2 */ GfxHints::ValueType::hintRenderDriver, SDL_HINT_RENDER_DRIVER },
    { /*  3 */ GfxHints::ValueType::hintRenderOpenGLShaders, SDL_HINT_RENDER_OPENGL_SHADERS },
    { /*  4 */ GfxHints::ValueType::hintRenderDirect3DThreadSafe, SDL_HINT_RENDER_DIRECT3D_THREADSAFE },
    { /*  5 */ GfxHints::ValueType::hintRenderDirect3D11Debug, SDL_HINT_RENDER_DIRECT3D11_DEBUG },
    { /*  6 */ GfxHints::ValueType::hintRenderLogicalSizeMode, SDL_HINT_RENDER_LOGICAL_SIZE_MODE },
    { /*  7 */ GfxHints::ValueType::hintRenderScaleQuality, SDL_HINT_RENDER_SCALE_QUALITY },
    { /*  8 */ GfxHints::ValueType::hintRenderVSync, SDL_HINT_RENDER_VSYNC },
    { /*  9 */ GfxHints::ValueType::hintVideoAllowScreensaver, SDL_HINT_VIDEO_ALLOW_SCREENSAVER },
    { /* 10 */ GfxHints::ValueType::hintVideoX11XVidMode, SDL_HINT_VIDEO_X11_XVIDMODE },
    { /* 11 */ GfxHints::ValueType::hintVideoX11Xinerama, SDL_HINT_VIDEO_X11_XINERAMA },
    { /* 12 */ GfxHints::ValueType::hintVideoX11XRandr, SDL_HINT_VIDEO_X11_XRANDR },
    { /* 13 */ GfxHints::ValueType::hintVideoX11NetWmPing, SDL_HINT_VIDEO_X11_NET_WM_PING },
    { /* 14 */ GfxHints::ValueType::hintVideoX11NetWmBypassCompositor, SDL_HINT_VIDEO_X11_NET_WM_BYPASS_COMPOSITOR }, // NOLINT
    { /* 15 */ GfxHints::ValueType::hintWindowFrameUsableWhileCursorHidden, SDL_HINT_WINDOW_FRAME_USABLE_WHILE_CURSOR_HIDDEN }, // NOLINT
    { /* 16 */ GfxHints::ValueType::hintWindowsEnableMessageloop, SDL_HINT_WINDOWS_ENABLE_MESSAGELOOP },
    { /* 17 */ GfxHints::ValueType::hintGrabKeyboard, SDL_HINT_GRAB_KEYBOARD },
    { /* 18 */ GfxHints::ValueType::hintMouseNormalSpeedScale, SDL_HINT_MOUSE_NORMAL_SPEED_SCALE },
    { /* 19 */ GfxHints::ValueType::hintMouseRelativeSpeedScale, SDL_HINT_MOUSE_RELATIVE_SPEED_SCALE },
    { /* 20 */ GfxHints::ValueType::hintMouseRelativeModeWrap, SDL_HINT_MOUSE_RELATIVE_MODE_WARP },
    { /* 21 */ GfxHints::ValueType::hintMouseFocusClickthrough, SDL_HINT_MOUSE_FOCUS_CLICKTHROUGH },
    { /* 22 */ GfxHints::ValueType::hintVideoMinimizeOnFocusLoss, SDL_HINT_VIDEO_MINIMIZE_ON_FOCUS_LOSS },
    { /* 23 */ GfxHints::ValueType::hintIdleTimerDisabled, SDL_HINT_IDLE_TIMER_DISABLED },
    { /* 24 */ GfxHints::ValueType::hintOrientations, SDL_HINT_ORIENTATIONS },
    { /* 25 */ GfxHints::ValueType::hintAppleTVControllerUIEvents, SDL_HINT_APPLE_TV_CONTROLLER_UI_EVENTS },
    { /* 26 */ GfxHints::ValueType::hintAppleTVRemoteAllowRotation, SDL_HINT_APPLE_TV_REMOTE_ALLOW_ROTATION },
    { /* 27 */ GfxHints::ValueType::hintiOSHideHomeIndicator, SDL_HINT_IOS_HIDE_HOME_INDICATOR},
    { /* 28 */ GfxHints::ValueType::hintAccelerometerAsJoystick, SDL_HINT_ACCELEROMETER_AS_JOYSTICK },
    { /* 29 */ GfxHints::ValueType::hintTvRemoteAsJoystick, SDL_HINT_TV_REMOTE_AS_JOYSTICK },
    { /* 30 */ GfxHints::ValueType::hintXInputEnabled, SDL_HINT_XINPUT_ENABLED },
    { /* 31 */ GfxHints::ValueType::hintXInputUseOldJoystickMapping, SDL_HINT_XINPUT_USE_OLD_JOYSTICK_MAPPING },
    { /* 32 */ GfxHints::ValueType::hintGamecontrollerconfig, SDL_HINT_GAMECONTROLLERCONFIG },
    { /* 33 */ GfxHints::ValueType::hintJoystickAllowBackgroundEvents, SDL_HINT_JOYSTICK_ALLOW_BACKGROUND_EVENTS },
    { /* 34 */ GfxHints::ValueType::hintAllowTopmost, SDL_HINT_ALLOW_TOPMOST },
    { /* 35 */ GfxHints::ValueType::hintTimerResolution, SDL_HINT_TIMER_RESOLUTION },
    { /* 36 */ GfxHints::ValueType::hintQTWaylandContentOrientation, SDL_HINT_QTWAYLAND_CONTENT_ORIENTATION },
    { /* 37 */ GfxHints::ValueType::hintQTWaylandWindowFlags, SDL_HINT_QTWAYLAND_WINDOW_FLAGS },
    { /* 38 */ GfxHints::ValueType::hintThreadStackSize, SDL_HINT_THREAD_STACK_SIZE },
    { /* 39 */ GfxHints::ValueType::hintVideoHighDPIDisabled, SDL_HINT_VIDEO_HIGHDPI_DISABLED },
    { /* 40 */ GfxHints::ValueType::hintMacCtrlClickEmulateRightClick, SDL_HINT_MAC_CTRL_CLICK_EMULATE_RIGHT_CLICK },
    { /* 41 */ GfxHints::ValueType::hintVideoWinD3DCompiler, SDL_HINT_VIDEO_WIN_D3DCOMPILER },
    { /* 42 */ GfxHints::ValueType::hintVideoWindowSharePixelFormat, SDL_HINT_VIDEO_WINDOW_SHARE_PIXEL_FORMAT },
    { /* 43 */ GfxHints::ValueType::hintWinRTPrivacyPolicyURL , SDL_HINT_WINRT_PRIVACY_POLICY_URL },
    { /* 44 */ GfxHints::ValueType::hintWinRTPrivacyPolicyLabel, SDL_HINT_WINRT_PRIVACY_POLICY_LABEL },
    { /* 45 */ GfxHints::ValueType::hintWinRTHandleBackButton, SDL_HINT_WINRT_HANDLE_BACK_BUTTON },
    { /* 46 */ GfxHints::ValueType::hintVideoMacFullscreenSpaces, SDL_HINT_VIDEO_MAC_FULLSCREEN_SPACES },
    { /* 47 */ GfxHints::ValueType::hintMacBackgroundApp, SDL_HINT_MAC_BACKGROUND_APP },
    { /* 48 */ GfxHints::ValueType::hintAndroidApkExpansionMainFileVersion, SDL_HINT_ANDROID_APK_EXPANSION_MAIN_FILE_VERSION }, // NOLINT
    { /* 49 */ GfxHints::ValueType::hintAndroidApkExpansionPatchFileVersion, SDL_HINT_ANDROID_APK_EXPANSION_PATCH_FILE_VERSION }, // NOLINT
    { /* 50 */ GfxHints::ValueType::hintIMEInternalEditing, SDL_HINT_IME_INTERNAL_EDITING },
    { /* 51 */ GfxHints::ValueType::hintAndroidSeparateMouseAndTouch, SDL_HINT_ANDROID_SEPARATE_MOUSE_AND_TOUCH },
    { /* 52 */ GfxHints::ValueType::hintReturnKeyHidesIme, SDL_HINT_RETURN_KEY_HIDES_IME },
    { /* 53 */ GfxHints::ValueType::hintEmScriptenKeyboardElement, SDL_HINT_EMSCRIPTEN_KEYBOARD_ELEMENT },
    { /* 54 */ GfxHints::ValueType::hintNoSignalHandlers, SDL_HINT_NO_SIGNAL_HANDLERS },
    { /* 55 */ GfxHints::ValueType::hintWindowsNoCloseOnAltF4, SDL_HINT_WINDOWS_NO_CLOSE_ON_ALT_F4 },
    { /* 56 */ GfxHints::ValueType::hintBmpSaveLegacyFormat, SDL_HINT_BMP_SAVE_LEGACY_FORMAT },
    { /* 57 */ GfxHints::ValueType::hintWindowsDisableThreadNaming, SDL_HINT_WINDOWS_DISABLE_THREAD_NAMING },
    { /* 58 */ GfxHints::ValueType::hintRPIVideoLayer, SDL_HINT_RPI_VIDEO_LAYER },
    { /* 59 */ GfxHints::ValueType::hintVideoDoubleBuffer, SDL_HINT_VIDEO_DOUBLE_BUFFER},
    { /* 60 */ GfxHints::ValueType::hintOpenGLESVideoDriver, SDL_HINT_OPENGL_ES_DRIVER },
    { /* 61 */ GfxHints::ValueType::hintAudioResamplingMode, SDL_HINT_AUDIO_RESAMPLING_MODE },
    { /* 62 */ GfxHints::ValueType::hintWindowIntResourceIcon, SDL_HINT_WINDOWS_INTRESOURCE_ICON },
    { /* 63 */ GfxHints::ValueType::hintWindowIntResourceIconSmall, SDL_HINT_WINDOWS_INTRESOURCE_ICON_SMALL },
    { /* 64 */ GfxHints::ValueType::hintTouchMouseEvents, SDL_HINT_TOUCH_MOUSE_EVENTS },
    { /* 65 */ GfxHints::ValueType::hintGameControllerIgnoreDevices, SDL_HINT_GAMECONTROLLER_IGNORE_DEVICES },
    { /* 66 */ GfxHints::ValueType::hintGameControllerIgnoreDevicesExcept, SDL_HINT_GAMECONTROLLER_IGNORE_DEVICES_EXCEPT }  // NOLINT
};

GfxHints::GfxHints() noexcept : GfxObject(ClassName)
{
    LOG_TRACE_PRIO_MED();

    callbackMap_.clear();
}

GfxHints::GfxHints(GfxHints&& other) noexcept : GfxObject(std::move(other))
{
    LOG_TRACE_PRIO_MED();

    callbackMap_ = other.callbackMap_;
    // Delete other's data
    other.callbackMap_.clear();
}

GfxHints& GfxHints::operator=(GfxHints&& other) noexcept
{
    LOG_TRACE_PRIO_MED();

    if (this != &other)
    {
        // Move base
        GfxObject::operator=(std::move(other));
        // Move this
        callbackMap_ = other.callbackMap_;
        // Delete other's data
        other.callbackMap_.clear();
    }
    return *this;
}

GfxHints::operator bool() const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return true;
}

std::string GfxHints::to_string(void) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return std::string(ClassName);
}

const GfxBool GfxHints::setHintWithPriority(const std::string& name, const std::string& value,
                                      const GfxHintPriority& prio) const noexcept
{
    LOG_TRACE_PRIO_MED();

    assert(name.length() > 0);
    assert(value.length() > 0);
    assert(prio);

    GfxBool::SdlType sdlbool;

    sdlbool = SDL_SetHintWithPriority(name.c_str(), value.c_str(), prio.getAsSdlType());
    return GfxBool(sdlbool);
}

const GfxBool GfxHints::setHint(const std::string& name, const std::string& value) const noexcept
{
    LOG_TRACE_PRIO_MED();

    assert(name.length() > 0);
    assert(value.length() > 0);

    GfxBool::SdlType sdlbool;

    sdlbool = SDL_SetHint(name.c_str(), value.c_str());
    return GfxBool(sdlbool);
}

const std::string GfxHints::getHint(const std::string& name) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(name.length() > 0);

    const char * ret;

    ret = SDL_GetHint(name.c_str());
    if (ret != NULL)
    {
        return std::string(ret);
    }
    return "";
}

const GfxBool GfxHints::getHintBoolean(const std::string& name, const GfxBool& defvalue) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    assert(name.length() > 0);
    assert(defvalue);

    GfxBool::SdlType sdlbool;

    sdlbool = SDL_GetHintBoolean(name.c_str(), defvalue.getAsSdlType());
    return GfxBool(sdlbool);
}

void GfxHints::addHintCallback(const std::string& name, const GfxHintCallback& callback) noexcept
{
    LOG_TRACE_PRIO_HIGH();

    assert(name.length() > 0);
    assert(callback);

    void * userdata = static_cast<void *>(this);

    callbackMap_[name] = const_cast<GfxHintCallback *>(&callback);
    SDL_AddHintCallback(name.c_str(), hintCallbackFunction, userdata);
}

void GfxHints::delHintCallback(const std::string& name, const GfxHintCallback& callback) throw(std::runtime_error)
{
    LOG_TRACE_PRIO_HIGH();

    assert(name.length() > 0);
    assert(callback);

    void * userdata = static_cast<void *>(this);
    GfxHintCallback * params;
    GfxHintCallback * inmap;

    params = const_cast<GfxHintCallback *>(&callback);
    if (callbackMap_.size() > 0)
    {
        auto pos = callbackMap_.find(name);
        if (pos != callbackMap_.end())
        {
            inmap = callbackMap_[name];
            if (params == inmap)
            {
                callbackMap_.erase(pos);
                SDL_DelHintCallback(name.c_str(), hintCallbackFunction, userdata);
            }
            else
            {
                throw std::runtime_error("Callback and userdata do not match");
            }
        }
        else
        {
            throw std::runtime_error("Callback not found");
        }
    }
    else
    {
        throw std::runtime_error("No callback set");
    }
}

const GfxBool GfxHints::setHintWithPriority(const ValueType hint, const std::string& value,
                                      const GfxHintPriority& prio) const noexcept
{
    LOG_TRACE_PRIO_MED();

    return setHintWithPriority(getHintNameByValue(hint), value, prio);
}

const GfxBool GfxHints::setHint(const ValueType hint, const std::string& value) const noexcept
{
    LOG_TRACE_PRIO_MED();

    return setHint(getHintNameByValue(hint), value);
}

const std::string GfxHints::getHint(const ValueType hint) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return getHint(getHintNameByValue(hint));
}

const GfxBool GfxHints::getHintBoolean(const ValueType hint, const GfxBool& defvalue) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    return getHintBoolean(getHintNameByValue(hint), defvalue);
}

void GfxHints::addHintCallback(const ValueType hint, const GfxHintCallback& callback) noexcept
{
    LOG_TRACE_PRIO_HIGH();

    addHintCallback(getHintNameByValue(hint), callback);
}

void GfxHints::delHintCallback(const ValueType hint, const GfxHintCallback& callback) throw(std::runtime_error)
{
    LOG_TRACE_PRIO_HIGH();

    delHintCallback(getHintNameByValue(hint), callback);
}

void GfxHints::clearHints(void) const noexcept
{
    LOG_TRACE_PRIO_MED();

    SDL_ClearHints();
}

// Private methods
const std::string GfxHints::getHintNameByValue(const ValueType value) const noexcept
{
    LOG_TRACE_PRIO_LOW();

    const char * chptr = nullptr;

    // std::pair<GfxHints::ValueType, const char *>
    for (const auto& it : hintsMap_)
    {
        if (it.first == value)
        {
            chptr = it.second;
        }
    }
    if (chptr != nullptr)
    {
        return std::string(chptr);
    }
    return std::string("");
}

void GfxHints::hintCallbackFunction(void * userdata, const char * name, const char * oldv, const char * newv)
{
    GfxHintCallback * inmap;
    GfxHints * thisptr = static_cast<GfxHints *>(userdata);

    if (thisptr != nullptr)
    {
        if (thisptr->callbackMap_.size() > 0)
        {
            auto pos = thisptr->callbackMap_.find(std::string(name));
            if (pos != thisptr->callbackMap_.end())
            {
                inmap = thisptr->callbackMap_.operator[](std::string(name));
                (*inmap)(std::string(name), std::string(oldv), std::string(newv));
            }
        }
    }
}

}  // namespace hints

}  // namespace gfx

/* EOF */
