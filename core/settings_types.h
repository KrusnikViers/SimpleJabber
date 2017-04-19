#pragma once

#include <QtCore>

namespace core {
namespace settings {

enum class Logging {
    ExternalWindow,
    File,
    Stdout,
    None
};

}  // namespace settings
}  // namespace core

Q_DECLARE_METATYPE(core::settings::Logging)
