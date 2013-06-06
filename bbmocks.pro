PROJECT_LOCATION = $$_PRO_FILE_PWD_

TEMPLATE = lib
TARGET = bbmocks

CONFIG += staticlib qt warn_on release no_keywords

QT += xml declarative

# add gtest/gmock to the include path and libs line
GMOCK_DIR = $${PROJECT_LOCATION}/../gmock
INCLUDEPATH += $${GMOCK_DIR}/include
LIBS += $${GMOCK_DIR}/build/release/libgmock.a


INCLUDEPATH += $${PROJECT_LOCATION}/src $${PROJECT_LOCATION}/include 
SOURCES += $$system("find $${PROJECT_LOCATION}/src -name '*.c*'")
HEADERS += $$system("find $${PROJECT_LOCATION}/include -name '*.h*'")


OBJECTS_DIR = .obj
MOC_DIR = .moc
RCC_DIR = .rcc
UI_DIR = .ui