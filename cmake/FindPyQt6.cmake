#[[
FindPyQt6
-------

Result Variables
^^^^^^^^^^^^^^^^

This will define the following variables:

``PyQt6_FOUND``
  True if the system has PyQt6 sip files.
``PyQt6_INCLUDE_DIRS``
  The directory containing PyQt6 sip files.

Cache Variables
^^^^^^^^^^^^^^^

The following cache variables may also be set:

``PyQt6_INCLUDE_DIR``
  The directory containing PyQt6 sip files.
]]

execute_process(
  COMMAND ${Python_EXECUTABLE} -c "import sys; print(sys.prefix)"
  OUTPUT_VARIABLE _Python3_PREFIX
  OUTPUT_STRIP_TRAILING_WHITESPACE
)

execute_process(
  COMMAND ${Python_EXECUTABLE} -c "import PyQt6; print(PyQt6.__path__[0])"
  OUTPUT_VARIABLE _PyQt6_PATH
  OUTPUT_STRIP_TRAILING_WHITESPACE
)

set( _PyQt6_HINTS
  "${Python3_SITELIB}"
  "${Python3_SITEARCH}"
)

find_path( PyQt6_INCLUDE_DIR
  NAMES "QtCore/QtCoremod.sip"
  PATHS "${_PyQt6_PATH}"
  HINTS ${_PyQt6_HINTS}
  PATH_SUFFIXES "PyQt6" "PyQt6/bindings" "bindings"
)

execute_process(
  COMMAND ${Python_EXECUTABLE} -c "from PyQt6.QtCore import PYQT_VERSION_STR; print(PYQT_VERSION_STR)"
  OUTPUT_VARIABLE PyQt6_VERSION
  OUTPUT_STRIP_TRAILING_WHITESPACE
)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args( PyQt6
  REQUIRED_VARS
    PyQt6_INCLUDE_DIR
  VERSION_VAR PyQt6_VERSION
)

if( PyQt6_FOUND )
  set( PyQt6_INCLUDE_DIRS ${PyQt6_INCLUDE_DIR} )
  RECURSIVE_DIRECTORIES(/opt/homebrew/include/Qt*.h pyqt6_includes)
  FILE(GLOB_RECURSE pyqt6_libs FOLLOW_SYMLINKS "${_PyQt6_PATH}/Qt6/lib/*")
  list(FILTER pyqt6_libs INCLUDE REGEX "${_PyQt6_PATH}/Qt6/lib/.*A/.*" )
  set( PyQt6_LIBRARIES ${pyqt6_libs} )
  message( "Found PyQt6: ${_PyQt6_PATH}")
else()
  message( "Could not locate PyQt6. This can be installed with \"pip install PyQt6\"")
endif()

mark_as_advanced( PyQt6_INCLUDE_DIR )