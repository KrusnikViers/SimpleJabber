#pragma once

#include <QDir>

namespace base {

extern const unsigned int kProjectMajorVersion;
extern const unsigned int kProjectMinorVersion;
extern const unsigned int kProjectPatchVersion;
extern const char kProjectFullVersion[];
extern const char kProjectFullName[];

QDir dataDirectory();
extern const char kLogFileName[];

}  // namespace base
