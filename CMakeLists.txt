cmake_minimum_required(VERSION 3.25)
project(lenti)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_CXX_FLAGS "-target x86_64-unknown-windows -ffreestanding -fshort-wchar -mno-red-zone")
set(CMAKE_EXE_LINKER_FLAGS "-target x86_64-unknown-windows -nostdlib -Wl,-entry:entry -Wl,-subsystem:efi_application -fuse-ld=lld-link")

include_directories(src)

add_executable(
        lenti
        src/entry.cpp
        src/shared/uefi.cpp
        src/core/Core.cpp
        src/core/Core.h
        src/service/output/Output.cpp
        src/service/output/Output.h
        src/service/filesystem/Filesystem.cpp
        src/service/filesystem/Filesystem.h
        src/service/config/Config.cpp
        src/service/config/Config.h
)

target_link_libraries(lenti ${CMAKE_CURRENT_SOURCE_DIR}/lib/data.o)