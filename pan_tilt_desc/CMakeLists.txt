cmake_minimum_required(VERSION 2.8.3)
project(pan_tilt_desc)

catkin_package()

install(DIRECTORY urdf DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION})
install(DIRECTORY stl DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION})
