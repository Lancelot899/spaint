##################
# UseVicon.cmake #
##################

OPTION(WITH_VICON "Build with Vicon support?" OFF)

IF(WITH_VICON)
  FIND_PATH(VICON_INCLUDE_DIR vicon/Client.h HINTS "${PROJECT_SOURCE_DIR}/libraries")
  FIND_LIBRARY(VICON_DATASTREAM_LIBRARY ViconDataStreamSDK_CPP HINTS "${PROJECT_SOURCE_DIR}/libraries/vicon")
  FIND_LIBRARY(VICON_DEBUGSERVICES_LIBRARY DebugServices HINTS "${PROJECT_SOURCE_DIR}/libraries/vicon")
  INCLUDE_DIRECTORIES(${VICON_INCLUDE_DIR})
ENDIF()
