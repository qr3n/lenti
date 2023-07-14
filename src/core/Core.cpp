#include "Core.h"
#include "config.h"
#include "service/output/Output.h"
#include "service/filesystem/Filesystem.h"
#include "service/config/Config.h"


void Core::main() {
    Output::clear();
    Output::info(L"Lenti loaded.");
    Output::log(L"Trying to load config file...");

    auto file = Filesystem::readTextFile(CONFIG_NAME);

    if (file == nullptr) {
        Output::error(L"Config not found!");

        return;
    }

    Output::success(L"Config was loaded.");
}