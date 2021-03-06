

PROJECT(gf)
CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

SET (VERSION_MAJOR "0")
SET (VERSION_MINOR "1")
SET (VERSION_PATCH "0")
SET (VERSION ${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH})

SET(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/modules")


include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X)
if(COMPILER_SUPPORTS_CXX11)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
elseif(COMPILER_SUPPORTS_CXX0X)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
else()
        message(STATUS "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support. Please use a different C++ compiler.")
endif()

#<< stores
find_package(MONGOXX)
set(MONGOSTORE '')
if(MONGOXX_FOUND)
    set(MONGOSTORE mongo_store)
endif()

set(STORES ${MONGOSTORE})
set(STORES_LIBRARIES ${MONGOXX_LIBRARIES})
ADD_SUBDIRECTORY(src/stores)
#>> stores

#<< idioms
set(TESTIDIOM test_idiom)


set(IDIOMS ${TESTIDIOM})
set(IDIOMS_LIBRARIES )
ADD_SUBDIRECTORY(src/idioms)
#>> idioms


# SET(Boost_USE_STATIC_LIBS        ON)
# SET(Boost_USE_MULTITHREADED      ON)
# SET(Boost_USE_STATIC_RUNTIME    OFF)


FIND_PACKAGE(Boost REQUIRED COMPONENTS graph system timer)


ADD_SUBDIRECTORY(src)

SET(CPACK_PACKAGE_DESCRIPTION_SUMMARY "A Graph Frontend")
SET(CPACK_PACKAGE_VENDOR "Pierre Marchand (Open Source Publishing), made.in")
SET(CPACK_PACKAGE_DESCRIPTION_FILE "${CMAKE_CURRENT_SOURCE_DIR}/INSTALL")
SET(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/LICENSE")

SET(CPACK_PACKAGE_VERSION_MAJOR ${VERSION_MAJOR})
SET(CPACK_PACKAGE_VERSION_MINOR ${VERSION_MINOR})
SET(CPACK_PACKAGE_VERSION_PATCH ${VERSION_PATCH})
SET(CPACK_PACKAGE_EXECUTABLES "gf")

INCLUDE(CPack)

