#include "base/project_info.h"

#include <QtCore>
#include <QSslSocket>


namespace base {

const unsigned int kProjectMajorVersion = 1;
const unsigned int kProjectMinorVersion = 0;
const unsigned int kProjectPatchVersion = 0;
const char kProjectFullVersion[] = "1.0.0";
const char kProjectFullName[] = "SimpleJabber";

bool sslSupported()
{
  return QSslSocket::supportsSsl();
}

QString sslVersion()
{
  return QSslSocket::sslLibraryVersionString() +
         QStringLiteral(" build ") + QSslSocket::sslLibraryBuildVersionString();
}

}  // namespace base
