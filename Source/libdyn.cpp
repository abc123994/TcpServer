#include "stdafx.h"
Q_IMPORT_PLUGIN(QWindowsIntegrationPlugin)
Q_IMPORT_PLUGIN(QODBCDriverPlugin)
#ifdef NDEBUG
#pragma comment(lib,"qtpcre2.lib")
#pragma comment(lib,"qtharfbuzz.lib")
#pragma comment(lib,"qtfreetype.lib")
#pragma comment(lib,"qtlibpng.lib")
#pragma comment(lib,"Qt5ThemeSupport.lib")

#pragma comment(lib,"Qt5WindowsUIAutomationSupport.lib")
#pragma comment(lib,"Qt5FontDatabaseSupport.lib")
#pragma comment(lib,"Qt5EventDispatcherSupport.lib")
#pragma comment(lib,"Qt5AccessibilitySupport.lib")
#pragma comment(lib,"qtmain.lib")
#pragma comment(lib,"Qt5Core.lib")
#pragma comment(lib,"Qt5Gui.lib")
#pragma comment(lib,"Qt5Widgets.lib")
#pragma comment(lib,"Qt5Network.lib")
#pragma comment(lib,"Qt5Sql.lib")
#pragma comment(lib,"../plugins/sqldrivers/qsqlodbc.lib")

#pragma comment(lib,"../plugins/platforms/qwindows.lib")


#else
#pragma comment(lib,"qtpcre2d.lib")
#pragma comment(lib,"qtharfbuzzd.lib")
#pragma comment(lib,"qtfreetyped.lib")
#pragma comment(lib,"qtlibpngd.lib")
#pragma comment(lib,"Qt5ThemeSupportd.lib")

#pragma comment(lib,"Qt5WindowsUIAutomationSupportd.lib")
#pragma comment(lib,"Qt5FontDatabaseSupportd.lib")
#pragma comment(lib,"Qt5EventDispatcherSupportd.lib")
#pragma comment(lib,"Qt5AccessibilitySupportd.lib")
#pragma comment(lib,"qtmaind.lib")
#pragma comment(lib,"Qt5Cored.lib")
#pragma comment(lib,"Qt5Guid.lib")
#pragma comment(lib,"Qt5Widgetsd.lib")
#pragma comment(lib,"Qt5Networkd.lib")
#pragma comment(lib,"Qt5Sqld.lib")
#pragma comment(lib,"../plugins/sqldrivers/qsqlodbcd.lib")

#pragma comment(lib,"../plugins/platforms/qwindowsd.lib")

#endif





// Windows System
#pragma comment(lib,"Ws2_32.lib")
#pragma comment(lib,"imm32.lib")
#pragma comment(lib,"winmm.lib")
#pragma comment(lib,"UxTheme.lib")
#pragma comment(lib,"Dwmapi.lib")
#pragma comment(lib,"version.lib")
#pragma comment(lib,"Netapi32.lib")
#pragma comment(lib, "wtsapi32.lib")
#pragma comment(lib,"Crypt32.lib")
#pragma comment(lib,"Iphlpapi.lib")
#pragma comment(lib, "userenv.lib")



