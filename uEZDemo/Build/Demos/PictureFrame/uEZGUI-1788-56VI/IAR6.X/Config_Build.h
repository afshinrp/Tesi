#define BUILD_NUMBER        2
#define BUILD_DATE          "5/31/2012"

#define COMPILER_TYPE       IAR
#define UEZ_PROCESSOR       NXP_LPC1788


#define UEZ_DEFAULT_LCD_CONFIG              LCD_CONFIG_INTELTRONIC_LMIX0560NTN53V1

// Modify the default accelerometer demo settings
#define ACCEL_DEMO_SWAP_XY        0
#define ACCEL_DEMO_FLIP_X         0
#define ACCEL_DEMO_ALLOW_ROTATE   0

#define PROCESSOR_OSCILLATOR_FREQUENCY      120000000

#define UEZ_ENABLE_WATCHDOG       0 // Turn on watchdog for testing

//#define UEZ_ICONS_SET       ICONS_SET_UEZ_OPEN_SOURCE
//#define UEZ_ICONS_SET       ICONS_SET_PROFESSIONAL_ICONS
#define UEZ_ICONS_SET ICONS_SET_PROFESSIONAL_ICONS_LARGE
#define SIMPLEUI_DOUBLE_SIZED_ICONS 0 // 1 to 1 icons

#define UEZ_USE_EXTERNAL_EEPROM   0
#define USB_PORT_B_HOST_DETECT_ENABLED        0

#define INCLUDE_EMWIN               1
#define APP_DEMO_EMWIN              INCLUDE_EMWIN
#define APP_DEMO_YOUR_APP           1
#define APP_DEMO_COM                1
#define APP_DEMO_DRAW               1
#define APP_DEMO_APPS               1
#define UEZ_ENABLE_TCPIP_STACK      1
#define UEZ_ENABLE_USB_HOST_STACK   1

#define UEZ_ENABLE_WIRED_NETWORK   1

#define UEZ_SLIDESHOW_NAME        "uEZGUI-1788-56VI"

#define SLIDESHOW_PREFETCH_AHEAD 5
#define SLIDESHOW_PREFETCH_BEHIND 1
#define SLIDESHOW_NUM_CACHED_SLIDES 5