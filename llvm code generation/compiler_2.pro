QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        main.cpp \
    codegeneratorutils.cpp \
    value.cpp \
    mathutils.cpp \
    ExprParser.cpp \
    ExprListener.cpp \
    ExprLexer.cpp \
    ExprBaseListener.cpp \
    ExprVisitor.cpp \
    ExprBaseVisitor.cpp \
    actions.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

unix|win32: LIBS += -lantlr4-runtime

HEADERS += \
    codegeneratorutils.hpp \
    value.hpp \
    mathutils.hpp \
    ExprParser.h \
    ExprListener.h \
    ExprLexer.h \
    ExprBaseListener.h \
    ExprVisitor.h \
    ExprBaseVisitor.h \
    actions.hpp

DISTFILES += \
    ExprLexer.tokens \
    ExprLexer.interp \
    Expr.tokens \
    Expr.interp \
    Expr.g4
