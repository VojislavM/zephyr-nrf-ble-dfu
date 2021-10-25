# zephyr-nrf-ble-dfu
The easiest way to add BLE DFU (Device Firmware Upgrade) to your nRF5x Zephyr application.

## Setup

To include DFU over BLE to your Zephyr project based on the nRF Connect SDK (NCS) for one of the BLE capable Nordic Semi SoCs you need to add a source from this repository to your application. To be able to run BLE DFU the application you are writing needs to have BLE already enabled, usually in `prj.conf` with `CONFIG_BT` and probably with some additional configurations. 
Steps to run:
* from `prj.conf` within this repository copy everything and add to your application `prj.conf` or to board-specific configuration within the project
* from `CMakeLists.txt` within this repository copy everything and add at the end of your application `CMakeLists.txt`
* Copy the file `init_dfu.c` from the `boards` folder within this repository to the `boards` folder in your application. If there is no boards folder in your application copy the whole `boards` folder.

After this build your project `west -b your_board -p` and flash the device `west flash`. After building in the `build/zephyr` folder you should see `app_update.bin` which is an image of your build that needs to be sent over BLE DFU (for more information about image files see the [link](https://developer.nordicsemi.com/nRF_Connect_SDK/doc/latest/mcuboot/readme-ncs.html)). Use one of the mobile applications that support SMP protocol for uploading the DFU image, like [nRF Connect](https://play.google.com/store/apps/details?id=no.nordicsemi.android.mcp&hl=en&gl=US) or [Device Manager](https://play.google.com/store/apps/details?id=no.nordicsemi.android.nrfconnectdevicemanager&hl=en&gl=US) from Nordic Semi or simply use `mcumgr` [CLI interface](https://docs.zephyrproject.org/latest/guides/device_mgmt/mcumgr.html) for uploading the new image.

## Testing

To test this setup you can use one of the NCS examples that utilize some BLE-connected device. For example `ncs/nrf/samples/bluetooth/...`