# Preinitialization related to DFU
# Instead of CONFIG_BOARD_YOU_ARE_USING set board you are building with
# for example: CONFIG_BOARD_NRF52840DK_NRF52840
target_sources_ifdef(CONFIG_BOARD_YOU_ARE_USING app PRIVATE
  boards/init_dfu.c
)
