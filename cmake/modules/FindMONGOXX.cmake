
# - Find MongoDB++
# Find the MongoDB++ includes and client library
# This module defines
#  MONGOXX_INCLUDE_DIR, where to find client/dbclient.h
#  MONGOXX_LIBRARIES, the libraries needed to use MongoDB++.
#  MONGOXX_FOUND, If false, do not try to use MongoDB++.
#
# Copyright (c) 2011, Philipp Fehre, <philipp.fehre@googlemail.com>
#
# Redistribution and use is allowed according to the terms of the BSD license.
# For details see the accompanying COPYING-CMAKE-SCRIPTS file.

# Add the MongoDB++ include paths here

if(MONGOXX_INCLUDE_DIR AND MONGOXX_LIBRARIES)
   set(MONGOXX_FOUND TRUE)

else(MONGOXX_INCLUDE_DIR AND MONGOXX_LIBRARIES)

        find_path(MONGOXX_INCLUDE_DIR mongo/client/dbclient.h
          /usr/include
          /usr/local/include
          /opt/local/include
    )

  find_library(MONGOXX_LIBRARIES NAMES mongoclient  libmongoclient
    PATHS
    /usr/lib
    /usr/local/lib
    /opt/local/lib
    )

  if(MONGOXX_INCLUDE_DIR AND MONGOXX_LIBRARIES)
    set(MONGOXX_FOUND TRUE)
    message(STATUS "Found MONGODB++: ${MONGOXX_INCLUDE_DIR}, ${MONGOXX_LIBRARIES}")
    INCLUDE_DIRECTORIES(${MONGOXX_INCLUDE_DIR})
  else(MONGOXX_INCLUDE_DIR AND MONGOXX_LIBRARIES)
    set(MONGOXX_FOUND FALSE)
    message(STATUS "MONGODB++ not found.")
  endif(MONGOXX_INCLUDE_DIR AND MONGOXX_LIBRARIES)
  
mark_as_advanced(MONGOXX_INCLUDE_DIR MONGOXX_LIBRARIES)
  mark_as_advanced(MONGOXX_VERSION_CHECK)

endif(MONGOXX_INCLUDE_DIR AND MONGOXX_LIBRARIES)

if (MONGOXX_FOUND)
  find_path(MONGOXX_VERSION_CHECK util/net/hostandport.h
        /usr/include/mongo/
        /usr/local/include/mongo/
        /opt/local/include/mongo)

  if (MONGOXX_VERSION_CHECK)
     set (MONGOXX_VERSION_2 TRUE)
  endif(MONGOXX_VERSION_CHECK)
endif (MONGOXX_FOUND)

