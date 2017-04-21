#pragma once

#include <QtCore>


namespace core {
namespace settings {

enum class Logging {
    File,
    Stdout,
    None
};

}  // namespace settings
}  // namespace core

Q_DECLARE_METATYPE(core::settings::Logging)
