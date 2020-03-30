#ifndef AUDIOVIDEOCORE_GLOBAL_H
#define AUDIOVIDEOCORE_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(AUDIOVIDEOCORE_LIBRARY)
#  define AUDIOVIDEOCORESHARED_EXPORT Q_DECL_EXPORT
#else
#  define AUDIOVIDEOCORESHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // AUDIOVIDEOCORE_GLOBAL_H
