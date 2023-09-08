#include <zephyr/drivers/flash.h>
#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>

LOG_MODULE_REGISTER(main);

#if CONFIG_FS_MODULE

#include <fs-module/FileSystem.hpp>
#include <fs-module/FileSystemFormatException.hpp>
#include <fs-module/FileSystemMountException.hpp>
#include <fs-module/FileSystemUnmountException.hpp>
#include <fs-module/fat/FatFileSystem.hpp>

#define FORMAT_FS 0

const std::string FS_MNTP = "/SD:";

int main() {
    // Instance of file system.
    std::unique_ptr<FileSystem> file_system = std::make_unique<FatFileSystem>();

#if FORMAT_FS

    // Format file system volume.
    try {
        file_system->format();
        LOG_INF("%s", "Formatted file system volume.");
    } catch (const FileSystemFormatException &e) {
        LOG_ERR("Failed to format file system volume: %s", e.what());
    }

#endif

    // Mount file system.
    try {
        file_system->mount(FS_MNTP);
        LOG_INF("%s", "Mounted file system.");
    } catch (const FileSystemMountException &e) {
        LOG_ERR("Failed to mount file system: %s", e.what());
    }

    // Unmount file system.
    try {
        file_system->unmount();
        LOG_INF("%s", "Unmounted file system.");
    } catch (const FileSystemUnmountException &e) {
        LOG_ERR("Failed to unmount file system: %s", e.what());
    }

    return 0;
}

#else

int main() {
    LOG_WRN("File system module is not enabled.");
    return 0;
}

#endif