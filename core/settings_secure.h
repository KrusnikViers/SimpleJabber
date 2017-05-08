#pragma once

#define QTKEYCHAIN_NO_EXPORT
#include "base/project_info.h"
#include "third_party/qtkeychain/keychain.h"


namespace core {
namespace settings {
namespace secure {

class ReadJob : public QKeychain::ReadPasswordJob
{
public:
    ReadJob(QObject* parent) : QKeychain::ReadPasswordJob(base::kProjectFullName, parent)
    {
        setAutoDelete(true);
        setInsecureFallback(true);
    }

private:
    QEventLoopLocker lock_;
};

class WriteJob : public QKeychain::WritePasswordJob
{
public:
    WriteJob(QObject* parent) : QKeychain::WritePasswordJob(base::kProjectFullName, parent)
    {
        setAutoDelete(true);
        setInsecureFallback(true);
    }

private:
    QEventLoopLocker lock_;
};

}  // namespace secure
}  // namespace settings
}  // namespace core
