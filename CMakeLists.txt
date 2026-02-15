cmake_minimum_required(VERSION 3.16)
project(wubigendaqi VERSION 1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(QT NAMES Qt5 Qt6 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core5Compat Gui Sql)
find_package(Qt${QT_VERSION_MAJOR} OPTIONAL_COMPONENTS PrintSupport Widgets)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

set(CMAKE_AUTOUIC_SEARCH_PATHS ${CMAKE_CURRENT_SOURCE_DIR}/ui ${CMAKE_CURRENT_SOURCE_DIR}/ui/Menu)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_CURRENT_SOURCE_DIR}/bin/Debug")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_CURRENT_SOURCE_DIR}/bin/Release")

file(GLOB_RECURSE SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
file(GLOB_RECURSE HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/include/*.h)
file(GLOB_RECURSE UI_FILES ${CMAKE_CURRENT_SOURCE_DIR}/ui/*.ui)
file(GLOB_RECURSE RESOURCE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/res/*.qrc)

qt_standard_project_setup()

qt_add_executable(wubigendaqi WIN32 MACOSX_BUNDLE
    ${SOURCES}
    ${HEADERS}
    ${UI_FILES}
    ${RESOURCE_FILES}
)

target_link_libraries(wubigendaqi PRIVATE
    Qt::Core
    Qt::Core5Compat
    Qt::Gui
    Qt::Sql
)

if((QT_VERSION_MAJOR GREATER 4))
    target_link_libraries(wubigendaqi PRIVATE
        Qt::PrintSupport
        Qt::Widgets
    )
endif()

install(TARGETS wubigendaqi
    BUNDLE DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

qt_generate_deploy_app_script(
    TARGET wubigendaqi
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)

install(SCRIPT ${deploy_script})
