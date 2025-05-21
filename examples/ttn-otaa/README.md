When using the ttn-otaa, you need to 

1) set the board type in ```#define BOARD ESP_S3```

2) set the frequency (433, 868, etc) in /project_config/lmic_project_config.h file

3) if changed the appkeys and devkeys, or made custom wiring for the boards, change that as well as normal