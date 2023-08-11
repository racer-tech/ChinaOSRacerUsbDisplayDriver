set(RacerDisplay_SOURCES
  driver.cpp
  RacerDisplay.cpp
)
add_executable(RacerDisplay ${RacerDisplay_SOURCES})

find_library(LIBEV_LIBRARY NAMES ev)
find_path(LIBEV_INCLUDE_DIR ev++.h PATH_SUFFIXES include/ev include) # Find header
#find_package_handle_standard_args(libev DEFAULT_MSG LIBEV_LIBRARY LIBEV_INCLUDE_DIR)

find_library(LIBUSB_LIBRARY NAMES usb-1.0)
INCLUDE_DIRECTORIES(/usr/local/include/libusb-1.0)

find_library(LIBX11_LIBRARY NAMES X11)
find_library(LIBXext_LIBRARY NAMES Xext)
find_library(LIBXrandr_LIBRARY NAMES Xrandr)

target_include_directories(RacerDisplay PRIVATE
  ../
)
add_definitions(-DDEBUG) # because driver.cpp also include debug.hpp and driver is used in RacerDisplay


target_link_libraries(RacerDisplay
  evdipp
  libevdi
  libusbdisp
  ${LIBEV_LIBRARY}
  ${LIBUSB_LIBRARY}
  ${LIBX11_LIBRARY}
  ${LIBXext_LIBRARY}
  ${LIBXrandr_LIBRARY}
)

install(TARGETS RacerDisplay
  RUNTIME DESTINATION bin
)
