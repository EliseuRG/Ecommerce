QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    AreaCliente.cpp \
    AreaMaster.cpp \
    CadastroCliente.cpp \
    Cliente.cpp \
    Clientes.cpp \
    GestaoCliente.cpp \
    GestaoPedido.cpp \
    GestaoProduto.cpp \
    LoginMaster.cpp \
    Pedido.cpp \
    Pedidos.cpp \
    Produto.cpp \
    Produtos.cpp \
    Sobre.cpp \
    main.cpp \
    MainWindow.cpp

HEADERS += \
    AreaCliente.h \
    AreaMaster.h \
    CRUD.h \
    CadastroCliente.h \
    Cliente.h \
    Clientes.h \
    GestaoCliente.h \
    GestaoPedido.h \
    GestaoProduto.h \
    LoginMaster.h \
    MainWindow.h \
    Pedido.h \
    Pedidos.h \
    Produto.h \
    Produtos.h \
    Sobre.h \
    TransformarDados.h

FORMS += \
    AreaCliente.ui \
    AreaMaster.ui \
    CadastroCliente.ui \
    GestaoCliente.ui \
    GestaoPedido.ui \
    GestaoProduto.ui \
    LoginMaster.ui \
    MainWindow.ui \
    Sobre.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    .gitignore \
    tp.pro.user

RESOURCES += \
    Recursos.qrc
