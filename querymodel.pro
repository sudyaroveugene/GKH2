HEADERS       = ../connection.h \
                customsqlmodel.h \
                editablesqlmodel.h \
    form1.h \
    ticket.h
SOURCES       = customsqlmodel.cpp \
                editablesqlmodel.cpp \
    main.cpp \
    ticket.cpp
QT           += sql widgets
requires(qtConfig(tableview))

# install
target.path = $$[QT_INSTALL_EXAMPLES]/sql/querymodel
INSTALLS += target

FORMS += \
    form1.ui

