#include "base/version.h"


#define xstr(v) str(v)
#define str(v) #v

namespace base {

const unsigned int kProjectMajorVersion = VER_MAJOR;
const unsigned int kProjectMinorVersion = VER_MINOR;
const unsigned int kProjectPatchVersion = VER_PATCH;
const char kProjectFullVersion[] = xstr(VER_FULL);

} // namespace base
