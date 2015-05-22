#-------------------------------------------------
#
# Project created by QtCreator 2015-05-12T19:25:33
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SansCar
TEMPLATE = app


SOURCES += main.cpp\
        dialog.cpp \
    cadastradocarro.cpp \
    cadastrocor.cpp \
    cadastrarcidade.cpp \
    cadastrarestado.cpp \
    janelaprincipal.cpp \
    controllerfile.cpp \
    carromodel.cpp \
    cadastromodelo.cpp \
    cadastramarca.cpp \
    pagamento.cpp

HEADERS  += dialog.h \
    cadastradocarro.h \
    cadastrocor.h \
    cadastrarcidade.h \
    cadastrarestado.h \
    janelaprincipal.h \
    controllerfile.h \
    carromodel.h \
    cadastromodelo.h \
    cadastramarca.h \
    pagamento.h

FORMS    += dialog.ui \
    cadastradocarro.ui \
    cadastrocor.ui \
    cadastrarcidade.ui \
    cadastrarestado.ui \
    janelaprincipal.ui \
    cadastromodelo.ui \
    cadastramarca.ui \
    pagamento.ui

RESOURCES += \
    Source.qrc
