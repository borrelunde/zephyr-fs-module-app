# Zephyr File System Module Application

A simple application that uses the [file system module (fs-module)](https://github.com/borrelunde/zephyr-fs-module).

# Building

Build using the nrf52840dk_nrf52840 configuration and overlay. This uses the internal flash.

You don't need to specify the configuration and overlay file because they match the board name.

```
west build -p -b nrf52840dk_nrf52840 app
```

But if you really want to, this is how.

```
west build -p -b nrf52840dk_nrf52840 app -- -DEXTRA_CONF_FILE=boards\nrf52840dk_nrf52840.conf -DDTC_OVERLAY_FILE=boards\nrf52840dk_nrf52840.overlay
```

Build using the nrf52840dk_nrf52840_qspi configuration and overlay. This uses the external flash.

```
west build -p -b nrf52840dk_nrf52840 app -- -DEXTRA_CONF_FILE=boards\nrf52840dk_nrf52840_qspi.conf -DDTC_OVERLAY_FILE=boards\nrf52840dk_nrf52840_qspi.overlay
```

When you've built once, you can build using what's in the cache. It remembers the CMake commands from the previous build.

```
west build
```

# Flashing

```
west flash
```