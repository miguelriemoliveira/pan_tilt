cmake_minimum_required(VERSION 2.8.3)
project(libpan_tilt)

find_package(catkin 
  REQUIRED COMPONENTS 
  actionlib
  actionlib_msgs
  std_msgs 
  genmsg 
  message_generation 
  roscpp 
  rospy 
)

find_package(Boost REQUIRED COMPONENTS system)

set(rnr_DIR /prj/lib/rnr)
find_package(rnr)

#message(STATUS, "${rnr_LIBRARIES}")

catkin_package(
  CATKIN_DEPENDS actionlib_msgs
)

include_directories(
  include 
  ../include
  ${rnr_INCLUDE_DIRS}
  ${catkin_INCLUDE_DIRS}
  ${Boost_INCLUDE_DIRS}
)

add_library(pan_tilt
  src/ptCalib.cxx
  src/ptDesc.cxx
  src/ptJoint.cxx
  src/ptProdAX.cxx
  src/ptProdMX.cxx
  src/ptRobot.cxx
  src/ptSpec.cxx
  src/ptStatus.cxx
  src/ptUtils.cxx
)

target_link_libraries(pan_tilt 
  ${rnr_LIBRARIES}
)

install(TARGETS pan_tilt
  ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
)

install(DIRECTORY ../include/
  DESTINATION ${CATKIN_GLOBAL_INCLUDE_DESTINATION}
  FILES_MATCHING PATTERN "*.h" PATTERN "*.hpp"
  PATTERN ".svn" EXCLUDE
)