
TEMPLATE        = lib
CONFIG         += plugin
QT             += widgets
INCLUDEPATH    += ../core
HEADERS         = sandboxplugin.h
SOURCES         = sandboxplugin.cpp
TARGET          = $$qtLibraryTarget(sandboxplugin)
DESTDIR         = ../plugins

EXAMPLE_FILES = sandboxplugin.json
