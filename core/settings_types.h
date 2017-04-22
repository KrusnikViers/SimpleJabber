#pragma once

#include <QtCore>


namespace core {
namespace settings {

enum class Logging : int {
    File,
    Stdout,
    None
};

}  // namespace settings
}  // namespace core
